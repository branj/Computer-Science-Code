//Serdar Numanoglu
//cs202 , assigment #2

//LLLofArrays.cpp

#include "LLLofArrays.h"
#include <iostream>

using namespace std;

LLLofArrays::LLLofArrays()
{
      head = NULL; //
      top = NULL;  //set the top to NULL
      index = 0;  //set the size 0
}

LLLofArrays::~LLLofArrays() //deallocate all the memory
{
	nodeTrans * current;


	while(head)
	{

		current = head->next;

		delete [] head->arrayTrans;
		delete head;

		head = current;
	}


	head = NULL;
	top = NULL;

}

int LLLofArrays::push(const transaction & transObj)
{


    if (!head)  //the list is empty , and stack too
    {
       head = new nodeTrans;  //now new node is adding the list.
       head->arrayTrans = new transaction[3]; //create a customer arra size 3
       top = head;
       top->arrayTrans = head->arrayTrans ;  // top points the top of the array.

	   //set all data members
       top->arrayTrans[index].copyTransactions(transObj);

	   top->next = NULL;

	   //index++; //increase the index
       return 1;
    }


    if (index < 2)
    {
		index++;

       //set all data members
       top->arrayTrans[index].copyTransactions(transObj);

       top->next = NULL;

       return 1;
    }
    else      //ARRAY  is FULL create next node
    {
	   index = 0; // set the size back to 0

       nodeTrans * current = head;

       if (current)
       {
           while(current->next)
                current = current->next;

           current->next = new nodeTrans;
           current = current->next;
           current->next = NULL;
       }

       current->arrayTrans = new transaction[3]; //create a customer array size 3
       top = current;

       //set all data members
       top->arrayTrans[index].copyTransactions(transObj);


}
       return 1;

}


int LLLofArrays::display()
{
   nodeTrans * temp = head;

   while(temp)
   {
	   for (int i = 0; i < 3; i++)
	   {
		   temp->arrayTrans[i].display();
	   }

	   temp = temp->next;
   }

   return 1;
}

