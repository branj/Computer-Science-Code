/* Brandon Jennings
   branj@pdx.edu
   CS 162 (online class)
   Program #1
   Due Date: Jan. 5th 2010
   
   PURPOSE:
   This program takes some number 'x' and some number 'y' then allows simple 
   calculations using simple operators (+,-,*,/). All in three steps! 
   The user then has the option to work with their answer as a running total.
   This program is also protected against division by 0.
   
   ALGORITHM:
   1. Output the Running Total along with Main Menu options.
   2. User inputs their choice. (Choosing '1' starts a new calculation) 
   3. Output directions and prompt for number x.
   4. User inputs number x. 
   5. Output a prompt for the user to enter an operator (+,-,*,/).
   6. User inputs an operator.
   7. Output a prompt for the user to enter number y.
   8. User inputs number y.
   9. Output the equation user has entered and ask if it is correct.
   10. User inputs 'y' or 'n' (If 'n' then steps 3 - 10 are repeated).
   11. Computer does calculation of user input. 
   12. Output the total from the calculation. 
   13. Repeat steps 1 and 2. 
   14. (User can now use running total) User inputs choice 2. 
   15. Output running total.
   16. Repeat steps 5 - 13. 
   17. Choosing 3 from the main menu resets the Running Total. 
   18. Choosing 4 from the main menu outputs information about the program. 
   19. Choosing 5 exits the program. 
*/

#include <iostream>	
using namespace std;

int main ()

