FILE *fptr;
        char data[30];
        fptr = fopen("BankRecord.ods","r");
        printf("Enter  Name to  Search: ");
        gets(data);
        gets(data);
        int flag = 0;
        while(!feof(fptr)){
        fread(&custRecord,sizeof(custRecord),1,fptr);
        if(!strcmp(custRecord.name,data))
        {
           flag++;

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

printf("Is it Your Record ? : (y/n)  ");
char choice = getche();
if(choice == 'y')
            break;
        }
}
if(flag==0)
    printf("\nsorry data not found");
else if (choice == 'y')
    {
        while(1)
            {
                fseek(fptr,sizeof(custRecord),SEEK_CUR);
                if(feof(fptr))
                    break;
                fread(&custRecord,sizeof(custRecord),1,fptr);
                fseek(fptr,sizeof(custRecord)*(-1),SEEK_CUR);
                fwrite(&custRecord,sizeof(custRecord),1,fptr);
            }
        fseek(fptr,sizeof(custRecord)*-1,SEEK_END);
        fputc(EOF);

    }
        fclose(fptr);
        }
