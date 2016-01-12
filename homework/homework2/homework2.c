/*Seanmichael Stanley*/
/*sts44b*/
/*08375210*/
/*Homework2*/

/*reference function libraries for this program*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*function prototypes for this program*/
int error_check(int);
void initializeArray(int);
void displayMenu();
int max(int);
int min(int);
float average(int);
int search(int, int);
void computeStats(int);
void replace(int num, int i);
int countNumber(int, int);
void printArray(int);

/*global array*/
int array1[20];

/*program to handle an array and povide various info about it*/
int main()
{
   /*declare the variables to be used in function main*/
   int choice = 0;
   int size;
   int num;
   int numx;
   int index;
   int new;

   printf("Enter the size of the input: ");/*prompt the user to enter the array size*/
   scanf("%d", &size);/*assign the array size to the variable size*/

   while (error_check(size) == 0)/*check to make sure user entered a valid araay size and loop input request until a valid input is entered*/
   {
      printf("Invalid input, enter the size of the input again: ");
      scanf("%d", &size);
   }

   srand(time(NULL));/*randomize the function rand()*/
   
   while (choice != 4)/*repeat program until user chooses to exit*/
   {
      initializeArray(size);/*initialize the array*/
      displayMenu();/*display the menu for user to choose from*/

      printf("Enter the operation you want to perform: ");/*prompt the user to make a selection from the menu*/
      scanf("%d", &choice);

      switch (choice)/*swith selection to direct program to perform the selected operation*/
      {
         case 0:/*selection for displaying general stats*/
            printf("\nInput array\n");
            printArray(size);/*display the array*/
            computeStats(size);/*display the general stats calculated*/
            break;
        
         case 1:/*selection to find a number present in the array*/
            printf("\n\nEnter the number you want to search: ");/*ask user what number they would like to search for*/
            scanf("%d", &num);

            printf("\nInput array\n");
            printArray(size);/*display the array*/
   
            index = search(size, num);/*find where the number is*/
     
            if (index == -1)/*if the number is not present let the user know or tell where the number is*/
               printf("The number you entered is not in the array\n");
            else 
               printf("The number %d is present at the index %d\n", num, index);           
            break;
      
         case 2:/*selection for counting how many times a number entered by the user appears in the array*/
            printf("\n\nEnter the number: ");/*get the number from the user*/
            scanf("%d", &num);
            
            printf("\nInput array\n");
            printArray(size);/*display the array*/

            numx = countNumber(num, size);/*let the user know if the number is present and how many times*/
            if (numx == -1)
               printf("The number you entered is not in the array\n");
            else
               printf("The number %d is present %d times in the array\n", num, numx);
            break;

         case 3:/*selection for replacing an element in the array*/
            printf("\nEnter the index: ");/*get the element to be changed from the user*/
            scanf("%d", &index);
			
			if (!array1[index]) {
				printf("That index is outside the scope of the array\n");
				break;
			}
			else {
				printf("\nEnter the new number: ");/*get the number to assign to the element from the user*/
				scanf("%d", &new);
            
				printf("\nArray before replacement operation\n");
				printArray(size);/*display the array before the change is made*/

				replace(new, index);/*replace the element with the nuew number*/
    
				printf("\nArray after replacement operation\n");
				printArray(size);/*display the new array*/
				
				break;
			}
         case 4:/*choice to exit the program*/
            break;
      }
   }
   
   printf("\nExiting the program\n");
}

/*function to check that user entered a valid array size*/
int error_check(int y)
{
   if (y > 0 && y <=20)
      return 1;
   else
      return 0;
}

/*function to initialize an array with a number of elements specified by the user*/
void initializeArray(int x)
{
   int i;
   
   for (i = 0; i < x; i++)
   {
      array1[i] = (rand() % 10);
   }
}

/*function to display a menu for the user to choose from*/
void displayMenu()
{
   printf("\nArray operations, your options are:\n\n");
   printf("0:General Statistics\n1:Search a number\n2:Count a number\n3:Replace a number\n4:Exit\n");
}

/*function to print the contents of an array*/
void printArray(int z)
{
   int j;

   for (j = 0; j < z; j++)
   {
      printf("%d ", array1[j]);
   }
   
   printf("\n\n");
}

/*function to display highest lowest and average of the array values*/
void computeStats(int x)
{
   /*variables for stats*/
   int big;
   int small;
   float avg;

   big = max(x);/*find the largest number in the array*/
   printf("Largest number is %d\n", big);

   small = min(x);/*find the smallest number in the array*/
   printf("Smallest number is %d\n", small);

   avg = average(x);/*find the average of the values in the array*/
   printf("Average of numbers is %.3f\n\n", avg);

}

/*function to find the highest number in the array*/
int max(int y)
{
   /*variables for max*/
   int high;
   int i;

   high = array1[0];/*set initial value for max to compare*/
   for (i = 0; i < y; i++)
   {
      if (high < array1[i])
         high = array1[i];/*replace high when a higher value is found in the array*/
   }
   
   return high;/*return the highest number*/
}

/*function to find the lowest number in the array*/
int min(int z)
{
   /*variables for finding min*/
   int low;
   int j;

   low = array1[0];/*assign initial value for comparison*/
   for (j = 0; j < z; j++)
   {
      if (low > array1[j])
         low = array1[j];/*replace low when a smaller value is found in the array*/
   }

   return low;/*return the lowest value*/
}

/*function to calculate the averag of the numbers in the array*/
float average(int x)
{
   /*variables for find the average*/
   int i;
   int total;
   float average;

   for (i = 0; i < x; i++){
      total += array1[i];/*add all values in the array*/
   }
   
   average = (float) total / x;/*divide total by the number of elements to find the average*/

return average;/*return the average*/
}

/*function to find where a number is present*/
int search(int x, int find)
{
   int i;
   int here = -1;

   for (i = 0; i < x; i++)
   {
      if (find == array1[i])
         here = i;
   }

return here;
}

/*function to count how many times a number is present*/
int countNumber(int find, int x)
{
   int i;
   int times = 0;

   for (i = 0; i < x; i++)/*look through array*/
   {
      if (find == array1[i])
         ++times;/*if number is found add one*/
   }

   if (times == 0)
      return -1;
   else
      return times; 
}

/*function to replace a value in an array*/
void replace(int num, int i)
{
		array1[i] = num;
}
