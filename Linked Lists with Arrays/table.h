//Serdar Numanoglu
//Cs 202 , Assigmnet #2
//Fall 06

//Table class,
//table.h

#ifndef TABLE_H
#define TABLE_H

#include "transaction.h"

struct node
{
	transaction  information;
    node * next;

};


class table
{
      public:
            table();       //default constructor set all members to 0
            ~table();      //deallocated device objects.

            int add(transaction & information);    //insert a data in array of LLL
			int display(void);

	  protected:

			node ** head;

			void deleteList(node * ptr);


      private:



};


#endif

