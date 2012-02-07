//sell.cpp

#include "sell.h"
#include <iostream.h>

using namespace std;

sell::sell()
{

	sellingPeriod = NULL;

}

sell::sell(char * pName,char * pAddress ,char * pPhone ,char * itemName ,
		   float itemPrice , char * trDate ,char * itDesc, char * sPeriod)
		   :transaction(pName,pAddress,pPhone,itemName,itemPrice,trDate,itDesc)
{
	sellingPeriod = new char[strlen(sPeriod)+1];
	strcpy(sellingPeriod ,sPeriod);
}


sell::~sell()
{
	delete [] sellingPeriod;
}

void sell::display()
{
	transaction::display();

	cout << "Selling Period is for " << sellingPeriod << endl;

}
