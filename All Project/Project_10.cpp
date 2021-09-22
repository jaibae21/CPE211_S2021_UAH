// **************************************************************
// **************************************************************
//
// **********  DO NOT MODIFY ANYTHING IN THIS SECTION
//
// solution cpp file for project 11
// all helper function definitions go in this file

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "Project_10.h"

using namespace std;

// **************************************************************
// **************************************************************
//
// **************************************************************
// **********   PUT ALL FUNCTION DEFINITIONS BELOW THIS COMMENT
//
// Function definitions start here. 

// ************** CONTRUCTORS **************
Date::Date()	//defualt set to 1/1/1900
{
	month = 1;
	day = 1;
	year = 1900;
}

Date::Date(int initMonth, int initDay, int initYear)	//parametrized
{
	month = initMonth;
	day = initDay;
	year = initYear;
}

Date::Date(int initMonth, int initYear)		//parametrized but day = 1
{
	day = 1;
	month = initMonth;
	year = initYear;
}
// ************** TRANSFORMERS **************
void Date::SetDate(int m, int d, int y)
{
	month = m;
	day = d;
	year = y;
}
void Date::IncrementDate()
{
	day++;
	//months with 31 days
	if ((month == JAN || month == MAR || month == MAY || month == JUL || month == AUG || month == OCT) && day > 31)
	{
		day = 0;
		day++;
		month++;
		
	}
	//Feb
	if (month == FEB && day > 28)
	{
		day = 0;
		day++;
		month++;
	}
	//months with 30 days
	if ((month == APR || month == JUN || month == SEP || month == NOV) && day > 30)
	{
		day = 0;
		day++;
		month++;
	}
	//new year
	if (month == DEC && day >= 31)
	{
		day = 0;
		//day++;
		month = 1;
		year++;
	}
	
}
// ************** OBSERVERS *******************
void Date::WriteNumberFormat() const	//fomrat MM/DD/YYYY
{
	if (month < 10 || day < 10)
	{
		cout << setfill('0');
		cout << right << setw(2) << month << '/' << setw(2) << day << '/' << year << endl;
		cout << setfill(' ');
	}
	else
	{
		cout << month << '/' << day << '/' << year << endl;
	}
	
}
void Date::WriteNameFormat() const
{
	switch (month)
	{
	case JAN:
		cout << "January " << day << ", " << year << endl;
		break;
	case FEB:
		cout << "February " << day << ", " << year << endl;
		break;
	case MAR:
		cout << "March " << day << ", " << year << endl;
		break;
	case APR:
		cout << "April " << day << ", " << year << endl;
		break;
	case MAY:
		cout << "May " << day << ", " << year << endl;
		break;
	case JUN:
		cout << "June " << day << ", " << year << endl;
		break;
	case JUL:
		cout << "July " << day << ", " << year << endl;
		break;
	case AUG:
		cout << "August " << day << ", " << year << endl;
		break;
	case SEP:
		cout << "September " << day << ", " << year << endl;
		break;
	case OCT:
		cout << "October " << day << ", " << year << endl;
		break;
	case NOV:
		cout << "November " << day << ", " << year << endl;
		break;
	case DEC:
		cout << "December " << day << ", " << year << endl;
		break;
	default:
		cout << "No month is selected" << endl;
		break;
	}
}
// determine if two dates are the same
bool Date::SameDate(Date otherDate) const
{
	if (month == otherDate.month && day == otherDate.day && year == otherDate.year)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}
// determine if one date is before the other date
bool Date::BeforeDate(Date otherDate) const
{
	if (month < otherDate.month || day < otherDate.day || year < otherDate.year)
	{
		return true;
	}
	else
	{
		return false;
	}

}
// determine if one date is after the other date
bool Date::AfterDate(Date otherDate) const
{
	if (month > otherDate.month || day > otherDate.day || year > otherDate.year)
	{
		return true;
	}
	else
	{
		return false;
	}

}