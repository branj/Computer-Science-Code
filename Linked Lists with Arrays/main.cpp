//main.cpp
//Serdar Numanoglu
//cs202 , assigment #2

//main.cpp
#include <iostream>
#include <fstream>
#include "transaction.h"
#include "sell.h"
#include "table.h"
#include "buy.h"
#include "trade.h"
#include "LLLofArrays.h"

using namespace std;

void listOfDevices(char * fileName , table & list, LLLofArrays & stack);
void menu(table & list, LLLofArrays & stack);
void test();

int main()
{
    table list;
    LLLofArrays stack;

    char fileName[] = "data.dat";

    listOfDevices(fileName,list,stack);

    menu(list,stack);

    return 0;
}

void menu(table & list,LLLofArrays & stack)
{
     char answer;

     char * name =  new char[10];
     char * nameForRetrieve = new char[20];
     int numberOfCol;


     do
     {
          cout << "\t\tWelcome to SERDAR'S Dynamic Binding  "<< endl;
          cout << endl;
          cout << "\tTest my program for DYNAMIC BIDING 't'\n"
               << "\tDisplay the data with Array of LLL(table) 'd'\n"
               << "\tDisplay the data with LLL of Arrays(stack) 's'\n"
               << "\tDisplay menu again 'm'\n"
               << "\tEXIT 'x' \n";

     	  cin >> answer;
          cin.ignore(100,'\n');

     switch(answer)
     {
          case 't':
          	   test();
               break;

           case 'd':
               if(!list.display())
                   cout << "NO data" << endl;
               break;

		   case 's':
               if(!stack.display())
                   cout << "NO data" << endl;
	  		   break;

           case  'x':
               cout<< "End of the program\n";
               break;

           default:
               cout << "NOT AN VALID CHOICE\n";
     }
     }while(answer != 'x');

}

void listOfDevices(char * fileName,table & list,LLLofArrays & stack)
{
    ifstream in;
    transaction objTrans;

    //allocate memory for data members
	char * item = new char[100];
	char * personName = new char[100];
	char * address = new char[100];
	char * phone = new char[100];
	char * dateTrans= new char[100];
    char * description = new char[100];
    float price;

    //initialize the list with the records in the file
	in.open(fileName);
	if(!in)
	{
		cerr << "fail to open " << fileName << " for input!" << endl;
		exit(1);
	}

	in.get(item, 100, ';');
	while(!in.eof())
	{
        //read

		in.ignore(100,';');
		in.get(personName,100 ,';');

		in.ignore(100,';');
	    in.get(address,100 ,';');

		in.ignore(100,';');
	    in.get(phone,100 ,';');

		in.ignore(100,';');
	    in.get(dateTrans,100 ,';');

		in.ignore(100,';');
	    in.get(description,100 ,';');
		in.ignore(100,';');

		in >> price;

        in.ignore(100, '\n');

		//insert the data in the list object.
        objTrans.setDataPerson(personName, address, phone);
        objTrans.setDataItem(item, price, dateTrans, description);

        list.add(objTrans);
        stack.push(objTrans);

        //start reading in next record
		in.get(item, 100, ';');

    }

}

void test()
{
	sell sellCard("Serdar","Milwaikue" ,"999-9999","Wireless Card",52.25,
				 "May/04/2007","Used Linksys Pc card","1 week");

	cout << "Testing Selling Object for dynamic binding" << endl;

	sell * sp = & sellCard; //
	sp->display();
	cout << endl;

	transaction * tp = & sellCard; //*** here i assigned transaction obj with sell
	tp->display(); //call display with transaction obj.
	cout << endl;

	//BUYING OBJ test
	buy buyGame("Olgay", "Beaverton" , "888-8888", "Fifa 2007",45.00,
				"Feb/14/2007","New Fifa Pc game", "VISA");

	cout << "Buying Object" << endl;

	buy * bp = & buyGame;
	bp->display();
	cout << endl;

	transaction *t1p = & buyGame;
	t1p->display();
	cout << endl;

	//TRADING OBJ tes
	trade tradeBook("Huseyin", "Portland", "777-7777", "Java Lovers", 78.9,
				    "Jun/30/2005","Java book for Advanced Users", "New York");

	cout << "Trading Object" << endl;

	trade * trp = & tradeBook;
	trp->display();
	cout << endl;

	transaction * tradeP = & tradeBook;
	trp->display();
	cout << endl;

}


