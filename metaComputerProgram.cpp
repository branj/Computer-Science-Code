/* 

   Brandon Jennings
   branj@pdx.edu
 
   
   PURPOSE:
   This program is a proof for a larger program that will allow people to
   input computers, display them, then rank them according to the 
   user's liking. As of now it is rather simple and straightforward.
   
   ALGORITHM:
   1.	Declare structure 'Puters'.
   2.	Greet user with the purpose of the program.
   3.	Call the 'menu' function, and declare an array of 'Puters'
   4.	Prompt user to choose a menu choice. 
        (1. Add Computer, 2. Display Computers, 3. Rank, 4.Quit)
   5.	User enters menu choice. (User chooses  1)
   6.	Call 'add' function. 
   7.	Prompt user for computer information. 
        (All variables from the structure 'puter_stats')
   8.	User inputs value for each of 'Puters' variables. 
   9.	Call 'Confirmation' function to check user's input. (All is well) 
   10.	Prompt user to enter a choice from main menu
   11.	User enters choice. (User chooses 1 to add another computer)
   12.	Repeat steps 6-9.
   13.	Prompt user to enter a choice from main menu. 
   14.	User enters choice.  (User chooses 2)
   15.	Call 'Display' function. 
   16.	Output all 'Puters' variables the user has entered. 
   17.	Prompt user to enter a choice from the main menu. 
   18.	 User enters choice. (User chooses 3)
   19.	 Call the 'Rank' function.
   20.	Output the first 'puter_stats' and prompt user for rank.
   21.	User enters rank
   22.	Output the second 'puter_stats' and prompt user for rank.
   23.	User enters rank
   24.  Now when 'Dispaly' function is called it displays ranks. 
   25.	Prompt user to enter a choice from main menu.  
   26.	User enters choice (They want to quit, so the enter 4)
   27.	Output "Are you sure?"
   28.	User inputs 'y'. 
   29.	Program terminates. 

*/

#include <iostream>
using namespace std;

const int BRAND_NUM = 13; 
const int MODEL_NUM = 13;
const int PROS_NUM = 131;
const int CONS_NUM = 131;
const int STORAGE_NUM = 10;
const int MEMORY_NUM = 10;

struct Puters
{
       
       float price;
       float review;
       char brand[BRAND_NUM];
       char model[MODEL_NUM];
       char pros[PROS_NUM]; 
       char cons[CONS_NUM];
       char storage[STORAGE_NUM];
       char memory [MEMORY_NUM];
};

void Greeting();
void Main_Menu();
void Add(Puters[], int &);
void Display(Puters[], int &);
void Rank(Puters[], int &);
bool Confirmation(Puters[], int);

int main()
{
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    cout.setf(ios::showpoint);
    
    Greeting();
    Main_Menu();
    return 0;   
}

//This function greets the user, and informs them of the programs purpose.
//Apparently the computer is sad.
void Greeting ()
{
     cout << "\nHello, I'm the computer!\n"
          << "But I'm old and you probably want a new one :(\n"
          << "I don't blame you really. I mean. I know I'm worthless.\n"
          << "I've seen the others too...they're beautiful. :(\n"
          << "What I'm getting at is...Is that I'm...\n"
          << "Is that I'm so tired of playing these games.\n"
          << "Just let me help you pick the new one\n"
          << "and get it over with. I can't take not knowing anymore\n"
          << "...It will make...Make me...Make me feel useful again.\n\n";
}


//The function serves as the library for Struct 'puters' variables.
//It also prompts users to selct a menu choice. 
//Their menu choice calls a different function. 
void Main_Menu ()
{
    //Declaring an array of struct Puters.
    //Only 100 entries are allowed.
    Puters all_input[100];
    int NUM = 0;
    int a;
    
    //Do while loop used to continue main menu until the user enters 4
    //or to protect against invalid data submission for choice.
    do {
        cout << "\n\n==================================================\n"
             << "=================================================="
             << "\n\nSo what'll it be?\n\n"
             << "1. Add a new Computer\n"
             << "2. Display Computers\n"
             << "3. Rank Computers\n"
             << "4. Quit \n"
             << "\n\nPlease choose for me to help you decide: ";
         cin >> a;
         cin.ignore(); 
        
        //If user enters 1 the Add function is called.
        if ( a == 1)
           Add(all_input, NUM);
        
        //If user enters 2 the Display function is called.
        else if (a == 2)
           Display(all_input, NUM);
        
        //If user enters 3 the Rank function is called.
        else if(a == 3)
           Rank(all_input, NUM);
        
        //If user enters 4 the program terminates.
        else if(a == 4)
           cout << "Hopefully I helped!"; 
        
        //If user enters something other than 1-4.
        else 
           cout << "!!!Please enter a valid choice!!!\n\n";
        
        } while ( a != 4 );
    
    
}

