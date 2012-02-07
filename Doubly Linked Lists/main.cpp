//main.cpp
//Serdar Numanoglu
//cs202 , assigment #3

//main.cpp
#include <iostream>
#include <fstream>
#include "portfolio.h"
#include "doublyList.h"
#include "stock.h"

using namespace std;

void listOfDevices(char * fileName , doublyList & list);
void menu(doublyList & list);
void addPortfolio(portfolio & obj,doublyList & list);
void testDisplay(portfolio & obj);
void calculateStock(stock & obj);
void testAssigment(stock & stockObj);


int main()
{
    doublyList list;

    char fileName[] = "data.dat";

    listOfDevices(fileName,list);

    menu(list);

    return 0;
}

void menu(doublyList & list)
{
     char answer;
     char * name =  new char[10];
     portfolio  obj;
     stock stockObj,testObj;

     do
     {
          cout << "\t\tWelcome to SERDAR'S Financial Portfolio "<< endl;
          cout << endl;
          cout << "\tDisplay the DATA 'd'\n"
          	   << "\tDisplay menu again 'm'\n"
               << "\tDo you want to add a yearly portfolio?'a'\n"
               << "\tCalculate how many stock I can buy 's'\n"
               << "\tTest assigment operator = 't'\n"
               << "\tEXIT 'x' \n";

     	  cin >> answer;
          cin.ignore(100,'\n');

     switch(answer)
     {
          case 'd':
               if(!list.display())
                   cout << "NO data" << endl;
               break;

          case 'a':
          		addPortfolio(obj,list);
          		//testDisplay(obj);
          		break;
		  case 's':
		  		calculateStock(stockObj);
				break;
		  case 't':
		  		testAssigment(testObj);
		  		break;
	      case  'x':
               cout<< "End of the program\n";
               break;

           default:
               cout << "NOT AN VALID CHOICE\n";
     }
     }while(answer != 'x');

}

void listOfDevices(char * fileName,doublyList & list)
{
    ifstream in;
    portfolio portObj;

    //allocate memory for data members
	char * mutualFund = new char[100];
	char * moneyMarket = new char[100];
	char * share = new char[100];
	char * year = new char[100];

    float currentMoney;

    //initialize the list with the records in the file
	in.open(fileName);
	if(!in)
	{
		cerr << "fail to open " << fileName << " for input!" << endl;
		exit(1);
	}

	in.get(mutualFund, 100, ';');
	while(!in.eof())
	{
        //read

		in.ignore(100,';');

		in.get(moneyMarket,100 ,';');
		in.ignore(100,';');

	    in.get(share,100 ,';');
		in.ignore(100,';');

	    in.get(year,100 ,';');
		in.ignore(100,';');

		in >> currentMoney;
		in.ignore(100, '\n');

		//insert the data in the list object.
        portObj.setData(mutualFund,moneyMarket,share,year,currentMoney);
        list.insert(portObj);

        //start reading in the next record
		in.get(mutualFund, 100, ';');
    }

}

void addPortfolio(portfolio & obj,doublyList & list)
{
	cin >> obj;
	list.insert(obj);//add the portfolio in the DLL
}

void testDisplay(portfolio & obj)
{
	cout << "Portfolio object you just added \n";
	cout << obj << endl;

}

void calculateStock(stock & obj)
{
	obj.setData("Wells Fargo","hapy",
            			 "Microsoft", "2007",15055);

    cout << "\t ***********Lets assume that per Microst share is $120**************\n";

	obj.calculateNumberOfStock(15055,120);
	cout << obj << endl;
}

void testAssigment(stock & stockObj)
{
	stock copyObj;
	stockObj.setData("Wells Fargo","HTT",
	            			 "Microsoft", "2007",15055);

    cout << "\t ***********Lets assume that per Microst share is $120**************\n";

	stockObj.calculateNumberOfStock(15055,120);

	cout <<"I will copy this stock obj into the other one\n";
	cout << "Here is what is in current obj\n\n";
	cout << stockObj << endl;

	copyObj = stockObj; //using assigment operator here.

	cout << "Here is copyObj after copying stockObj into it" << endl;
	cout << copyObj;

}

