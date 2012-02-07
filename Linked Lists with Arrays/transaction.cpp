//transaction.cpp

#include "transaction.h"
#include <iostream.h>

using namespace std;


transaction::transaction()
{
	personName = address = phone = item = dateTrans = description = NULL;
	price = 0.0;
}

transaction::transaction(char * pName,char * pAddress ,char * pPhone ,char * itemName ,
						 float itemPrice , char * trDate ,char * itDesc )
{
	//first allocate memory for data members
	personName = new char[strlen(pName)+1];
	address = new char[strlen(pAddress)+1];
	phone = new char[strlen(pPhone)+1];
	item = new char[strlen(itemName)+1];
	dateTrans = new char[strlen(trDate)+1];
	description = new char[strlen(itDesc)+1];

	//copy
	strcpy(personName, pName);
	strcpy(address, pAddress);
	strcpy(phone, pPhone);
	strcpy(item, itemName);
	price = itemPrice;
	strcpy(dateTrans,trDate);
	strcpy(description,itDesc);
}

transaction::~transaction()
{
	delete [] personName;
	delete [] address;
	delete [] phone;
	delete [] item;
	delete [] dateTrans;
	delete [] description;
}

//set person information
void transaction::setDataPerson(char * personName, char * address, char * phone)
{
	//allocate data members for person information.
	this->personName = new char[strlen(personName)+1];
	this->address = new char[strlen(address)+1];
	this->phone = new char[strlen(phone)+1];

	//copy
	strcpy(this->personName, personName);
	strcpy(this->address, address);
	strcpy(this->phone, phone);

}

//set item information
void transaction::setDataItem(char * item,float price, char * dateTrans, char * description)
{
	//allocate data member for item information
	this->item = new char[strlen(item)+1];
	this->dateTrans = new char[strlen(dateTrans)+1];
	this->description = new char[strlen(description)+1];

	//copy
	strcpy(this->item, item);
	strcpy(this->dateTrans, dateTrans);
	strcpy(this->description, description);
	this->price = price;

}

//get functions
void transaction::getItem(char *  item)
{
	strcpy(item, this->item);
}

//copy transaction object
void transaction::copyTransactions(const transaction & transObj)
{
	//allocate data member for item information
	this->item = new char[strlen(transObj.item)+1];
	this->dateTrans = new char[strlen(transObj.dateTrans)+1];
	this->description = new char[strlen(transObj.description)+1];
	this->personName = new char[strlen(transObj.personName)+1];
	this->address = new char[strlen(transObj.address)+1];
	this->phone = new char[strlen(transObj.phone)+1];

	//copy
	strcpy(this->personName, transObj.personName);
	strcpy(this->address, transObj.address);
	strcpy(this->phone, transObj.phone);

	strcpy(this->item, transObj.item);
	strcpy(this->dateTrans, transObj.dateTrans);
	strcpy(this->description, transObj.description);

	this->price = transObj.price;

}

void transaction::display()
{
	cout << "TRANSACTION display" << "\n"
		 << "Person Name: " << personName << "\n"
		 << "Adress: " << address << "\n"
		 << "Phone: " << phone << "\n"
		 << "Item: " << item << "\n"
		 << "Date Transacion: " << dateTrans << "\n"
		 << "Price: $ " << price << "\n"
		 << "Description of the item: " << description << endl << endl;

}


