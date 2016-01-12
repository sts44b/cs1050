/*Seanmicheal Stanley*/
/*sts44b*/
/*08375210*/
/*Homework assignment 3*/

/*reference function libraries*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*set the array size MAX*/
#define MAX 100

/*declare global 2D arrrays for this program*/
char display[MAX][MAX];
char play[MAX][MAX];

/*function prototypes for the functions implemented in this program*/
void set_bomb(int);
void set_antibomb(int);
void initialize_grid(int);
void display_grid(char[][MAX], int);
int error_check(int x, int y, int n);
int check_position(int x, int y);

/*program for the game "tank"*/
int main()/*begin finction main*/
{
   /*declare variables for this program*/
   int size;
   int x;
   int y;
   int counter = 0;
   int check = 0;
   int checkpos;
   int antibomb = 1;

   printf("\nEnter the grid size: ");/*prompt user to enter a grid size*/
   scanf("%d", &size);/*assign value to the variable size*/

   srand(time(NULL));/*ranomize the function rand*/

   initialize_grid(size);/*initialize the display array*/

   set_bomb(size);/*set bombs and open spots on the grid*/

   set_antibomb(size);/*set two antibombs on grid*/

   while (counter < 5)/*begin game code for 5 rounds of safe tank moves*/
   {
      check = 0;/*set check back to 0*/
      
      while (check == 0)
      {
         printf("\nEnter the x position for tank: ");/*promt user to enter x postition to move tank to*/
         scanf("%d", &x);

         printf("Enter the y position for tank: ");/*prompt user to enter y position to move tank to */
         scanf("%d", &y);
         
         check = error_check(x, y, size); /*check to see that user entered correct coordnance to move tank to*/
      }    

      checkpos = check_position(x, y);/*check to see what lies where user chose to move tank*/

      if (checkpos == 1)/*case user landed on a bomb*/
      { 
         --antibomb;/*remove antibomb*/
         if (antibomb == 0)/*if no anti bombs, GAME OVER*/
         {   
            printf("\nTank was bombed\nYou lost the game\n\n");
            play[y][x] = '$';/*mark where bomb was*/
            display_grid(play, size);/*display play grid*/
            printf("\n");
            return 0;/*game over*/
         }
         else
         {
            printf("Tank was bombed but but anti-bomb saved the tank\n\n");/*if user had an anti bomb, game continues*/
            display_grid(display, size);
         } 
      }
      else if (checkpos == 2)/*case user lands on antibomb*/
      {
         ++antibomb;/*add an antibomb*/
         printf("\nAntibomb collected\n\n");/*let user know they collected an antibomb*/
         display_grid(display, size);/*display grid with moves marked*/
      }
      else
      {
         counter++;/*add one to counter*/
         display[y][x] = '+';/*add one to counter and mark spot that user has already moved to*/
         printf("\n");
         display_grid(display, size);/*display grid with move marked moves*/
      }
   }

   printf("\nCongratulations you won the game.\nTank survived all the bomb attacks.\n\n");/*prompt the user that they have won the game*/

}/*end function main*/

/*function to initialize display array*/
void initialize_grid(int size)
{
   int i, j;

   for (i = 0; i < size; i++)
   {
      for (j = 0; j < size; j++)
      {
         display[i][j] = '#';
      }
   }
}

/*function to print 2D arrays*/
void display_grid(char array[][MAX], int size)
{
   int i, j;

   for (i = 0; i < size; i++)
   {
      for (j = 0; j < size; j++)
      {
         printf("%c ", array[i][j]);
      }
      
      printf("\n");
   }
}

/*function to inittialize the play array with bombs and open positions*/
void set_bomb(int size)
{
   int i, j;
   int x;

   for (i = 0; i < size; i++)
   {
      for (j = 0; j < size; j++)
      {
         x = rand() % 10;/*generate random numbers for each row*/

         if (x >= 0 && x <= 3)
            play[i][j] = '@';/*40% chance of a bomb being laid*/
         else
            play[i][j] = '#';/*for each spot a bomb is not laid leave an open spot*/      
      }
   }
}

/*function to set two anti bombs*/
void set_antibomb(int size)
{
   int x, y;
   int check = 0;
   int count = 0;

   while (count < 2)/*count to lay 2 antibombs*/
   {
      check = 0;/*set check back to 0*/
      while (check == 0)
      {
         x = rand() % size;/*get a random number for x*/
         y = rand() % size;/*get a random number for y*/
        
         if (play[y][x] == '@'|| play[y][x] == '&')/*dont replace a bomb or anti bomb*/
            check = 0;
         else
            check = 1;
      }
    
      play[y][x] = '&';/*place the anti bomb*/
       
      count++;/*bump count*/
   }
}

/*function to check that user entered a valid location on the grid*/
int error_check(int x, int y, int n)
{
   if (x < 0 || x > (n - 1))/*check that x is correct*/
   {
      printf("Invalid position to move the tank");
      return 0;
   }
   else if (y < 0 || y > (n - 1))/*check that y is correct*/
   {
      printf("Invalid position to move tank");
      return 0;
   }
   else if (display[y][x] == '+')/*check that the user hasn't alreaady moved a tank to the location*/
   {
      printf("Tank was already moved to this position");
      return 0;
   }
   else
      return 1;/*return 1 if valid input*/
}

/*function to check what is at the location enterd by the user*/
int check_position (int x, int y)
{
   if (play[y][x] == '@')/*if a bomb is present*/
      return 1;
   else if (play[y][x] == '&')/*if an anti bomb is present*/
      return 2;
   else/*if the spot is open*/
      return 3;
}
