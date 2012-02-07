/*
 Brandon Jennings
 CS163 Online
 Fant
 Program #3

 PURPOSE:
 This program serves as a simple address book. Users can input a person's name, address,and phone#, then stores this informations
 for them to look up or delete later simply by typing their contact's name. This system is impletemented using an array of linked lists, the LL
 are their in the event of hashed index collisions.
*/
#include "ClassAddBookandClassTable.cpp"
#include <iostream>

using namespace std;


int input(char * & key, Contact & tempContact);


int main()
{
    int tablesize;
    cout << "How big would you like your address book to be?";
    cin >> tablesize;
    //Declaring Hashtable
    Table hashtable(tablesize);

    //Temporary list items to be passed
    Contact tempContact;

    int choice;


    char * contacttype; //Temporary pointers to fill up tempContact.
    char * time;
    char * emailornumber;
    char * contactinfo;

    while (choice != 3)
    {
        cout << "\nWhat would you like to do?\n\n"
        << "1.Add new person to your address book.\n"
        << "2.Look up contact.\n"
        << "3.Quit.\n"
        << "\n\nPlease enter a number: ";

        cin  >> choice;
        cin.ignore();
        cout << endl;

        switch (choice)
        {

        case 1:

            char * key;
            input(key,tempContact); //Fills a conatct to send to the hash table
            hashtable.insert(key,tempContact); //send the k
            delete[] key;
            break;


        case 2:
            char temp[25];
            cout << "Please enter a name: ";
            cin.get(temp, 100);
            cin.ignore(100, '\n');
            key = new char[strlen(temp)+1];
            strcpy(key, temp);
            hashtable.retrieve(key);
            delete[]key;
            break;

        case 3:

            break;



        default:
            cout << "Please input a valid choice." << endl;
            break;
        }//   End of switch statment

    } //   End of while loop
}    //   End of Main


//Asks input questions, then populates temptask with entry
int input(char * & key, Contact & tempContact)
{

    char temp[50];    //Temp for data entry
    int charnum;

    cout << "What is the contacts name?:\n";
    cin.get(temp, 50);
    cin.ignore(100, '\n');
    char * contacttype = new char[strlen(temp)+1];
    strcpy(contacttype, temp);
    key = new char[strlen(temp)+1];
    strcpy (key, temp);


    cout << "Phone#:\n";
    cin.get(temp, 50), cin.ignore(100, '\n');
    char * time = new char[strlen(temp)+1];
    strcpy(time, temp);

    cout << "Address:\n";
    cin.get(temp, 50), cin.ignore(100, '\n');
    char * emailornumber = new char[strlen(temp)+1];
    strcpy(emailornumber, temp);

    cout << "Any other Contact Info:\n";
    cin.get(temp, 50), cin.ignore(100, '\n');
    char * contactinfo = new char[strlen(temp)+1];
    strcpy(contactinfo, temp);



    tempContact.populate(contacttype, time, emailornumber, contactinfo);

}

