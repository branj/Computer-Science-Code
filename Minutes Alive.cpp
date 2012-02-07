#include <iostream>
using namespace std;

void minute_calc (int &);

int main ()
{
  int age;
  int minutes_alive;
  
  cout <<"Ever wondered how many minutes old are you?"
       <<"\nUse this program to see how!!!\n\n"
       <<"Please enter your age here:  ";
  
  cin  >> age; 
  
  minute_calc(age);
  cout << "You've been on this Earth for "<< age << " minutes!!!";
  cin >> age;
  return 0;
 
}

void minute_calc (int& a) 
{   
    
    a = a * 60 * 24 * 365;
     
}    
