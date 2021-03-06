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
*                                       USER DEFINED DATA TYPES
*
************************************************************************************************/
typedef struct linked_list{
                                char info;
                                struct linked_list *link; //pointer to the next node
                           }node;

/************************************************************************************************
*
*                               FUNCTION DECLARATIONS
*
**************************************************************************************************/

void push(node **top,char ch);
char pop(node **top);
void free_list(node **top);
