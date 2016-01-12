/*
CS 1050 Lab 1
Seanmichael Stanley
sts44b
Labcode:050613 
*/


#include<stdio.h> /*access library for funtions*/

int main()/*begin main function*/
{
   double r,h;/*declare variables for radius and height as integers*/
   float v;/*declare the variable for volume as a decimal*/
   
   printf("Enter the radius of the cone: "); /*prompt user to enter the cone radius*/
   scanf("%lf", &r); /*assign a value to the radius variable*/

   while (r<=0)/*check to see if r is positive*/
   {
	   printf("Radius must positive. \n");/*prompt user if radius is negative*/
	   printf("Enter the radius of the cone: ");
	   scanf("%lf", &r);/*assign positive value to the radius variable*/
   }
   

   printf("Enter the height of the cone: ");/*promt user for the height of the cone*/
   scanf("%lf", &h);/*assign a value to the height variable*/

   while (h<=0)/*check to see if height is positive*/
   {
	   printf("Height must be positive. \n");/*promt user if height is negative*/
	   printf("Enter the height of the cone: ");
	   scanf("%lf", &h);/*assign a positive value to height*/
   }

  
   v = 3.14 * r * r * h;/*calculate the volume*/

 
   printf("The volume of the cone is: %.2f\n", v);/*display the volume of the cone*/


return 0;/*end the function*/
}


    
