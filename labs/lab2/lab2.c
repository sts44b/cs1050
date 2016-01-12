/*Seanmichael Stanley*/
/*sts44b*/
/*labcode: 120613*/


/*Program to calculate average grade and highest grade*/
#include<stdio.h>/*call library*/

int main()/*begin function main*/
{

   int m1, m2, f;/*declare variables to hold the three grades*/
   float avg;/*declare a variable to hole the student's average*/
   printf("Enter the miderm1 grade: ");/*prompt user to enter the first grade*/
   scanf("%d", &m1);/*assign grade to a variable*/

   while (m1 < 0 ||  m1 > 100)/*check to see if a valid grade was entered*/
   {
   printf("\nInvalid grade. Enter the midterm1 grade: ");/*if invalid grade, promt user*/
   scanf("%d", &m1);/*get correct grade*/
   }

   printf("\nEnter the midterm2 grade: ");/*prompt user for second grade*/
   scanf("%d", &m2);/*assign second grade*/

   while (m2 < 0 || m2 > 100)/*check to see if second grade is valid*/
   {
   printf("Invalid grade. Enter the midterm2 grade: ");/*prompt user for a valid grade*/
   scanf("%d", &m2);/*assign a valid grade*/
   }

   printf("\nEnter the final grade: ");/*prompt the user for the final grade*/
   scanf("%d", &f);/*assign the final grade*/

   while (f < 0 || f > 100)/*check to see if final grade is valid*/
   {
   printf("\nInvalid grade. Enter the final grade: ");/*if final grade is invalid prompt the user*/
   scanf("%d", &f);/*assign a correct grade*/
   }

   if (m1 >= m2 && m1 >= f)/*check to see if midterm1 is student's highest grade*/
   printf("\nThe student's highest grade was %d on midterm1.", m1);/*print high  grade*/
    else if (m2 >= m1 && m2 >= f)/*check to see if midterm2 is student's highest grade*/
    printf("\nThe student's highest grade was %d on midterm2.", m2);/*print high grade*/
    else if (f >= m1 && f >= m2)/*Check to see if final is the student's highest grade*/
    printf("\nThe student's highest grade was %d on the final.", f);/*print high grade*/

   if (m1 <= m2 && m1 <= f)/*Check to see if midterm1 was student's lowest grade*/
   printf("\nThe student's lowest grade was %d on midterm1.", m1); /*print low grade*/
     else if (m2 <= m1 && m2 <=f)/*Check to see if midterm2 is the student's lowest grade*/
     printf("\nThe student's lowest grade was %d on midterm2.", m2);/*print low grade*/
     else if (f <= m1 && f <= m2)/*Check to see if final was the student's lowest grade*/
     printf("\nThe student's lowest grade was %d on the final.", f);/*print low grade*/

   avg = (float) (m1 + m2 + f) / 3;/*calculate the student's average score*/

   
   if (avg >= 90)/*Check to see what grade the student scored and show score and grade*/
   printf("\nThe student's average is %.2f and the overall grade is A.", avg);/*Print grade if A*/

      else if (avg >= 80 && avg < 90)
      printf("\nThe student's average is %.2f and the overall grade is B.", avg);/*Print grade if B*/
 
      else  if (avg >= 70 && avg < 80)
      printf("\nThe student's average is %.2f and the overall grade is C.", avg);/*Print grade if C*/

      else if (avg >= 60 && avg < 70)
      printf("\nThe student's average is %.2f and the overall grade is D.", avg);/*Print grade if D*/

      else if (avg < 60)
      printf("\nThe student's average is %.2f and the overall grade is F.", avg);/*Print grade if F*/
   
return 0;
}/*End Main*/
