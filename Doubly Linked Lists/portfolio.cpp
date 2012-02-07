//portfolio.cpp

#include <iostream>
#include "portfolio.h"

using namespace std;

/**********************
protected:

    char * mutualFund;
    char * moneyMarket;
    char * share;
    char * year;
    float currentMoney;
***********************/

portfolio::portfolio()
{
	mutualFund = NULL;
	moneyMarket = NULL;
	share = NULL;
	year = NULL;
	currentMoney = 0.0;
}

portfolio::~portfolio()
{
	delete [] mutualFund;
	delete [] moneyMarket;
	delete [] share;
	delete [] year;
}

void portfolio::setData(char * mutualFund,char * moneyMarket,
				        char * share, char * year, float currentMoney)
{
	//allocate data members for person information.
	this->mutualFund = new char[strlen(mutualFund)+1];
	this->moneyMarket = new char[strlen(moneyMarket)+1];
	this->share = new char[strlen(share)+1];
	this->year = new char[strlen(year)+1];

	//copy
	strcpy(this->mutualFund, mutualFund);
	strcpy(this->moneyMarket, moneyMarket);
	strcpy(this->share, share);
	strcpy(this->year, year);
	this->currentMoney = currentMoney;
}

ostream & operator << (ostream& o ,portfolio & portObj)
{
	portObj.display(o);
	return o;
}

void portfolio::display(ostream & out)
{
	cout  << "Year: " << year << " portfolio \n"
	      << "Mutual Fund: " << mutualFund << "\n"
		  << "Money Market: " << moneyMarket << "\n"
		  << "Shares: " << share << "\n"
		  << "Current Money in the bank:$" << currentMoney
		  << "\n";

}

istream & operator >> (istream & in, portfolio & portObj)
{
	char year[100];
	char mutual[100];
	char moneyMarket[100];
	char shares[100];
	float money;

	cout << "What year is this yearly portfolio?\n";
	in.get(year,100,'\n');
	in.ignore(100,'\n');

	cout << "What is the mutual Fund?\n";
	in.get(mutual,100,'\n');
	in.ignore(100,'\n');

	cout << "What money Market are you in?\n";
	in.get(moneyMarket,100,'\n');
	in.ignore(100,'\n');

	cout << "What share did you buy?\n";
	in.get(shares,100,'\n');
	in.ignore(100,'\n');

	cout << "What is your total money? **Please type an INTEGER**\n";
	in >> money;
	in.ignore(100,'\n');

	portObj.setData(mutual,moneyMarket,shares,year,money);

	return in;
}

portfolio& portfolio::operator = (const portfolio& portObj)
{
	if (this == &portObj)     //check for self assignment
	    return *this;

	//CHECK IF the current obj memebers have value and dellocate them if they have
	if (mutualFund)             //current object has a value
	    delete [] mutualFund;     //deallocate any dynamic memory

	if (moneyMarket)
		delete [] moneyMarket;

	if (share)
		delete [] share;

	if (year)
		delete [] year;
	////////////////////////////////////////

	//NOW start copying ..
	//allocate data members for person information.
	mutualFund = new char[strlen(portObj.mutualFund)+1];
	moneyMarket = new char[strlen(portObj.moneyMarket)+1];
	share = new char[strlen(portObj.share)+1];
	year = new char[strlen(portObj.year)+1];

	//copy
	strcpy(mutualFund, portObj.mutualFund);
	strcpy(moneyMarket, portObj.moneyMarket);
	strcpy(share, portObj.share);
	strcpy(year, portObj.year);
	currentMoney = portObj.currentMoney;

    return *this;

}

portfolio::portfolio(const portfolio & portObj)
{
	//allocate data members for person information.
	mutualFund = new char[strlen(portObj.mutualFund)+1];
	moneyMarket = new char[strlen(portObj.moneyMarket)+1];
	share = new char[strlen(portObj.share)+1];
	year = new char[strlen(portObj.year)+1];

	//copy
	strcpy(mutualFund, portObj.mutualFund);
	strcpy(moneyMarket, portObj.moneyMarket);
	strcpy(share, portObj.share);
	strcpy(year, portObj.year);
	currentMoney = portObj.currentMoney;
}

