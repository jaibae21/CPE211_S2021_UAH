// ****************************************
// Program Title: Project 3
// Project File: Project_03.cpp
// Name: Jaiden Gann
// Course Section: CPE-211-02
// Lab Section: 2
// Due Date: 02/5/21
// program description:Calculate cost of and return
// from selling stocks,along with net loss and gain
// ****************************************
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main()
{
	cout << fixed << showpoint << setprecision(2);
	//Setting up variables
	const float BUYCOMMISION = 0.02;
	const float SELLCOMMISSION = 0.015;
	const float TAXRATE = 0.25;
	string stockName;
	int numberofShares;
	float shareCost;
	float sellCost;
	float buy_cost, buy_commission, total_cost;
	float return_sale, sell_commission, total_return;
	float net_Gain, tax_credit;
	//Stock Calculation Header
	cout << endl; 
	cout << string(25, '*') << endl;
	cout << "Stock Calculations" << endl;
	cout << string(25, '*') << endl << endl;
	//Setting up inputs
	cout << "Enter the name of the stock: ";
	cin >> stockName;
	cout << stockName << endl;

	cout << "Enter the number of shares purchased: ";
	cin >> numberofShares;
	cout << numberofShares << endl;

	cout << "Enter the buy price per share: ";
	cin >> shareCost;
	cout << shareCost << endl;

	cout << "Enter the sell price per share: ";
	cin >> sellCost;
	cout << sellCost << endl << endl;

	cout << "Results for " << numberofShares << " shares of " << stockName << ":" << endl;
	//Calculations
	buy_cost = shareCost * numberofShares;
	buy_commission = buy_cost * BUYCOMMISION;
	total_cost = buy_cost + buy_commission;
	
	return_sale = sellCost * numberofShares;
	sell_commission = return_sale * SELLCOMMISSION;
	total_return = return_sale - sell_commission;

	net_Gain = total_return - total_cost;
	tax_credit = net_Gain * TAXRATE; 
	//Output Section
	cout << string(35, '-') << endl;	
	cout << setfill('.') << left;
	cout << setw(20) << "Buy Commission" << "$" << buy_commission << endl;
	cout << setw(20) << "Total Cost" << "$" << total_cost << endl;
	cout << setw(20) << "Sell Commission" << "$" << sell_commission << endl;
	cout << setw(20) << "Total Return" << "$" << total_return << endl;
	cout << setw(20) << "Net Profit/Loss" << "$" << net_Gain << endl;
	cout << setw(20) << "Tax/Credit" << "$" << tax_credit << endl << endl;
}
