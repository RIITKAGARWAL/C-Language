#include <stdio.h>
#include <process.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct custRecord {
char accountNum[25];
char name[25];
int dob;
int age;
char gender[7];
char mobile[11];
char email[30];
}custRecord;

void template1();
void customerCreation();
void recordEntry();
void recordDisplay();

void main()
{
int num;
template1();
customerCreation();
scanf("%d",&num);

}

void template1(){
system("cls");
system("color 0b");
printf("					*******	Banking ATM Project ********\n\n");
printf("						***Jiya-Ritik Bank***\n\n");

}

void customerCreation(){
FILE *fptr;
fptr = fopen("BankRecord.ods","a+");
if(!fptr)
exit(0);


recordEntry();
fwrite(&custRecord,sizeof(custRecord),1,fptr);
rewind(fptr);
{


while(!feof(fptr))
{
    fread(&custRecord,sizeof(custRecord),1,fptr);
    recordDisplay();
}
}
exit(0);

}

void recordEntry(){

int dob,age;
char gender[7],name[25],email[30],mobile[11];

printf("\nEnter Customer Name: ");
gets(name);

printf("\nEnter Customer Gender (M/F): ");
gets(gender);

printf("\nEnter Customer Email id: ");
gets(email);


printf("\nEnter Customer Mobile Number: ");
gets(mobile);


printf("\nEnter Customer Date of Birth (ddmmyyyy) : ");
scanf("%d",&dob);

printf("\nEnter Customer Age: ");
scanf("%d",&age);



strcpy(custRecord.name,name);
strcpy(custRecord.gender,gender);
strcpy(custRecord.email,email);
strcpy(custRecord.mobile,mobile);
custRecord.dob =dob;
custRecord.age=age;


}


void recordDisplay(){
printf("\n***********************************************\n\n");
printf("\nRecord Entered Successfully...\n\n");
system("pause");
system("cls");
printf("\n***********************************************\n\n");

printf("\nName          : %s",custRecord.name);
printf("\nDate of Birth : %d",custRecord.dob);
printf("\nAge           : %d",custRecord.age);

printf("\nGender        : %s",custRecord.gender);
printf("\nMobile        : %s",custRecord.mobile);
printf("\nEmail         : %s",custRecord.email);
printf("\n\n***********************************************\n\n");

};













