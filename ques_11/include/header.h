/*********************************************************************************************************************************
*	FILE NAME : header.h
*
*	DESCRIPTION : contains header files, macros, userdefined datatypes and function declarartions
*
*	NAME		ID	DATE	REASON
*--------------------------------------------------------------------------------------------------------------------------------
*PRAVEEN CHAUBEY	38263	7/12/14	CDSA RE TEST
************************************************************************************************************************************/

/*********************************************************************************************************************************
*				HEADER FILES
*
***************************************************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*********************************************************************************************************************************
*				MACROS
*
***************************************************************************************************************************************/
#define SUCCESS 0
#define	FAILURE 1
#define	MAX 100


/*********************************************************************************************************************************
*				USER DEFINED DATATYPES
*
***************************************************************************************************************************************/
typedef struct tree{
			struct tree *lchild; //pointer for left child
			char info[MAX];
			struct tree *rchild; //pointer for right child
		}node;

typedef struct queue{
			node *info; //pointer to the tree node
			struct queue *link; //pointer to the next node
		}qnode;


/*********************************************************************************************************************************
*				FUNCTIONS DECLARATIONS
*
***************************************************************************************************************************************/
void file_open(FILE **fp, char *file_name, char *mode);
void file_close(FILE **fp);
void insert_bst(node **root, char input[],int *duplicates);
void insert_file(node **root, FILE **fp);
void insert_queue(node **ptr, qnode **front, qnode **rear);
void delete_queue(qnode **front, qnode **rear, FILE **fp);
void free_bst(node **root);
