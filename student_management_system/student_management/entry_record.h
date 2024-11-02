
int emailCheck(char * email)
{
    int i=0;
    int a=0,dot=0,flag1=0,flag2=0;
    while(email[i]!='\0')
    {
        if(!((email[i]>=48&&email[i]<=57)||(email[i]>=97&&email[i]<=122)||email[i]=='@'||email[i]=='.'))
            return 1;
        if(email[i]=='@')
        {
            a=i;
            flag1++;
        }
        if(email[i]=='.')
        {
            dot=i;
            flag2++;
        }
        i++;
    }
    if(flag1!=1&&flag2!=1)
        return 1;
    else
    {
        if((a+1)<dot)
            return 0;
    }

}

void student_entry()
{
    struct student
    {
        char name[30];
        char course[10];
        char dob[13];
        char father[30];
        char address[60];
        char mob[11];
        char email[60];
        int roll;
    };
    struct student stud;
    while (1)
    {
        system("cls");
        printf("\033[4m\033[1m***               Entry of student record               ***\033[0m");
        printf("\n\n");
        printf("\tEnter your Name : ");
        fflush(stdin);
        gets(stud.name);
        printf("\tEnter your cource :");
        gets(stud.course);
        printf("\tEnter your roll number: ");
        scanf("%d", &stud.roll);
        fflush(stdin);
        printf("\tEnter your D.O.B. (dd-mm-yyyy) : ");
        gets(stud.dob);
        printf("\tEnter your Father's Name : ");
        gets(stud.father);
        printf("\tEnter your Address: ");
        gets(stud.address);
        printf("\tEnter your Mobile Number : ");
        retake_mob:
        gets(stud.mob);
        if(strlen(stud.mob)!=10)
        {
            printf("Enter a valid Mobile number: ");
            goto retake_mob;
        }

        printf("\tEnter your Email Id : ");
        retake_email:
        gets(stud.email);
        if(emailCheck(stud.email))
        {
            printf("Enter a valid Email: ");
            goto retake_email;
        }
        printf("\n\033[4m*                                                       *\033[0m\n");
        printf("\nDo you want add this record(Y/N): ");
        char choice;
        scanf("%c", &choice);
        if (choice == 'Y' || choice == 'y')
        {
            FILE *fptr;
            fptr = fopen("data.txt", "a");
            if (fptr == NULL)
                break;
            fwrite(&stud, sizeof(stud), 1, fptr);
            fclose(fptr);
        }

        printf("Do you want to add more record(Y/N): \n");
        fflush(stdin);
        scanf("%c", &choice);
        if (choice == 'Y' || choice == 'y')
            continue;
        else
            break;
    }
}