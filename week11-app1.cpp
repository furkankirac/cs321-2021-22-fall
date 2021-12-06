#include <iostream>
#include <array>
#include <list>
#include <vector>
//#include <tuple>

// higher-order-functions, lifting/currying, composing


using namespace std;

template<typename T>
concept IsContainer = requires(T t) {
    t.begin();
    t.end();
    t.size();
};

// terse syntax
auto print_(const IsContainer auto& container)
{
    for(const auto& item : container)
        cout << item << endl;
    cout << endl;

    return container;
}

auto print_(const auto& value)
{
    cout << value << endl << endl;
}

auto print()
{
    return [](const auto& a) {
        return print_(a);
    };
}

auto reverse_(const IsContainer auto& container)
{
    auto new_container = container;
    auto sz = container.size();
    auto it1 = new_container.begin();
    auto it2 = new_container.end()-1;
    for(auto i=0; i<sz/2; ++i)
    {
        swap(*it1, *it2);
        ++it1;
        --it2;
    }
    return new_container;
}

auto reverse()
{
    return [](const IsContainer auto& container) {
        return reverse_(container);
    };
}

template<IsContainer Container>
auto filter_(const Container& container, auto lambda)
{
    auto new_container = Container{};
    for(const auto& item : container)
        if(lambda(item))
            new_container.push_back(item);
    return new_container;
}

auto filter(auto criterion)
{
    return [criterion](const IsContainer auto& container) {
        return filter_(container, criterion);
    };
}

auto less_than(auto limit)
{
    return [limit](auto value) {
        return value < limit;
    };
}

auto higher_than(auto limit)
{
    return [limit](auto value) {
        return value > limit;
    };
}

auto operator|(const auto& left, const auto& right)
{
    return right(left);
}


//template<typename Value, typename ... Lambdas>
//auto all_of_(Value value, Lambdas ... lambdas)
auto all_of_(auto value, auto ... lambdas) { return (lambdas(value) && ...); }

auto all_of(auto ... lambdas) {
    return [=](auto value) {
        return all_of_(value, lambdas...);
    };
}

//auto none_of_(auto value, auto ... lambdas) { return !all_of_(value, lambdas...); }
//auto none_of_(auto value, auto ... lambdas) { return (lambdas(value) + ...) == 0; }
auto two_of_(auto value, auto ... lambdas) { return (lambdas(value) + ...) == 2; }

template<int count, typename Container>
requires(IsContainer<Container>)
auto take_(const Container& container)
{
    auto new_container = Container{};
    auto it = container.begin();
    for(auto i=0; i<count; ++i)
    {
        new_container.push_back(*it);
        ++it;
    }
    return new_container;
}

template<int count>
auto take()
{
    return [](const IsContainer auto& container) {
        return take_<count>(container);
    };
}

auto transform_(const IsContainer auto& container, auto lambda)
{
    auto new_container = container;
    for(auto& item : new_container)
        item = lambda(item);

    return new_container;
}

auto transform(auto lambda)
{
    return [=](const IsContainer auto& container) {
        return transform_(container, lambda);
    };
}

auto add_(auto value1, auto value2) { return value1 + value2; }
auto add(auto value1)
{
    return [=](auto value2) {
        return add_(value1, value2);
    };
}


auto accumulator_(const IsContainer auto& container, auto initval, auto lambda)
{
    auto a = initval;
    for(const auto& item : container)
        a = lambda(a, item);
    return a;
}

auto accumulator(auto initval, auto lambda)
{
    return [=](const IsContainer auto& container) {
        return accumulator_(container, initval, lambda);
    };
}

int main(int, char* [])
{
//    using CONTAINER = std::array<int, 6>;
    using CONTAINER = std::vector<float>;

    auto PRINT = print();

//    auto a = all_of_(70, higher_than(0), less_than(60));
//    cout << (a ? "True" : "False") << endl;

//    print_(take_<1>(CONTAINER{1, 50, -3, 5, 10, 100}));

//    cout << accumulator_(CONTAINER{1, 50, -3, 5, 10, 100}, 0, [](auto a, auto b) { return a+b; })
//        << endl;

    auto multiplier = [](auto a, auto b) { return a*b; };

    CONTAINER{1, 50, -3, 5, 10, 100}
        | PRINT
        | reverse() | PRINT
        | filter(all_of(higher_than(0), less_than(60))) | PRINT
        | take<2>() | PRINT
        | transform(add(2)) | PRINT
        | accumulator(1, multiplier) | PRINT;

    return 0;
}
