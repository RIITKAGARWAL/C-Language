#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <process.h>
#include <string.h>
#define MAX 25
#define op(ctr) (ptr[ctr] == '+' || ptr[ctr] == '-' || ptr[ctr] == '*' || ptr[ctr] == '/' || ptr[ctr] == '%' || ptr[ctr] == '(' || ptr[ctr] == ')' )
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
char inFix[MAX];
char preFix[MAX];
char postFix[MAX];
char stack[MAX];

int top = -1;
int topInFix = -1;
int topPostFix = -1;
int topPreFix = -1;

//-------------------------------------------------------------------------------------------
void push(char ptr){
if(top <= MAX - 1)
 {
   top++;
   stack[top] = ptr;
 }
else
printf("\nStack OverFlow ");
}
//-------------------------------------------------------------------------------------------
void pushPostFix(char ptr){
if(topPostFix < MAX - 1)
    {
        topPostFix++;
        postFix[topPostFix] = ptr;
    }
else
    printf("\nstack overflow");
}

void pushPreFix(char ptr){
if(topPreFix < MAX -1)
   {
    topPreFix++;
    preFix[topPreFix] = ptr;
   }
else
    printf("\nPreFix Stack is Empty: ");

}
//-------------------------------------------------------------------------------------------
char pop(){
char n = '\0';
if(top == -1)
	{
	printf("\nStack UnderFlow: ");

	}
else
	{
		n = stack[top];
		top--;

	}

return n;
}
//-------------------------------------------------------------------------------------------
void display(){
int ctr;
if (top == -1 )
    printf("\n Stack is empty");
else
     for (ctr = top; ctr>=0; ctr--)
            printf("\t %c",stack[ctr]);
}
//-------------------------------------------------------------------------------------------
void displayInFix(){
    int ctr;
    printf("\n\n");
if(topInFix == -1)
    printf("\npostfix stack is empty");
else
    for (ctr = 0; ctr <=topInFix; ctr ++)
        printf("%c",inFix[ctr]);
}
void displayPostFix(){
int ctr;
    printf("\n\n");

if(topPostFix == -1)
    printf("\npostfix stack is empty");
else
    for (ctr = 0; ctr <=topPostFix; ctr ++)
        printf("%c",postFix[ctr]);
}

