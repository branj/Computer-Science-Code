//Serdar Numanoglu
//cs202 , assigment #2

//doublyList.h

#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include "portfolio.h"


struct node     //struct node for creating a Doubly linked list
{
       portfolio info;
       node * next;  //two ptr for next ptr and back ptr
       node * back;
};

class doublyList
{
      public:
             doublyList();       //default constructo set all members to 0
             ~doublyList();      //deallocated stack objects.

	     int insert(const portfolio & yearPort);
	     int display();


      protected:
      		 node * head;
      		 node * tail; // no need maybe???????

};




#endif
