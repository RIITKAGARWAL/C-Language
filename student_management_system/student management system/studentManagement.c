#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bhaloo{
	char course[10];
	int roll;
	char name[30];
	char dob[12];
};
struct bhaloo raj;
void main(){
FILE *fptr;
fptr  = fopen("C:/Users/agarw/OneDrive/Desktop/student project/studRecord.txt","w");
if(fptr == NULL)
	{
		printf("File not Created");
		exit(0);
	}

strcpy(raj.name, "rajeev");
strcpy(raj.course,"BCA");
strcpy(raj.dob,"23-08-1998");
raj.roll = 22014;

fwrite(&raj,sizeof(raj),1,fptr);

printf("\nFile created successfully");
fclose(fptr);


}