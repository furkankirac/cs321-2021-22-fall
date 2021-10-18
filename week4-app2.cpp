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

// structure forward declaration
struct Fahrenheit; // promise to the compiler that there is a structure called Fahrenheit to be declared later

struct Celsius
{
    static char suffix;

    double value;
//    Celsius() : value(0.0) { }
    Celsius(double value = 0.0) : value(value) { }

    // forward declaration of a method
    explicit Celsius(const Fahrenheit& f); // : value((f.value - 32.0) / 180.0 * 100.0) { }

    auto operator=(const Fahrenheit& f);

    operator double() { return value; }
};

char Celsius::suffix = 'C';

struct Fahrenheit
{
    static char suffix;

    double value;
    Fahrenheit(double value = 0.0) : value(value) { }
    Fahrenheit(const Celsius& c) : value(c.value / 100.0 * 180.0 + 32.0) { }
    operator double() { return value; }
};

char Fahrenheit::suffix = 'F';

Celsius::Celsius(const Fahrenheit& f) : value((f.value - 32.0) / 180.0 * 100.0) { }

auto Celsius::operator=(const Fahrenheit& f)
{
    value = (f.value - 32.0) / 180.0 * 100.0;
}


template<typename T>
void print(const T& c) { cout << c.value << " " << T::suffix << endl; }

//void print(const Celsius& a) { cout << a.value << " C" << endl; }
//void print(const Fahrenheit& a) { cout << a.value << " F" << endl; }

bool operator ==(const Celsius& left, const Fahrenheit& right)
{
    return left.value == Celsius(right).value;
}

bool operator ==(const Fahrenheit& left, const Celsius& right)
{
    return left.value == Fahrenheit(right).value;
}

int main(int argc, char* argv[])
{
    auto c1 = Celsius(100.0);
    print(c1);

    auto f1 = Fahrenheit(30.0);
    print(f1);

    auto f2 = Fahrenheit(c1);
    print(f2);

    auto c2 = Celsius(f2);
    print(c2);

    auto c3 = Celsius(10);
    // ....
    c3 = Fahrenheit(40.0);

    if(f2 == c2)
//    if(operator==(f2, c2))
    {
        cout << "Both temperatures are the same" << endl;
    }

    (cout.operator<<((double)c1)).operator<<(endl);
//    cout << (double)c1 << endl;

    return 0;
}
