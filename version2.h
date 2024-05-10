#pragma once
/* COMPSCI 424 Program 1
   Name: Bonnie Sullivan

   version2.h: contains the code to implement the process creation
   hierarchy for Version 2, which does not use linked lists.

   This is a template. Feel free to edit any of these files, even
   these pre-written comments or my provided code. You can add any
   classes, methods, and data structures that you need to solve the
   problem and display your solution in the correct format.

   C++ style note:
   This .h file is set up to include both declarations and code. It's
   considered good practice for .h files to contain only declarations
   and for most or all non-declaration code to be in .cpp files (which
   #include the relevant .h file(s)). However, if you're not used to
   compiling and linking multiple .cpp (or .cc or .C) files at once,
   putting both declarations and code in the .h files is easier.

   If you prefer to separate your declarations and code, feel free to
   do that. GitHub Classroom is set up to compile all .cpp, .cc, and
   .C files that are in your repository.
*/

#ifndef VERSION2_H
#define VERSION2_H

// You may need to add more #include directives.
// Remember: use <angle brackets> for standard C++ headers/libraries
// and "double quotes" for headers in the same directory as this file.
#include <iostream>

using namespace std; // I normally use this, but feel free to delete it

class Version2 {
private: // it's good OOP practice to make data members private
    int* PCBArray;
    int parent = -1;
    int first_child = NULL;
    int younger_sibling = NULL;
    int older_sibling = NULL;
    int size;

public:  // all methods are normally public
    Version2(int& size) {
        /* Default constructor. Use this to allocate (if needed) and
        initialize the PCB array, create the PCB for process 0, and do
        any other initialization that is needed.
        */
        // Pull the size of the array (number of commands entered) from main into v2 so it can be used
        this->size = size;
        // Create PCB Array & fill it with null values
        PCBArray = new int[size];
        for (int i = 0; i < size; i++) {
            PCBArray[i] = NULL; 
        }
    }

    ~Version2() {
        /* Destructor. If you allocated anything with "new" during
        the lifetime of this object, and you haven't yet "delete"d
        it, "delete" it (using the "delete" keyword) here.
        */
        delete[] PCBArray;
    }

    /* Creates a new child process of process with ID parentPid.
    */
    int create(int parentPid) {
        // If parentPid is not in the process hierarchy, do nothing; 
        // your code may return an error code or message in this case,
        // but it should not halt.
        if (size == 0 && parentPid != 0) {
            cout << "The first process must be zero" << endl;
        }
        // Assuming you've found the PCB for parentPid in the PCB array:
        // 1. Allocate and initialize a free PCB object from the array
        //    of PCB objects
        PCBArray[parentPid] = parentPid;

        // 2. Connect the new PCB object to its parent, its older
        //    sibling (if any), and its younger sibling (if any)
        if (size > 1) { // Parent should be the PCB Array elem with the parent's Pid ??
            parent = PCBArray[parentPid];
        }
        if (PCBArray[parentPid - 1] != NULL) {
            younger_sibling = PCBArray[parentPid - 1];
            
        }
        else {
            younger_sibling = NULL;
        }
        if (PCBArray[parentPid + 1] != NULL) {
            older_sibling = PCBArray[parentPid + 1];
        }
        else {
            older_sibling = NULL;
        }
        if (PCBArray[parentPid * 2]) {  // I don't know how to check if the PCB has a child?
            first_child = PCBArray[parentPid + 1];
        }
        else {
            first_child = NULL;
        }

        // You can decide what the return value(s), if any, should be.
        return 0; // often means "success" or "terminated normally"
    }

    /* Recursively destroys the process with ID parentPid and all of
       its descendant processes (child, grandchild, etc.).
    */
    int destroy(int targetPid) {
        // If targetPid is not in the process hierarchy, do nothing; 
        // your code may return an error code or message in this case,
        // but it should not halt
        if (targetPid < 0 || targetPid > size) {
            cout << targetPid << " is not in the process creation hierarchy" << endl;
        }
        // Assuming you've found the PCB for targetPid in the PCB array:
        // 1. Recursively destroy all descendants of targetPid, if it
        //    has any, and mark their PCBs as "free" in the PCB array 
        //    (i.e., deallocate them)
        parent = -1;
        first_child = NULL;
        older_sibling = NULL;
        younger_sibling = NULL;
        // 2. Adjust connections within the hierarchy graph as needed to
        //    re-connect the graph
        if (PCBArray[targetPid - 1] != NULL) {
            younger_sibling = PCBArray[targetPid - 1];

        }
        else {
            younger_sibling = NULL;
        }
        if (PCBArray[targetPid + 1] != NULL) {
            older_sibling = PCBArray[targetPid + 1];
        }
        else {
            older_sibling = NULL;
        }

        // 3. Deallocate targetPid's PCB and mark its PCB array entry
        //    as "free"
        PCBArray[targetPid] = NULL;

        // You can decide what the return value(s), if any, should be.
        return 0; // often means "success" or "terminated normally"
    }

    /* Traverse the process creation hierarchy graph, printing
       information about each process as you go. See Canvas for the
       *required* output format.

       You can directly use "cout" or "printf" statements to send
       the required output to stdout, or you can change the return
       type of this function to return the text to the main program
       for printing. It's your choice.
    */
    void showProcessInfo() {
        for (int i = 0; i < size; i++) {
            cout << "Process is " << PCBArray[i] << ": parent is " << parent << " and ";
            if (first_child != NULL) {
                cout << " children are " << first_child << endl;
            }
            else {
                cout << " has no children" << endl;
            }
        }
    }

    /* If you need or want more functions, feel free to add them. */

};

#endif  // VERSION2_H
