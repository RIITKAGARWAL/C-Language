

void deleteRecord(){
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

            switch(choice)
                {
                    case 1:
                      {


                        FILE *fptr;
                        char data[30];
                        fptr = fopen("BankRecord.ods","r");
                        printf("Enter  Name to  Search: ");
                        gets(data);
                        gets(data);

                        int flag = 0;
                        while(!feof(fptr))
                            {
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
                               // fputc('-1');

                            }
                        fclose(fptr);
                        break;
                      }
    case 2:
        break;
    case 3:
         {
        FILE *fptr;
        int data,flag = 0;
        fptr = fopen("BankRecord.ods","r");
        printf("Enter Age to  Search: ");
        scanf("%d",&data);
        while(!feof(fptr)){
        fread(&custRecord,sizeof(custRecord),1,fptr);
        if(custRecord.age==data)
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

    }
        fclose(fptr);
        }
        break;
    case 4:
         {
        FILE *fptr;
        char data[30];
        int flag = 0;
        fptr = fopen("BankRecord.ods","r");
        printf("Enter  Gender to  Search: ");
        gets(data);
        gets(data);
        while(!feof(fptr)){
        fread(&custRecord,sizeof(custRecord),1,fptr);
        if(!strcmp(custRecord.gender,data))
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

    }
        fclose(fptr);
        }
        break;
    case 5:
         {
        FILE *fptr;
        char data[30];
        int flag = 0;
        fptr = fopen("BankRecord.ods","r");
        printf("Enter  Email to  Search: ");
        gets(data);
        gets(data);
        while(!feof(fptr)){
        fread(&custRecord,sizeof(custRecord),1,fptr);
        if(!strcmp(custRecord.email,data))
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


    }
        fclose(fptr);
        }
        break;
    case 6:
         {
        FILE *fptr;
        char data[30];
        int flag = 0;
        fptr = fopen("BankRecord.ods","r");
        printf("Enter  Mobile Number to  Search: ");
        gets(data);
        gets(data);
        while(!feof(fptr)){
        fread(&custRecord,sizeof(custRecord),1,fptr);
        if(!strcmp(custRecord.mobile,data))
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

}
