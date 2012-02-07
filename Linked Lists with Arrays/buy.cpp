//buy.cpp

#include "buy.h"
#include <iostream.h>

using namespace std;

buy::buy()
{

	buyingMethod = NULL;

}

buy::buy(char * pName,char * pAddress ,char * pPhone ,char * itemName ,
		   float itemPrice , char * trDate ,char * itDesc, char * buyMeth)
		   :transaction(pName,pAddress,pPhone,itemName,itemPrice,trDate,itDesc)
{
	buyingMethod = new char[strlen(buyMeth)+1];
	strcpy(buyingMethod ,buyMeth);
}


buy::~buy()
{
	delete [] buyingMethod;
}

void buy::display()
{
	transaction::display();

	cout << "Buying this item with " << buyingMethod << endl;

}
