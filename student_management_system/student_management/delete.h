
void delete_record()
{
    system("cls");
    printf("\033[4m\033[1m****             Update record              ****\033[0m\n");
    printf("\nEnter the Roll number, which you want to Delete: ");
    int roll;
    fflush(stdin);
    scanf("%d", &roll);
    printf("\n\033[1m\033[4m*                                                 *\033[0m\n");
    FILE *fptr1;
    FILE *fptr2;
    struct student stud;
    {
        /* data */
    };
    int flag=0;
    fptr1 = fopen("data.txt", "r");
    fptr2 = fopen("temp.txt", "w");
    while(1)
    {
        if(!fread(&stud,sizeof(stud),1,fptr1))
        {
            break;
        }
        if(stud.roll!=roll)
        {
            fwrite(&stud,sizeof(stud),1,fptr2);
        }
        else
            flag=1;
    }
    fclose(fptr1);
    fclose(fptr2);
    if(flag==0)
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