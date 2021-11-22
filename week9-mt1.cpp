// Write your STUDENTID and NAME here
// Write your COMPILER and its VERSION here

// ---- READ CAREFULLY ----
// During the exam, you MUST upload your code's snapshots at 16:30, 17:30, and finally 18:30 or before the exam ends.
// A snapshot is the *.cpp file of your solution at a specific time.
// 1st snapshot is at 16:30 (16:20-16:40 range is fine):
// Snapshot itself will be graded as 10 points if everything compiles, 5 points if not.
// Not submitting a snapshot costs you (minus) -25 points.
// 2nd snapshot is at 17:30 (17:20-17:40 range is fine):
// This snapshot must show at least a tiny improvement on Snapshot 1.
// Otherwise it will be considered as not uploaded.
// Snapshot itself will be graded as 10 points if everything compiles, 5 points if not.
// Not submitting or submitting the same snapshot as 1st one costs you (minus) -25 points.
// 3rd snapshot is the completed exam. This code must definitely compile for us to grade it!
// This snapshot will not be given grades itself. This snapshot can be the same with the 2nd snapshot, no problem.
// For extra exam rules, please look at the "main" function below.
// ---- READ CAREFULLY ----

#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <string>

struct Course
{
    int code;
    std::string name;
    void print() const { std::cout << "'CS" << code << " " << name << "'"; }
};

// ----- WRITE HERE -----

// ----- WRITE HERE -----

int main(int argc, char* argv[])
{
    // ----- FORBIDDEN THINGS -----
    // Overloading any operators is forbidden. Only overloading is forbidden. You can use already available operators.
    // Using "if constexpr", or "std::is_same" is forbidden.
    // You CANNOT CHANGE the exam template given. You CAN only write in between the "--- WRITE HERE ---" blocks
    // Doing any of the forbidden things will get you 0 points.
    // ----- FORBIDDEN THINGS -----

    // Q1 (25 pts): Consists of these sub-questions ---> Q1a (10 pts), Q1b (10 pts), Q1c (5 pts)
    // Write a "print" free-function overload-set that can exactly print the containers
    // as illustrated in the console output.
    // Note that Course struct already knows how to print itself via its "print" method.

    // Q2 (5 pts)
    // Write a generic my_swap function which swaps the values of two "same-typed" instances

    // Q3 (35 pts): Consists of these sub-questions ---> Q3a (10pts), Q3b (10pts), Q3c (10pts), Q3d (5pts)
    // Write a "my_sort" free-function that inline sorts any container by a helper lambda
    // that defines the valid order between two consecutive items of the container.
    // Implement the sorting yourself by using bubble-sort. Do not use std::sort or any functions in standard library.
    // For helper lambda examples, check the below "ascending", "descending" variables.
    // inline sort means that the content of the provided container is directly changed.

    // Q4 (15 pts): Consists of these sub-questions ---> Q4a (10 pts), Q4b (5 pts)
    // Write necessary lambdas customized for sorting the Course struct by its different attributes

    // Q5 (10 pts)
    // Snapshot 1 (*.cpp file) uploaded to the LMS and compiles

    // Q6 (10 pts)
    // Snapshot 2 (*.cpp file) uploaded to the LMS and compiles

    auto ascending = []<typename T>(const T& a, const T& b) { return a < b; };
    auto descending = []<typename T>(const T& a, const T& b) { return a > b; };

    auto v = std::vector<int>{10, 5, 8, -3, 1, 101};
    // Q1a (10 pts)
    print(v, "vector<int> original");

    // Q2 (5 pts)
    my_swap(v[1], v[5]);

    print(v, "vector<int> after swap");

    // Q3a (10pts)
    my_sort(v, ascending);

    print(v, "vector<int> ascending sorted");

    // Q3b (10pts)
    my_sort(v, descending);

    print(v, "vector<int> descending sorted");

    auto a = std::array<float, 6>{10.10f, 5.5f, 8.8f, -3.3f, 1.1f, 101.101f};
    // Q3c (10 pts)
    my_sort(a, ascending);

    // Q1b (10 pts)
    print(a, "array<float, 6> ascending sorted");

    my_sort(a, descending);
    print(a, "array<float, 6> descending sorted");

    auto l = std::list<Course>{
        {321, "Programming Paradigms"},
        {409, "Advanced C++ Programming"},
        {423, "Computer Vision"}
    };

    // Q2c (5 pts) - my_sort works on list<T>
    // Q4a (10 pts) - write ascending_by_name lambda
    // < and > operators that does alphabetical comparison are already overloaded for std::string in the std library
    my_sort(l, ascending_by_name);
    print(l, "list<Course> ascending sorted by name");

    // Q1c (5 pts) - print works on list<T>
    // Q3d (5 pts) - my_sort returns correctly for print to work (no extra copies of the container shall be made)
    // Q4b (5 pts) - write descending_by_code lambda
    print(my_sort(l, descending_by_code), "list<Course> descending sorted by code");

    return 0;
}

// ----- Correct console output of the exam solution -----
// vector<int> original
// 10, 5, 8, -3, 1, 101
//
// vector<int> after swap
// 10, 101, 8, -3, 1, 5
//
// vector<int> ascending sorted
// -3, 1, 5, 8, 10, 101
//
// vector<int> descending sorted
// 101, 10, 8, 5, 1, -3
//
// array<float, 6> ascending sorted
// -3.3, 1.1, 5.5, 8.8, 10.1, 101.101
//
// array<float, 6> descending sorted
// 101.101, 10.1, 8.8, 5.5, 1.1, -3.3
//
// list<Course> ascending sorted by name
// 'CS409 Advanced C++ Programming', 'CS423 Computer Vision', 'CS321 Programming Paradigms'
//
// list<Course> descending sorted by code
// 'CS423 Computer Vision', 'CS409 Advanced C++ Programming', 'CS321 Programming Paradigms'
