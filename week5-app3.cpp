// pointers, dereferencing, pointer arithmetic
// OOP: unified/universal construction:
//   stricter construction with {} instead of (),
//   designated initializers
//   initializer_list support for ctors
// iterators and range-for-loop
// introducing std::vector<T>
// "transform" algorithm with function pointers
// encapsulating functions:
//   functions themselves (with func pointers)
//   function objects
//   lambda functions

#include <iostream>
#include <vector>   // an array dynamically allocated contiguously in heap memory
#include <list>     // this is a linked-list implementation
#include <string>

using namespace std;

void incrementBy(int& i, int value) { i += value; }
void decrementBy(int& i, int value) { i -= value; }

using FunctionPtr = void(*)(int&, int);

// transform is a very generic algorithm
// it doesn't care what to do with the content
// all it cares is to transform the contents of the vector according to what func does

template<typename Container>
void transform(Container& container, FunctionPtr func)
{
    for(auto& item : container)
        func(item);
}

template<typename Container>
void transform(Container& container, FunctionPtr func, int by_what)
{
    for(auto& item : container)
        func(item, by_what);
}

template<typename Container>
void transform(Container& container, FunctionPtr func, int p1, int p2)
{
    for(auto& item : container)
        func(item, p1, p2);
}

template<typename Container>
void print(const Container& container, std::string title)
{
    cout << title << endl;
    for(auto item : container)
        cout << item << endl;
}


int main(int argc, char* argv[])
{
    auto v1 = std::vector<int>(10); // initialize a vector instance storing 10 integers which are default constructed
    auto v2 = std::vector<int>{10, 20, 30, 40, 50, 60, 70};
    auto l1 = std::list<int>{10, 20, 30, 40, 50, 60, 70};

    cout << "v1" << endl;
    cout << v1[0] << endl;

    cout << "v2" << endl;
//    for(int i=0; i<v2.size(); ++i)
//        cout << v2[i] << endl;

    cout << "v2 with iterators" << endl;
    for(auto it = v2.begin(); it != v2.end(); ++it)
        cout << *it << endl;

//    for(auto& item : v2)
//        increment(item);

    transform(v2, &incrementBy, 1);
    transform(l1, &decrementBy, 10);

    print(v2, "v2 with iterators (range-for version)");
//    cout << "v2 with iterators (range-for version)" << endl;
//    for(auto item : v2)
//        cout << item << endl;

    print(l1, "l1 with iterators (range-for version)");
//    cout << "l1 with iterators (range-for version)" << endl;
//    for(auto item : l1)
//        cout << item << endl;





//    auto p = new int[10];
//    delete[] p;
//    auto V = vector<int>(10); // dynamic memory allocation of 10 integers

    return 0;
}
