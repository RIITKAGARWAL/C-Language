#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <stdlib.h>


typedef struct linklist{
int coefficient;
char var[4] ;
struct linklist *next;
}link;


link *start1 = NULL;
link *start2 = NULL;
link *start3 = NULL;

void main(){
void create1(int *);
void create2(int *);
void result();
void display1(int *);
void display2(int *);
void adjustment2();
void adjustment1();
void resultDisplay(int *);


int degree[3];
//------first polynomial equation-----

printf("what is the highest degree of 1st polynomial Equation: ");
scanf("%d",&degree[1]);
printf("degree is : %d",degree[1]);
degree[0] = degree[1];
for(;degree[0]>=0;degree[0]--)
{
	create1(degree);
}


//--------2nd polynomial equation-------
printf("\n\n------------------------------------------------------ ");
printf("\n\nwhat is the highest degree of 2nd polynomial Equation: ");
scanf("%d",&degree[2]);
degree[0] = degree[2];
for(;degree[0]>=0;degree[0]--)
{
	create2(degree);
}
printf("\n\n------------------------------------------------------ ");

printf("\n\nThankYou Your data has entered successfully \t");

system("pause");
system("cls");

//-----------Display part----------------
printf("Equations are ...");
printf("---------------------------------------------------");
display1(&degree[1]);
printf("\n");
display2(&degree[2]);

//----------------adjustment part---------
if(degree[1]>degree[2]){
degree[0]=degree[1]-degree[2];

for(;degree[0]>0;degree[0]--)
	adjustment2();}

else if (degree[1]<degree[2]){
degree[0]=degree[2]-degree[1];

for(;degree[0]>0;degree[0]--)
	adjustment1();}

//------------process part-----------------

result();

//-----------result display part----------------------
degree[0]=(degree[1]>degree[2])?(degree[1]):(degree[2]);
resultDisplay(degree);

}


//---------function part--------------
void create1(int *degree){
link *temp,*p;
int num;
printf("\nEnter Coefficient of (x^%d): ",*degree);
scanf("%d",&num);

temp = (link *)malloc(sizeof(link));
temp->coefficient = num;
temp->next = NULL;

if(start1 == NULL)
	start1 = temp;
else
      {
	p = start1;
	while(p->next !=NULL)
		p=p->next;
        p->next = temp;
      }
}

//-------------------------------------
void create2(int *degree){
link *temp,*p;
int num;
printf("\nEnter Coefficient of (x^%d): ",*degree);
scanf("%d",&num);

temp = (link *)malloc(sizeof(link));
temp->coefficient = num;
temp->next = NULL;

if(start2 == NULL)
	start2 = temp;
else
      {
	p = start2;
	while(p->next !=NULL)
		p=p->next;
        p->next = temp;
      }
}

//-----------------display---------------------

void display1(int *degree){
link *p;
int deg = *degree;
if(start1==NULL)
printf("\nlist is empty: ");
else
{
	p = start1;

    printf("\n\nf(x) = ");
	while(p!= NULL) {
                if(p->coefficient != 0)
                    if(deg!=0)
                        printf(" %dx^%d +",p->coefficient,deg);
                    else
                         printf(" %d +",p->coefficient);
                deg--;
				p = p->next;
			}
    printf("\b = 0 \n");
}
};

//--------------------------------------------------
void display2(int *degree){
link *p;
int deg = *degree;
if(start2==NULL)
printf("\nlist is empty: ");
else
{
	p = start2;
	printf("g(x) = ");
	while(p!= NULL) {
                if(p->coefficient != 0)
                    if(deg!=0)
                        printf(" %dx^%d +",p->coefficient,deg);
                    else
                         printf(" %d +",p->coefficient);
                deg--;
				p = p->next;
			}
    printf("\b = 0 \n");
}
};
//-------------------------adjustment part----------------
void adjustment2(){
link *temp;
/*
int num;
printf("\nEnter a number: ");
scanf("%d",&num);
*/
temp = (link *)malloc(sizeof(link));
temp->coefficient = 0;
temp->next = start2;
start2 = temp;


};
void adjustment1(){
link *temp;
/*
int num;
printf("\nEnter a number: ");
scanf("%d",&num);
*/
temp = (link *)malloc(sizeof(link));
temp->coefficient = 0;
temp->next = start1;
start1 = temp;


};
//-------------------------------------------------------
//-------------------------resultdisplay part-----------------------------
void resultDisplay(int *degree){
link *p;
int deg = *degree;
if(start3==NULL)
printf("\nlist is empty: ");
else
{
	p = start3;
	printf("\n\n---------------------------------------");
	printf("\n\nYour Result is ...\n\n");
	 printf("\n\nh(x) = ");
	while(p!= NULL) {
                if(p->coefficient != 0)
                    if(deg!=0)
                        printf(" %dx^%d +",p->coefficient,deg);
                    else
                         printf(" %d +",p->coefficient);
                deg--;
				p = p->next;
			}
    printf("\b = 0 \n");



}
};

//----------------------result----------------------------
void result(){

link *p1,*p2,*p3,*temp;

	p1 = start1;
	p2 = start2;

	while(p1!= NULL) {
                temp = (link *)malloc(sizeof(link));
                temp->coefficient = p1->coefficient + p2->coefficient;

               // strcpy(temp->var,"x^");
                //strcat(temp->var,atoi(degree[0]));

                temp->next = NULL;
                if(start3 == NULL)
                    start3 = temp;
                else
                {
                    p3 = start3;
                    while(p3->next != NULL)
                     p3 = p3->next;
                    p3->next = temp;

                }

				p1 = p1->next;
				p2 = p2->next;

			}

};


