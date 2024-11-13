#include <stdio.h>

//------------------------creating 3 user defined data types----------------------------------------
struct myDtype1
{
    int num;
    struct myDtype1 *ptr;
    void *ptrVoid;                    // taking void pointer to see if it will work with inconistent pointer error
}d1;                                   // variable d1 is created from struct myDtype1

struct myDtype2
{
    char ch;
    struct myDtype2 *ptr;
    void *ptrVoid;                    // taking void pointer to see if it will work with inconistent pointer error  

}d2;                                   // variable d2 is created from struct myDtype2

struct myDtype3
{
    double decimal;
    struct myDtype2 *ptr;
    void *ptrVoid;                    // taking void pointer to see if it will work with inconistent pointer error

}d3;                               // variable d3 is created from struct myDtype3

//++++++++++++++++++++++++++++end of creation of user defined data types++++++++++++++++++++++++++++++++++


void main()
{
    d1.num = 10;
    // d1.ptr = &d2;    failed attempt
    d1.ptrVoid = &d2;

    d2.ch = 'a';
    // d2.ptr = &d3;    failed attempt
    d2.ptrVoid = &d3;

    d3.decimal = 9.99;
    // d3.ptr = &d1;    failed attempt
    d3.ptrVoid = &d1;

    printf("\n\nd1.num = %d \n", d1.num);
    printf("d2.ch = %c \n", d2.ch);
    printf("d3.decimal = %.2lf \n\n", d3.decimal);

    // printf("d1.ptr = %c \n", d3.ptr->num);       failed attempt
    // printf("d2.ptr = %d \n", d1.ptr->ch);       failed attempt
    // printf("d3.ptr = %c \n", d2.ptr->decimal);       failed attempt


//  ---------------------------------------testing zone-------------------------------------------------

    //type casting to their datatypes resolved error
    printf("d1.voidPtr is pointing to d2 stuffs: \n d2.ch is   %c \n\n", ((struct myDtype2 *)d1.ptrVoid)->ch);      

     //type casting to their datatypes resolved error
     printf("d2.voidPtr is pointing to d3 stuffs: \n d3.decimal is   %g \n\n", ((struct myDtype3 *)d2.ptrVoid)->decimal);    

    //type casting to their datatypes resolved error
    printf("d3.voidPtr is pointing to d1 stuffs: \n d1.num is   %d \n\n", ((struct myDtype1 *)d3.ptrVoid)->num);     

  
// +++++++++++++++++++++++++++++ end of code ++++++++++++++++++++++++++++++++

}