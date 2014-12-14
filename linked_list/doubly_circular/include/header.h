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
                                int info;
                                struct linked_list *next; //pointer to the next node
				struct linked_list *prev; //pointer to the previous node
                           }node;

/************************************************************************************************
*
*                               FUNCTION DECLARATIONS
*
**************************************************************************************************/

void create(node **start);

void insert_empty(node **start);

void insert_beginning(node **start);

void insert_end(node **start);

void insert_after(node **start);

void insert_before(node **start);

void delete_node(node **start);

void display(node **start);

void count(node **start);

void free_list(node **start);

