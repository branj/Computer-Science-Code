//Scheduler tasklist.cpp file
#include "ClassAddBookandTable.h"
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
    delete [] contact;
    contact = NULL;
    delete [] time;
    time = NULL;
    delete [] emailornumber;
    emailornumber = NULL;
    delete [] contactinfo;
    contactinfo = NULL;
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
int Contact::store(Contact & putintable)
{
    contact = new char[strlen(putintable.contact)+1];
    strcpy (contact, putintable.contact);

    time = new char[strlen(putintable.time)+1];
    strcpy (time, putintable.time);

    emailornumber = new char[strlen(putintable.emailornumber)+1];
    strcpy (emailornumber, putintable.emailornumber);

    contactinfo = new char[strlen(putintable.contactinfo)+1];
    strcpy (contactinfo, putintable.contactinfo);
}

//Displays a Contact and it's finished status
int Contact::Display()
{
    cout <<"\n\nContact Type:"<<contact<<"\nDate:"<< time <<"\nEmail or Phone #:"<<
    emailornumber << "\nContact info:"<<contactinfo<<"\n\n";
}

int Contact::Edit()
{
    delete [] time;
    delete [] emailornumber;
    delete [] contactinfo;

    char temp[50];

    cout <<"Please enter this contacts new number";
    cin.get(temp,50);
    cin.ignore(100, '\n');
    time = new char[strlen(temp)+1];
    strcpy(time, temp);

    cout <<"Please enter this contacts new address";
    cin.get(temp, 50);
    cin.ignore(100, '\n');
    emailornumber = new char[strlen(temp)+1];
    strcpy(emailornumber, temp);

    cout <<"Please enter this contacts new contact informoation (notes, etc)";
    cin.get(temp, 50);
    cin.ignore(100, '\n');
    contactinfo = new char[strlen(temp)+1];
    strcpy(contactinfo, temp);

}


//Table constructor
Table::Table(int tablesize)
{
    maxsize = tablesize;
    ht = new node * [maxsize];
    for (int i = 0; i < maxsize; ++i)
    {
        ht[i]= NULL;
    }
}

Table::Table()
{
    maxsize = 100;
    ht = new node * [maxsize];
    for (int i = 0; i < maxsize; ++i)
    {
        ht[i]= NULL;
    }
}



//Destructor
Table::~Table()
{
    int i = maxsize;
    node * current = NULL;
    while (i <= maxsize)
    {
        current = ht[i];
        while (current)
        {

            delete current;
            current = current->next;
        }
        ++i;
    }

}


//Add a new contact to that day
int Table::insert(char * & key, Contact & addthis)
{
    int index;


    //HASHING THE CONTACTS NAME
    index = (key[0] + key[1] + key[2])% maxsize;
    node * current = NULL;

    if (!current)
    {
        current = ht[index];
        ht[index] = new node;
        ht[index]->hasher = new Contact;
        ht[index]->hasher->store(addthis);
        ht[index]->next = current;
    }

    else

    {
        current = new node;
        current->hasher = new Contact;
        current->hasher->store(addthis);
        current->next=NULL;
    }


}

int Table::retrieve(char * key)
{
    int index;
    index = (key[0] + key[1] + key[2])% maxsize;
    node * current = ht[index];

    if (!current)
        cout << "No entries found";

    else

        while (current)
        {
            current->hasher->Display();
            cout << "Would you like to edit this information?";
            char yorno;
            cin.get(yorno);
            cin.ignore();
            if (yorno == 'y' || yorno == 'Y')
            {
                current->hasher->Edit();
                current = current->next;
            }
            else
                current = current->next;
        }

}





