/********************************************************************************************
 *
 *       FILE NAME:      header.h
 *
 *       DESCRIPTION:    Contains header files, macros and function prototypes.
 *
 ************************************************************************************************/

/*********************************************************************************************
 *                               HEADER FILES
 *
 **********************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*********************************************************************************************
 *                                       Macros
 *
 ************************************************************************************************/
#define MAX 10

/************************************************************************************************
 *
 *                               FUNCTION DECLARATIONS
 *
 **************************************************************************************************/

void insert_item(int *rear,int *front,int array[]);
void delete_item(int *rear,int *front,int array[]);
void display(int *rear,int *front,int array[]);

