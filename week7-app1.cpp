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
#include <string>

using namespace std;

//void print() // free function, not a pure function because of its state dependency
//{
//    static auto i = 0;
//    cout << "Hello " << ++i << endl;
//}

struct Print
{
    string title;

//    Print() : title("Hello") { }
    Print(string title = "Hello") : title(title) { }

    void operator() (int i) const
    {
        cout << title << " " << i << endl;
    }
};

void print(int i) // free function, pure function because of its state independency
{
    cout << "Hello " << i << endl;
}

int main(int argc, char* argv[])
{
    auto i = 0;
    print(++i); // 1
    print(++i); // 2
    print(++i); // 3

    auto func = Print{"Hi there!"};

    string s = "Hi there!";

    auto lambda = [title=s](int i)
    {
        cout << title << " " << i << endl;
    };

    auto j = 0;
    func(++j); // 1
    func(++j); // 2
    func(++j); // 3

    auto k = 0;
    lambda(++k); // 1
    lambda(++k); // 2
    lambda(++k); // 3

    return 0;
}
