// C has malloc and free for dynamic memory handling.
// C++ has new/delete.
// static variables, static member variables
// Generic Programming = Templates

// const keyword

// OOP:
// ctor/dtor
// copy-ctor, copy-assignment
// move-ctor, move-assignment (later)
// std::initializer_list<T> (later)
// inheritance (later)

// function pointers
// function overloading
// operators and operator overloading
// function parameters: pass by value, pass by reference

// auto, AAA rule (almost always auto)

#include <iostream>
#include "week3-app1.hpp"

template<> int Vector<int>::n_vectors = 0;
template<> int Vector<double>::n_vectors = 0;

using namespace std;

void doSomething1(int value)
{
    int m = 1000;
    m += value;
    cout << "m = " << m << endl;
}

void doSomething2(int value)
{
    int m = 10;
    m *= value;
    cout << "m = " << m << endl;
}

void increment_by_one(int& value)
{
    value++;
}

void multiply_by_two(int& value)
{
    value*=2;
}

using Func_t = void(*)(int&);

void for_each(int* values, int n_items, Func_t func)
{
    for(int i=0; i<n_items; i++)
        func(values[i]);
}


int main(int argc, char* argv[])
{
    doSomething1(10);
    doSomething2(111);
    doSomething1(500);

    using FuncPtr = void (*)(int);
    FuncPtr p1 = &doSomething1;
    p1(500);

    p1 = &doSomething2;
    p1(1);

    int k = 0;
    increment_by_one(k);

    cout << "k = " << ++k << endl;
    cout << "k = " << k << endl;

    int Gvalues[3] = {11, 22, 33};
    double Hvalues[4] = {11.1, 22.2, 33.3, 44.4};

//    Vector D();

    Vector<int> G(3, Gvalues);
    cout << "Number of vector instances after G is " << Vector<int>::n_vectors << endl;
    Vector<double> H(4, Hvalues);
    cout << "Number of vector instances after H is " << Vector<int>::n_vectors << endl;
//    Vector<int> I = G.addVector(G);
    Vector<int> I = G + G;
//    Vector<int> I = G.operator+(G);
    cout << "Number of vector instances after I is " << Vector<int>::n_vectors << endl;
    cout << I.n_dims << endl;
    for(int i=0; i<I.n_dims; i++)
        cout << I.values[i] << endl;

    return 0;
}
