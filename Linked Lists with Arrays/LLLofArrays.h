//Serdar Numanoglu
//cs202 , assigment #2

//LLLofArrays.h

#ifndef LLLOFARRAYS_H
#define LLLOFARRAYS_H

#include "transaction.h"


struct nodeTrans     //struct node for creating a LLL
{
       transaction  * arrayTrans;  //array of transaction insight each node
       nodeTrans * next;
};

class LLLofArrays
{
      public:
             LLLofArrays();       //default constructo set all members to 0
             ~LLLofArrays();      //deallocated stack objects.

             int push(const transaction & transObj);    //add a transacton in the stack.
             int display();

      private:
              nodeTrans * head;  //head of the list
              nodeTrans * top; //top ptr to stack.
              int index; // size of array transactions
};




#endif
