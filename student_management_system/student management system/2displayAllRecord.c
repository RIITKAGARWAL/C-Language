
extern void recordDisplay()
{
	FILE *fptr;
	fptr = fopen("studRecord.txt","r");

while(!feof(fptr))
   {
	system("cls");
	
	fread(&stud,sizeof(stud),1,fptr);

	printf("\033[1mSTUDENT RECORD DISPLAY***\n\n");
	printf("\t%s\n",stud.name);
	printf("\tCourse		: %s\n",stud.course);
	printf("\tSession		: %s\n",stud.session);
	printf("\tRoll no		: %d\n",stud.roll);
	printf("\tDOB			: %s\n",stud.dob);
	printf("\tFather's Name	: %s\n",stud.father);
	printf("\tAddress		: %s\n",stud.address);
	printf("\tContact No 	: %s\n",stud.mobile);
	printf("\tEmail ID 		: %s\n",stud.email);
	
	printf("\nDo You Want To Display Another record: (Y/N)");
	char choice;
	scanf("%c",choice);
	if(choice=='n'||choice=='N')
		break;
	system("pause");
   }

   fclose(fptr);
}