// CS321 Programming Paradigms

// Major Concepts to touch:

// Lecture contents will be available in the LMS
// code will be available in https://github.com/furkankirac

// History of C++
// Who designed C language? Dennis Ritchie (also designer of UNIX OS)
// Smalltalk - First flavor of OOP
// C++ by Bjarne Stroustrup

// Core language + Standard Library (Alexander Stepanov)
// ANSI
// ISO

// C++8x, C++98, C++04, C++11, C++14, C++17, C++20, C++23 (upcoming)

// Standard Library: libstdc++ (GCC), libc++ (clang is a fork of GCC4.2), MSVC
// windows uses \ as path separator
// macos, and linux uses / as path separator

// CMake: is important, not very likable, but nothing better than it right now :(

// Imperative-Programming paradigm
// Object-Oriented-Programming paradigm
// Functional-Programming paradigm
// Generic-Programming paradigm

// Compile-time vs run-time parameters

// Midterm Exam 1 (25%)
// A difficult problem to be solved in a few days time (open-book)
// Your unique solution is required

// Midterm Exam 2 (35%)
// A difficult problem to be solved in a few days time (open-book)
// Your unique solution is required

// Final Exam (40%)
// A difficult problem to be solved in a few days time (open-book)
// Your unique solution is required

// Will use:
//   Compiler: (Clang 11+ or GCC 11+ or MSVC latest) and C++20 standard.
//   MacOS: install Clang by using Homebrew: brew install llvm
//   Linux: install by using the package manager the latest GCC
//   Windows: use a Virtual Machine, install latest Ubuntu with GCC
//   You can use one of Clang, GCC, MSVC compilers, and any editor of your choice.

//   However, I would highly suggest you to use Qt Creator if not familiar with C++.
//   Editor: Qt Creator 4.13+. Why? Lightweight, very nicely supports CMake.
//   Don't download the whole Qt Framework! You can only download QtCreator for your machine.


// COMPILER CONFORMANCE: https://en.cppreference.com/w/cpp/compiler_support
// LANGUAGE REFERENCE: https://en.cppreference.com/

// C and C++ have smt. called preprocessor

#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "Hello World!" << std::endl;
    std::cout << argc << std::endl;

    for(int i=0; i<argc; i++)
    {
        std::cout << argv[i] << std::endl;
    }

    return 0; // 0 means everything is okay
}













