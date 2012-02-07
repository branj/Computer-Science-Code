/*
 Brandon Jennings
 CS163 Online
 Fant
 Program #2
 
 PURPOSE:
 This program allows the user to input messages using a flexible array stack.
 The user can then display these tasks by day, the most recent being shown first
 . It also allows the user to delete the most recent message. There are 7 
 different stacks to accomadate each day of the week. Thusly, the data is 
 sortable by days.
*/
#include "ClassContactAndStack.h"
#include <iostream>

using namespace std;


int input(Contact & tempContact);
int whichday();


int main()
{
    Stack myStack[6];   //Declaring 7 stack objects; Each day of the week;
    Contact tempContact;    //Temporary list items to be passed 
    
    int choice;       //The menu choice
    int listchoice;   //Passed to the list to identify.     
    
    char * contacttype; //Temporary pointers to fill up tempContact.
    char * time;
    char * emailornumber;
    char * contactinfo;
    
    while(choice != 4){
    cout << "\nWhat would you like to do?\n\n"
         << "1.Add new message by day.\n"
         << "2.Display messages by day.\n"
         << "3.Erase most recent message by day.\n"
         << "4.Quit"
         << "\n\nPlease enter a number: ";
    
    cin >> choice; cin.ignore();
    cout << endl;
         
    switch (choice)
    {
    
           case 1:{
                input(tempContact); //fills an object to send to stack
                myStack[whichday()].Push(tempContact);
                break;}
           
           case 2:{
                myStack[whichday()].Display();
                break;}
         
           case 3:{
                myStack[whichday()].Pop();
                break;}
     
           case 4:
                break;
    }//   End of switch statment

   } //   End of while loop                            
}    //   End of Main


//Asks input questions, then populates temptask with entry
int input(Contact & tempContact)
{
 
 char temp[50];    //Temp for data entry
 int charnum; 
    
cout << "Please give the message a name:\n";
cin.get(temp, 100), cin.ignore(100, '\n');
char * contacttype = new char[charnum = strlen(temp)+1];
strcpy(contacttype, temp); 

cout << "Please the date and time this message was recieved:\n";
cin.get(temp, 100), cin.ignore(100, '\n');
char * time = new char[charnum = strlen(temp)+1];
strcpy(time, temp); 

cout << "What number or email address should you reply to?:\n";
cin.get(temp, 100), cin.ignore(100, '\n');
char * emailornumber = new char[charnum = strlen(temp)+1];
strcpy(emailornumber, temp); 

cout << "Anyother Contact Info (name, business, ect):\n";
cin.get(temp, 100), cin.ignore(100, '\n');
char * contactinfo = new char[charnum = strlen(temp)+1];
strcpy(contactinfo, temp); 

int dne = 0;

tempContact.populate(contacttype, time, emailornumber, contactinfo);
}

//Ask user for a number then returns it to client to determin which stack to 
//use.
int whichday()
{
    int stackobjectindexchooser = 0;
cout << "\n\n1.Sunday\n2.Monday\n3.Tuesday\n4.Wednesday\n5.Thursday\n6.Friday\n7."
     << "Saturday\n\n Which day's messages would you like to work with?";
   
cin >> stackobjectindexchooser; cin.ignore();
return --stackobjectindexchooser;
}   
