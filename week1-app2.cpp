// stack memory vs heap memory
// value semantics vs reference semantics

// global scope, local scope
// free-functions

// class/struct? object? ------> type? instance?
// typedef (C)

// c-tor of a primitive type
// c-tor of a complex type (struct)

// write a c-tor of a struct instance as a free function (imperative programming paradigm)
// write a c-tor of a struct instance as a member function (OOP paradigm)

// allocate memory at run-time (dynamic memory allocation)
// free memory at run-time

// write a dtor as a free function (imperative programming paradigm)
// write a dtor as a member function (OOP paradigm)

// member variables ~= attributes ~= properties (OOP)

#include <iostream>

int e[2] = { 10, 20 };
int f[2] = { 1, 2 };

int m[2] = { 10, 20 };
int n[2] = { 1, 2 };

int i = 100;

//typedef struct { int x; int y; } Vector2d;
struct Vector2d
{
    int x; // member variable, attribute, property
    int y;

    Vector2d(int x_, int y_)
    {
        x = x_;
        y = y_;
    }

    // uses new type created by "struct Vector2d" and its two different instances as input
    // returns the result as a Vector2d instance as well
    Vector2d addVector2d(const Vector2d& a2) const
    {
        Vector2d k(x + a2.x, y + a2.y);
        return k;
    }
};


struct Vector
{
    int n_dims;
    int* values;

    Vector(int n_dims_, int* values_)
    {
        n_dims = n_dims_;
        values = new int[n_dims];
        if(values_ != nullptr)
        {
            for(int i=0; i<n_dims; i++)
            {
                values[i] = values_[i];
            }
        }
    }

    ~Vector()
    {
        delete[] values;
    }

    // uses new type created by "struct Vector2d" and its two different instances as input
    // returns the result as a Vector2d instance as well
    Vector addVector(const Vector& other) const
    {
        Vector result(n_dims, nullptr);
        if(n_dims != other.n_dims)
        {
            std::cout << "Number of dimensions don't hold" << std::endl;
            return result;
        }

        for(int i=0; i<n_dims; i++)
            result.values[i] = this->values[i] + other.values[i];

        return result;
    }
};


// uses arrays with at least two elements as 2d vectors
void addVectors(int* v1, int* v2)
{
    int k[2];
    k[0] = v1[0] + v2[0];
    k[1] = v1[1] + v2[1];
}

//// uses new type created by "struct Vector2d" and its two different instances as input
//// returns the result as a Vector2d instance as well
Vector2d addVector2d(const Vector2d& a1, const Vector2d& a2)
{
    Vector2d k(a1.x + a2.x, a1.y + a2.y);
    return k;
}


void doSomething()
{
    int i = 0;
    ::i += 1; // global i which is equal to 100 is incremented by 1, local i stays as 0
    std::cout << i << std::endl;
}

int main(int argc, char* argv[])
{
    Vector2d v1(10, 20), v2(1, 2);
//    v1.x = 10;
//    v1.y = 20;
//    v2.x = 1;
//    v2.y = 2;

    int i = 0; // another local i value, different than the i in doSomething function above
    doSomething();

    addVectors(&e[0], &f[0]); // get the address of first element of e array, ...
    addVectors(&m[0], &n[0]);

    Vector2d K = addVector2d(v1, v2); // send v1 value, and v2 value to addVector2d. values are copied when addVector2d starts
    Vector2d K2 = v1.addVector2d(v2); // send v1 value, and v2 value to addVector2d. values are copied when addVector2d starts
    std::cout << K.x << std::endl;
    std::cout << K.y << std::endl;
    std::cout << K2.x << std::endl;
    std::cout << K2.y << std::endl;

    int Gvalues[3] = {11, 22, 33};
    int Hvalues[4] = {11, 22, 33, 44};
    Vector G(3, Gvalues);
    Vector H(4, Hvalues);
//    G.addVector(H); // shouldn't work
    Vector I = G.addVector(G); // shouldn't work
    std::cout << I.n_dims << std::endl;
    for(int i=0; i<I.n_dims; i++)
        std::cout << I.values[i] << std::endl;

    return 0; // 0 means everything is okay
}




