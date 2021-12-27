// nested for-loops in functional programming paradigm
// attaching two or more objects together for making them act as a single sequence

// std::tuple, is_tuple, is_tuple_v
// std::get<T>, std::get<index>
// tuple_element_t<index, T>
// tuple_size_v<T>

#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

void print_(const auto& container)
{
    for(const auto& [key, value] : container)
        cout << key << "|" << value << endl;
}


template<typename Container1, typename Container2, typename FUNC>
auto cartesian_product(const Container1& c1, const Container2& c2, FUNC func)
{
    for(const auto& i1 : c1)
        for(const auto& i2 : c2)
            func(i1, i2);
}

template<typename Container1, typename Container2, typename Container3, typename FUNC>
auto cartesian_product(const Container1& c1, const Container2& c2, const Container3& c3, FUNC func)
{
    for(const auto& i1 : c1)
        for(const auto& i2 : c2)
            for(const auto& i3 : c3)
                func(i1, i2, i3);
}

//auto take_minimumof(const auto& ... values)
//{

//}

template<
    template<typename ...> typename CT1,
    template<typename ...> typename CT2,
    typename ITEMTYPE1,
    typename ITEMTYPE2
    >
auto zip(const CT1<ITEMTYPE1>& c1, const CT2<ITEMTYPE2>& c2)
{
    auto sz = c1.size();
    if(sz > c2.size())
        sz = c2.size();

    auto container = CT1<std::pair<ITEMTYPE1, ITEMTYPE2>>(sz);
    auto it1 = c1.begin();
    auto it2 = c2.begin();
    auto it_dest = container.begin();
    for(int i=0; i<sz; ++i)
    {
        *it_dest = std::pair<ITEMTYPE1, ITEMTYPE2>{*it1, *it2};
        ++it1;
        ++it2;
        ++it_dest;
    }
    return container;
}

template<typename ...>
struct TypeDisplayer;

int main(int argc, char* argv[])
{
    auto v1 = vector<int>{1, 2, 3};
    auto v2 = list<string>{"aaa", "bbb", "ccc", "ddd"};

//    auto v_zipped = vector<pair<int, string>>{
//        {1, "aaa"},
//        {2, "bbb"},
//        {3, "ccc"},
//    };

    auto v_zipped = zip(v1, v2);
//    auto display = TypeDisplayer<decltype(v_zipped)>{};
    print_(v_zipped);

//    auto sz = v1.size();
//    if(sz > v2.size())
//        sz = v2.size();
//    for(int i=0; i<sz; ++i)
//        cout << v1[i] << "|" << v2[i] << endl;
//    take_minimumof(v1.size(), v2.size());


//    cartesian_product(v1, v2, [](int i, const string& s) {
//        cout << i << "/" << s << endl;
//    });
//    for(const auto& i1 : v1)
//        for(const auto& i2 : v2)
//            cout << i1 << "/" << i2 << endl;


//    print_(v1);
//    for(int i=0; i<v.size(); ++i)
//        cout << v[i] << endl;

    // no more raw-for-loops. If you do, then consider and alternative algorithm to use
//    for(int i=0; i<10; ++i)


    return 0;
}
