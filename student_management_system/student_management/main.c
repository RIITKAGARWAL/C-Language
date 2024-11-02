#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entry_record.h"
#include "display_all.h"
#include "update.h"
#include "delete.h"


void main()
{
    void (*funptr[])() = {student_entry, display_all_record, display_specific, update_record, delete_record, exit};
    int choice;
    while (1)
    {
        system("cls");
        printf("\033[4m\033[1m****  Welcome  to the student management  ****\033[0m");
        printf("\n\n");
        printf("\t1.Enter student record.\n");
        printf("\t2.Display all student record\n");
        printf("\t3.Search specific student\n");
        printf("\t4.Update record\n");
        printf("\t5.Delete record.\n");
        printf("\t6.Exit\n");
        printf("\033[4m*                                             *\033[0m\n");
        printf(" Enter your choice: ");
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 6)
            (*funptr[--choice])();
        else
            printf("\ninvalid choice\n");
        system("pause");
    }
}