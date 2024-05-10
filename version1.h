#pragma once
/* COMPSCI 424 Program 1
   Name: Bonnie Sullivan

   version1.h: contains the code to implement the process creation
   hierarchy for Version 1, which uses linked lists.

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

#ifndef VERSION1_H
#define VERSION1_H

// You may need to add more #include directives.
// Remember: use <angle brackets> for standard C++ headers/libraries
// and "double quotes" for headers in the same directory as this file.
#include <iostream>
#include <forward_list>
#include <string>

using namespace std; // I normally use this, but feel free to delete it

class PCBArray {    // Create PCBArray class
public:
    int value;
    PCBArray* next;

    PCBArray(int val) {
        value = val;
        next = NULL;
    }
};

class Version1 {
private: // it's good OOP practice to make data members private
    PCBArray* head, * tail;
    int size;
    forward_list<int> forwardList;

public:  // all methods are normally public
    Version1() {
        /* Default constructor. Use this to allocate (if needed) and
        initialize the PCB array, create the PCB for process 0, and do
        any other initialization that is needed.
        */
    }

    Version1(int val) {
        head = tail = NULL;    
        size = 0;
    }

    ~Version1() {
        /* Destructor. If you allocated anything with "new" during
        the lifetime of this object, and you haven't yet "delete"d
        it, "delete" it (using the "delete" keyword) here.
        */
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
        // 2. Insert the newly allocated PCB object into parentPid's
        //    list of children
        
        PCBArray* temp = new PCBArray(parentPid);   // Allocate a free PCB & record the parent's index in it

        // Initialize the children of the newly created PCB as empty
        temp->next = NULL;

        // Add the new PCB to the list of processes
        if (size == 0) { // If this is the first process added to the list
            head = tail = temp; 
        }
        else {  // If this is not the first process added to the list
            tail->next = temp;
            tail = temp;
        }
        size++;

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
        // 2. Remove targetPid from its parent's list of children
        // 3. Deallocate targetPid's PCB and mark its PCB array entry
        //    as "free"

        PCBArray* currentProcess = head;
        while (currentProcess != tail) {
            if (currentProcess->value == targetPid) {
                size--;
                head = head->next;
                if (currentProcess->next != NULL) {
                    delete currentProcess->next;
                }
                delete currentProcess;
            }
            else if (currentProcess->next != NULL) {
                currentProcess = currentProcess->next;
            }
            else {
                currentProcess = tail;
            }
        }
        if (currentProcess == tail && currentProcess->value != targetPid) {
            cout << targetPid << " is not in the process hierarchy" << endl;
            exit;
        }
        else {
            delete currentProcess;
        }

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
            PCBArray* currentProcess = head;
            PCBArray* parentProcess = head;
            string parent = "-1";    // First PCB is process -1
            string children = "has no children";
            while (currentProcess != NULL) {
                // Find the parent process of the current process
                if (parentProcess->next == currentProcess) {
                    parent = parentProcess->value;
                }
                else {
                    parentProcess = parentProcess->next;
                }
                // Find the children of the current process (if there are any)
                while (currentProcess->next != NULL) {
                    children = "children are ";
                    string tmpStr = to_string(currentProcess->next->value);
                    children.append(tmpStr);
                }
                cout << "Process is " << currentProcess->value << ": parent is " << parent << " and " << children << endl;
                currentProcess = currentProcess->next;
        }
    }

    /* If you need or want more functions, feel free to add them. */

};

#endif  // VERSION1_H
