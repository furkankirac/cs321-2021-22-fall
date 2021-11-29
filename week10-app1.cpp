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

template<typename>
struct TypeDisplayer;

using INT = int;

// class template
template<typename>      struct is_integral         { static const auto value = false; };
template<>              struct is_integral<int>    { static const auto value = true; };
template<>              struct is_integral<short>  { static const auto value = true; };
template<>              struct is_integral<char>   { static const auto value = true; };
template<>              struct is_integral<long>   { static const auto value = true; };


template<typename T>
const auto is_integral_v = is_integral<T>::value;


// class template
template<bool B, typename T1, typename T2>  struct conditional                 { using type = T1; };
template<typename T1, typename T2>          struct conditional<false, T1, T2>  { using type = T2; };

// type alias template
template<bool B, typename T1, typename T2>
using conditional_t = typename conditional<B, T1, T2>::type;

template<typename T1, typename T2>  struct is_same          { static const bool value = false; };
template<typename T>                struct is_same<T, T>    { static const bool value = true; };


// function template
template<typename T>
void foo(int)
{
}

int main(int, char* [])
{
    foo<int>(1);
    foo<float>(2);

//    const auto a = is_integral<int>::value;
    const auto a = is_integral_v<int>;
    std::cout << (a ? "true" : "false") << std::endl;

    const auto b = is_same<int, short>::value;
    std::cout << (b ? "true" : "false") << std::endl;


    using T = conditional<false, int, float>::type;
    using T2 = conditional_t<false, int, float>;
//    auto t = TypeDisplayer<T2>{};

    return 0;
}
