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
#include <initializer_list> // bridge between standard library and core C++ language part

using namespace std;

struct Vector3d;
struct Vector3d_iterator
{
    Vector3d* obj;
    int index;

    auto operator*() const;
    auto operator++() // ++ as a prefix overload
    {
        ++index;
    }
//    auto operator++(int) // ++ as a suffix overload
//    {
//        index++;
//    }

    bool operator==(const Vector3d_iterator& other) const
    {
        return obj==other.obj && index == other.index;
    }

//    bool operator!=(const Vector3d_iterator& other) const
//    {
////        return obj!=other.obj || index != other.index;
//        return !(*this == other);
//    }

};

struct Vector3d
{
    int size;
    int x = -1;
    int y = -1;
    int z = -1;
    Vector3d(std::initializer_list<int> il)
    {
        size = il.size();
        if(size > 3) size = 3;
        cout << "size of IL=" << size << endl;
        auto ptr = il.begin();
        if(size >= 1) x = ptr[0];
        if(size >= 2) y = ptr[1];
        if(size >= 3) z = ptr[2];
    }
    Vector3d(int, int) { cout << "2 integers passed to me" << endl; }
//    Vector3d(int, int, int) { cout << "3 integers passed to me" << endl; }

    auto begin()    { return Vector3d_iterator{this, 0}; }
    auto end()      { return Vector3d_iterator{this, size}; }
};

auto Vector3d_iterator::operator*() const
{
    if(index == 0) return obj->x;
    if(index == 1) return obj->y;
    if(index == 2) return obj->z;
    return -1;
}


int main(int argc, char* argv[])
{
    auto v = Vector3d{1, 2, 10, 100};
    auto it = v.begin();
    cout << "x with iterator access is " << *it << endl;
//    ++it.index;
    ++it;
//    it.operator++();
    cout << "y with iterator access is " << it.operator*() << endl;
    it.index++;
    cout << "z with iterator access is " << it.operator*() << endl;

    cout << "for loop for iterator access" << endl;
    for(auto it = v.begin(); it != v.end(); ++it)
        cout << *it << endl;

    cout << "for range-for-loop for iterator access" << endl;
    for(auto item : v)
        cout << item << endl;




    cout << "x=" << v.x << endl;
    cout << "y=" << v.y << endl;
    cout << "z=" << v.z << endl;

    return 0;
}