//If the user's menu choice is 1 then this function is called. 
//'Add' populates 1 of the 100 alloted entrys for struct Puters
// then increments it's counter so user can enter up to 100.   
void Add(Puters all_input2[], int & NUM2)
{
     
     bool goforth;  
     
     //Checking to make sure user doesn't input too many computers
     if (NUM2 >= 100)
        cout << "!!!You've reached your limit for computers!!!";
     
     //This is the meat of the 'Add' function.
     //Here the user is asked to to input information
     //for struct Puters' variables.   
     else 
     {  
        //Do while loop used to confirm user input
        //Gives them another chance to enter if it's wrong.
        do{   
        cout << "==================================================\n";
        cout << "\nPlease enter the computer's brand: ";
        cin.get (all_input2[NUM2].brand, 13); 
        cin.ignore(100,'\n');
        cout << "Please enter the computer's model: ";
        cin.get (all_input2[NUM2].model,13);
        cin.ignore (100,'\n');
        cout << "Pleae enter the computer's memory: ";
        cin.get (all_input2[NUM2].memory,10);
        cin.ignore(100,'\n');
        cout << "Please enter the computer's storage capacity: ";
        cin.get (all_input2[NUM2].storage,10); 
        cin.ignore();
        cout << "Please enter the computer's price: $"; 
        cin >> all_input2[NUM2].price; 
        cin.ignore(100,'\n');
        cout << "PROS?:\n"; 
        cin.get (all_input2[NUM2].pros, 131);
        cin.ignore (100, '\n');
        cout << "\nCONS?:\n";
        cin.get (all_input2[NUM2].cons, 131);
        
        //Calling the 'Confirmation' function to echo 
        //and confirm user input.
        //Then equaling the return bool value to 'goforth'
        goforth = Confirmation (all_input2, NUM2);
        
        //The returned bool value is then used to exit the do while loop
        //If it's true it exits the loop. 
        if (goforth == true)
        {
        cout << "\nThank you. Computer is now in the database\n\n"; 
        ++NUM2;
        }
        
        //If it's false it allows them to input the information again
        else if (goforth == false)
        {
        cout << "\nPlease enter your information again.\n\n";
        }
        }while (goforth == false);
        
      }
  
}

//This function is used to echo the user's input
//and ask them if they'd like to input it again.
//It returns a bool value to the 'add' function.
bool Confirmation (Puters all_input3[], int NUM4)
{
      char yayornay;
      bool whatitis;
      int looper; 
     
     //do while loop used in case the user doesn't enter a y or n.
     do{
      cout << "\n=================================================\n";
      cout << "\nYou entered:";
      cout << "\n\nBrand: " << all_input3[NUM4].brand;
      cout << "\nModel: " << all_input3[NUM4].model;
      cout << "\nMemory Size: " << all_input3[NUM4].memory;
      cout << "\nStorage Capacity: " << all_input3[NUM4].storage;
      cout << "\nPrice: $" << all_input3[NUM4].price;
      cout << "\nPROS:\n" << all_input3[NUM4].pros;
      cout << "\n\nCONS:\n" << all_input3[NUM4].cons;
      cout << "\n\nIs this correct? (Press Y or N)";
      cin  >> yayornay;
      cin.ignore();
      
      //This returns a true value to the 'add'function
      //so it can exit it's confirmation loop.
      if ( yayornay == 'Y' || yayornay == 'y')
         {
         looper = 0;
         whatitis = true;
         }
      
      //This returns a a negative value to the 'add function
      //so it can prompt the user for their information again
      else if (yayornay == 'N' || yayornay == 'n')
         {
         looper = 0;
         whatitis = false;
         }
      //If user enters anything other y or n the 'Confirmation'
      //function is looped over; this is used for the do while 
      //loop.
      else 
         {
         cout << "Sorry, but that is an invalid choice!";
         looper = 1;
         }
      }
      while ( looper == 1 );
      return whatitis;
}
     
//This function increments through the array of structure
//'Puters' and displays it until the current counter
//,NUM1, is reached.
void Display(Puters output[], int & NUM3)
{
     //This increments through the array of structures and 
     //stops once it gets to the valuee of NUM3.
     for (int i = 0; i < NUM3; ++i)
     {
         cout << "\n========================================";
         cout << "\n\nCOMPUTER " << i + 1; 
         
         //if else statement used to dynamically display 
         //the ranking.
         if (output[i].review == 0)
            cout << "\n\nRank: Currently unranked.";
         else
            cout << "\n\nReview: " << output[i].review;  
         
         cout << "\n\nBrand: " << output[i].brand;
         cout << "\nModel: " << output[i].model;
         cout << "\nMemory Size: " << output[i].memory;
         cout << "\nStorage Capacity: " << output[i].storage;
         cout << "\nPrice: $" << output[i].price;
         cout << "\nPROS:\n\n" << output[i].pros;
         cout << "\n\nCONS:\n\n" << output[i].cons;  
     }
}

//This increments through the array of structure "Puters"
//and gives the user a chance to rank other computers. 
void Rank(Puters rankthem[], int & NUM4)
{
     //Increments through the array of sturctur "Puters'
     //and stops once it reaches the value of NUM4. 
     for (int i = 0; i<NUM4; ++i)
     {
         cout << "\nComputer " << i + 1;
         cout << endl << rankthem[i].brand << endl;
         cout << rankthem[i].model << endl;
         //if else statment used to dynamically display
         //the computers current ranking.
         if (rankthem[i].review == 0)
            cout << "\nThis computer does not have a review";
         else
            cout << "\n\nCurrent review: " << rankthem[i].review; 
            cout << "\n\nWhat would you like to rank this computer?: ";
            cin  >> rankthem[i].review; cin.ignore();
     }
}     
