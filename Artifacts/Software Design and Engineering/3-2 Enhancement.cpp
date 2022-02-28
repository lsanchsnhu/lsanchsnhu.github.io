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
			cout << "- Add -" << endl;
			cout << "- Enter 2 digits to be added -" << endl;
			cin >> first >> second;
			cout << first << " + " << second << " = " << first + second << endl;
			break;
		case 2:
			cout << "- Subtract -" << endl;
			cout << "- Enter 2 digits to be subtracted -" << endl;
			cin >> first >> second;
			cout << first << " - " << second << " = " << first - second << endl;
			break;
		case 3:
			cout << "- Multiply -" << endl;
			cout << "- Enter 2 digits to be multiplied -" << endl;
			cin >> first >> second;
			cout << first << " * " << second << " = " << first * second << endl;
			break;
		case 4:
			i = 0;
			break;
		default:
			cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
			break;
		}
	}
}