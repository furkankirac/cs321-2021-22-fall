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

using namespace std;

template<int a, int b>              struct Multiply2 { static const int value = a * b; };
template<int a, int b, int c>       struct Multiply3 { static const int value = a * b * c; };

template<int first, int ... rest>   struct Multiply         { static const int value = first * Multiply<rest...>::value; };
template<int last>                  struct Multiply<last>   { static const int value = last; };

//struct Multiply_10_3_5_2 { static const int value = 10 * Multiply_3_5_2::value; };
//struct Multiply_3_5_2    { static const int value = 3 * Multiply_5_2::value; };
//struct Multiply_5_2      { static const int value = 5 * Multiply_2::value; };
//struct Multiply_2        { static const int value = 2; };

template<int a, int b> struct Divide          { static const int value = a / b; };
template<int a>        struct Divide<a, 0>    { static const int value = 0; };

// definition of abs function in math
// {  x   if x >= 0
// |
// |  -x  if x < 0
// {


//struct Multiply_10_2 { static const int value = 20; };
//struct Multiply_10_3 { static const int value = 30; };

//void absolute_value(int i)
//{
//    if(i<0)
//        return -i;
//    else
//        return i;
//}


int main(int argc, char* argv[])
{
//    int i = 10 * 2;
//    int i = Multiply_10_2::value;
//    int j = Multiply_10_3::value;

    int i = Multiply2<10, 2>::value;
    int j = Multiply3<10, 3, 5>::value;
    int k = Divide<10, 0>::value;

    int m = Multiply<10, 3, 5, 2>::value;


    cout << i << endl;
    cout << j << endl;
    cout << k << endl;
    cout << m << endl;


    return 0;
}
