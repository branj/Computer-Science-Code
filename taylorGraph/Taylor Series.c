/*
Brandon Jennings
ECE 103
Wong
Homework 4

Purpose: 
         This program accepts two agruments (x and the order of expansion N) and displays
         the result of sinc(x) vin the sin() function provided by the math.h library, 
         it then calculates it's Taylor Series equivilant.

*/


#include <stdio.h>
#include <math.h>

const int ARGX_MAX_LOW = -50.00;
const int ARGX_MAX_HIGH = 50.00;
const int N_MAX_LOW = 0;
const int N_MAX_HIGH = 1000;

double calcSinC(double x);
double calcTaylor(double argX, double orderN);
double findFactorialOf(double someNumber);

int main(void)
{
    
 double argX = 0;
 double orderN = 0;
 double sinC = 0;
 int checkout = 0;
     
     while(checkout == 0)
     {
      printf ("Please enter argument x:");
      scanf("%lf", &argX);
      
      //Make sure user input is within range
      if(argX >= ARGX_MAX_LOW & argX <= ARGX_MAX_HIGH) 
      {
              checkout = 1;
      }
      //Print number if out of range
      else
      {
          printf("***Please enter a number between -50.00 and 50.00***\n");
      }
     
     }
     
     checkout = 0;
     
     while(checkout == 0)
     {
       printf ("Please enter the order N:");
       scanf("%lf", &orderN);  
                  
       //Make sure user input is OK
       if( orderN >= N_MAX_LOW & orderN <= N_MAX_HIGH)
       { 
           checkout = 1;
       } 
       //Print error if number is out of range
       else
       {
          printf("***Please enter a number between 0 and 1000***\n");
       }
      
     }
    
    //Display initial value of sinc
    printf("\nThe math.h value is: %lf\n",calcSinC(argX));
    
    //Calling the functions nescarry to display calculations then displaying its value 
    printf("The Taylor Series value is: %lf for N = %f", calcTaylor(argX, orderN),orderN);
    printf("\n\nThank You and have a nice day :)");
    scanf("%d",orderN);
 
 return 0;
    
}

//Calculates sinc given argument x
double calcSinC(double x)
{ 
   double sinC = 0;
   
   sinC = sin(x)/x;
   
   return sinC;
   
}

//Calculates the Taylor series for a given sine and the order N
double calcTaylor(double argX, double orderN)
{
   double count = 0;
   double sinOfArgX = 0;
   double sinC = 0;
   
   while(count <= orderN)
   { 
      /*This is the meat and potatoes of the program: it is essentially the Taylor series equation*/
      sinOfArgX = sinOfArgX + ((pow(-1, count) * pow( argX , 2 * count + 1))/findFactorialOf(2 * count + 1));
      count = count + 1;     
   }
   
   //Since I already know the sinOfArgX there's no need to call the calcSinc 
   //function here, so will just divide the result by 2 and we have the Taylor 
   //series expansion.
   sinC = sinOfArgX/argX;
   return sinC;
}

//Returns the result of the given factorial
double findFactorialOf(double factorial)
{
       int count = 1;
       double result  = 1; 

       while(count <= factorial)
       {
        result = result * count;
        count++; 
       }
       
       return result;
}



