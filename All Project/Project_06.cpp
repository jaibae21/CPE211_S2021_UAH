// ****************************************
// Program Title: Project 6
// Project File: Project_06.cpp
// Name: Jaiden Gann
// Course Section: CPE-211-02
// Lab Section: 2
// Due Date: 03/02/21
// program description: Exercise using while
// and if statements along with I/O operations
// to do a series of math operations on grades
// ****************************************
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <climits>
#include <cmath>
using namespace std;
int main(int argc, char *argv[])
{
	//Test for Number of Command Line Arguments//
	if (argc != 3)
	{
		cout << endl;
		cout << string(9, '*') << " Command Line Argument Error " << string(9, '*') << endl;
		cout << "==> Incorrect number of Command Line Arguments!\n";
		cout << "==> Command for running the program is:\n";
		cout << "==> ./Project_06 inputFileName outputFileName\n";
		cout << string(47, '*') << endl << endl;
		return 1;	//terminate program
	}
	//Variabel Setup//
	string inFileName = argv[1];
	string outFileName = argv[2];
	ifstream inFile;
	ofstream outFile;
	const float N = 4.00;
	int num1, num2, num3, num4;
	float variance, stdDeviation, sum, average;
	string infoLine;
	char letterGrade;
	//Variables for Variance
	float part1, part2, part3, part4, allPartMult;
	//Open input and output//
	inFile.open(inFileName.c_str());
	outFile.open(outFileName.c_str());

	cout << endl << "Opening input file: " << inFileName << endl << endl;
	//Test of File Stream Pass 1//

	while (inFile.fail())	//input file
	{
		inFile.clear();
		cout << string(15, '*') << " File Open Error " << string(15, '*') << endl;
		cout << "==> Input file failed to open properly!!\n";
		cout << "==> Attempted to open file: " << inFileName << endl;
		cout << "==> Try Again\n";
		cout << string(47, '*') << endl << endl;
		cout << "Enter in the name of the input file: ";
		cin >> inFileName;
		cout << inFileName << endl << endl;
		cin.ignore(INT_MAX, '\n');
		inFile.open(inFileName.c_str());
	}
	cout << "Opening output file: " << outFileName << endl << endl;
 
	while (outFile.fail())	//output file
	{
		outFile.clear();
		cout << string(15, '*') << " File Open Error " << string(15, '*') << endl;
		cout << "==> Output file failed to open properly!!\n";
		cout << "==> Attempted to open file: " << outFileName << endl;
		cout << "==> Try Again\n";
		cout << string(47, '*') << endl << endl;
		cout << "Enter in the name of the output file: ";
		cin >> outFileName;
		cout << outFileName << endl << endl;
		cin.ignore(INT_MAX, '\n');
		outFile.open(outFileName.c_str());
	}
	//Start: Ignoring 1st and Reading 2nd line// 
	inFile.ignore(INT_MAX, '\n');
	inFile >> num1;
	inFile >> num2;
	inFile >> num3;
	inFile >> num4;
	//Re-Test of File Stream
	if (inFile.fail())
	{
		cout << string(15, '*') << " File Read Error " << string(15, '*') << endl;
		cout << "==> Reading of the 4 test scores failed.\n";
		cout << "==> The input stream is in the fail state mode.\n";
		cout << "==> There is an error in the input file.\n";
		cout << "==> Program Terminated.\n";
		cout << string(47, '*') << endl;
		//Output File
		outFile << string(15, '*') << " File Read Error " << string(15, '*') << endl;
		outFile << "==> Reading of the 4 test scores failed.\n";
		outFile << "==> The input stream is in the fail state mode.\n";
		outFile << "==> There is an error in the input file.\n";
		outFile << "==> Program Terminated.\n";
		outFile << string(47, '*') << endl;
		return 1;	//terminates program
	}
	//Negative Test
	if (num1 < 0 || num2 < 0 || num3 < 0 || num4 < 0)
	{
		cout << string(15, '*') << " File Read Error " << string(15, '*') << endl;
		cout << left << noshowpoint;
		cout << "==> Test scores read are: " << setw(6) << num1 << setw(6) << num2 << setw(6) << num3 << setw(6) << num4 << endl;
		cout << "==> One or more of the scores is negative!\n";
		cout << "==> Program Terminated.\n";
		cout << string(47, '*') << endl;
		//Output File
		outFile << string(15, '*') << " File Read Error " << string(15, '*') << endl;
		outFile << left << noshowpoint;
		outFile << "==> Test scores read are: " << setw(6) << num1 << setw(6) << num2 << setw(6) << num3 << setw(6) << num4 << endl;
		outFile << "==> One or more of the scores is negative!\n";
		outFile << "==> Program Terminated.\n";
		outFile << string(47, '*') << endl;
		return 1;
	}
	//Math
	sum = num1 + num2 + num3 + num4;
	average = sum / N;
	part1 = pow((num1 - average), 2);
	part2 = pow((num2 - average), 2);
	part3 = pow((num3 - average), 2);
	part4 = pow((num4 - average), 2);
	allPartMult = part1 + part2 + part3 + part4;
	variance = allPartMult / N;
	stdDeviation = sqrt(variance);
	//Assign Letter Grade
	if (average >= 90)
	{
		letterGrade = 'A';
	}
	else if (average < 90 && average >= 80)
	{
		letterGrade = 'B';
	}
	else if (average < 80 && average >= 70)
	{
		letterGrade = 'C';
	}
	else if (average < 70 && average >= 60)
	{
		letterGrade = 'D';
	}
	else
	{
		letterGrade = 'F';
	}
	//Read last line & Re-Test File Stream
	getline(inFile, infoLine, ':');
	if (inFile.eof())
	{
		cout << string(15, '*') << " File Read Error " << string(15, '*') << endl;
		cout << "==> Reading of the information line failed.\n";
		cout << "==> Input stream is in the fail state mode.\n";
		cout << "==> There is an error in the input file.\n";
		cout << "==> Program Terminated.\n";
		cout << string(47, '*') << endl;
		//Output
		outFile << string(15, '*') << " File Read Error " << string(15, '*') << endl;
		outFile << "==> Reading of the information line failed.\n";
		outFile << "==> Input stream is in the fail state mode.\n";
		outFile << "==> There is an error in the input file.\n";
		outFile << "==> Program Terminated.\n";
		outFile << string(47, '*') << endl;
		return 1;
	}
	infoLine = infoLine + ":";
	//Output//
	outFile << string(17, '*') << "   Statistics   " << string(17, '*');
	outFile << left << fixed;
	outFile << setw(33) << noshowpoint << infoLine << setw(6) << num1 << setw(6) << num2 << setw(6) << num3 << setw(6) << num4 << endl;
	outFile << setw(32) << showpoint << setprecision(2) << "The sum of the scores is:" << sum << endl;
	outFile << setw(32) << "The average of the scores is:" << average << endl;
	outFile << setw(32) << "Letter grade equivalent:" << letterGrade << endl;
	outFile << setw(32) << "The variance of the scores is:" << variance << endl;
	outFile << setw(32) << "The standard deviation is:" << stdDeviation << endl;
	outFile << string(50, '*') << endl;
 
 inFile.close();
 outFile.close();
 return 0;
}