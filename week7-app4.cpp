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
#include <vector>
#include <string>
#include <map>

template<typename T>
struct TypeDisplay;

using namespace std;

template<typename T1, typename T2>
struct Pair
{
    T1 first;
    T2 second;
};
// std::pair

using BirthYearOfPerson = Pair<int, string>;

template<typename Key, typename Value>
auto reverse_map(const map<Key, Value>& m)
{
    auto return_value = std::map<Value, Key>{};
    for(const auto& [key, value] : m)
        return_value[value] = key;

    return return_value;
}

template<typename Key, typename Value>
auto print(const map<Key, Value>& m)
{
    for(const auto& [key, value] : m)
        cout << key << " " << value << endl;
}

//auto print(const vector<BirthYearOfPerson>& v)
//{
//    for(const auto& item : v)
//        cout << item.first << ", " << item.second << endl;
//}

template<typename T>
auto print(const vector<T>& v)
{
    for(const auto& item : v)
    {
//        if constexpr( std::is_same<T, BirthYearOfPerson>::value )
//            cout << item.first << ", " << item.second << endl;
//        else
        cout << item << endl;
    }
}


auto& operator<<(ostream& out, const BirthYearOfPerson& item)
{
    out << item.first << ", " << item.second << endl;
    return out;
}

int main(int argc, char* argv[])
{
    auto v = vector<BirthYearOfPerson>{{1978, "Furkan"}, {1980, "Veli"}, {2000, "Ayse"}};
    auto v_int = vector<int>{1, 2, 3};

    auto m = std::map<int, string>{
        {1, "one"},
        {2, "two"},
        {11, "eleven"}
    };

    auto m2 = reverse_map(m);

    print(m);
    print(m2);

    print(v);
    print(v_int);


//    cout << m[11] << endl;

    cout << endl;
    auto byop = BirthYearOfPerson{1978, "Furkan"};
    cout << byop << endl;
//    operator<<(cout, byop).operator<<(endl);

    return 0;
}
