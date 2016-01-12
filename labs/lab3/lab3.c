/*Seanmichael Stanley*/
/*sts44b*/
/*Labcode: 190613*/

/*Multi function program to compute exponents and compond interest*/
#include <stdio.h>/*reference function library*/

/*function protocols*/
int check_number(float y);
int check_exponent(int z);
float compute_power(float x, int n);

/*begin main*/
int main()
{
/*declare variables for holding values to calculate exponents and interest*/
	float x;
	int exp;
	float pow;
	float amtc;
	float amt ;
	float rate;
	int year;
	float interest;

	printf("Enter a number: ");/*prompt user to enter a number*/
	scanf("%f", &x);/*assign the number to a variable*/

	while (check_number(x) == 0)/*check to make sure number is within the correct range*/
	{
		printf("Invalid. Enter a number from -100 to 100: ");
		scanf("%f", &x);
	}

	printf("Enter the exponent: ");/*prompt the user to enter an exponent*/
    scanf("%d", &exp);  
   
	while (check_exponent(exp) == 0)/*check to make sure the user entered a valid exponent*/
	{
		printf("invalid. Enter an exponent between -5 and 5: ");
		scanf("%d", &exp);
	}

	pow = compute_power(x, exp);/*send values to compute_power function to calculate exponent*/

   printf("\nPow(%.2f,%d) is %.2f\n", x, exp, pow);/*display results of the calculation*/

   printf("Enter a dollar amount: ");/*prompt user to enter a dollar amount*/
    scanf("%f", &amt);
   printf("Enter an interest rate: ");/*prompt user to enter an interest rate*/
    scanf("%f", &rate);
   printf("Enter the the number of years: ");/*prompt user to enter the number of years of compound interest*/
    scanf("%d", &year);

  
   amtc = amt * compute_power(1+rate/100,year);/*calculate the amound after compound interest*/
   interest = amtc - amt;/*calculate the amount of interest earned*/

   /*display the results of the calculations for interest*/
   printf("\n\nInterest earned on $%.2f at a rate of %.3f%% after %d years is $%.2f.\n", amt, rate, year, interest);


return 0;
}   /*end main*/

int check_number(float y) /*function to check that the value entered by the user is between -100 and 100*/
{
   if (y >= -100 && y <= 100)
      return 1;
   else
      return 0;
}/*end check number*/

int check_exponent(int z) /*function to check that the value entered by the user is between -5 and 5*/
{
   if (z >= -5 && z <= 5)
      return 1;
   else
      return 0;
}/*end check_exponent*/

float compute_power(float x, int n)/*function to calulate exponents*/
{
    int counter;
    int z;
    float num = 1;

	 if(n == 0)/*any number raised to the 0 power is 1*/
   	{	
		   return 1;
	}
   else
   {
	if (n < 0)
	 z = -n;/*make z positive for the exponent calculation*/

	else
	z=n;
	
	for (counter = 1; counter <= z; ++counter)/*part of the function that acutally calculates the exponent*/
	{ num = num *  x;  
 	}

     
    if (n < 0)
      return 1 / num;
   else
      return num;
   }
}/*end calculate_power*/



