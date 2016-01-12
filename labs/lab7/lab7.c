/*Seanmichael Stanley*/
/*sts44b*/
/*08375210*/
/*Labcode: 170713*/
/*lab 7*/

/*reference function libraries*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*function prototypes for this program*/
int* initialize_array(int n);
int* search_arrays(int*, int, int*, int, int);
void print_array(int*, int);
int* merge_array(int*, int, int*, int);
int* reverse_array(int*, int);
void print_histogram(int*, int);

/*program to handle arrays with pointers*/
int main(int argc, char* argv[])/*get array sizes from the command line*/
{
   if (argc != 3)/*check to make sure there were the appropriate number of arguments entered*/
   {
      printf("\nInsufficient arguments. Please provide two integers before executing.\n");
      return 0;/*if wrong number of arguments quit program*/
   }

   /*declare the variables and pointers to be used in this program*/
   int size1, size2;
   int *ptr1;
   int *ptr2;
   int *ptrMerge;
   int *ptrRev;

   srand(time(NULL));/*randomize the function rand()*/

   /*convert the string values for the array sizes to integers with the function atoi*/
   size1 = atoi(argv[1]);
   size2 = atoi(argv[2]);

   ptr1 = initialize_array(size1);/*initialize array1*/
   ptr2 = initialize_array(size2);/*initialize array2*/

   printf("\nFirst input array\n");/*display the first array generated*/
   print_array(ptr1, size1);
   printf("\nSecond input array\n");/*display the secon array generated*/
   print_array(ptr2, size2);

   
   ptrMerge = merge_array(ptr1, size1, ptr2, size2);/*call the function to merge the two generated arrays*/

   printf("\nMerged array is\n");
   print_array(ptrMerge, (size1 + size2));/*print the merged array*/

   ptrRev = reverse_array(ptrMerge, (size1 + size2));/*call the function to reverse the merged array*/
   
   printf("\nReverse array is \n");/*print the reversed array*/
   print_array(ptrRev, (size1 + size2));

   printf("\n\nPrinting histogram\n");/*print the histogram of the reversed array*/
   print_histogram(ptrRev, (size1 + size2)); 

return 0;
}/*end function main*/

/*function to create an array of a given size with a pointer and assign random numbers to the elements*/
int * initialize_array(int size)
{
   int i;
   int *ptr;

   ptr = malloc(sizeof(int) * size);/*malloc function to allocate memory for an array at execution time*/

   for (i = 0; i < size; i++)
   {
      *(ptr + i) = rand() % 10;/*assign random integers 0-9*/
   }
return ptr;/*return the memory location of the array created*/
}

/*function to print arrays from a memory location of a given size*/
void print_array(int *ptrP, int size)
{
   int i;

   for (i = 0; i < size; i++)
   {
      printf("%d ", *(ptrP + i));
   }
}

/*function to merge two arrays into one*/
int* merge_array(int *ptrA, int sizeA, int *ptrB, int sizeB)
{
   int i, j;
   int *ptrM;

   ptrM = initialize_array(sizeA + sizeB);/*allocate memory for the arrays to be merged to*/

   for (i = 0; i < sizeA; i++)
   {
      *(ptrM + i) = *(ptrA + i);/*move values of array 1 to this location*/
   }
 
   for (j = 0; j < sizeB; j++)
   {
      *(ptrM + i + j) = *(ptrB + j);/*move values of the second array adjacent to the first array*/
   }

return ptrM;/*return the memory location for the merged arrays*/
}

/*function to reverse the merged array*/
int * reverse_array(int *ptrX, int size)
{
   int i, j;
   int *ptrR;

   ptrR = initialize_array(size);/*allocate memroy of the rever array*/

   i = 1;

   for (j = 0; j < size; j++)
   {
      *(ptrR + j) = *(ptrX + (size - i));/*take the last value of the merged array and assign it to the first memory location of the resed array etc*/
      i++;
   }
return ptrR;/*return the memory location of the reversed array*/
}

/*function to print a histogram of the values in the two arrays*/
void print_histogram(int *ptrY, int size)
{
   int i, j;

   for (i = 0; i < 10; i++)/*check from 0-9*/
   {
      printf("%d:", i);
      for (j = 0; j < size; j++)
      {
         if (*(ptrY + j) == i)
            printf("%c", '*');/*each time number is present print an **/
      }
      printf("\n");
   }
}

