//buy.h

#ifndef BUY_H
#define BUY_H

#include "transaction.h"

class buy : public transaction
{
      public:
      		//CONSTRUCTORS
            buy();
            buy(char * pName,char * pAddres ,char * pPhone ,char * itemName ,
		         float itemPrice , char * trDate ,char * itDesc, char * buyMeth);

      		//DESCTRUCTOR
             ~buy();      //deallocated device objects.

              void display();

	  protected:
            char * buyingMethod; //paypal, visa , cash ???


};


#endif
