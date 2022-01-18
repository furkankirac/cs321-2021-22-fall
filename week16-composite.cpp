// Write your STUDENTID and NAME here
// Write your COMPILER and its VERSION here

// ---- READ CAREFULLY ----
// During the exam, you MUST upload your code snapshots at 9:30, and finally 10:30 or before the exam ends.
// ALWAYS CHECK YOUR UPLOADED CODE BY DOWNLOADING IT BACK FROM THE LMS.
// IN CASE OF A PROBLEM, EMAIL YOUR SNAPSHOT TO THE INSTRUCTOR AND ALL TEACHING ASSISTANTS.

// A snapshot is the *.cpp file of your solution at a specific time.
// 1st snapshot is at 9:30 (09:20-9:40 range is fine):
// Snapshot itself will be graded. Check below.
// 2nd snapshot is the completed exam. This code must definitely compile for us to grade it!
// This snapshot will not be given grades itself.
// Submitting only the last (2nd) snapshot causes you to fail the exam and get 0 points.
// >>>>> For extra exam rules, please look at the "main" function below.
// ---- READ CAREFULLY ----

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

#include <range/v3/all.hpp>

namespace views = ranges::views; // instead of ranges::views::*, directly use views::*
namespace actions = ranges::actions; // instead of ranges::views::*, directly use views::*
using namespace ranges; // instead of ranges::*, directly use *

int main(int argc, char* argv[])
{
    // Q1 (20pts) - Write the encrypt v1 algorithm: encrypts "s" below to "enc_v1" and prints it
    //            - This is the algorithm as known as Caesar Cipher, check it in the Internet.
    // Q2 (20pts) - Write the decrypt v1 algorithm: decrypts "enc_v1" to "dec_v1" and prints it
    // Q3 (20pts) - Write the encrypt v2 algorithm: encrypts "s" below to "enc_v2" and prints it
    //            - This is a modification of Caesar Cipher, which also takes into account
    //            - the index of the character that is being encoded as an offset to the dictionary
    //            - analyze the console output given for better understanding of how it works
    //            - compare encrypted v1 and encrypted v2 lines.
    // Q4 (20pts) - Write the decrypt v2 algorithm: decrypts "enc_v2" to "dec_v2" and prints it
    // Q5 (20pts) - Snapshot at 9:30 that compiles successfully and solves Q1 correctly.

    // ------- CAREFUL - CAREFUL - CAREFUL - CAREFUL - CAREFUL -------
    // Using any imperative paradigm loop construct is FORBIDDEN!
    // (such as "for", "do-while", "while", "goto". you CANNOT use them!)
    // Using for_each algorithm either from std, or from ranges is FORBIDDEN!
    // Using any imperative paradigm conditional branching is FORBIDDEN! (such as "if")
    // Any forbidden keyword usage will cause you to lose all the points from related questions
    // Use ranges-v3 library for easier solutions. But all solutions that obey the above rules are accepted)
    // ------- CAREFUL - CAREFUL - CAREFUL - CAREFUL - CAREFUL -------

    // Hints:
    // 'a' is a char. It's ASCII code as a decimal is 97
    // 'b' is 98 as a decimal.
    // 'z' is 122 as a decimal.
    // 'a' ... 'z' English lowercase characters are continuously valued between 97 ... 122 in ASCII table.
    // char('a'+1) is equivalent to 'b'
    // modulus operator is % in C/C++
    // taking the modulus of a negative value does not make it positive.
    // -1 % 7 is NOT 6. It is -1.

    // this is the encryption key
    auto encrypt_dict = string("hufvyitsdplorkwcjbgamqzxne");
    auto s = string("quickbrownfoxjumpedoverthelazydog");
    cout << "string to encrypt: " << s << endl;

    // WRITE YOUR SOLUTIONS HERE - BEGIN //

    cout << "encrypted (v1)   : ";
    auto enc_v1 = s | views::transform([&](char c) {
                      return char('a' + (ranges::find(encrypt_dict, c) - ranges::begin(encrypt_dict)));
                  }) | to<string>();
    cout << enc_v1 << endl;
    cout << "decrypted (v1)   : ";
    auto dec_v1 = enc_v1 | views::transform([&](char c) {
                      return encrypt_dict[c - 'a'];
                  }) | to<string>();
    cout << dec_v1 << endl;

    cout << "encrypted (v2)   : ";
    auto enc_v2 = views::zip_with(
                      [&](char c, int i) {
                          auto it = ranges::find(encrypt_dict, c);
                          return char('a' + (i + (it-ranges::begin(encrypt_dict))) % 26);
                      }, s, views::ints(0, unreachable)
                      ) | to<string>();
    cout << enc_v2 << endl;

    cout << "decrypted (v2)   : ";
    auto dec_v2 = views::zip_with(
                      [&](char c, int i) {
                          return encrypt_dict[(c-'a'-i+26)%26];
                      }, enc_v2, views::ints(0, unreachable)
                      ) | to<string>();
    cout << dec_v2 << endl;

    // WRITE YOUR SOLUTIONS HERE - END //

    return 0;
}
