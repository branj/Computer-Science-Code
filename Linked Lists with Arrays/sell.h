//sell.h

#ifndef SELL_H
#define SELL_H

#include "transaction.h"

class sell : public transaction
{
      public:
      		//CONSTRUCTORS
            sell();
            sell(char * pName,char * pAddres ,char * pPhone ,char * itemName ,
		         float itemPrice , char * trDate ,char * itDesc, char * sPeriod);

      		//DESCTRUCTOR
             ~sell();      //deallocated device objects.

              void display();

	  protected:
            char * sellingPeriod;


};


#endif
