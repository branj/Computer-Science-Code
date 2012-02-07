//table.cpp

#include "table.h"
#include <iostream.h>

using namespace std;

table::table()
{

	head = new node*[5];

	for (int i = 0; i < 5; ++i) //initialize array items to NULL
		head[i] = NULL;


}

table::~table()
{
	for(int i = 0; i < 5 ; i++)
	{
		deleteList(head[i]); // delete the lists in the array

		delete head[i];
	}

}

void table::deleteList(node * ptr)
{
	node * current;

	while(ptr)
	{
		current = ptr->next;

		//this will also called the destructor in transaction.h
		delete ptr;

		ptr = current;
	}
}

//add in the table, key is the iteam name
int table::add(transaction & transObj)
{
	int total = 0; //total point for correspoind char values
	int index = 0;

	char * item = new char[25];

	transObj.getItem(item);

	for (int i = 0; item[i] != '\0'&& i < 5; i += 2)
		  total += (int)item[i];

	index = total % 5; //calculate the index

	if ( head[index] ) //in this case , collision is occured.
	{
		node * temp = head[index];
		head[index] = new node;

		//copy into the table.
		head[index]->information.copyTransactions(transObj);

		head[index]->next = temp;

	}
	else
	{
		head[index] = new node; //now go to index and assign a node.

		//copy into the table
		head[index]->information.copyTransactions(transObj);

		head[index]->next = NULL;
	}

    return 1;

}


int table::display(void)
{
	node * temp;

	if (!head)
		return 0;

	for (int i = 0; i < 5; ++i)
	{
		temp = head[i];

		if (temp)
		{
			//If there are more than one nodes.
			while (temp->next)
			{
				temp->information.display();

				temp = temp->next;
			}

				//IF THERE IS ONLY ONE node
			temp->information.display();
		}
    }

	return 1;
}







