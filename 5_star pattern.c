#include <stdio.h>
#include <conio.h>

void main()
 {
 
  int i,j;
  
  for(i=1; i<=5; i++)
  {
  
 for(j=1; j<=9; j++){
 if ((j<=i) || (j>(9-i)))
 printf("*");
 else 
 printf(" ");
 }
printf("\n");
 }
 
  getch();
  
 }