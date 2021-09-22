// ****************************************
// Program Title: Project 7
// Project File: Project_07.cpp
// Name: Jaiden Gann
// Course Section: CPE-211-02
// Lab Section: 2
// Due Date: 03/16/21
// program description: Practice using user
// created functions for decom/comp on files
// ****************************************
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <climits>
using namespace std;
void PrintMenu();
bool InputReturn(int&); //read and determine input
bool OpenInput(ifstream&);	//open the input file
void OpenOutput(ofstream&);	//open the output file
void Compression(ifstream&, ofstream&);
void Decompression(ifstream&, ofstream&);
int main()
{
	int menuChoice;
	bool endLoop;
	ifstream InFile;
	ofstream OutFile;

	endLoop = false;
	while (!endLoop) //loop so long as not at end
	{
		PrintMenu();

		while (!InputReturn(menuChoice)) //loops until valid choice given 
		{
			PrintMenu(); //re-outputs menu
		}
		if (menuChoice == 1)	//run compression
		{
			if(OpenInput(InFile) == true)	//opened successfully->open output and run compression
			{
				OpenOutput(OutFile);
				Compression(InFile, OutFile);
			}
			//else(i.e opens bad) will reprint menu
		}
		if (menuChoice == 2) // run decompression
		{
			if (OpenInput(InFile) == true) //same logic as option 1
			{
				OpenOutput(OutFile);
				Decompression(InFile, OutFile);
			}
		}
		if (menuChoice == 0)
		{
			cout << "Quit selected.  Terminating program now...\n\n";
			endLoop = true;
		}
	}
 return 0;
}
void PrintMenu()
{
	cout << endl << string(10, '*') << "  Compression Menu  " << string(10, '*') << endl;
	cout << "0. Exit Program" << endl;
	cout << "1. Compress File" << endl;
	cout << "2. Uncompress File" << endl;
	cout << string(40, '*') << endl;
	cout << "\nInput your selection now: ";
	return;
}
bool InputReturn(int& menuChoice)
{
	bool validChoice;	//flag value
	char invalidChoice; //reads invalid character

	validChoice = false;
	cin >> menuChoice;
	if (cin.fail()) //if integer value wasn't entered
	{
		cin.clear();	//clears input stream
		cin >> invalidChoice;
		cout << invalidChoice << endl << endl;
		cout << string(14, '*') << " Invalid Selection " << string(14, '*') << endl;
		cout << "==> Invalid character entered!!\n";
		cout << "==> Please enter 0, 1 or 2\n";
		cout << string(47, '*') << endl;

	}
	else if (menuChoice == 0 || menuChoice == 1 || menuChoice == 2)
	{
		validChoice = true; //changes flag so you exit loop
		cout << menuChoice << endl << endl;
	}
	else	//integer was entered but not a valid one
	{
		cout << menuChoice << endl << endl;
		cout << string(14, '*') << " Invalid Selection " << string(14, '*') << endl;
		cout << "==> Invalid integer value entered\n";
		cout << "==> Please enter 0, 1 or 2\n";
		cout << string(47, '*') << endl;
	}
	cin.ignore(INT_MAX, '\n');
	return validChoice;
}
bool OpenInput(ifstream& InFile)
{
	bool success;	//flag for the function
	string fileName;
	cout << "Enter the name of the input file: ";
	cin >> fileName;
	cout << fileName << endl << endl;
	InFile.open(fileName.c_str());
	if (InFile.fail())
	{
		cin.clear();	//clears input stream
		InFile.clear();	//clear fail flag
		
		cout << string(15, '*') << " File Open Error " << string(15, '*') << endl;
		cout << "==> Input file failed to open properly!!\n";
		cout << "==> Attempted to open file: " << fileName << endl;
		cout << "==> Selected operation has been canceled\n";
		cout << string(47, '*') << endl;
		success = false;
	}
	else
	{
		success = true;
	}
	cin.ignore(INT_MAX, '\n');	//ignore any extra stuff in input stream
	return success;
}
void OpenOutput(ofstream& Output)
{
	string outName;
	cout << "Enter the name of the output file: ";
	cin >> outName;
	cout << outName << endl << endl;
	Output.open(outName.c_str());

	if (Output.fail())	// clear flags and stream for next use
	{
		cin.clear();
		Output.clear();
	}
	return;
}
void Compression(ifstream& InFile, ofstream& OutFile)
{
	int counter;
	char letter;
	char prevChar;
	char nextChar;

	InFile.get(nextChar);	//priming read
	if (InFile.eof())
	{
		cout << string(15, '*') << " Empty Input File " << string(14, '*') << endl;
		cout << "==> Empty file for Compression\n";
		cout << "==> Nothing written to the output file\n";
		cout << string(47, '*') << endl;
	}
	else
	{
		while (!InFile.eof()) //while end of file is not reached
		{
			counter = 1;	//counter intialization
			prevChar = nextChar;	//set next char as the prev char, aka first char on first pass

			InFile.get(nextChar);	//grab next char
			while (nextChar == prevChar && InFile.good()) //if the characters equal and stream is good
			{
				//up the counter, the current character becomes previous, read in new character
				counter++;
				InFile.get(nextChar);
			}
			OutFile << counter << prevChar;

		}
		cout << "==> File has been Compressed" << endl;
	}
	InFile.close();	//close connection so next run opens properly
	InFile.clear(); //re-clear flag for good measure
	OutFile.close();
	OutFile.clear();
	return;
}
void Decompression(ifstream& InFile, ofstream& OutFile)
{
	int num;
	char letter;
	InFile >> num;	//priming read
	if (InFile.fail())	//if fail state after priming read, method to handle empty file
	{
		cout << string(15, '*') << " Empty Input File " << string(14, '*') << endl;
		cout << "==> Empty file for Decompression\n";
		cout << "==> Nothing written to the output file\n";
		cout << string(47, '*') << endl;
	}
	else
	{
		while (!InFile.eof())
		{
			InFile.get(letter);
			OutFile << string(num, letter);
			InFile >> num;	//read next number and overwrite first read
		}
	cout << "==> File has been Decompressed" << endl;
	}
	
	InFile.close();	//close connection so next run opens properly
	InFile.clear(); //re-clear flag for good measure
	OutFile.close();
	OutFile.clear(); //doesn't hurt to have
	return;
}