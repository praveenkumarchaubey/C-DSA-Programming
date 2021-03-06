/*********************************************************************************************
 *	FILE NAME : header.h
 *
 *	DESCRIPTION : contains header files, macros, user defined data types and function
 *			prototypes for the implementation of given problem
 *
 *	NAME			ID	DATE		REASON
 *-----------------------------------------------------------------------------------------------
 *	Praveen Chaubey		38263	1/12/14 	Re test preperation
 *
 *************************************************************************************************/

/*********************************************************************************************
 *
 *		HEADER FILES
 *
 ********************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*********************************************************************************************
 *
 *		MACROS
 *
 ********************************************************************************************/
#define SUCCESS 0
#define FAILURE 1
#define MAX 50

/*********************************************************************************************
 *
 *		USER DEFINED DATA TYPE
 *
 ********************************************************************************************/
typedef struct list{
    char info[MAX];
    struct list *link;
}node;

/*********************************************************************************************
 *
 *		FUNCTION PROTOTYPES
 *
 ********************************************************************************************/
void file_open(FILE **fp, char *file_name, char *mode);
void insert_list(node **start, char *token);
void insert_list_position(node **start, char *token, int *position);
void display_list(node **start);
void file_close(FILE **fp);
void free_list(node **start);

