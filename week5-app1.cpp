// pointers, dereferencing, pointer arithmetic
// OOP: unified/universal construction:
//   stricter construction with {} instead of (),
//   designated initializers
//   initializer_list support for ctors
// iterators and range-for-loop
// introducing std::vector<T>
// "transform/map" algorithm with function pointers
// encapsulating functions:
//   functions themselves (with func pointers),
//   function objects
//   lambda functions

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int i = 100;
    int* ptr = &i;

    cout << ptr[0] << endl;
    cout << *(ptr + 0) << endl;
    cout << *ptr << endl;

    cout << *(ptr + 1) << endl; // ptr[1]
    cout << *(1 + ptr) << endl;
    cout << 1[ptr] << endl;

    return 0;
}
