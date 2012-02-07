//Serdar Numanoglu
//Cs 202 , Assigmnet #3
//Spring 07
//Portfolio class , Base class
//portfolio.h

#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include <iostream>

using namespace std;

class portfolio
{
      public:
      		//CONSTRUCTORS
            portfolio();       //default constructor set all members to 0
            //portfolio(char * ,char * ,char * ,char * ,float , char * ,char * );

      		//DESCTRUCTOR
            ~portfolio();      //deallocated device objects.

            //COPY CONST.
            portfolio(const portfolio & portObj);

            void setData(char * mutualFund,char * moneyMarket,
            			 char * share, char * year, float currentMoney);

            friend ostream & operator<< (ostream& o , portfolio & portObj);
            friend istream & operator>> (istream& in, portfolio & portObj);

            portfolio& operator = (const portfolio & portObj);

            //VIRTUAL HELPER MEMBER FUNCTIONS
            virtual void display(ostream & out) ;




	  protected:
            char * mutualFund;
            char * moneyMarket;
            char * share;
            char * year;  //I am keeping my portfolio yearly.
            float currentMoney;

};


#endif


