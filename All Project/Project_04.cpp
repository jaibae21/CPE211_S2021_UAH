// ****************************************
// Program Title: Project 4
// Project File: Project_04.cpp
// Name: Jaiden Gann
// Course Section: CPE-211-02
// Lab Section: 2
// Due Date: 02/12/21
// program description: Generate a password
//  
// ****************************************
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	cout << setprecision(3);
	//Variable setup
	float average_wordL, length1, length2, length3, name_length;
	float total_length;
	string name, word1, word2, word3;
	string first_initial, last_initial;
	string firstL_word1, lastL_word1;
	string firstL_word2, lastL_word2;
	string firstL_word3, lastL_word3;
	int position;
	//Header Setup 
	cout << right;
	cout << endl << string(60, '*') << endl;
	cout << setw(40) << "Password Generator" << endl;
	cout << string(60, '*') << endl;
	
	//Inputs and Echos 
	cout << "Enter user's first and last names separated by a space: ";
	getline(cin, name);
	cout << endl << "name = " << name << endl << endl;

	cout << "Enter the first word: ";
	cin >> word1;
	cout << endl << "first word = " << word1 << endl << endl;

	cout << "Enter the second word: ";
	cin >> word2;
	cout << endl << "second word = " << word2 << endl << endl;

	cout << "Enter the third word: ";
	cin >> word3;
	cout << endl << "third word = " << word3 << endl << endl;

	//Gathering Needed Info//
	//Lengths
	length1 = word1.length();
	length2 = word2.length();
	length3 = word3.length();
	name_length = name.length();
	//Name
	first_initial = name.substr(0, 1);
	position = name.find(' ');
	last_initial = name.substr(position+1, 1);
	//Words
	firstL_word1 = word1.substr(0, 1);
	lastL_word1 = word1.substr(length1-1, 1);

	firstL_word2 = word2.substr(0, 1);
	lastL_word2 = word2.substr(length2-1,1);

	firstL_word3 = word3.substr(0, 1);
	lastL_word3 = word3.substr(length3-1,1);
	//Word Length
	average_wordL = (length1 + length2 + length3)/ 3.00;
	//Output Section Start//
	//Top of table
	cout << string(60, '*') << endl;
	cout << left << setw(8) << "Word#" << setw(10) << "Length" << setw(20) << "Word" << endl;
	cout << setw(8) << string(5, '-') << setw(10) << string(6, '-') << setw(20) << string(4, '-') << endl;
	//Inside the table
	cout << setw(8) << "1" << setw(10) << length1 << setw(20) << word1 << endl;
	cout << setw(8) << "2" << setw(10) << length2 << setw(20) << word2 << endl;
	cout << setw(8) << "3" << setw(10) << length3 << setw(20) << word3 << endl;
	//Bottomg of table
	cout << setw(8) << string(5, '-') << setw(10) << string(6, '-') << setw(20) << string(4, '-') << endl << endl;
	//Average word length and password
	cout << showpoint << "Average word length = " << average_wordL << endl << endl;
	cout << noshowpoint;
	cout << "password = ";
	cout << first_initial << last_initial << name_length;
	cout << firstL_word1 << lastL_word1 << length1;
	cout << firstL_word2 << lastL_word2 << length2;
	cout << firstL_word3 << lastL_word3 << length3;
	cout << endl;
	cout << string(60, '*') << endl << endl;
}