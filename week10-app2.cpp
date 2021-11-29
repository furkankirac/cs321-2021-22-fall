// some fancy type traits
//  is_integral<int>::value
//  conditional_type<boolean_value, T1, T2>::type
//  is_same<int, int>::value

// some fancy concepts (compile-time validation of types):
//  integral, same_as, ...

// accumulate algorithm, adder function
// lifted (higher order) accumulate algorithm, adder_lifed function

// comma operator
// fold expressions

#include <iostream>
#include <vector>
#include <list>
#include <numeric>

template<typename Container, typename T, typename Lambda>
auto accumulate_(const Container& v, T initial_value, Lambda lambda)
{
    auto result = initial_value;
    for(const auto& item : v)
        result = lambda(result, item);
//        result = result + item;
    return result;
}

template<typename T, typename Lambda>
auto accumulate(T initial_value, Lambda lambda)
{
    return [=]<typename Container>(const Container& v) {
        return accumulate_(v, initial_value, lambda);
    };
}

auto bar()
{
    std::cout << "Hi There" << std::endl;
    return 100;
}


//template<typename ... Ts>
void print(const auto& ... ts)
{
    ((std::cout << ts << std::endl), ...);
}

auto sum(const auto& ... values)
{
    return (values + ...);
}

//double sum(int i, double d, float f)
//{
//    return i + d + f;
//}

void print(int i, float f, char c, double d)
{
    (std::cout << i << std::endl),
        (std::cout << f << std::endl),
        (std::cout << c << std::endl),
        (std::cout << d << std::endl);
}

int main(int, char* [])
{
//    print<int, float, char, double>(10, 1.1f, 'a', 3.14);
    print(10, 1.1f, 'a', 3.14);
    std::cout << sum(10, 3.14, 100.1f) << std::endl;

    auto v = std::vector<int>{1, 2, 3, 4, 5};
    auto v_f = std::vector<float>{1.1, 2.2, 3.3, 4.4, 5.5};

    auto adder = [](auto a, auto b) { return a+b; };
    auto multiplier = [](auto a, auto b) { return a*b; };

//    v_f | filter(greater_than(2)) | accumulate(1.1, adder) | PRINT;
//    print(accumulate_(filter(v_f, greater_than(2)), 1.1, adder));

    std::cout << accumulate_(v, 1.1, adder) << std::endl;
    std::cout << accumulate_(v_f, 1.1f, multiplier) << std::endl;

//    std::cout << std::accumulate(v_f.begin()+1, v_f.end()-1, 1.1f, multiplier) << std::endl;

    return 0;
}
