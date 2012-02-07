//Serdar Numanoglu
//Cs 202 , Assigmnet #2
//Fall 06

//Transaction class , Base class
//transaction.h

#ifndef TRANSACTION_H
#define TRANSACTION_H


class transaction
{
      public:
      		//CONSTRUCTORS
            transaction();       //default constructor set all members to 0
            transaction(char * ,char * ,char * ,char * ,float , char * ,char * );

      		//DESCTRUCTOR
            virtual ~transaction();      //deallocated device objects.

            virtual void setDataPerson(char * personName, char * address, char * phone);
            virtual void setDataItem(char * item,float price, char * dateTrans, char * description);

 			virtual void copyTransactions(const transaction & transObj); //copy trans obj in any nodes.

            virtual void getItem(char * item);

            virtual void display();




	  protected:
            char * personName;
            char * address;
            char * phone;
            char * item;
            float price;
            char * dateTrans;
            char * description;

};


#endif

