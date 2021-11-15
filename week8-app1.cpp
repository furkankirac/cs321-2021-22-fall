#include <iostream>
#include <vector>
#include <list>
#include <string>

// in search of a simpler and more understandable generic way of writing code
//  the dance of OOP, FP and GP paradigms

// lifting a function (higher order functions):
//  a function returning a function object: delays function use
// lt, gt, get_name, ...

// composing functions

// concepts, requires expression/clause

// extra generic transform algorithm
// "template template" arguments!

using namespace std;

enum Boolean { False, True };

struct Library
{
    string name;
    string location;
    Boolean is_public;
    int year;
};

// this requires i and j to be present at the call-time
bool less_than_(int i, int j) { return i < j; }
auto less_than(int j) // lifted function
{
    return [j](int i) { return less_than_(i, j); };
}
//bool less_than_2000(int i) { return i < 2000; }


bool greater_than_(int i, int j) { return i > j; }
auto greater_than(int j) { return [j](int i) { return greater_than_(i, j); }; }

auto get_name_(const auto& anything) { return anything.name; }
auto get_name()
{
    return [](const auto& anything) {
        return get_name_(anything);
    };
}

auto get_year_(const auto& anything) { return anything.year; }
auto get_year()
{
    return [](const auto& anything) {
        return get_year_(anything);
    };
}

auto compose(auto f, auto g)
{
    return [f, g](auto item) {
        return g(f(item));
    };
}

auto operator|(auto f, auto g) { return compose(f, g); }

template<typename>
struct TypeDisplay;

template< template<typename...> typename ContainerTemplate, typename Item, typename Lambda>
auto transform_(const ContainerTemplate<Item>& container, Lambda func)
{
    auto it = container.begin();
    const auto& item = *it;

    using type_of_item = typename std::remove_cvref<decltype(item)>::type;
//    TypeDisplay<type_of_item> a;
//    auto a = TypeDisplay<type_of_item>{};

    using type_of_returned_item = decltype(func(type_of_item{}));
//    auto b = TypeDisplay<type_of_returned_item>{};

    // Container is std::vector<Library>
    // ContainerTemplate is std::vector
    // Item is Library
    auto new_container = ContainerTemplate<type_of_returned_item>(container.size());

    auto it1 = container.begin();
    auto it2 = new_container.begin();
    while(it1 != container.end())
    {
        *it2 = func(*it1);
        ++it1;
        ++it2;
    }
    return new_container;
}

auto transform(auto func)
{
    return [func](const auto& container) {
        return transform_(container, func);
    };
}

template<typename Container>
auto filter_(const Container& container, auto func)
{
    auto new_container = Container{};
    for(const auto& item : container)
        if(func(item))
            new_container.push_back(item);

    return new_container;
}

auto filter(auto func)
{
    return [func](const auto& container) {
        return filter_(container, func);
    };
}

template<typename T>
concept AnyContainer = requires(T container) {
    container.begin();
    container.end();
    container.size();
};

template<typename T>
void print(const T& container) requires AnyContainer<T>
{
    for(const auto& item : container)
        cout << item << endl;
}

void print(int item)
{
    cout << "int: " << item << endl;
}



int main(int argc, char* argv[])
{
    auto result1 = less_than_(10, 25);
    cout << (result1 ? "True" : "False") << endl;

    auto lambda = less_than(25);
    auto result2 = lambda(100);
    cout << (result2 ? "True" : "False") << endl;

    auto v = vector<Library>{
                             {"Ozyegin University Library", "Cekmekoy", Boolean::True, 2009},
                             {"Bogazici University Library", "Hisar", Boolean::True, 1863},
                             {"Istanbul Technical University Library", "Maslak", Boolean::True, 1900},
                             };

    auto library1 = *v.begin();
    cout << "Name of the first library is " << get_name_(library1) << endl;

    auto gn = get_name();
    cout << "Name of the first library is " << gn(library1) << endl;

    auto before_2000 = less_than(2000);
    auto gy = get_year();
    cout << (before_2000(gy(library1)) ? "True" : "False") << endl;

//    auto composed_gy_before2000 = compose(gy, before_2000);
    auto composed_gy_before2000 = gy | before_2000;
    cout << (composed_gy_before2000(library1) ? "True" : "False") << endl;
    cout << ((gy | before_2000)(library1) ? "True" : "False") << endl;

    auto filtered = filter(get_year() | less_than(2000));
    cout << "Filtered container contains this many items ---> " << filtered(v).size() << endl;
//    print(filtered(v));

    auto get_names = transform(get_name());
    auto new_container = get_names(v);
//    auto new_container = transform_(v, get_name()); //year() | less_than(2000));

    print(new_container);

//    auto v_names = vector<string>{"Ozyegin University Library", "Bogazici University Library"};
//    auto v_fdate = vector<int>{2009, 1980 };

    print(5);
//    print(Library{});

    return 0;
}
