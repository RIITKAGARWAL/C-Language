
extern void recordEntry()
{	
	system("cls");

	printf("ENTRY OF STUDENT RECORD\n\n\n");
	printf("\n\tEnter Your Name 	  			: ");
	gets(stud.name);
        gets(stud.name);
	printf("\n\tEnter Your Course				 : ");
	gets(stud.course);
	printf("\n\tEnter Your D.O.B(dd-mm-yyyy) 	: ");
	gets(stud.dob);
	printf("\n\tEnter Your Father's Name 		: ");
	gets(stud.father);
	printf("\n\tEnter Your Address 				: ");
	gets(stud.address);
	printf("\n\tEnter Your MobileNo 			 : ");
	gets(stud.mobile);
	printf("\n\tEnter Your EmailId 				: ");
	gets(stud.email);
	printf("\n\tEnter Your Roll Number			: ");
	scanf("%d",stud.roll);

	FILE *fptr;
	fptr = fopen("studRecord.txt","a");
	fwrite(&stud,sizeof(stud),1,fptr);
	fclose(fptr);
	


	printf("\n\n\tRecord Inserted Successfully...\n");	
	
	system("pause");

}