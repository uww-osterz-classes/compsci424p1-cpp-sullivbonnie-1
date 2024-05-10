# UWW COMPSCI 424 Program 1 in C++

## Your notes for me

This is my submission for program 1 at 11:54 pm 5/9/24. Late program submission was submitted & approved.

## About this repository and autograding
 
Use this template for Operating Systems Program 1 in C++.

**Your C++ code files must use the extension `.cpp`**, except header files may use the extension `.h`. The makefile that GitHub Classroom uses to run your code searches only for files with .cpp extensions.

The included files use a (mostly) typical C++ file structure for a program like this. Feel free to change, add, divide, combine, or delete files; add or combine classes; create more methods; modify the existing methods; and more. Providing correct functionality is more important than having a specific program structure.

The GitHub Classroom autograder will compile and run your code on a Linux virtual machine using the GNU C++ compiler. You can use all C++ features that are supported by the C++17 standard plus amendments. 

If you develop on **washington.uww.edu**, suggested compiler commands are `gcc-5` (C) or `g++-5` (C++).

If you are encountering problems getting your code to pass tests when you push to GitHub Classroom, please [email me](osterz@uww.edu) with a description of what's happening. I will look at your repository on GitHub to try to help you debug.

## Advice for C++ programmers

This advice is also posted on the Program 1 page on Canvas. Updates, if any, will be posted there.

* Instead of classes, you could use 2 separate functions, then use the main function/method to run the tests and evaluate running times for both versions. You may define additional functions as needed.
* The `clock` function, provided by `#include <ctime>` (C++) or `#include <time.h>` (C), gives you a current time measurement as the number of "clock ticks" since a previous time. For an example of timing part of a C++ program, see: [clock - C++ Reference](http://cplusplus.com/reference/ctime/clock/). The example code works in essentially the same way in C.
* C++ programmers may use the `forward_list` or `list` class template that is defined in the C++11 standard to implement your linked lists.
  - If you want to use a `forward_list` or `list` object in your program, you will need to `#include <forward_list>` or `#include <list>`.
  - If the `g++` compiler complains about these names not being defined, try adding the `-std=c++14` or `-std=c++17` option to your compile command.
  - More info about these class templates: [forward_list - C++ Reference](http://cplusplus.com/reference/forward_list/forward_list/), [list - C++ Reference](http://cplusplus.com/reference/list/list/).
  - You can also use your own linked list implementation if you prefer that.
