// nested for-loops in functional programming paradigm
// attaching two or more objects together for making them act as a single sequence

// std::tuple, is_tuple, is_tuple_v
// std::get<T>, std::get<index>
// tuple_element_t<index, T>
// tuple_size_v<T>

#include <iostream>
#include <tuple>
#include <string>

using namespace std;

template<typename ...>
struct TypeDisplayer;

struct Custom
{
    int i;
    float f;
    string s;
};


//std::tuple<int, float, string>

using TUPLE = std::tuple<int, float, string, Custom, float>;


template<typename T>        struct is_tuple                         { static const bool value = false; };
template<typename ... Ts>   struct is_tuple< std::tuple<Ts...> >    { static const bool value = true; };


template<typename T>
const bool is_tuple_v = is_tuple<T>::value;

int main(int argc, char* argv[])
{
    auto pair = std::pair<int, float>{10, 3.14f};
    auto tuple = TUPLE{10, 3.14f, "Hi there", Custom{}, 2.2f};

    cout << is_tuple<TUPLE>::value << endl;
    cout << is_tuple_v<TUPLE> << endl;

    cout << std::get<4>(tuple) << endl;

    using type_index_2 = std::tuple_element_t<2, TUPLE>;
//    auto td = TypeDisplayer<type_index_2>{};

    cout << std::tuple_size_v<TUPLE> << endl;
//    cout << 5 << endl;


    return 0;
}
