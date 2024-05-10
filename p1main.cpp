/* COMPSCI 424 Program 1
   Name: Bonnie Sullivan

   p1main.cpp: contains the main function for this program.

   This is a template. Feel free to edit any of these files, even
   these pre-written comments or my provided code. You can add any
   classes, methods, and data structures that you need to solve the
   problem and display your solution in the correct format.
*/

// You will probably need to add more #include directives.
// Remember: use <angle brackets> for standard C++ headers/libraries
// and "double quotes" for headers in the same directory as this file.
#include <iostream>
#include "version1.h" // file containing Version 1 code
#include <unordered_map>
#include <string>
#include <ctime>
#include "version2.h" // file containing Version 2 code

using namespace std; // I normally use this, but feel free to delete it

int main(int argc, char* argv[]) {
	// Main program goes here. The required steps have been copied into
	// this file as comments. Feel free to add more comments to help
	// you understand your code, or for any other reason.

	// 1. Ask the user to enter commands of the form "create N", 
	//   "destroy N", or "end", where N is an integer between 0 and 15.
	unordered_map<string, int> command;
	string inputStr = "";
	string commandWord = "";
	int N = -1;
	cout << "Valid commands include 'create N', 'destroy N', or 'end' where N is an integer btwn 0 & 15." << endl;
	cout << "Enter your command: ";
	getline(cin, inputStr);
	commandWord = inputStr.substr(0, inputStr.find(" "));
	if (commandWord.length() != inputStr.length()) {
		N = stoi(inputStr.erase(0, commandWord.length()));
	}
	if ((commandWord == "destroy" || commandWord == "create") && (N >= 0 && N <= 15)) {
		command.insert({ commandWord, N });
	}
	int numCommands = 0;	// Keep track of number of commands entered for v2, do not include "end"

	// 2. While the user has not typed "end", continue accepting
	//    commands. Add each command to a list of actions to take while
	//    you run the simulation. 
	// 3. When the user types "end" (or optionally any word that is not
	//    "create" or "destroy"), stop accepting commands and complete
	//    the following steps.
	//
	// Hint: Steps 2 and 3 refer to the same loop. ;-)
	
	while (commandWord != "end") {
		cout << "Enter another command: ";
		getline(cin, inputStr);
		commandWord = inputStr.substr(0, inputStr.find(" "));
		if (commandWord.length() != inputStr.length()) {
			N = stoi(inputStr.erase(0, commandWord.length()));
		}
		if ((commandWord == "destroy" || commandWord == "create") && (N >= 0 && N <= 15)) {
			command.insert({ commandWord, N });
		}
		numCommands = numCommands + 1;
	}

	// 4. Create an object of the Version 1 class and an object of the
	//    Version 2 class.
	Version1 version1obj;
	Version2 version2obj(numCommands);

	// 5. Run the command sequence once with the Version 1 object, 
	//    calling its showProcessTree method after each command to show
	//    the changes in the tree after each command.
	for (auto it = command.begin(); it != command.end(); it++) {
		if (it->first == "create") {
			version1obj.create(it->second);
			version1obj.showProcessInfo();
		}
		else if (it->first == "destroy") {
			version1obj.destroy(it->second);
			version1obj.showProcessInfo();
		}
	}

	// 6. Repeat step 5, but with the Version 2 object.
	for (auto it = command.begin(); it != command.end(); it++) {
		if (it->first == "create") {
			version2obj.create(it->second);
			version2obj.showProcessInfo();
		}
		else if (it->first == "destroy") {
			version2obj.destroy(it->second);
			version2obj.showProcessInfo();
		}
	}

	// 7. Store the current system time in a variable

	clock_t t;
	t = clock();

	// ... then run the command sequence 200 times with Version 1.

	// I don't think I can do this because I used kbd input instead of command line
	// I'm not sure how to process command-line inputs on a Windows 10 Machine in C++ :(

	// ... After this, store the new current system time in a second
	//     variable. Subtract the start time from the end time to get
	//     the Version 1 running time, then display the Version 1
	//     running time.

	// 8. Repeat step 7, but with the Version 2 object.

	// Don't forget to delete anything that you created with "new"!

	cout << "Builds without errors and runs to completion.\n";

	return 0; // tells the OS that the program terminated normally
}
