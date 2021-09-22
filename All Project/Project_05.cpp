// ****************************************
// Program Title: Project 5
// Project File: Project_05.cpp
// Name: Jaiden Gann
// Course Section: CPE-211-02
// Lab Section: 2
// Due Date: 02/221/21
// program description: Test opening of input
// and output file. Read from file letters and
// numbers. Practice Usage of if statements
// ****************************************
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <climits>
using namespace std;
int main(int argc, char *argv[])
{
	//Test for Correct Number of Command Line Arguments//
	if(argc != 3)
	{
		cout << endl;
		cout << string(9, '*') << " Command Line Argument Error " << string(9, '*') << endl;
		cout << "==> Incorrect number of Command Line Arguments!\n";
		cout << "==> Command for running the program is:\n";
		cout << "==> ./Project_05 inputFileName  outputFileName\n";
		cout << string(47, '*') << endl << endl;
		return 1;	//terminate program
	}

	//Variable Setup//
	float after_A, after_B, after_C;
	float sum, average;
	string avg_score;
	string inFileName = argv[1];	//input name to first command argument
	string outFileName = argv[2];	//output name to second command argument
	ifstream inFile;
	ofstream outFile;
	//Setup for opening input and output file//
	inFile.open(inFileName.c_str());

	cout << endl << "Opening Input File: " << inFileName << endl << endl;

	//Test State of File Stream
	if(inFile.fail())
	{
		cout << string(15, '*') << " File Open Error " << string(15, '*') << endl;
		cout << "==> Input file failed to open properly!!\n";
		cout << "==> Attempted to open file: " << inFileName << endl;
		cout << "==> Terminating program!!!\n";
		cout << string(47, '*') << endl << endl;
		return 1;	//terminates program
	}
	
	outFile.open(outFileName.c_str());
	cout << "Opening Output File: " << outFileName << endl << endl;
	
	if(outFile.fail())
	{
		cout << string(15, '*') << " File Open Error " << string(15, '*') << endl;
		cout << "==> Output file failed to open properly!!\n";
		cout << "==> Attempted to open file: " << outFileName << endl;
		cout << "==> Terminating program!!!\n";
		cout << string(47, '*') << endl << endl;
		return 1;	//terminates program
	}
	//Finding numbers 
	inFile.ignore(INT_MAX, 'A');
	inFile >> after_A;
	inFile.ignore(INT_MAX, 'B');
	inFile >> after_B;
	inFile.ignore(INT_MAX, 'C');
	inFile >> after_C;

	//Negative Number Test//
	if (after_A < 0 || after_B < 0 || after_C < 0)
	{
		cout << string(15, '*') << " Negative Number " << string(15, '*') << endl;
		if (after_A < 0)
		{
			cout << "==> First number is less than 0" << endl;
		}
		if (after_B < 0)
		{
			cout << "==> Second number is less than 0" << endl;
		}
		if (after_C < 0)
		{
			cout << "==> Third number is less than 0" << endl;
		}
		cout << "==> All numbers should be positive" << endl;
		cout << "==> Terminating program!!!" << endl;
		cout << string(47, '*');
		cout << endl << endl;
		return 1;
	}
	else
	{
		sum = (after_A + after_B + after_C);
		average = sum / 3.0;
	}
 
	//Testing Average//
	if (average >= 75)	//100 to 75
	{
		avg_score = "High";
	}
  if (average < 75 && average >= 25)	//75 to 25
	{
		avg_score = "Medium";
	}
	if (average < 25)  //25 to 0
	{
		avg_score = "Low";
	}
	
	//Ouput File Stuff//
	outFile << setprecision(2) << fixed;
	outFile << string(47, '*') << endl;
	outFile << left << setw(35) << "The numbers read are:" << after_A << ' ' << after_B << ' ' << after_C << endl;
	outFile << setw(35) << "The sum of the numbers is:" <<  sum << endl;  //setw(14) except for Low
	outFile << setw(35) << "The average of these numbers is:" << average << endl;
	outFile << setw(35) << "This average is:" << avg_score << endl;  //setw(24) on the right for High
	outFile << string(47, '*') << endl;
  

	//Closing Input and Output File
	inFile.close();
	outFile.close();
}