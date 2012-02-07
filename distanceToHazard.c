/*
Brandon Jennings
Homework #2
ECE 103
Wong

This program determines the distance of a ship to a hazard given two angles of a 
telescope. It utilized the math function, namely the sin, pow, and sqrt functions
to figure out what it needs to figure out.
*/
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main()
{
  /*Variables*/
  double angleA;
  double angleB;
  double angleC;
  double angleD;
  double angleE;
  double sideB;
  double shipXlocation;
  double shipYlocation;
  double hazardX = 0.73;
  double hazardY = 0.38;
  double distanceToHazard;
  int goOn = 0;
  
  /*Greeting and Collecting User Input*/
  printf("Danger! Danger! A ship is approaching and a collision is iminent!\n\n");
  
  while(goOn == 0)
  {
  printf("Quickly, enter the first telescope angle: ");
  scanf("%lf", &angleA);
     if(angleA > 90)
     {
       printf("That's too big a number! Are you trying to kill them!?\n");
     }
     else
     {
       goOn = 1;
     }
  }
  
  goOn = 0;
  
  while(goOn==0) 
  {
  printf("Oh, dear I hope not all is lost! Enter the second telescope angle: ");
  scanf("%lf", &angleB);
  
     if(angleB > 90)
     {
       printf("That's too big a number! Are you trying to kill them?\n");
     }
     else
     {
       goOn = 1;
     }        
  }
  
  /*Finding the angle of the ship's location*/
  angleC = 180 - (angleA + angleB);
  
  /*Finding the distance from first telescope to ship*/
  sideB = 1.75 * sin(angleB*PI/180)/sin(angleC*PI/180);
  
  /*Doing calculations to find ship's coordinates*/
  angleD = 90 - angleA;
  angleE = 180 - (90 + angleD);
  shipXlocation = sideB * sin(angleD*PI/180)/1;
  shipYlocation = shipXlocation * sin(angleE*PI/180)/sin(angleD*PI/180);
  printf("\nThis ship's coordinates are: %lf Km, %lf Km\n", shipXlocation, shipYlocation);
  
  /*Doing calculations to find ship's distance to hazard
    Basically using the standard calculation to determine distance
    Between two sets of coordinates*/ 
  distanceToHazard = sqrt(pow(shipXlocation - hazardX, 2) + pow(shipYlocation - hazardY,2));
  
  printf("\nThe ship's distance to the hazard is: %lf Km\n\nI think we got to them in time :)", distanceToHazard);
  scanf("%lf",angleD);
  
  
  
  
}
