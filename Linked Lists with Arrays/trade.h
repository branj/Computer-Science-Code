//trade.h

#ifndef TRADE_H
#define TRADE_H

#include "transaction.h"

class trade : public transaction
{
      public:
      		//CONSTRUCTORS
            trade();
            trade(char * pName,char * pAddres ,char * pPhone ,char * itemName ,
		         float itemPrice , char * trDate ,char * itDesc, char * location);

      		//DESCTRUCTOR
             ~trade();      //deallocated device objects.

              void display();

	  protected:
            char * tradeLocation; //paypal, visa , cash ???


};


#endif
