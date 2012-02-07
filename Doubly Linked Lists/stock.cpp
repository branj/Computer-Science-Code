//stock.cpp

#include <iostream>
#include "stock.h"

using namespace std;

/**********************
protected: "this is portfolio class members

    char * mutualFund;
    char * moneyMarket;
    char * share;
    char * year;
    float currentMoney;
 *////////////////////

/*********************
protected:
    int numberOfStock;
*////////////////////

stock::stock()
{
	numberOfStock = 0;
}

stock::~stock()
{
	//NOTHING TO delete in this class.
}

void stock::calculateNumberOfStock(int money,int stockPrice)
{
	numberOfStock = money/stockPrice;

}

void stock::display(ostream & out)
{
	portfolio::display(out);

	cout << "You can buy " << numberOfStock << " of them\n";
}

stock& stock::operator = (const stock& stockObj)
{
	portfolio::operator= (stockObj);
	numberOfStock = stockObj.numberOfStock;

    return *this;
}
