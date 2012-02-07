# include <iostream>
using namespace std;

int main ()

{
 int a,b,c; 
 float num1, num2, total;
 bool d, e = false;
 
 do 

{
   
 cout << "**********************************" << endl
      << "*  Brandon's Cordial Calculator  *" << endl  
      << "**********************************" << endl << endl
      << "1. + " << endl
      << "2. - " << endl
      << "3. * " << endl
      << "4. / " << endl
      << "5. Continue working with previous total" << endl
      << "6. Quit" << endl << endl 
      << "Please the operation you'd like to perform today: ";
      
 cin >> a; cout << endl << endl;
 
} while (a < 1 || a > 6);
if ( a == 6)
{
     
     }
else
 switch (a)
   {
      case 1:
           cout << "Please enter the first number:  ";
           cin >> num1;
           cout << "Please enter the second number: ";
           cin >> num2;
           total = num1 + num2; 
           cout << "Your result is: " << num1 << "+" << num2 << "=" << total << endl << endl;
           would you l
           break;     
      
      case 2:
           cout << "Please enter the first number:  "; 
           cin >> num1; 
           cout << "Please enter the second number: ";
           cin >> num2;
           total = num1 + num2;
           cout << "Your result is: " << num1 << "-" << num2 << "=" << total << endl << endl;
           break;
                
       case 3:
           cout << "Please enter the first number:  "; 
           cin >> num1; 
           cout << "Please enter the second number: ";
           cin >> num2;
           total = num1 * num2;
           cout << "Your result is: " << num1 << "*" << num2 << "=" << total << endl << endl;          
           break;
           
           }      
     
        

 

return 0;

}
         
           
