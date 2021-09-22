// ****************************************
// Program Title: Project 9
// Project File: Project_09.cpp
// Name: Jaiden Gann
// Course Section: CPE-211-02
// Lab Section: 2
// Due Date: 04/11/21
// program description: Arrays /w Functs. &
// structs,calculate boolean results of 2
// arrays, and print results
// ****************************************
#include <iostream>
#include <string>
#include <climits>
#include <fstream>
#include <iomanip>
using namespace std;
//typedef things
const int MAX_R = 10;
const int MAX_C = 10;
typedef int BitArray[MAX_R][MAX_C];
//structs
struct TheArrays
{
	BitArray andArray;
	BitArray orArray;
	BitArray xorArray;
	BitArray array1;
	BitArray array2;
	int cols;
	int rows;
};

//functions protoypes
void OpenInput(ifstream&);
void ReadData(TheArrays&, ifstream&);
void ORResults(TheArrays&);
void ANDResults(TheArrays&);
void XORResults(TheArrays&);
void CalculateDecimal(TheArrays&);	//calculate and print
void PrintInput(TheArrays&);
void PrintOutput(TheArrays&);
int main()
{
	ifstream InFile;
	ofstream OutFile;
	TheArrays projectArrays;

	OpenInput(InFile);
	ReadData(projectArrays, InFile);
	ORResults(projectArrays);
	ANDResults(projectArrays);
	XORResults(projectArrays);
	
	PrintInput(projectArrays);
	PrintOutput(projectArrays);
	CalculateDecimal(projectArrays);
	
 return 0;
}
//Functions
void OpenInput(ifstream& InFile)
{
	string filename;
	cout << "\nEnter the name of the input file: ";
	cin >> filename;
	cout << filename << endl << endl;

	InFile.open(filename.c_str());
	while (InFile.fail())
	{
		InFile.clear();
		InFile.close();
		cout << string(15, '*') << " File Open Error " << string(15, '*') << endl;
		cout << "==> Input file failed to open properly!!\n";
		cout << "==> Attempted to open file: " << filename << endl;
		cout << "==> Please try again...\n";
		cout << string(47, '*') << endl << endl;
		cout << "Enter the name of the input file: ";
		cin >> filename;
		cout << filename << endl << endl;
		cin.ignore(INT_MAX, '\n');
		InFile.open(filename.c_str());
	}
	return;
}
void ReadData(TheArrays& projectArrays, ifstream& InFile)
{
	int rows, cols;
	InFile >> projectArrays.rows;	//read in rows
	InFile.ignore(INT_MAX, '\n');	//skip comment
	InFile >> projectArrays.cols;	//read in columns
	InFile.ignore(INT_MAX, '\n');	//skip comment
	InFile.ignore(INT_MAX, '\n');	//skip extra line
	//should put me at first array
	//setup arrays in a while loop for eof


	for (rows = 0; rows < projectArrays.rows; rows++)
		for (cols = 0; cols < projectArrays.cols; cols++)
			InFile >> projectArrays.array1[rows][cols];
	//loop over should need to skip extra line to put me at next array
	//repeat previous process
	for (rows = 0; rows < projectArrays.rows; rows++)
		for (cols = 0; cols < projectArrays.cols; cols++)
			InFile >> projectArrays.array2[rows][cols];

	InFile.clear();
	InFile.close();	//closing because we don't need it anymore
	return;
}
void ORResults(TheArrays& projectArrays)
{
	int rows, cols;
	for (rows = 0; rows < projectArrays.rows; rows++)
	{
		for (cols = 0; cols < projectArrays.cols; cols++)
			if (projectArrays.array1[rows][cols] == 1 || projectArrays.array2[rows][cols] == 1)
			{
				projectArrays.orArray[rows][cols] = 1;
			}
			else
			{
				projectArrays.orArray[rows][cols] = 0;
			}
	}
	return;
}
void ANDResults(TheArrays& projectArrays)
{
	int rows, cols;
	for (rows = 0; rows < projectArrays.rows; rows++)
	{
		for (cols = 0; cols < projectArrays.cols; cols++)
			if (projectArrays.array1[rows][cols] == 1 && projectArrays.array2[rows][cols] == 1)
			{
				projectArrays.andArray[rows][cols] = 1;
			}
			else
			{
				projectArrays.andArray[rows][cols] = 0;
			}
	}
	return;
}
void XORResults(TheArrays& projectArrays)
{
	int rows, cols;
	for (rows = 0; rows < projectArrays.rows; rows++)
	{
		for (cols = 0; cols < projectArrays.cols; cols++)
			if ((projectArrays.array1[rows][cols] == 0 && projectArrays.array2[rows][cols] == 1) || (projectArrays.array1[rows][cols] == 1 && projectArrays.array2[rows][cols] == 0))
			{
				projectArrays.xorArray[rows][cols] = 1;
			}
			else
			{
				projectArrays.xorArray[rows][cols] = 0;
			}
	}
	return;
}
void PrintInput(TheArrays& projectArrays)
{
	int rows, cols;
	cout << "Initial values of the arrays processed" << endl;
	cout << string(38, '-') << endl;
	cout << setw(2 * projectArrays.cols) << left << "Array 1" << "    " << setw(2 * projectArrays.cols) << "Array 2" << endl;
	cout << setw(2 * projectArrays.cols) << "-------" << "    " << setw(2 * projectArrays.cols) << "-------" << endl;
	for (rows = 0; rows < projectArrays.rows; rows++)
	{
		for (cols = 0; cols < projectArrays.cols; cols++)
		{
			cout << projectArrays.array1[rows][cols] << " ";
		}
		cout << "    ";
		for (cols = 0; cols < projectArrays.cols; cols++)
		{
			cout << projectArrays.array2[rows][cols] << " ";	
		}
		cout << endl;
	}
}
void PrintOutput(TheArrays& projectArrays)
{
	int rows, cols;
	cout << "\nOR, AND and XOR results\n";
	cout << string(23, '-') << endl;
	cout << left << setw(2 * projectArrays.cols) << "OR";
	cout << "    " << setw(2 * projectArrays.cols) << "AND" << "    ";
	cout << setw(2 * projectArrays.cols) << "XOR" << endl;
	cout << setw(2 * projectArrays.cols) << "--" << "    " << setw(2 * projectArrays.cols) << "---";
	cout << "    " << setw(2 * projectArrays.cols) << "---" << endl;
	for (rows = 0; rows < projectArrays.rows; rows++)
	{
		for (cols = 0; cols < projectArrays.cols; cols++)
		{
			cout << projectArrays.orArray[rows][cols] << " ";
		}
		cout << "    ";
		for (cols = 0; cols < projectArrays.cols; cols++)
		{
			cout << projectArrays.andArray[rows][cols] << " ";
		}
		cout << "    ";
		for (cols = 0; cols < projectArrays.cols; cols++)
		{
			cout << projectArrays.xorArray[rows][cols] << " ";
		}
		cout << endl;
	}
	return;
}
void CalculateDecimal(TheArrays& projectArrays)
{
	int base = 1;
	int orResult, andResult, xorResult;
	orResult = 0;
	andResult = 0;
	xorResult = 0;
	int rows, cols;
	cout << "\n\nInteger Equivalents for the rows\n";
	cout << "of the OR, AND and XOR arrays\n";
	cout << string(32, '-') << endl;
	cout << left << setw(8) << "OR" << setw(8) << "AND" << setw(8) << "XOR" << endl;
	cout << setw(8) << "--" << setw(8) << "---" << setw(8) << "---" << endl;
	for (rows = 0; rows < projectArrays.rows; rows++)
	{
		
		for (cols = projectArrays.cols - 1; cols >= 0; cols--)
		{
			//cout << projectArrays.orArray[rows][cols] << endl; debug statement
			orResult += (base) * (projectArrays.orArray[rows][cols]);
			andResult += (base) * (projectArrays.andArray[rows][cols]);
			xorResult += (base) * (projectArrays.xorArray[rows][cols]);
			base *= 2;
			
		}
	cout << left << setw(8) << orResult << setw(8) << andResult << setw(8) << xorResult << endl;
	orResult = 0;
	andResult = 0;
	xorResult = 0;
	base = 1;
	}
	
	return;
}