{

int choice;                       // This is for the user's main menu choice.
float num1, num2, total = 0;      // Numbers for user calculations and total.                                               
char c,d;                         // To hold the operator for calculations
bool  g = false;                  // To ensure data entered during if statements 
                                  // is valid. 
                                  
// Program starts with a do-while statement to ensure it continues as long the
// user's choice isn't 5. 
do 
{ 
    cout << "\n\nRUNNING TOTAL: " <<"[" << total << "]\n\n"
         << "1. New Calculation" << endl
         << "2. Work with the Running Total: " << total << endl
         << "3. Reset the Running Total" << endl
         << "4. About Me"  << endl 
         << "5. Quit\n\n"
         << "Please pick a Number:  ";
    cin  >>  choice;
    cout << endl << endl;
    
    //Switch statement employed to carry out the 5 different menu choices. 
    //Thus 5 cases for this switch statment.
    switch (choice)
    {    
		//This case peforms a new calculation.
		case 1:
			
			//Do-while statment employed to ensure data is entered correctly.
            //Once bool variable "g" equals "True" loop is closed.  
			do 
			{   
			cout << "Follow the steps to complete your calculation.\n\n"; 
            cout << "STEP 1: Enter a number: "; cin >> num1;              
            cout << "STEP 2: Enter an operator (+,-,*,/): "; cin >> c;
            cout << "STEP 3: Enter another number: "; cin >> num2; 
            cout << "\nYou entered " << num1 << " " << c << " " << num2 << endl
            << "\nShall I peform the calculation? (Press Y/N): "; cin >> d; 
                     
                     
                //If function used to give user a chance to verfify their input
                //in the form of "y" or "no." Thus the argument "d='y'".
				if ( d == 'Y' || d == 'y')
				{
                     
					//Switch function used to check contents of the variable
                    //"c." There are 4 cases (+,-,*,/) and each one calculates
                    //num1 and num2 to find a total then evaluates g to true so 
                    //the program can exit the previous do while. 
					switch (c)
                          {
                          case '+':
                               total = num1 + num2; 
                               cout << "\nANSWER: "<< total << endl; 
                               g = true; 
                               break; 
                          case '-':
                               total = num1 - num2; 
                               cout << "\nANSWER: "<< total << endl; 
                               g = true;
                               break;
                          case '*':
                               total = num1 * num2; 
                               cout << "\nANSWER: "<< total << endl; 
                               g = true; 
                               break;
                          case '/':
						       
							    // If-else function is used to check against 
							    // division by zero. If num2 is 0 program 
							    // outputs "INVALID FUNCTION" and prompts user 
							    // for num2 again. Else  performs calculation 
							    // and outputs the answer. 
								if ( num2 == 0 )
                                {
						          cout << "\n !!!INVALID FUNCTION!!!.\n"
							         << "(Division with 0 prohibited)\n"; 
						          g = false; 
						          break;
                                }
                                
								else 
						        {
                                 total = num1 / num2; 
                                 cout << "\nANSWER: "<< total << endl; 
                                 g = true; 
                                 break;
                                 }
                          default:
                                  cout << "\n!!!INVALID DATA SUBMISSION!!!.\n" 
                                       << num1 << " " << c << " " << num2 
                                       << "\n\nPlease Try Again.\n\n";
                                  g = false;
                                  break;
                          }
                    } 
                    
				
				//As mentioned earlier, this else function is used along with 
				//the if function that prompts the user to check their data 
                //submission. This evaluates g to false so the do while statment 
                //continues to loop and the user can input their data again.  
				else if (d == 'N' || d == 'n')
                         {
                          g = false;
                         }          
         
			
			// This is part of the do while statement beginning right after case
			//1. As long g = false the user will be able to input their data. 
			//Basically this loop is used to ensure proper data input. 
			} while( g == false );   
			  cout << endl;
              break;      
   
    //This case does a calculation using the running runnning total.               
    case 2:
         //Much like the do while function in case 1 this do while statment is 
         //used to ensure proper data input. If data is invalid it allows the 
         //user a second chance to enter it. 
         do 
		 {
         cout << "\nThe RUNNING TOTAL is: " << total;
         cout << "\nPlease choose an OPERATOR (+,-,*,/): "; 
         cin >> c;    
         cout << "Please enter NUMBER 2: ";
		 cin  >> num2; 
		 cout << "\nYou entered " << total << " " << c << " " << num2 
              << "\n\nShall I perform the calculation? (Press Y/N) "; 
         cin >> d;
         cout << endl << endl;
    
                     
			    //If function used to give user a chance to verfify their input
                //in the form of "y" or "no." Thus the argument "d='y'".
					 if ( d == 'Y' || d == 'y')
					 {
                          
						 //Switch function used to check contents of the variable
                         //"c." There are 4 cases (+,-,*,/) and each one calculates
                         //num1 and num2 to find a total then evaluates g to true so 
                         //the program can exit the previous do while loop. 
						 switch (c)
                                 {
                                 case '+':
                                      total += num2; 
                                      cout << "\nANSWER: n"<< total << endl;  
                                      g = true; 
                                      break; 
                                 
								 case '-':
                                      total -=  num2; 
                                      cout << "\nANSWER: "<< total << endl; 
                                      g = true;
                                      break;
                                 
								 case '*':
                                      total *= num2; 
                                      cout << "\nANSWER: "<< total << endl; 
                                      g = true; 
                                      break;
                                 
								 case '/':
                                      
									  //If-else function used to protect agains
									  //division by 0. 
									  if ( num2 == 0 )
									  {
						              cout <<"\nDividing with 0 is INVALID.\n\n";
                                      g = false;
						              break;
									  }
									  
                                      else 
									  {
						              total /= num2; 
                                      cout << "ANSWER: "<< total << endl; 
						              g = true; 
						              break;
									  }
                                 
								 default:
                                      cout << "INVALID INPUT!!!" << endl;
                                      g = false;
                                      break;
                                 }        
                       
					 } 
                   
				//As mentioned earlier, this else function is used along with 
				//the if function that prompts the user to check their data 
                //submission. This evaluates g to false so the do while statment 
                //continues to loop and the user can input their data again. 
					else  if ( d == 'n' || d == 'N')
							  {
                              g = false;
							  }
                        
					
     
		 
		 // This is part of the do while statement beginning right after case
		 //2. As long g = false the user will be able to input their data. 
		 //Basically this loop is used to ensure proper data input. 
		 } while (g == false);
         cout << endl;
         break;
                              
    
	//This case resets the running total to 0. 
	case 3:     
		 {
          total = 0;
          break;
         }
    //This gives a brief "About Me" kinda thing.
	case 4:
		{
		cout <<"This program is maintained by Jinks the cordial calculator.\n"
             <<"It performs simple mathmatic functions for those with simple\n"
             <<"needs\n\n"
             <<"It's creator is Brandon Lee Jennings. A benevolent scientist\n"
	         <<"whose works include 'Brain Bust' and 'Bug Dig: Super Dig Bugs'"
	         <<"\n\nAny feed back is welcomed. So please let me know at:\n\n"
	         <<"                branj@pdx.edu.\n\n";
        
         break;
         }              
    //This case ends the program. 
	case 5:
         {
         cout << "Thanks for using the calculator.";
         break; 
         }
    //This case protects agains invalid data. 
	default:
         cout << "1-5 ARE THE ONLY VALID CHOICES!!!\n\n"; 
         
     }


//Part of the first do while statment of the program. It is constantly checking 
//to see if choice isn't 5 so the user can continue using the program until 
//they want to quit and input 5 for choice. 
} while ( choice != 5 || choice < 1 || choice > 5); 



return 0;
}
         
