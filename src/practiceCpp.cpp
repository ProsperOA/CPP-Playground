/**
 * This program utilizes concepts from OOP C++ such as
 * basic input/output, switch statements, string functions,
 * exception handling, recursion, dynamic memory allocation
 * with pointers and also memory deallocation, and templates.
 *
 * @author:      Obosa Osagie-Amayo
 * Source File:	 practiceCpp.cpp
 */

#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

//Function contains multiple string manipulation functions.
void stringFunctions() {
	string str, temp;

	cout << "Enter a string." << endl;
	cin >> str;
	cout << endl;

	cout << "String length: " << str.length() << endl;

	reverse(str.begin(), str.end());
	cout << "String reversed: " << str << endl;
	reverse(str.begin(), str.end());

	cout << "Last character in string: " << str[str.length() - 1] << endl;

	for (unsigned int i = 0; i < str.length(); i++) {
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o'
				|| str[i] == 'u')
			temp = str.erase(i, 1);
	}
	cout << "String without vowels: " << temp << endl;
}

//Exception handling: try, throw, catch.
void exceptions() {
	int num;

	try {
		cout << "How many letters are in the alphabet?" << endl;
		cin >> num;
		cout << endl;

		if (num == 26)
			cout << "Correct! That catchy song worked!" << endl;

		if (num != 26)
			throw num;
	} catch (int num) {
		cout << "There are 26 numbers in the alphabet, not " << num << "."
				<< endl;
	}
}

//Recursive function that calls itself if user's answer is incorrect.
void recursion(int a, int b, int c) {
	int temp = a, newNum, newAns, newCount = 0;

	for (int i = a; i >= 0; i--) {
		a /= 2;
		c++;
		if (a == 0) {
			cout << temp << " was divided " << c << " times before it "
					<< "equaled 0." << endl;

			if (b != c) {
				cout << "Your answer was incorrect!\nTry again." << endl;
				cout << endl;
				cout << "New Number: ";
				cin >> newNum;
				cout << "New Answer: ";
				cin >> newAns;
				cout << endl;
				recursion(newNum, newAns, newCount);
			}
			if (b == c) {
				cout << "Your answer was correct!" << endl;
			}
			exit(EXIT_SUCCESS);
		}
	}
}

//Fills 2D array with user inputed integers.
void fillArrayBoard(int **boardSize, int rowSize, int colSize) {
	for (int r = 0; r < rowSize; r++) {
		cout << "Enter " << colSize << " numbers for row number " << r << ": ";
		cout << endl;

		for (int c = 0; c < colSize; c++) {
			cin >> boardSize[r][c];
			cout << endl;
		}
	}
	cout << "Your Dynamically Allocated\n2D Array:\n";
	cout << endl;
	for (int r = 0; r < rowSize; r++) {
		for (int c = 0; c < colSize; c++)
			cout << setw(5) << boardSize[c][r];
		cout << endl << endl;
	}
	delete[] boardSize;
	cout << "Deallocating arrayBoard..." << endl;
}

//Dynamically allocated memory for array.
//Size is based upon user input.
void arrayBoard(int rowSize, int colSize) {
	int **array;
	array = new int*[rowSize];

	for (int i = 0; i < rowSize; i++)
		array[i] = new int[colSize];

	fillArrayBoard(array, rowSize, colSize);
}

//Basic template to return the "greater" of two
//types inputed by the user.
template<class Type>
Type overloadOperator(Type a, Type b) {
	if (a > b)
		return a;
	else
		return b;
}

//Main contains switch statement which prompts user for an integer.
//Each topic is chosen based on the number the user enters.
int main() {
	int randNum;
	int count = 0;
	string word1, word2;

	cout << "Enter a number from 1 to 5" << endl;
	cin >> randNum;
	cout << endl;

	switch (randNum) {
	case 1:
		cout << "You chose exception handling!" << endl << endl;
		exceptions();
		break;
	case 2:
		cout << "You chose recusion!" << endl << endl;
		int twoMultiple, answer;

		cout << "Task:\n -Enter a multiple of two and guess how many times that "
				<< "number must by divided by 2 to equal 0. If you get "
				<< "the answer wrong, you must try again." << endl;

		cout << "Enter a multiple of 2: ";
		cin >> twoMultiple;
		cout << endl;
		cout << "How many times do you think " << twoMultiple << " will be "
				<< "divided by 2 until it equals 0?" << endl;
		cin >> answer;
		cout << endl;

		recursion(twoMultiple, answer, count);
		break;
	case 3:
		cout << "You chose string functions!" << endl << endl;
		stringFunctions();
		break;
	case 4:
		cout << "You chose dynamic allocation of 2D array!" << endl << endl;
		int rows, col;

		cout << "Enter a number of rows and columns:" << endl;
		cin >> rows >> col;
		cout << endl;

		arrayBoard(rows, col);
		break;
	case 5:
		cout << "You chose templates!" << endl << endl;
		char ch1, ch2;

		cout << "Enter two characters." << endl;
		cin >> ch1 >> ch2;
		cout << endl;
		cout << overloadOperator(ch1, ch2) << " is larger!\n" << endl;

		cout << "Enter two strings." << endl;
		cin >> word1 >> word2;
		cout << endl;
		cout << overloadOperator(word1, word2) << " is larger!" << endl;
		break;
	default:
		cout << "OUT OF RANGE!" << endl;
		break;
	}
	system("pause");
	return 0;
}
