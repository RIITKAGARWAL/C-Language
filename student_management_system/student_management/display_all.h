
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
void display()
{
    system("cls");
    printf("\033[1m\033[4m***          Student record Display          ***");
    printf("\n\n\t%s\033[0m", stud.name);
    printf("\ncourse: %s", stud.course);
    printf("\nRoll: %d", stud.roll);
    printf("\nD.O.B: %s", stud.dob);
    printf("\nFather name: %s", stud.father);
    printf("\nAddress: %s", stud.address);
    printf("\nMobile number: %s", stud.mob);
    printf("\nEmail: %s", stud.email);
    printf("\n\033[1m\033[4m*                                                 *\033[0m\n");
}
void display_all_record()
{
    FILE *fptr;
    fptr = fopen("data.txt", "r");

    while (1)
    {
        if (!fread(&stud, sizeof(stud), 1, fptr))
        {
            printf("All available records are printed\n");
            break;
        }
        display();
        printf("For next record press any key...\n else press (N): ");
        char choice;
        fflush(stdin);
        scanf("%c", &choice);
        if (choice == 'N' || choice == 'n')
        {
            break;
        }
        else
            continue;
    }
    fclose(fptr);
}
union std1
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

void display_specific()
{
    FILE *fptr;
    union std1 std1;
    fptr = fopen("data.txt", "r");
    system("cls");
    printf("\033[1m\033[4m***          Chose the Search parameter          ***\033[0m\n");
    printf("\t1.Name\n");
    printf("\t2.Course\n");
    printf("\t3.Roll\n");
    printf("\t4.D.O.B.\n");
    printf("\t5.Father's Name\n");
    printf("\t6.Moblie number\n");
    printf("\t7.Email\n");
    printf("\n\033[1m\033[4m*                                                 *\033[0m\n");

    int choice;
    printf("Enter your choice: ");
    fflush(stdin);
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Enter the name: ");
        fflush(stdin);
        gets(std1.name);
        break;
    case 2:
        printf("Enter the course: ");
        fflush(stdin);
        gets(std1.course);
        break;
    case 3:
        printf("Enter the Roll number: ");
        fflush(stdin);
        scanf("%d", &std1.roll);
        break;
    case 4:
        printf("Enter the D.O.B.: ");
        fflush(stdin);
        gets(std1.roll);
        break;
    case 5:
        printf("Enter the Father's name: ");
        fflush(stdin);
        gets(std1.father);
        break;
    case 6:
        printf("Enter the Mobile Number: ");
        fflush(stdin);
        gets(std1.mob);
        break;
    case 7:
        printf("Enter the Email: ");
        fflush(stdin);
        gets(std1.email);
        break;
    default:
        printf("invalid choice");
        goto out;
    }
    int flag = 0;
    while (1)
    {
        if (!fread(&stud, sizeof(stud), 1, fptr))
        {
            if (flag != 0)
                printf("\nAll available records are printed\n");
            break;
        }

        char ch;
        switch (choice)
        {
        case 1:
            if (strncmp(stud.name, std1.name, strlen(std1.name)) == 0)
            {
                display();
                flag = 1;
                printf("For next record press any key...\n else press (N): ");
                fflush(stdin);
                scanf("%c", &ch);
            }
            break;
        case 2:
            if (strncmp(stud.course, std1.course, strlen(std1.course)) == 0)
            {
                display();
                flag = 1;
                printf("For next record press any key...\n else press (N): ");
                fflush(stdin);
                scanf("%c", &ch);
            }
            break;
        case 3:
            if (stud.roll == std1.roll)
            {
                display();
                flag = 1;
                printf("For next record press any key...\n else press (N): ");
                fflush(stdin);
                scanf("%c", &ch);
            }
            break;
        case 4:
            if (strncmp(stud.roll, std1.roll, strlen(std1.roll)) == 0)
            {
                display();
                flag = 1;
                printf("For next record press any key...\n else press (N): ");
                fflush(stdin);
                scanf("%c", &ch);
            }
            break;
        case 5:
            if (strncmp(stud.father, std1.father, strlen(std1.father)) == 0)
            {
                display();
                flag = 1;
                printf("For next record press any key...\n else press (N): ");
                fflush(stdin);
                scanf("%c", &ch);
            }
            break;
        case 6:
            if (strncmp(stud.mob, std1.mob, strlen(std1.mob)) == 0)
            {
                display();
                flag = 1;
                printf("For next record press any key...\n else press (N): ");
                fflush(stdin);
                scanf("%c", &ch);
            }
            break;
        case 7:
            if (strncmp(stud.email, std1.email, strlen(std1.email)) == 0)
            {
                display();
                flag = 1;
                printf("For next record press any key...\n else press (N): ");
                fflush(stdin);
                scanf("%c", &ch);
            }
            break;
        default:
            printf("invalid choice");
            goto out;
        }
        if (ch == 'N' || ch == 'n')
        {
            break;
        }
        else
            continue;
    }
out:
    fclose(fptr);

    if (flag == 0)
        printf("\nNo record Found!\n");
}