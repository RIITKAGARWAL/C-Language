void update_record()
{
    system("cls");
    printf("\033[4m\033[1m****             Update record              ****\033[0m\n");
    printf("\nEnter the Roll number on which you want to update: ");
    int roll;
    fflush(stdin);
    scanf("%d", &roll);
    printf("\n\033[1m\033[4m*                                                 *\033[0m\n");

    FILE *fptr1;
    FILE *fptr2;
    struct student stud;
    fptr1 = fopen("data.txt", "r");
    fptr2 = fopen("temp.txt", "w");

    int flag = 0;
    system("cls");
    printf("\033[1m\033[4m***          Chose which field you want to update          ***\033[0m\n");
    printf("\t1.Name\n");
    printf("\t2.Course\n");
    printf("\t3.Roll\n");
    printf("\t4.D.O.B.\n");
    printf("\t5.Father's Name\n");
    printf("\t6.Address\n");
    printf("\t7.Moblie number\n");
    printf("\t8.Email\n");
    printf("\n\033[1m\033[4m*                                                 *\033[0m\n");
    int choice;
    printf("Enter your choice: ");
    fflush(stdin);
    scanf("%d", &choice);
    union std1 std1;

    switch (choice)
    {
    case 1:
        printf("Enter the new name: ");
        fflush(stdin);
        gets(std1.name);
        break;
    case 2:
        printf("Enter the new course: ");
        fflush(stdin);
        gets(std1.course);
        break;
    case 3:
        printf("Enter the new Roll: ");
        fflush(stdin);
        scanf("%d", &std1.roll);
        break;
    case 4:
        printf("Enter the new D.O.B.: ");
        fflush(stdin);
        gets(std1.roll);
        break;
    case 5:
        printf("Enter the new Father's name: ");
        fflush(stdin);
        gets(std1.father);
        break;
    case 6:
        printf("Enter the new Address: ");
        fflush(stdin);
        gets(std1.address);
        break;
    case 7:
        printf("Enter the Mobile Number: ");
        fflush(stdin);
        gets(std1.mob);
        break;
    case 8:
        printf("Enter the Email: ");
        fflush(stdin);
        gets(std1.email);
        break;
    default:
        printf("invalid choice");
    }

    while (1)
    {
        if (!fread(&stud, sizeof(stud), 1, fptr1))
        {
            break;
        } 
        
        if (stud.roll == roll)
        {
            flag = 1;
            switch (choice)
            {
            case 1:
                strcpy(stud.name,std1.name);
                break;
            case 2:
                strcpy(stud.course,std1.course);
                break;
            case 3:
                stud.roll=std1.roll;
                break;
            case 4:
                strcpy(stud.dob,std1.dob);
                break;
            case 5:
                strcpy(stud.father,std1.father);
                break;
            case 6:
                strcpy(stud.address,std1.address);
                break;
            case 7:
                strcpy(stud.mob,std1.mob);
                break;
            case 8:
                strcpy(stud.email,std1.email);
                break;
            default:
                printf("invalid choice");
                goto out;
            }
        }
        fwrite(&stud, sizeof(stud), 1, fptr2);
    }
out:
    fclose(fptr1);
    fclose(fptr2);
    if (flag = 0)
    {
        printf("\nRoll Not found!\n");
        remove("temp.txt");
    }
    else
    {
        remove("data.txt");
        rename("temp.txt","data.txt");
    }
}