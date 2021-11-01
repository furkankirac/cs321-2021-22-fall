// encapsulating functions:
//   functions themselves (with func pointers)
//   function objects (overloading the function call operator  "operator()"
//   lambda functions

// HomeWork: make a container from ordinary C array; make it suitable for container based generic algorithms
// very simple implementation of std::array
// auto a1 = std::array<int, 6>{};
// int a2[6];
// struct Array { ... };

// filter algorithm
// count_if algorithm
// mutable lambda: fibonacci generator

#include <iostream>
#include <vector>   // an array dynamically allocated contiguously in heap memory
#include <list>     // this is a linked-list implementation
#include <string>

using namespace std;

// transform is a very generic algorithm, it doesn't care what to do with the content
// all it cares is to transform the content of the CONTAINER according to what supplied "func" does

void transform_inline(auto& container, const auto& func_obj)
{
    for(auto& item : container)
        func_obj(item);
//        func_obj.operator()(item);
}

template<typename Container>
auto transform(const Container& container, const auto& func_obj)
{
    auto sz = container.size();
    auto c = Container(sz);
    auto iter = c.begin();
    for(const auto& item : container)
    {
        auto item_transformed = func_obj(item);
        *iter = item_transformed;
        iter++;
    }
    return c;
}

template<typename Container>
auto filter(const Container& container, const auto& func_obj)
{
    auto c = Container{};
    for(const auto& item : container)
    {
        if(func_obj(item))
            c.push_back(item);
    }
    return c;
}

auto count_if(const auto& container, const auto& func_obj)
{
    auto count = 0;
    for(const auto& item : container)
    {
        if(func_obj(item))
            ++count;
    }
    return count;
}


void print(const auto& container, std::string title)
{
    cout << title << endl;
    for(auto item : container)
        cout << item << endl;
}


//template<typename T>
//struct IncrementBy
//{
//    T by_what;
//    //    IncrementBy(T by_what) : by_what(by_what) { }
//    void operator() (T& i) const { i += by_what; }
//};

//template<typename T>
//struct DecrementBy
//{
//    T by_what;
//    //    DecrementBy(T by_what) : by_what(by_what) { }
//    void operator() (T& i) const { i -= by_what; }
//};

int main(int argc, char* argv[])
{
    auto v2 = std::vector<int>{10, 20, 31, 47, 55, 60, 70};
    auto l1 = std::list<double>{10.1, 20.2, 30.3, 40.4, 50.5, 60.6, 70.7};

//    IncrementBy func_obj(10);
//    auto func_obj1 = IncrementBy<int>{5};
    auto func_obj2 = [by_what=5](int& i) { i += by_what; };
//    transform_inline(v2, func_obj2);

    auto func_obj3 = [by_what=5](int i) { return i + by_what; };
    auto v2_transformed = transform(v2, func_obj3);

    auto func_obj4 = [by_what=5.5](auto i) { return i + by_what; };
    auto l1_transformed = transform(l1, func_obj4);


    auto is_even = [](int i) { return i % 2 == 0; };
    auto v2_filtered = filter(v2, is_even);

//    transform_inline(l1, [by_what=3.3](double& i) { i -= by_what; }); // DecrementBy<double>{3.3});

    print(v2, "v2");
    print(v2_transformed, "v2_transformed");
    print(l1, "l1");
    print(l1_transformed, "l1_transformed");

    print(v2_filtered, "v2_filtered");
    cout << "Number of even values in v2_filtered is " << count_if(v2, is_even) << endl;

    return 0;
}
