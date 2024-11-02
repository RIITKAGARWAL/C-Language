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
void customerDisplay();
void recordDisplay();
void menu();
void searchMenu();

void main()
{
int num;
template1();
menu();

scanf("%d",&num);

}

void template1(){
system("cls");
system("color 0b");
printf("					*******	Banking ATM Project ********\n\n");
printf("						***Jiya-Ritik Bank***\n\n");

}
void menu(){
while(1){
    int choice;
    system("cls");
    printf("Welcome To The JR BANKING...\n");
    system("pause");

    template1();
    printf("\n***********************************************\n\n");
    printf("1.Customer Creation\n");
    printf("2.Login Customer\n");
    printf("3.Display All Customers Info\n");
    printf("4.Search Customer\n");
    printf("5.Update Existing Customer info\n");
    printf("6.Delete Customer Record\n");
    printf("7.Exit\n");
    printf("\n***********************************************\n\n");




        printf("\nEnter choice (1-7): ");
        scanf("%d",&choice);

        switch(choice){
    case 1:
        customerCreation();
        break;
    case 2:
        break;
    case 3:
        customerDisplay();
        break;
    case 4:
        searchMenu();
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        exit(1);
    default:
        printf("\nInvalid Choice");
        }

}
}
void customerCreation(){
FILE *fptr;
fptr = fopen("BankRecord.ods","a");
if(!fptr)
exit(0);


recordEntry();
fwrite(&custRecord,sizeof(custRecord),1,fptr);
printf("\nRecord Entered Successfully...\n\n");
fclose(fptr);
}

void recordEntry(){

char gender[7],name[25],email[30],mobile[11];
int dob,age;


printf("\nEnter Customer Name: ");
gets(name);
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

void customerDisplay(){
FILE *fptr;
fptr = fopen("BankRecord.ods","r");
while(!feof(fptr))
{
    fread(&custRecord,sizeof(custRecord),1,fptr);
    recordDisplay();
}
fclose(fptr);
}
void recordDisplay(){
printf("\n***********************************************\n\n");
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
void searchMenu(){
while(1){
    int choice;
    system("cls");
    printf("Welcome To The JR BANKING...\n");
    system("pause");

    template1();
    printf("\n***********************************************\n\n");
    printf("1.Search by Name\n");
    printf("2.Search by Account Number\n");
    printf("3.Search by Age\n");
    printf("4.Search by Gender\n");
    printf("5.Search by Email\n");
    printf("6.Search by Mobile Number\n");
    printf("7.Return to Previous Menu\n");
    printf("8.Exit\n");
    printf("\n***********************************************\n\n");




        printf("\nEnter choice (1-8): ");
        scanf("%d",&choice);

        switch(choice){
    case 1:
        {
        FILE *fptr;
        char data[30];
        fptr = fopen("BankRecord.ods","r");
        printf("Enter  Name to  Search: ");
        gets(data);
        gets(data);
        while(!feof(fptr)){
        fread(&custRecord,sizeof(custRecord),1,fptr);
        if(!strcmp(custRecord.name,data))
            recordDisplay();
        }
        fclose(fptr);
        }
        break;
    case 2:
        break;
    case 3:
         {
        FILE *fptr;
        int data;
        fptr = fopen("BankRecord.ods","r");
        printf("Enter Age to  Search: ");
       scanf("%d",&data);
        while(!feof(fptr)){
        fread(&custRecord,sizeof(custRecord),1,fptr);
        if(custRecord.age==data)
            recordDisplay();
        }
        fclose(fptr);
        }
        break;
    case 4:
         {
        FILE *fptr;
        char data[30];
        fptr = fopen("BankRecord.ods","r");
        printf("Enter  Gender to  Search: ");
        gets(data);
        gets(data);
        while(!feof(fptr)){
        fread(&custRecord,sizeof(custRecord),1,fptr);
        if(!strcmp(custRecord.gender,data))
            recordDisplay();
        }
        fclose(fptr);
        }
        break;
    case 5:
         {
        FILE *fptr;
        char data[30];
        fptr = fopen("BankRecord.ods","r");
        printf("Enter  Email to  Search: ");
        gets(data);
        gets(data);
        while(!feof(fptr)){
        fread(&custRecord,sizeof(custRecord),1,fptr);
        if(!strcmp(custRecord.email,data))
            recordDisplay();
        }
        fclose(fptr);
        }
        break;
    case 6:
         {
        FILE *fptr;
        char data[30];
        fptr = fopen("BankRecord.ods","r");
        printf("Enter  Mobile Number to  Search: ");
        gets(data);
        gets(data);
        while(!feof(fptr)){
        fread(&custRecord,sizeof(custRecord),1,fptr);
        if(!strcmp(custRecord.mobile,data))
            recordDisplay();
        }
        fclose(fptr);
        }
        break;
    case 7:
        menu();
        break;
    case 8:
        exit(1);
    default:
        printf("\nInvalid Choice");
        }

}
};












