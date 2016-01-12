/*Seanmichael Stanley*/
/*sts44b*/
/*08375210*/
/*labcode: */

/*reference function libraries*/
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

/*function prototypes for this program*/
int check_error(int);
void initialize_2Darray(int);
int search_max(int r, int c, int size);
void print_2Darray(int);
void initialize_1Darray(int);
void print_1Darray(int);
int count_diagonal(int i, int size);
int closest_row(int);

/*global arrays used in this program*/
int array2D[100][100];
int array1D[100];

int main()/*begin function main*/
{
   /*vaiables used in the main function*/
   int num;
   int large;
   int row;
   int col;
   int i;
   int x;
   int close;

   printf("\nEnter the size of the 2D  array: ");/*prompt user for the size of the array to be initialized*/
   scanf("%d", &num);

   while (check_error(num) == 0)/*check that a valid size was entered*/
   {
      printf("Invalid input enter the size of the array again: ");
      scanf("%d", &num);
   }

   srand(time(NULL));/*randomize the function reand()*/

   initialize_2Darray(num);/*initialize the 2D array*/

   print_2Darray(num);/*display the 2D array*/

   initialize_1Darray(num);/*initialize the 1D array*/

   print_1Darray(num);/*display the 1D array*/

   printf("\n\nEnter the row: ");/*prompt the user to enter a row number*/
   scanf("%d", &row);

   printf("Enter the col: ");/*prompt the user to enter a column number*/
   scanf("%d", &col);   

   large = search_max(row, col, num);/*find the largest number in the row and column entered by the user*/

   printf("\nThe largest number present in the row %d and col %d is %d\n", row, col, large);/*display the largest value found in the coulumn*/

   for (i = 0; i < num; i++)/*display the diagonal value and how many times it is present in that row and column*/
   {
      x = count_diagonal(i, num);   

      printf("\nDiagonal element %d is present %d more times in the row %d and col %d", array2D[i][i], x, i, i);
   }
  
   close = closest_row(num);/*assign the number of the closest row to the variable closest*/
   
   printf("\n\nRow closest to the array is row %d\n\n", close);/*display the row of the 2D array cloasest to the 1D array*/
}

/*Function to check that user entered a valid array size*/
int check_error(int x)
{
   if (x > 0 && x < 100)
      return 1;
   else
      return 0;
}

/*function to initialize a 2D array*/
void initialize_2Darray(int size)
{
   int i, j;

   for (i = 0; i < size; i++)
   {
      for (j = 0; j < size; j++)
      {
         array2D[i][j] = (rand() % 10);
      }
   }
}

/*function to find the highest number of a row and column*/
int search_max(int r, int c, int size)
{
   int i, j;
   int high;

   high = array2D[r][c];/*set initial value for comparison*/

   for (i = 0; i < size; i++)
   {
      if (high < array2D[r][i])/*compare the values down the row*/
         high = array2D[r][i];
   }

   for (j = 0; j < size; j++)
   {
      if (high < array2D[j][c])/*compare the vlaues down the column*/
         high = array2D[j][c];
   }
return high;/*return the highest value*/
}

/*function to print a 2D array*/
void print_2Darray(int size)
{
   int i, j;
   
   printf("\n2D arrays\n");
   
   for (i = 0; i < size; i++)/*for each row*/
   {
      for (j = 0; j < size; j++)/*elements of each column*/
      {
         printf("%d ", array2D[i][j]);
      }
  
      printf("\n");
   }
}

/*function to assign random numbers to the elements of a 1D array*/
void initialize_1Darray(int size)
{ 
   int i;

   for (i = 0; i < size; i++)
   {
      array1D[i] = (rand() % 10);
   }
}

/*function to print a 1D array*/
void print_1Darray(int size)
{
   int j;
   
   printf("\n1D array\n"); 

   for (j = 0; j < size; j++)
   {
      printf("%d ", array1D[j]); 
   }
}

/*function to count how many times a nuber is present in the row and column its found in*/
int count_diagonal(int i, int size)
{
   /*declare variables for the function*/
   int num = array2D[i][i];
   int j; 
   int count = 0;

   for (j = 0; j < size; j++)
   {
      if (array2D[i][j] == num)/*check the column*/
         count++;
      
      if (array2D[j][i] == num)/*check the row*/
         count++;
   }   
return count - 2;/*return the count minus two becase num was counted twice*/
}

/*function to compaer each row of a 2d array to a 1d array and determine which is least different*/
int closest_row(int size)
{
   /*declare variables for the function*/
   int closest = 0;
   int i;
   int j;
   int sum = 0;
   int comp = 0;

   for (i = 0; i < size; i++)
   {
      for(j = 0; j < size; j++)/*add up the differences*/
      {
         sum += abs(array1D[j] - array2D[i][j]);   
      } 
      
      if (i == 0)/*establish a value to compare to*/
         comp = sum;
 
      else if (sum < comp)/*assign the row with the lowest difference to the variable closest*/
      {   
         comp = sum;
         closest = i;
      }
      sum = 0;/*return sum to zero for the next comparison*/
   }

   return closest;/*return the row witht the lowest difference*/
}