void displayPreFix(){
    int ctr;
        printf("\n\n");

    if(topPreFix == -1)
        printf("\nPreFix Stack is empty");
    else{
       for(ctr = topPreFix;ctr >=0; ctr --)
         printf("%c",preFix[ctr]);

    }
}
//-------------------------------------------------------------------------------------------
void dataInput(char *notation,char *msg){
system("cls");

printf("Please Enter the %s Equation : ",msg);
gets(notation);
gets(notation);

printf("%s : ",msg);
puts(notation);

}
//-------------------------------------------------------------------------------------------
int opPrecedence(char operator){
if (operator == '*' || operator == '/' || operator == '%'  )
    return 1;
else if(operator == '+' || operator == '-' )
    return 2;
else
    return 3;
}
//-------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------
void preFixFun(){

strrev(inFix);



char *ptr = inFix;

while(*ptr != NULL){

if(*ptr == '+' || *ptr == '-' || *ptr == '*' || *ptr == '/' || *ptr == '%' || *ptr == '(' || *ptr == ')' )
	{
	    mileStone1:
		if (opPrecedence(*ptr) <= opPrecedence(stack[top]))
			push(*ptr);
		else{
			pushPreFix(pop());
			goto mileStone1;
		}
	}
else
    pushPreFix(*ptr);



ptr++;
}
while(top != -1)
    pushPreFix(pop());

}
//------------------------------------------------------------------------------------------------------------
void postFixFun(){
char *ptr = inFix;

while(*ptr != NULL){

if(*ptr == '+' || *ptr == '-' || *ptr == '*' || *ptr == '/' || *ptr == '%' || *ptr == '(' || *ptr == ')' )
	{
	    mileStone1:
		if (opPrecedence(*ptr) < opPrecedence(stack[top]))
			push(*ptr);
		else{
			pushPostFix(pop());
			goto mileStone1;
		}
	}
else
    pushPostFix(*ptr);

ptr++;
}
while(top != -1)
    pushPostFix(pop());

}
//------------------------------------------------------------------------------------------------------------
void infixOperandsSet(char *annotation){
char *ptr = annotation;
topInFix = strlen(annotation);
int countOperands = 0;
int countOperators = 0;

for(int ctr = 0; ctr <topInFix; ctr ++ ,ptr++)
   {

    if(*ptr == '+' || *ptr == '-' || *ptr == '*' || *ptr == '/' || *ptr == '%' || *ptr == '(' || *ptr == ')' )
       {
                countOperators++;
                inFix[countOperators*2-1] = ' ';

       }
    else{
        countOperands++;
        inFix[countOperands*2-2] = *ptr;
    }
   }
}
void pre2InFixFun(){
 infixOperandsSet(preFix);
topPreFix = strlen(preFix);

char *ptr = preFix;

int ctr,ctr2;
for(ctr = 0; ctr <topInFix;  ctr++)
   {

        if(op(ctr)&& (!op(ctr+1)) && (!op(ctr +2)))
                    {
                        int flag = 1;
                        for(ctr2=0; ctr2<topInFix; ctr2++)
                            {
                               if((ptr[ctr+1] != 'X')&&(inFix[ctr2]== ptr[ctr+2]))
                                    break;

                                else if((ptr[ctr+1] == 'X')&&(flag))
                                        {
                                            flag = 0;
                                            ctr2 = ctr+1;
                                        }
                                else if((ptr[ctr+1] == 'X')&&(inFix[ctr2] == ' '))
                                        {
                                            ctr2++;
                                            break;
                                        }
                            }

                        inFix[ctr2 -1] = ptr[ctr];
                        ptr[ctr] = 'X';
                        ctr = -1;
                    }
    }



}
void post2InFixFun(){


infixOperandsSet(postFix);
char *ptr = postFix;

int ctr,ctr2;
for(ctr = 0; ctr <topInFix;  ctr++)
   {

        if(op(ctr)&& (!op(ctr-1)) && (!op(ctr -2)))
                    {
                        for(ctr2=0; ctr2<topInFix; ctr2++)
                            {
                               if((ptr[ctr-1] != 'X')&&(inFix[ctr2]== ptr[ctr-1]))
                                    break;

                                else if((ptr[ctr-1] == 'X')&&(inFix[ctr2] == ' '))
                                        {
                                            ctr2++;
                                            break;
                                        }
                            }

                        inFix[ctr2 -1] = ptr[ctr];
                        ptr[ctr] = 'X';
                    }
    }

}

void menu(){
int choice ;
while(1){
system("cls");
printf("------------------------Polish Notation Converter--------------------------\n\n");
printf("\n1. Pre-Fix  Converter");
printf("\n2. Post-Fix Converter");
printf("\n3. Pre-Fix to infix Converter");
printf("\n4. Post-Fix to infix Converter");
printf("\n5. Pre-Fix to postfix Converter");
printf("\n6. Post-Fix to prefix Converter");
printf("\n7. Exit");

printf("\n\n-----------------------------------------------------------------------------\n\n");
printf("please Enter Your choice (1 or 2 or 3 or 4 or 5 or 6 or 7) : ");
scanf("%d",&choice);

switch(choice){
case 1:
    dataInput(inFix,"In-Fix");
	preFixFun();
	displayPreFix();
    topPreFix = -1;
	getch();
	break;
case 2:
    dataInput(inFix,"infix");
	postFixFun();
	displayPostFix();
	topPostFix = -1;
	getch();
	break;

case 3:
    dataInput(preFix,"pre-fix");
    pre2InFixFun();
    displayInFix();
    topInFix = -1;
    topPreFix = -1;
    getch();
	break;

case 4:
    dataInput(postFix,"post-fix");
    topInFix = topPostFix = strlen(postFix);
    post2InFixFun();

    displayInFix();


    topInFix = -1;
    topPostFix = -1;
	getch();
	break;
case 5:

    dataInput(preFix,"pre-fix");
    pre2InFixFun();
    displayInFix();

	postFixFun();
	displayPostFix();
	topPostFix = -1;
	getch();
	break;

case 6:
    dataInput(postFix,"post-fix");
    topInFix = topPostFix = strlen(postFix);
    post2InFixFun();

    displayInFix();


    preFixFun();
	displayPreFix();

    topPreFix = -1;
    topPostFix = -1;
    topInFix = -1;
	getch();
	break;


case 7:
	exit(0);
};

}}
//------------------------------------------------------------------------------------------------------------
void main(){
menu();

}
