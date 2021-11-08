// pure functions != free functions
// pure functions are better. eliminate state if possible.
// if state is definitely required, better use OOP to encapsulate it from the outside world in a lambda function

// compile-time pure functions are represented by template meta programming in C++
// and also "constexpr" keyword.

// meta-programming trick in templates

// constexpr, if constexpr, concepts
// Pair
// print_container


#include <iostream>
#include <string>
#include <vector>

template<typename T>
struct TypeDisplay;

using namespace std;

//typedef int Integer;
//using Integer = int;


template<typename T>    struct remove_modifiers             { using type = T; };
template<typename U>    struct remove_modifiers<const U>    { using type = U; };
template<typename U>    struct remove_modifiers<U&>         { using type = U; };
template<typename U>    struct remove_modifiers<const U&>   { using type = U; };

//auto incremented_elements = [](const auto& container, int increment=1) {
////    const std::vector<int>& a;
////    std::vector<int> a;
////    decltype(container) a;
//    using T = decltype(container);
//    using T_clean = typename remove_modifiers<T>::type;

////    TypeDisplay<T_clean> td;
//    T_clean new_container(container);

//    for(auto& item : new_container)
//        item += increment;

//    return new_container;
//};

auto incremented_elements = [](const auto& container, int increment=1) {
    auto new_container = container;
    for(auto& item : new_container)
        item += increment;

    return new_container;
};


auto print(const auto& container)
{
    for(const auto& item : container)
        cout << item << endl;
}



int main(int argc, char* argv[])
{
    auto v = vector<int>{10, 20, 30};
    print(v);

    auto v_incremented_by_2 = incremented_elements(v, 2);
    print(v_incremented_by_2);

    print(v);

//    auto td = TypeDisplay<remove_modifiers<const int>::type>{};

//    remove_modifiers<const int>::type a = 100;

    return 0;
}
