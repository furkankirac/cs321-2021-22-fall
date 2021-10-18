// Fraction class: Want to represent rational numbers with a numerator and denominator

// OOP: (encapsulates all necessary tools in a box that communicates
//  with outside via c-tors, assignment operators, and casting
// ctor/dtor
// copy-ctor, copy-assignment
// move-ctor, move-assignment (advanced, will discuss later)
// casting
// inheritance (will discuss later)

// function overloading, overload set
// operators and operator overloading

//struct Acceleration
//{
//    double value;
//    Acceleration(double value) : value(value) { }
//};

// literals, types of constants (remember units in your Physics class: 9.8 m/s^2)
// user-defined literals (a special way to create your own literals)

// Celsius/Fahrenheit example
// converting constructors

// pass by value, pass by reference, pass by constant reference
// implicit/explicit constructors

// operator+ overload for Celsius/Fahrenheit

#include <iostream>
using namespace std;

struct Fraction
{
    int n; // numerator
    int d; // denominator

    Fraction() : n(0), d(1) { /* cout << "!!!" << endl; */ }
    Fraction(int n) : n(n), d(1) { }
    Fraction(int n, int d) : n(n), d(d) { }

    Fraction(const Fraction& other) : n(other.n), d(other.d) // copy construction
    {
        cout << "Copy constructed" << endl;
    }

    void operator=(const Fraction& right) // copy assignment
    {
        cout << "Copy assignment" << endl;
        n = right.n;
        d = right.d;
    }

    void print() const
    {
        cout << n << " / " << d << endl;
    }

    operator double() const // conversion operator for double type request
    {
        return double(n) / d;
    }

    operator int() const // conversion operator for double type request
    {
        return int(double(n) / d);
    }

    auto get_value() const
    {
        return double(n) / d;
    }
};

auto operator"" _frac(long double value) // value can be 3.456 ----> 3456 / 1000
{
    return Fraction((int)value, 1);
}

// free function form of overloading assignment operator is forbidden
//void operator=(Fraction& left, const Fraction& right)
//{
//    left.n = right.n;
//    left.d = right.d;
//}

// free function
void print(const Fraction& f) // pass by constant reference
{
    cout << f.n << " / " << f.d << endl;
}

void print()
{
    cout << "Hello World" << endl;
}



Fraction a(); // forward declaration
// func_name();
Fraction a() { }

int main(int argc, char* argv[])
{
    auto i = 5;

    print();
//    Fraction a(); // this is stupidly deduced as a function with name "a" that takes no input and return Fraction
    auto a = Fraction(); // modern way of default construction
    print(a);
    a = Fraction(20, 7); // copy assignment
    a.print(); // this pointer becomes equal to &a (address of a)
//    cout << a.n << " / " << a.d << endl;
//    Fraction b(10);
    auto b = Fraction(10);
    print(b);
    b.print();
//    cout << b.n << " / " << b.d << endl;
//    Fraction c(10, 3);
    auto c = Fraction(10, 3);
    print(c);
    c.print();
//    cout << c.n << " / " << c.d << endl;

    auto d = Fraction(c);
    cout << d.get_value() << endl;
    cout << (double)d << endl;
    cout << double(d) << endl;
    cout << int(d) << endl;

    auto e = 11.567_frac;
    print(e);

    return 0;
}
