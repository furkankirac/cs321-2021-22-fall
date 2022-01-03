// Write your STUDENTID and NAME here
// Write your COMPILER and its VERSION here

// ---- READ CAREFULLY ----
// During the exam, you MUST upload your code snapshots at 10:00, and finally 11:30 or before the exam ends.
// ALWAYS CHECK YOUR UPLOADED CODE BY DOWNLOADING IT BACK FROM THE LMS.
// IN CASE OF A PROBLEM, EMAIL YOUR SNAPSHOT TO THE INSTRUCTOR AND ALL TEACHING ASSISTANTS.

// A snapshot is the *.cpp file of your solution at a specific time.
// 1st snapshot is at 10:00 (09:50-10:10 range is fine):
// Snapshot itself will be graded as 10 points if everything compiles, 5 points if not.
// Not submitting a snapshot costs you (minus) -25 points.
// 2nd snapshot is the completed exam. This code must definitely compile for us to grade it!
// This snapshot will not be given grades itself.
// Submitting only the last (2nd) snapshot causes you to fail the exam and get 0 points.
// For extra exam rules, please look at the "main" function below.
// ---- READ CAREFULLY ----

#include <iostream>
#include <vector>
#include <string>
#include <map>

using std::vector;
using std::map;
using std::pair;
using std::string;
using std::cout;
using std::endl;
using std::get;

using Date = string;
using Count = int;

using ProductCount = pair<string, Count>;

struct StockRecord
{
    string date;
    ProductCount product_count;
};

// makes ProductCount directly sendable to the console
auto& operator<<(std::ostream& os, const ProductCount& pc)
{
    const auto& [name, count] = pc;
    cout << "(" << name << ";" << count << ")";
    return os;
}

// makes StockRecord directly sendable to the console
auto& operator<<(std::ostream& os, const StockRecord& sr)
{
    cout << "(" << sr.date << ";" << sr.product_count << ")";
    return os;
}

#include <range/v3/all.hpp>

namespace views = ranges::views; // instead of ranges::views::*, directly use views::*
namespace actions = ranges::actions; // instead of ranges::views::*, directly use views::*
using namespace ranges; // instead of ranges::*, directly use *

int main(int argc, char* argv[])
{
    auto stock_data = vector<StockRecord>{
        {"2021-11-11", {"Motherboard", 2}},
        {"2021-12-02", {"SSD", 21}},
        {"2021-11-05", {"CPU", 12}},
        {"2021-11-21", {"GPU", 35}},
        {"2021-11-23", {"Keyboard", 3}},
        {"2021-11-11", {"Mouse", 20}},
        {"2021-12-02", {"Monitor", 10}},
        {"2021-12-11", {"CPU", 5}},
    };

    auto price_data = map<string, int>{
        {"Motherboard", 100},
        {"SSD", 60},
        {"CPU", 85},
        {"GPU", 120},
        {"Keyboard", 5},
        {"Mouse", 8},
        {"Monitor", 45},
    };

    // Q1 (15pts) - Write unique dates in ascending order when at least one stock delivery happened
    // Q2 (15pts) - Write all stock data sorted by ascending date
    // Q3 (25pts) - Write total stock of products acquired after all stock arrivals
    // Q4 (20pts) - Write product stocks owned at a specific date (2021-11-11)
    // Q5 (15pts) - Write the price of product stocks owned at a specific date (2021-11-11)
    // Q6 (10pts) - Snapshot at 10:00 that compiles successfully.

    // WRITE YOUR SOLUTIONS HERE - BEGIN //
    // Using any imperative paradigm loop construct is FORBIDDEN!
    // (such as "for", "do-while", "while", "goto". you CANNOT use them!)
    // Using for_each algorithm either from std, or from ranges is FORBIDDEN!
    // Using any imperative paradigm conditional branching is FORBIDDEN! (such as "if")
    // Any forbidden keyword usage will cause you to lose all the points from related questions
    // Use ranges-v3 library for easier solutions. But all solutions that obey the above rules are accepted)
    // Hint: actions::sort function has two optional parameters
    // 1st one is a lambda that describes how to sort two similar items by returning a boolean
    // true means that two items are already sorted, false means that they need to be swapped
    // 2nd one is a lambda that returns the necessary portion of the whole item on which the sorting will be handled



    // WRITE YOUR SOLUTIONS HERE - END //

    return 0;
}
