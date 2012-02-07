#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define MAX 100

/*Struct of charges*/
typedef struct fieldCharge
        {
          int k;
          float Qk;
          float X, Y, Z;       
        } fieldCharge;

//Using struct for ease of passing variable between functions
//Notice the array of 100 charges for the field data
typedef struct dataFileInfo
        {

            /*Array of Structs*/
            fieldCharge charges[MAX];

            /*General File Pointer*/
            FILE * file;
            char fileName[50];
            int fileSize;
            
            /*Counters*/
            int colCounter;
            int rowCounter;     
            
        } dataFile;
        

/*The Four Functions Used To Get The Job Done*/
int getDataFileInfo(dataFile * data);
int printCharges(dataFile * data);
int getUserDefinedCharges(dataFile * data);


int main ()
{
  //Declare an instance of all the data we're going to be working with
  //This includes the 50 structs
  dataFile data;

  getDataFileInfo(&data);
  
  printCharges(&data);
  
  getUserDefinedCharges(&data);
  
  doFieldChargeCalculations(&data);
  
  system("PAUSE");
  return 0;
}

/*This gets the file name and parses the file into an array of structs*/
int getDataFileInfo(dataFile * data)
{
	int goforth = 0;

    //Prompt the user for input
	while(goforth == 0)
	{
	printf("Please enter the file you'd like to use:");
	scanf("%s", &data->fileName);
	data->file = fopen(data->fileName,"r");

	if(data->file == NULL)
	{
	  printf("Sorry we couldn't find that file\n");
	}
	   else
	   {
		goforth = 1;
	   }
	}

   data->rowCounter = 0;
   char c;
      
   do
   {
      //Get Qk value
      fscanf(data->file,"%f", &data->charges[data->rowCounter].Qk);
      //Get X value
      fscanf(data->file,"%f", &data->charges[data->rowCounter].X);
      //Get Y value
      fscanf(data->file,"%f", &data->charges[data->rowCounter].Y);
      //Get Z value
      fscanf(data->file,"%f", &data->charges[data->rowCounter].Z);
      
      data->rowCounter++;
      
    //Have to check to see if EOF has been reached since fscanf ignores such things  
   }while(c = getc(data->file)!=EOF);
   

	  return 0;
}

//Nicely prints the values of the charges.
int printCharges(dataFile * data)
{
  
   int count = 0;
   while(count < data->rowCounter)
   {
    printf("Q=%lf P=(%lf,%lf,%lf)\n", data->charges[count].Qk, data->charges[count].X,data->charges[count].Y,data->charges[count].Z);
    count++;
   }
   
   return 0;
}

//Accepts user defined input
int getUserDefinedCharges(dataFile * data)
{
    double x, y, z;
    
    printf("\nPlease enter an X coordinate:");
	scanf("%lf", &x);    
	
	printf("\nPlease enter a Y coordinate:");
	scanf("%lf", &y); 
	
	printf("\nPlease enter a X coordinate:");
	scanf("%lf", &z); 
	
	return 0;
}

int doFieldChargeCalculations(dataFile * data)
{
   printf("\nInsert Field Charge Calculations Here (I'm a programmer not a Mathematician)\n");                     
}


