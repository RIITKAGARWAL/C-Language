#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-------------------variable section-------------------------
char datee[12] ;
char dob[12];
char asOnDate[12];
char str[5];
int birDate,birYear,birMonth;
int currMonth,currDate,currYear;
int ageDay,ageMonth,ageYear;

//------------------------------------------------------------

char* subString(char *destStr,char *srcStr,int pos,int len){
int ctr;
strcpy(destStr,"");
for(ctr=pos ; ctr< pos+len ;ctr++)
	destStr[ctr-pos] = srcStr[ctr];
return destStr;
}

int monthConverter(){
if(strcmp(str,"Jan") == 0)
 return 1;
else if(strcmp(str,"Feb") == 0)
 return 2;
else if(strcmp(str,"Mar") == 0)
 return 3;
else if(strcmp(str,"Apr") == 0)
 return 4;
else if(strcmp(str,"May") == 0)
 return 5;
else if(strcmp(str,"Jun") == 0)
 return 6;
else if(strcmp(str,"Jul") == 0)
 return 7;
else if(strcmp(str,"Aug") == 0)
 return 8;
else if(strcmp(str,"Sep") == 0)
 return 9;
else if(strcmp(str,"Oct") == 0)
 return 10;
else if(strcmp(str,"Nov") == 0)
 return 11;
else if(strcmp(str,"Dec") == 0)
 return 12;
}

void currDateFetcher(){
strcpy(datee, __DATE__);


currDate = atoi(subString(str,datee,4,3));
currYear = atoi(subString(str,datee,7,5));
subString(str,datee,0,3);
str[3] = '\0';
currMonth = monthConverter();
}
void dobFetcher(){
printf("\nEnter Your Date of Birth (dd-mm-yyyy): ");

gets(dob);
//gets(dob);

str[2]='\0';
birDate  = atoi(subString(str,dob,0,2));
str[2]='\0';
birMonth  = atoi(subString(str,dob,3,2));
birYear = atoi(subString(str,dob,6,5));
printf("\n%d %d %d ",birDate,birMonth,birYear);
};

void dateFetcher(){
printf("\nEnter the Date (dd-mm-yyyy): ");

gets(asOnDate);
gets(asOnDate);


str[2]='\0';
currDate  = atoi(subString(str,asOnDate,0,2));

str[2]='\0';

currMonth  = atoi(subString(str,asOnDate,3,2));


currYear = atoi(subString(str,asOnDate,6,5));


printf("\n%d %d %d ",currDate,currMonth,currYear);


};
int totalDayInMonth(){
if(((birMonth % 2 != 0) && (birMonth <=7)) || ((birMonth % 2 == 0) && (birMonth > 7)) )
 return 31;
else{
    if(birMonth == 2)
        if (birYear % 4 == 0 && birYear % 400 != 0 )
            return 29;
        else
            return 28;

    else
        return 30;
}


}
void ageFinder(){
 if(currDate >= birDate)
    ageDay = currDate - birDate;
 else
    ageDay = totalDayInMonth() - birDate + currDate;

if (currMonth >= birMonth)
{
    ageYear = currYear - birYear;
    if(currDate >= birDate)
        ageMonth = currMonth - birMonth;
    else
        ageMonth = currMonth - birMonth -1;
}
else
{
    ageYear = currYear - birYear -1;
     if(currDate >= birDate)
        ageMonth = (12 - birMonth) + currMonth;

    else
        ageMonth = currMonth + (12 - birMonth) -1;
}
printf("\n\n--------------------------------------\n");
printf("Age is ...\n");
printf("\nYear  : %d",ageYear);
printf("\nMonth : %d",ageMonth);
printf("\nDays  : %d",ageDay);
}
void menu(){
    int choice;
    while(1){
        system("cls");
        printf("-----------Welcome to Age Finder-------------------------\n\n");
        printf("\n1.Age as on Date: ");
        printf("\n2.Age as on Current Date " );
        printf("\n3.Exit " );

        printf("\n\n-----------------------------------------------------------");
        printf("\nPlease Enter Your Choice (1 or 2 or 3) : ");
        scanf("%d",&choice);

    switch(choice){
    case 1:
        system("cls");
        dateFetcher();
        dobFetcher();
        ageFinder();
        getch();
        break;

    case 2:
        system("cls");
        currDateFetcher();
        dobFetcher();
        ageFinder();
        getch();
        break;

    case 3:
        exit(0);
        break;

    }

    }
}
void main(){
menu();



}
