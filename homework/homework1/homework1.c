/*Seanmichael Stanley*/
/*sts44b*/
/*Homework 1*/

#include <stdio.h>/*reference library of functions*/

/*prototypes for program functions for error checking user entries and returning tax rates*/
int income_check(int x);
int check_selection(int y);
float tax_rate1(int z);
float tax_rate2(int z);
float tax_rate3(int z);


int main()/*begin main*/
{
   /*declare variables for user etries and calculating net income and taxes paid*/ 
   int s;
   int inc;
   float rate;
   float net;
   float tax;

   do
   {/*begin loop to keep accepting entries for calculating tax rate until user chooses to quit*/

	/*promt user to choose from a menu*/
	printf("\nFiling Status\n(1)Single\n(2)Married\n(3)Head of Household\n(0)Quit Program\nPlease make selection: ");
	scanf("%d", &s);/*assign users choice*/

	   while (check_selection(s) == 0)/*check that user made a valid choice*/
     	   {
	   printf("\nInvalid choice. Please make a selection:");
	   scanf("%d", &s);
	   }
   
	if (s == 0)
	   return 0;/*end program if user enters 0*/
   

	printf("\nEnter your annual income: ");/*prompt user to enter income*/
	scanf("%d", &inc);

	   while (income_check(inc)==0)/*make sure user entered a positve income amount*/
	   {
		printf("\nIncome must be positive. Please enter your income: ");
		scanf("%d", &inc);
	   }

	switch (s)
	{/*switch to send and recieve values from the correct function*/

      		case 1:
         	   rate =  tax_rate1(inc);/*go with single tax function*/
         	   break;

     		case 2:
        	   rate = tax_rate2(inc);/*go to married tax function*/
         	   break;

      		case 3:
         	   rate = tax_rate3(inc);/*go to head of household income*/
         	   break;
  
      		default:/*just in case something weird happens*/
         	   return 0;
         	   break;
  	 }

   	net = (float) inc - (inc * rate) / 100;/*calculate net income*/
   
   	tax = (float) (inc * rate) / 100;/*calculate tax paid*/

   	printf("\nYour tax rate is: %.0f%%", rate);/*display tax rate*/
   	printf("\nYou pay $%.2f in taxes.", tax);/*display amount of taxes paid*/
  	 printf("\nAfter taxes your net income is: $%.2f\n", net);/*display net income*/

   }while (s != 0);/*keep looping until the user quits*/

return 0;
}/*end main*/

/*function to check that the user made a valid selection from the list*/
int check_selection(int y)
{
   if (y < 0 || y >3)
      return 0;
   else
      return 1;
}

/*function to make sure user entered a positve income amount*/
int income_check(int y)
{
   if (y >= 0)
      return 1;
   else
      return 0;
}

/*function to return correct single tax rate*/
float tax_rate1(int z)
{
   if (z <= 20000)
      return 10;
   else if (z > 20000 && z <= 50000)
      return 20;
   else if (z > 50000 && z <= 100000)
      return 30;
   else if (z > 100000 && z <= 250000)
      return 35;
   else 
      return 40;
}

/*function to return the correct married tax rate*/
float tax_rate2(int z)
{
   if (z <= 30000)
      return 10;
   else if (z > 30000 && z <= 60000)
      return 20;
   else if (z > 60000 && z <= 125000)
      return 30;
   else if (z < 125000 && z <= 300000)
      return 35;
   else 
      return 40;
}

/*function to return the correct head of house tax rate*/
float tax_rate3(int z)
{
   if (z <= 50000)
      return 10;
   else if (z > 50000 && z <= 100000)
      return 20;
   else if (z > 100000 && z <= 250000)
      return 30;
   else if (z > 250000 && z <= 500000)
      return 35;
   else
      return 40;
}
/*end of program*/
