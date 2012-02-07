//doublyList.cpp

#include <iostream>
#include "doublyList.h"

using namespace std;

doublyList::doublyList()
{
	head = NULL;
	tail = NULL;
}

doublyList::~doublyList()
{
	node * temp;

	while(temp)
	{
		temp = head->next;
		delete head;
		head = temp;
	}

}

int doublyList::insert(const portfolio & yearPort)
{
	node * previous;
	node * newNode = new node;

	newNode->info = yearPort; //Using the assigment operator.
	newNode->next = NULL;
	newNode->back = NULL;

	if (!head)
	{
	    head = newNode;
	    tail = newNode;
	}
    else
	{
	    tail->next = newNode;
	    newNode->back = tail;
	    tail = newNode;
	}

}

int doublyList::display() //this will display from end of the list
{
	node * current;

	current = tail;

	if (!tail)
	     cout << "NO DATA IN THIS list" << endl;

	while(current)
	{
	    cout << current->info << endl; //using << operator for portfolio class
	    current = current->back;
	}

	return 1;
}

