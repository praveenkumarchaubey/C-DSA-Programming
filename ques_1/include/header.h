/******************************************************************************************************
*	FINE NAME : header.h
*
*	DESCRIPTION : contains header files along with macros and user defined functions for merging
*		      two sorted linked list into a third linked list
*
*	NAME		ID		DATE		REASON
*-----------------------------------------------------------------------------------------------------
*	PRAVEEN CHAUBEY	38263		28/11/2014	RE TEST PPEPERATION	
*
**********************************************************************************************************/

/********************************************************************************************************
*
*			HEADER FILES
*
*********************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/********************************************************************************************************
*
*			MACROS
********************************************************************************************************/
#define SUCCESS 0
#define FAILURE 1
#define MAX 100


/********************************************************************************************************
*
*			USER DEFINED DATA TYPE
********************************************************************************************************/
typedef struct linked_list{
				char info[MAX];
				struct linked_list *link;
			}node;
			

/********************************************************************************************************
*
*			FUNCTIONS DECLARATIONS
********************************************************************************************************/
void file_open(FILE **fp, char *file_name, char *file_mode);
void file_close(FILE **fp);
void insert_list(node **start, char name[]);
void display_list(node **start);
node *merge_list(node **start1, node **start2);
void write_output(FILE **fp, node **start);
void free_list(node **start);
