#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


//-------------global variable declaration----------------------------
struct student{
	int roll;
	char name[30];
	char course[10];
	char session[12];
	char dob[12];
	char father[30];
	char address[100];
	char mobile[11];
	char email[40];

}stud;

//-------------global variable declaration----------------------------

//---------------------function prototypes----------------------------
extern void recordEntry();
extern void recordDisplay();


//--------------------function prototypes----------------------------

void main()
{
	int num;
	while(1)
	{
		system("cls");
		printf("\033[1m  \033[4mWELCOME TO THE STUDENT MANAGEMENT SYSTEM\033[0m\n\n");
		
		printf("\t\033[1m 1.Enter Student Record\n");
		printf("\t\033[1m 2.Display All Student Record\n");
		printf("\t\033[1m 3.Search Specific Student\n");
		printf("\t\033[1m 4.Update Record\n");
		printf("\t\033[1m 5.Delete\n");
		printf("\t\033[1m 6.Exit\n\n");
		
		printf("\n\033[1m Enter Your Choice:  ");
		scanf("%d",&num);
			switch(num)
			{
				case 1:
					recordEntry();
				   break;
				case 2:
					recordDisplay();
				    break;
				case 3:
				   break;
				case 4:
				    break;
				case 5:
				   break;
				case 6:
					exit(0);
				default:
				    printf("\n\033[1mInvalid Choice");
			}
	}

}