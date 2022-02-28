#include <iostream>
using namespace std;

int main() {
	int choice, i = 1;
	int first, second;

	while (i > 0) {
		cout << "----------------" << endl;
		cout << "- 1)Add -" << endl;
		cout << "- 2)Subtract -" << endl;
		cout << "- 3)Multiply -" << endl;
		cout << "- 4)Exit -" << endl;
		cout << "----------------" << endl;
		cin >> choice;

		switch (choice) {
		case 1: 
			cin >> first >> second;
			// Vulnerability #1: This line subtracts the value even though this option is for addition. This will be fixed
			// by changing the operator from '-' to '+'

			// Vulnerability #2: This line also outputs the - sign even thhough the option is for addition.This will be fixed
			// by changing the output from '-' to '+'
			cout << first << " + " << second << " = " << first + second << endl;
			break;
		case 2:
			cin >> first >> second;
			// Vulnerability #3: This line adds the value even though this option is for subtraction. This will be fixed
			// by changing the operator from '+' to '-'
			cout << first << " - " << second << " = " << first - second << endl;
			break;
		case 3:
			cin >> first >> second;
			// Vulnerability #4: This line divides the value even though this option is for multiplication. This will be fixed
			// by changing the operator from '/' to '*'

			// Vulnerability #2: This line also outputs the - sign even thhough the option is for multiplication.This will be fixed
			// by changing the output from '-' to '*'
			cout << first << " * " << second << " = " << first * second << endl;
			break;
		// Vulnerability #6: This line is used to exit the program even though the option text says that 4 is supposed to be
		// the option for exiting the program. This will  be fixed  by changing the case from 5 to 4
		case 4:
			i = 0;
			break;
		default:
			// Vulnerability  #5: This line is used to handle any other integers other than 1-4, but it doesn't actually tell the
			// user what is happening. This will be fixed by outputting an error message telling the user the proper options.
			cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
			break;
		}
	}
}