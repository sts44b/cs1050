/*Seanmichael Stanley*/
/*sts44b*/
/*08375210*/
/*Labcode: */
/*LAB 5: 13032013*/


/*reference function libraries necessary for this program*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100

/*function prototypes for this program*/
int check_error(int);
void initialize_array(int a[MAX], int);
void print_array(int a[MAX], int);
int common_numbers(int, int);
int mode(int a[MAX], int);
void print_histogram(int, int);

/*global arrays*/
int array1[MAX];
int array2[MAX];

int main()/*begin function main*/
{
   /*declare variables for function main*/
   int num1;
   int num2;
   int common;
   int mode1;
   int mode2;

   srand(time(NULL));/*randomize function rand*/

   printf("Enter the size of the first array (between 1 and 100): ");/*prompt user for size of first array*/
   scanf("%d", &num1);

   while (check_error(num1) == 0)/*check for valid input*/
   {
		   printf("\nInvalid input enter the size of the array again: ");
		   scanf("%d", &num1);
   }

   initialize_array(array1, num1);/*initalize array1*/

   printf("Enter the size of the second array (between 1 and 100): ");/*prompt user for the size of the second array*/
   scanf("%d", &num2);

   while (check_error(num2) == 0)/*check for a valid enter*/
   {
      printf("\nInvalid input enter the size of the input again: ");
      scanf("%d", &num2);
   }
 
   initialize_array(array2, num2);/*initailize array 2*/

   printf("\nInput for array1\n");/*display araay1*/
   print_array(array1, num1);
   printf("\nInput for array2\n");/*display array2*/
   print_array(array2, num2);

   common = common_numbers(num1, num2);/*find common numbers*/
   
   if (common > 0)/*display the dumber of common numbers*/
      printf("\n\nThere are %d common numbers between the two arrays.", common);
   else
      printf("\n\nThere are no common numbers between the arrays.");

   mode1 = mode(array1, num1);/*find mode of array1*/
   
   if (mode1 == -1)
      printf("\nAll numbers are unique in this array");
   else
      printf("\nMode for the first array is number %d", mode1);

   mode2 = mode(array2, num2);/*find mode of array2*/

   if (mode2 == -1)
      printf("\nAll numbers are unique in this array");
   else
      printf("\nMode for the second array is number %d", mode2);
  
   print_histogram(num1, num2);/*print a histogram*/

}/*end function main*/

/*function to check for a valid input from user*/
int check_error(int y)
{
   if (y >= 0 && y <= 100)
      return 1;
   else
      return 0;
}/*end function check_error*/

/*function to initalize arrays with random numbers*/
void initialize_array(int a[], int size)
{
   int i;

   for (i = 0; i <= (size - 1); i++)
   {
      a[i] = ( rand() % 10);
   }
}

/*function to print arrays*/
void print_array(int a[], int size)
{
   int i;

   for (i = 0; i <= (size - 1); i++)
   {
      printf("%d ", a[i]);
   }
}

/*function to find common numbers*/
int common_numbers(int x, int z)
{
   int i, j;    
   int counter = 0;

   for (i = 0; i < x; i++)
   {
      for (j = 0; j < z; j++)
      {
         if (array1[i] == array2[j])
            ++counter;
      }
   }
return counter;
}

/*function to find the mode of an array*/
int mode(int a[], int size)
{
   int i;
   int  count[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
   int num;
   int highest = 0;
   int modeNum = 0;

   for (i = 0; i < size; i++)
   {
      ++count[ a [ i ] ];
   }

   for (num = 0; num <= 9; num++)
   {
      if (count[num] > highest)
      {
         highest = count[num];
         modeNum = num;
      }
   }
   if (highest == 1)
      return -1;
   else
      return modeNum;
}

/*function to print a histogram*/
void print_histogram(int a, int b)
{
   int i;
   int j;
   int k;
   int l;
   int num[10]; 

   for (i = 0; i < a; i++)
      ++num[array1[i]];
   for (j = 0; j < b; j++)
      ++num[array2[j]];

   printf("\n\nPrinting histogram");

   for (k = 0; k < 10; k++)
   {
      printf("\n%d:",k);
      for (l = 1; l < num[k]; l++)
         printf("*");
   }
}
