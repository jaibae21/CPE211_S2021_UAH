// ****************************************
// Program Title: Project_08
// Project File: Project_08.cpp
// Name: Jaiden Gann
// Course Section: CPE-211-02
// Lab Section: 2
// Due Date: 03/28/21
// program description: Read records of 
// subscribers for a magazine. Practice with
// structs and more functions
// ****************************************
#include <iostream>
#include <string>
#include <climits>
#include <fstream>
#include <iomanip>
using namespace std;
//structures
struct SubscriberName
{
	string firstName;
	string lastName;
	int customerID;
};
struct Address
{
	string street;
	string city;
	string state;
	int zip_code;
};
struct Date
{
	string month;
	int day;
	int year;
};
struct RenewalInfo
{
	int monthLeft;
	Date renewal_notice;
};
struct MagazineService
{
	SubscriberName subscriber_name;
	Address address;
	RenewalInfo renewal_info;
};
//function prototypes
void OpenInput(ifstream&);
void OpenOutput(ofstream&);
void ReadRecord(MagazineService&, ifstream&);	//assign things structs
bool CheckEmpty(MagazineService&, ifstream&);	//check for the empty file
void WriteInfo(MagazineService&, ofstream&);	//write to output file
int main()
{
	MagazineService customer;
	int numberSubscribers, expireSubscriptions;	//counters
	numberSubscribers = 0;
	expireSubscriptions = 0;
	ifstream InFile;
	ofstream OutFile;


	OpenInput(InFile);	//open input file
	OpenOutput(OutFile);	//open output file

	if (CheckEmpty(customer, InFile) == true)	//test to see if file is empty at start
	{
		cout << "===> Input file is empty.  Program terminated\n\n";
		OutFile << string(52, '-') << endl;
		OutFile << "==> The input file does not contain any information.\n";
		OutFile << string(52, '-') << endl;
		OutFile.close();
		return 1;
	}
	else
	{
		while (!InFile.eof())
		{
			cout << "====> Processing Customer ID: " << customer.subscriber_name.customerID << endl;
			if (customer.renewal_info.monthLeft == 0)
			{

				numberSubscribers++;
				expireSubscriptions++;
				WriteInfo(customer, OutFile);
				ReadRecord(customer, InFile);
			}
			else
			{
				numberSubscribers++;
				ReadRecord(customer, InFile);
			}
		}
		cout << endl << string(47, '-') << endl;
		cout << "Number of subscribers processed: " << numberSubscribers << endl;
		cout << "The number of expired subscriptions is: " << expireSubscriptions << endl;
		cout << string(47, '-') << endl << endl;
	}


	InFile.close();
	OutFile.close();
	InFile.clear();
	return 0;
}
//functions
void OpenInput(ifstream& InFile)
{
	string filename;
	cout << endl << "Enter name of input file or Control-C to quit program: ";
	cin >> filename;
	cout << filename << endl << endl;

	InFile.open(filename.c_str());
	while (InFile.fail())
	{
		InFile.clear();
		cout << string(15, '*') << " File Open Error " << string(15, '*') << endl;
		cout << "==> Input file failed to open properly!!\n";
		cout << "==> Attempted to open file: " << filename << endl;
		cout << "==> Please try again...\n";
		cout << string(47, '*') << endl << endl;
		cout << "Enter name of input file or Control-C to quit program: ";
		cin >> filename;
		cout << filename << endl << endl;
		cin.ignore(INT_MAX, '\n');
		InFile.open(filename.c_str());
	}
	return;
}
void OpenOutput(ofstream& OutFile)
{
	string outname;
	cout << "Enter name of output file or Control-C to quit program: ";
	cin >> outname;
	cout << outname << endl << endl;

	OutFile.open(outname.c_str());
	while (OutFile.fail())
	{
		OutFile.clear();
		cout << string(15, '*') << " File Open Error " << string(15, '*') << endl;
		cout << "==> Output file failed to open properly!!\n";
		cout << "==> Attempted to open file: " << outname << endl;
		cout << "==> Please try again...\n";
		cout << string(47, '*') << endl << endl;
		cout << "Enter name of output file or Control-C to quit program: ";
		cin >> outname;
		cout << outname << endl << endl;
		cin.ignore(INT_MAX, '\n');
		OutFile.open(outname.c_str());
	}
	return;
}
bool CheckEmpty(MagazineService& customer, ifstream& InFile)
{
	bool empty;
	string emptyfile;
	empty = false;
	getline(InFile, customer.subscriber_name.firstName);
	getline(InFile, customer.subscriber_name.lastName, '\n');
	InFile >> customer.subscriber_name.customerID;	//ID
	InFile.ignore(INT_MAX, '\n');

	getline(InFile, customer.address.street, '\n');	//street
	getline(InFile, customer.address.city, '\n');	//city
	getline(InFile, customer.address.state, '\n');	//state
	InFile >> customer.address.zip_code;	//zip
	InFile.ignore(INT_MAX, '\n');


	InFile >> customer.renewal_info.monthLeft;	//months remaining on sub
	InFile.ignore(INT_MAX, '\n');
	getline(InFile, customer.renewal_info.renewal_notice.month, '\n');
	InFile >> customer.renewal_info.renewal_notice.day; //renewal notice day
	InFile.ignore(INT_MAX, '\n');
	InFile >> customer.renewal_info.renewal_notice.year; //renewal notic year
	InFile.ignore(INT_MAX, '\n');
	if (InFile.fail())	//would mean file is empty
	{
		empty = true;
		InFile.clear();
		InFile.close();
	}
	return empty;
}
void ReadRecord(MagazineService& customer, ifstream& InFile)
{
	bool done;
	done = false;
	InFile.clear();//clear stream from empty check
	
	{
		getline(InFile, customer.subscriber_name.firstName);
		getline(InFile, customer.subscriber_name.lastName, '\n');
		InFile >> customer.subscriber_name.customerID;	//ID
		//cout << "Processing Customer ID:" << customer.subscriber_name.customerID << endl;
		InFile.ignore(INT_MAX, '\n');

		getline(InFile, customer.address.street, '\n');	//street
		getline(InFile, customer.address.city, '\n');	//city
		getline(InFile, customer.address.state, '\n');	//state
		InFile >> customer.address.zip_code;	//zip
		InFile.ignore(INT_MAX, '\n');


		InFile >> customer.renewal_info.monthLeft;	//months remaining on sub
		InFile.ignore(INT_MAX, '\n');
		getline(InFile, customer.renewal_info.renewal_notice.month, '\n');
		InFile >> customer.renewal_info.renewal_notice.day; //renewal notice day
		InFile.ignore(INT_MAX, '\n');
		InFile >> customer.renewal_info.renewal_notice.year; //renewal notic year
		InFile.ignore(INT_MAX, '\n');

	}

	return;
}
void WriteInfo(MagazineService& customer, ofstream& OutFile)
{
	OutFile << string(55, '*') << endl;
	OutFile << customer.subscriber_name.firstName << " " << customer.subscriber_name.lastName << "(" << customer.subscriber_name.customerID << ")\n";
	OutFile << customer.address.street << endl;
	OutFile << customer.address.city << ", " << customer.address.state << " " << customer.address.zip_code << endl;
	OutFile << "The last renewal notice was sent on " << customer.renewal_info.renewal_notice.month << " " << customer.renewal_info.renewal_notice.day << ", " << customer.renewal_info.renewal_notice.year << endl;
	OutFile << string(55, '*') << endl << endl;
}