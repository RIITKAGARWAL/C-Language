#include <stdio.h>
#include <conio.h>
#include <string.h>

void main()
 {
 
  int i,j,length;
  char *str;
  
  printf("Enter your String Value: ");
  gets(str);
  
  length = strlen(str);
  
  for(i=1; i<= ((length % 2 == 0) ? length/2 : ((length +1) /2)); i++)
      {
  
         for(j=1; j<=length; j++)
         {
             if ((j<=i) || (j>(length-i)))
                 printf("%c",str[j-1]);
             else 
                 printf(" ");
         }
     
         printf("\n");
 }
 
  getch();
  
 }