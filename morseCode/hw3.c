/*
Brandon Jennings
ECE 103
Wong
HW3

Purpose: 

This program takes a Morse Code file through indirect input and outputs the decoded message to the screen. 
It does so by reading the the stream of . and - and converting them to ASCII values which is mapped to it's 
corresponding letter via the decode() function.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//A massive switch statement with ASCII codes of the various combinatios of . or - and their subsecquet letter.
void decoder(unsigned long int decodethis);

int main()
{
 unsigned long int total;
 char morse[50] = {0};
 char buffer[50] = {0};
 char c;

 /*DEBUGINFO - 
 So far everything has worked out as I had planned, however, two problems persists: 
 1. I keep exiting the while loop before the final character is displayed to the screen. 
    a. Thinking about this, it is because the file reaches EOF before the final newline. I just added another
	   call to decode with what was left in morse after the while loop. (*fixed*)
 2. For some reason any morse code string of more than 4 characters won't convert to the ASCII code properly.
    a. For the default value in the switch statement I print decodethis. Keep getting the same number 2147483647:(
	b. Thought maybe the plain int wasn't big enough, tried long int but problem persists. 
	c. I found that I was reaching the maximum value for an int, so I tried using an unsigned long int, and dividing the total by 2
	   but that didn't seem to help. Oh well, I have to turn in:(
 */

 //This reads in a char changes it back to a char and concatonates into a morse until new line is reachesd...
 while((c = getchar())!=EOF)
 {
	//Grabbing current char converting it to a string and adding it to the morse code string
	if(c != '\n')
	{
		itoa(c,buffer,10);
		strcat(morse, buffer);
	}

	//Once newline is reached it converts the string into it's ASCII equivilant,
	//which is then passed as the 'key' if you well to the massive switch statement 
	//contained in the decoder() function.
	else
	{	
		total = atoi(morse);
		decoder(total/20);
		morse[0]=0;
		buffer[0]=0;
	}
  
 
 }
  //Call the last letter...while loop exits before last code can be called. 
  total = atoi(morse);
  decoder(total/20);

  return 0;
  
}

//This takes the ASCII code and determines which letter to print.
void decoder(decodethis)
{

switch(decodethis)
{

case 4645/20:
printf("A");
break;

case 45464646/20:
printf("B");
break;

case 45464546/20:
printf("C");
break;

case 454646/20:
printf("D");
break;

case 46/20:
printf("E");
break;

case 46464546/20:
printf("F");
break;

case 454546/20:
printf("G");
break;

case 46464646/20:
printf("H");
break;

case 4646/20:
printf("I");
break;

case 46454545/20:
printf("J");
break;

case 454645/20:
printf("K");
break;

case 46454646/20:
printf("L");
break;

case 4545/20:
printf("M");
break;

case 4546/20:
printf("N");
break;

case 454545/20:
printf("O");
break;

case 46454546/20:
printf("P");
break;

case 45454645/20:
printf("Q");
break;

case 464546/20:
printf("R");
break;

case 464646/20:
printf("S");
break;

case 45/20:
printf("T");
break;

case 464645/20:
printf("U");
break;

case 46464645/20:
printf("V");
break;

case 464545/20:
printf("W");
break;

case 45464645/20:
printf("X");
break;

case 45464545/20:
printf("Y");
break;

case 45454646/20:
printf("Z");
break;

case 4545454545/20:
printf("0");
break;

case 4645454545/20:
printf("1");
break;

case 4646454545/20:
printf("2");
break;

case 4646464545/20:
printf("3");
break;

case 4646464645/20:
printf("4");
break;

case 4646464646/20:
printf("5");
break;

case 4546464646/20:
printf("6");
break;

case 4545464646/20:
printf("7");
break;

case 4545454646/20:
printf("8");
break;

case 4545454546/20:
printf("9");
break;

case 464546454645/20:
printf(".");
break;

case 454546464545/20:
printf(",");
break;

case 464645454646/20:
printf("?");
break;

default:
	printf(" ");
break;

}

}