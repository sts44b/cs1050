/*Seanmichael Stanley*/
/*sts44b*/
/*CS 1050 Lab 4*/
/*Labcode: 260613 */


/*reference function libraries*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*Function prototypes*/
int generateNumber(void);
void printResult(int, int);
void displayMenu(void);
int checkGuess(int, int);
int check_error(int);

/*global variables to be accessed by multiple functions*/
int choice;
int correct;

/*Begin function main*/
int main()
{
   /*declare variables to be used in function main*/
   int num;
   int check;
   int z=1;
   int count = 0;
   float won;


   while (z!=0)/*while loop for user to guess multiple times without ending the program*/
   { 
        ++ count;/*counter for calculating win percentage*/

	srand(time(NULL));/*seed rand so that sequence is not the same each time the program is run again*/

   	num = generateNumber();/*get a random number*/

  	displayMenu();/*display menu for user to choose from*/

   	while (check_error(choice)== 0)/*check to be sure user makes a valid choice*/
   	{
      	   printf("Invalid guess enter your choice again: ");
      	   scanf("%d", &choice);
   	}

   	check = checkGuess(choice, num);/*check to see if the user made the correct guess*/

	printResult(check, num);/*tell user if they were correct or not, if not what the correct answer was*/

        printf("\nDo you want to play again? (1 yes, 0 no): ");/*ask the user if they would like to play again*/
        scanf("%d", &z);/*if 0 program ends if other value play continues*/
   }
   
   won = (float)correct / count * 100;/*calculate win percentage*/

   printf("\n\nYou guessed %d correct colors.", correct);/*display number of correct answers*/
   printf("\nYour winning percentage is %.2f%%.", won);/*display the win percentage*/
   return 0;
}/*End function main*/

/*function to get a random number from the function rand()*/
int generateNumber()
{
   int x = (rand() % 4);

   return x;
}

/*function to display the menu for the user to choose from*/
void displayMenu()
{
   printf("\n\nPlease guess a color\nColors options are:\n0 : Green\n1 : Red\n2 : Blue\n3 : Yellow");
   printf("\n\nEnter your choice: ");
   scanf("%d", &choice);
}

/*function to check to be sure user made a proper selection*/
int check_error(int guess)
{
   if (guess >= 0 && guess <= 3)
      return 1;
   else
      return 0;
}

/*Function to check if user answered correctly or not*/
int checkGuess (int guess, int answer)
{
   if (guess == answer)
      return 1;
   else
      return 0;
}

/*Function to display if user answered correctly or not and what the correct answer was*/
void printResult(int result, int answer)
{
   if (result == 1)
   {   printf("Your answer is right!");
       correct++;/*counter for number of correct answers for calculating win percentage*/
   }
    else
   {
   	switch(answer)
   	{
      	   case 0:
       		printf("Your guess was incorrect.\nCorrect answer was Green");
			break;

      	   case 1:
       		printf("Your guess was incorrect.\nCorrect answer was Red");
       		break;

      	   case 2:
       		printf("Your guess was incorrect.\nCorrect answer was Blue");
       		break;

      	   case 3:
       		printf("your guess was incorrect.\nCorrect answer was Yellow");
       		break;
  
  	 }
   }
}
