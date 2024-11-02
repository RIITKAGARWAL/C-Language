#include <stdio.h>
#include <conio.h>
//-------------------global variable---------------------------
struct student
{
    int rollnum;
    char name[25];
	char address[30];
	int mobile[10];
	char g_mail[30];
    char course[25];
}stud;
//---------------------global varible declaration end----------
//------------------function definition area begining--------------------------
void create()
{
	FILE *fptr;
	struct student stud;
	int num;
	char choice;
	do
	{
		printf("How Many Record Do You Want To Store");
		scanf("%d",&num);
		for(int i=1;i<=num;i++)
		{	
			system("cls");
			printf("\tAdd Student Information");
			fptr=fopen("Student_Record.txt","w");
			printf("\nEnter Your RollNumber: ");
			scanf("%d",stud.rollnum);
			printf("\nEnter Your Name: ");
			gets(stud.name);
			gets(stud.name);
			printf("\nEnter Your Address: ");
			gets(stud.address);
			gets(stud.address);
			printf("\nEnter Your Mobilenum: ");
			scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",stud.mobile[0],stud.mobile[1],stud.mobile[2],stud.mobile[3],stud.mobile[4],stud.mobile[5],stud.mobile[6],stud.mobile[7],stud.mobile[8],stud.mobile[9],stud.mobile[10]);
			//printf("\nEnter Your Gmail ID");
			//scanf("%[]s",$stud.g_mail);
			printf("\nEnter Your course: ");
			scanf("%[]s",stud.course);

			fwrite(&stud,sizeof(stud),1,fptr);
			fclose(fptr);
	} 
	}while((choice=='y')||(choice=='Y'));
}
void display()
{

}
void append()
{

}
void search()
{

}
void del()
{

}


//------------------function definition area end--------------------------


void main()
	{
        int choice;

	    do
		{
			printf("\n1.create record");
			printf("\n2.display record");
			printf("\n3.append record");
			printf("\n4.search record");
			printf("\n5.delete record");
			printf("\n0.exit");

			printf("\nenter your choice: ");
			scanf("%d",&choice);

			switch(choice)
            {
				case 1:
					system("cls");
					create();
                    break;
				case 2:
					system("cls");
					display();
                    break;
				case 3:
					system("cls");
					append();
					break;
				case 4:
					system("cls");
					search();
					break;
				case 5:
					system("cls");
					del();
					break;
                case 0:
                    printf("\nThanks...");				
			}
		}
            while(choice!=0);


	}