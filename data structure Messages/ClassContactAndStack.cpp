//Scheduler tasklist.cpp file
#include "ClassContactAndStack.h"
#include <iostream>
using namespace std;



//Constructor
Contact::Contact()
{
   contact = NULL;
   time = NULL;
   emailornumber = NULL;
   contactinfo = NULL;
}




//Destructor
Contact::~Contact()
{
    delete [] contact;  contact = NULL;
    delete [] time; time = NULL;
    delete [] emailornumber; emailornumber = NULL;
    delete [] contactinfo;  contactinfo = NULL;
}



//Copies data provided by the client to instance of a Contact
int Contact::populate(char* contacttype, char* tyme, char* emailnumber, char* con)
{
   contact = new char[strlen(contacttype)+1];
   strcpy(contact, contacttype);
   
   time = new char[strlen(tyme)+1];
   strcpy(time, tyme);
   
   emailornumber = new char[strlen(emailnumber)+1];
   strcpy(emailornumber, emailnumber);
   
   contactinfo = new char[strlen(con)+1];
   strcpy(contactinfo,con);
                     
}  


//Accepts a populated Contact to input into list using "new node."
int Contact::store(Contact & putinstack)
{
   contact = new char[strlen(putinstack.contact)+1];
   strcpy (contact, putinstack.contact);
   
   time = new char[strlen(putinstack.time)+1];
   strcpy (time, putinstack.time);
   
   emailornumber = new char[strlen(putinstack.emailornumber)+1];
   strcpy (emailornumber, putinstack.emailornumber);
   
   contactinfo = new char[strlen(putinstack.contactinfo)+1];
   strcpy (contactinfo, putinstack.contactinfo);
}

//Displays a Contact and it's finished status
int Contact::Display()
{
  cout <<"\n\nContact Type:"<<contact<<"\nDate:"<< time <<"\nEmail or Phone #:"<<
       emailornumber << "\nContact info:"<<contactinfo<<"\n\n";
}



//Stack constructor;
Stack::Stack()
{
  head = NULL;
  top = 0;
  maxsize = 3;
}
     
            
//Destructor                
Stack::~Stack()
{
  node * current;
  while(head)
  {
   current = head->next;
   delete head;
   head = current;
  }
  
}   


//Add a new contact to that day
int Stack::Push(Contact & addthis)
{    
     if(!head) //Adds the first node and populates the first array index
     {
     head = new node;
     head->array = new Contact[maxsize]; 
     head->array[top].store(addthis);
     head->next = NULL;
     }
     
     else //Checking to see if the first node's array is full. If it is
          //create a new node and make it the head. 
     if(top > maxsize)
     {
      top = 0;
      node*temp = new node;
      temp->array = new Contact[maxsize];
      temp->array[top].store(addthis);
      temp->next=head;
      head=temp;
     }
     
     else //If previous arguements aren't met, increase top and add a new object
          //to top's index.
     {
     ++top;
     head->array[top].store(addthis); 
     }
}    


//Displays all entries of the list.
int Stack::Display()
{
 
  node * temp = head;
  int i = top; //so I don't lose track of top's position. 
       
     if(temp) //if the list isn't empty
     {  
      while(i >= 0) //While top is greater than 0
      {
        temp->array[i].Display(); //descend through the stack of arrays
        --i;
      } //End of while loop
       
       if(temp->next) //checking to see the list isn't over, if it's not...
       {
          i = maxsize; //reset the top counter and link up to the next node
          temp = temp->next;
          while(i >= 0) //Then cycle through the array in this node.
          {
            temp->array[i].Display();
            --i;
          }
      
       }
     }  
       
 }   
 
//Delete current index. If index is empty, it deletes the node, and alters head
int Stack::Pop()
{   
    head->array[top].~Contact();
    --top;
    if(top < 0)
    {
    node * temp = head;
    head = head-> next;
    delete temp;
    top = maxsize;
    }
}
 
 
