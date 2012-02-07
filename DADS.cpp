/*
  Brandon Jennings
  CS 162 Online
  Prepared for: Karla Fant
  Program #5
  
  Overview:
  
  This program allows users to keep track of music files. The library
  database is allocated dynamically as a linked list so it can be as large or
  as small as the user wants. It also allows the user to input/delete 
  their list entries from either the beginning or the end, search their list, 
  and display the size of the list as it grows.  
  
  
  Algorithm:
  
  1. Call "Greeting" function.
  2. Prompt user for "mainmenuchoice"
  (1.Input,2.Display,3.Delete,4.Search,5.SizeofLL,6.About,7.Quit) 
  3. User inputs "mainmenuchoice" (User wants to input a new file).
  4. Ask user if they want to insert at the begginning or the end.
  5. Prompt user for Song information.
  6. User inputs song information.
  7. User repeats steps 3-6 until all songs are entered.
  8.User inputs 2 at the main menu(They want to display their files).
  9.Output database to screen.
  10.User inputs 3 at the main menu(They want to delete a song)
  11.Ask user if they want to delete the first of last item of LLL
  12.User chooses first of last.
  13.Call corresponding delete function
  14.User inputs 4 at the main menu(They want to lookup a song.
  15.Prompt user to input serach term.
  16.User inputs search term.
  17.Call "Search" function to look for the file in the database.
  18.Display file if found, otherwise output "sorry..." message.
  19.User inputs 5 at the main menu(They want to know the size of their list)
  20.Call sizeofList function and output the size of the list. 
  21.User inputs 6 at main menu(They want to know what the program is all about)
  22.Display contents of About()
  23.User inputs 7 at main menu (They are done with their list)
*/


#include "SongClasses.cpp"
#include<iostream>

using namespace std;

//Self-explanatory functions
int Greeting();
int MainMenu();
void About();
       

int main()
{
    cout.setf(ios::fixed, ios::floatfield); //Setting values to display money.
    cout.precision(2);
    cout.setf(ios::showpoint);
    
    Greeting();
    MainMenu();

return 0;
}

int Greeting()
{
  cout <<"\n\n                          WELCOME TO D.A.D.S. v2.0" << endl
       <<"                   (Dynamically Allocated Database of Songs)\n";
  
  return 0;
}

int MainMenu()          //Where my library of SongFiles is created.
{
 int menuchoice;       
 
 List songlist;        //Declaring an object 'songlist' for database.
 
 
 do{                   //Do-While loop used to cycle the main menu
 cout << "\n\n                      What can D.A.D.S. do for you today?\n\n"
      << "                          1. Enter a new song\n"
      << "                          2. Display all songs\n"
      << "                          3. Delete a song\n"
      << "                          4. Lookup List Item\n"
      << "                          5. Size of List\n"
      << "                          6. About\n"
      << "                          7. Quit\n\n"
      << "                          Please choose a number:  "; 
      cin >> menuchoice; cin.ignore(100, '\n');
      
      switch (menuchoice)
            { 
             case 1:
      
                   
                  cout << "\nWould you like to insert at the beginning or end?\n"
                       << "1.Beginning\n2.End\n"
                       << "What is your choice:";
                  int subchoice;
                  cin  >> subchoice; cin.ignore(100,'\n');
                  
                  if(subchoice == 1)
                  {
                  songlist.Input(); 
                  break; 
                  }
                  
                  if(subchoice == 2)
                  {
                  songlist.Append(); 
                  break;                          //Input function called
                  }
                  
                  else
                  {
                  cout << "Please choose 1 or 2.";
                  break;
                  }
                  
             case 2:
                  songlist.Display();             //Display function called
                  break;
             case 3:
                  int subchoice2;
                  cout << "\nWould you like to delete the first or last record?\n"
                       << "\n1.First\n2.Last\n";
                  cin  >> subchoice2; cin.ignore(100, '\n');
                  
                  if (subchoice == 1)
                  {
                    songlist.RemoveFirstEntry();
                    break;
                    }
                    
                  if (subchoice == 2)
                  {
                     songlist.RemoveLastEntry();
                     break;
                   }
                   
                   else
                   cout << "Please choose 1 or 2"; 
                   break;
            
             case 4:
                  char searchforthis[25];   
                  cout << "\nPlease provide either a title, media type,"
                       << "or artist: ";
                  cin  >> searchforthis; cin.ignore(100, '\n');
                  songlist.Search(searchforthis);      //Search function called
                  break;
             case 5:
                  songlist.SizeofLLL();                //About function called
                  break;
             case 6:
                  About();
                  break;
             default:
                  cout << "\nPlease enter 1,2,3,4, or 5!";
                  break;
                               
             }
}while (menuchoice != 7); 

return 0;
 
}
    

void About()
{
     cout << "\n\n"
          << "***NOW FEATURING LINEAR LINKED LISTS!!!***\n"
          << "This program was made for Karla Fant's CS 162 assignment.\n"
          << "It serves as an example of dynamically allocated memory,\n"
          << "and allows user's to keep track of mp3 file information.\n"
          << "Thank you for using!!!\n\n\n"
          << "                              --Brandon Lee Jennings";
}
