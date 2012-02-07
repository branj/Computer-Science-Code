//Serdar Numanoglu
//Cs 202 , Assigmnet #3
//Spring 07
//Stock class , derived from Base class portfolio
//stock.h

#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include "portfolio.h"

using namespace std;

class stock: public portfolio
{
      public:
      		//CONSTRUCTORS
            stock();       //default constructor set all members to 0

      		//DESCTRUCTOR
            ~stock();      //deallocated device objects.

			//note: no need for copy const. becuase this class
			//does not have DYNAMIC member.

            void calculateNumberOfStock(int money,int numberStock);
            void display(ostream & out);

            stock& operator = (const stock & stockObj);



	  protected:
           int numberOfStock; //number of stock you can buy.
};


#endif

