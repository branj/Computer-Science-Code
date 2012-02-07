//trade.cpp

#include "trade.h"
#include <iostream.h>

using namespace std;

trade::trade()
{

	tradeLocation = NULL;

}

trade::trade(char * pName,char * pAddress ,char * pPhone ,char * itemName ,
		   float itemPrice , char * trDate ,char * itDesc, char * location)
		   :transaction(pName,pAddress,pPhone,itemName,itemPrice,trDate,itDesc)
{
	tradeLocation = new char[strlen(location)+1];
	strcpy(tradeLocation ,location);
}


trade::~trade()
{
	delete [] tradeLocation;
}

void trade::display()
{
	transaction::display();

	cout << "This item is traded from " << tradeLocation << endl;

}
