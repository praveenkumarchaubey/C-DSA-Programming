/**********************************************************************************************************************
*	FILE NAME : func.c
*
*	DESCRIPTION : contains function definations 
*
*	NAME		ID	DATE		REASON
*---------------------------------------------------------------------------------------------------------------------
*	PRAVEEN CHAUBEY	38263	2/12/14		RE TEST PREP
***************************************************************************************************************************/

/************************************************************************************************************************
*
*				HEADER FILES
*
**********************************************************************************************************************/
#include "header.h"

/***********************************************************************************************************************************************
*	FUNCTION NAME : file_open
*
*	DESCRIPTION : opens a file
*
*	RETURN VALUE : nothing
*
**************************************************************************************************************************************************/
void file_open(FILE **fp, char *file_name, char *mode)
{
	*fp = fopen(file_name, mode);
	/*error handling for file opening*/
	if(NULL == *fp)
	{
		printf("Error in opening the file %s\n",file_name);
		exit(FAILURE);
	}
	else
	{
		printf("File %s opened successfully\n",file_name);
	}
}


/***********************************************************************************************************************************************
*	FUNCTION NAME : file_close
*
*	DESCRIPTION : closes a file
*
*	RETURN VALUE : nothing
*
**************************************************************************************************************************************************/
void file_close(FILE **fp)
{
	int n;
	n = fclose(*fp);
	/*error handling for file closing*/
	if(EOF == n)
	{
		printf("Error in closing the file\n");
	}
	else
	{
		printf("File closed successfully\n");
	}
}

/***********************************************************************************************************************************************
*	FUNCTION NAME : free_list
*
*	DESCRIPTION : free the linked list
*
*	RETURN VALUE : nothing
*
**************************************************************************************************************************************************/
void free_list(node **start)
{
	node *temp;
	while(*start != NULL)
	{
		temp = *start;
		*start = (*start)->link;
		free(temp);
	}

}

/***********************************************************************************************************************************************
*	FUNCTION NAME : insert_list
*
*	DESCRIPTION : inserts an elemnt into a list
*
*	RETURN VALUE : nothing
*
**************************************************************************************************************************************************/
void insert_list(node **start, char *string)
{
	node *new; //new node
	node *temp;//temporary node for traversal
		
	new = (node *) malloc(sizeof(node)); //allocating memory to the new node
	if(NULL != new)
	{
		strcpy(new->info, string);//copying token into the new node
		new->link = NULL;//new node is the last node
		/*if list is empty*/
		if(NULL == *start)
		{
			*start = new;
		}
		/*if lis is not empty*/
		else
		{
			temp = *start;
			while(NULL != temp->link)
			{
				temp = temp->link;
			}
			temp->link = new;
		}
	}
	else
	{
		printf("Error in memory allocation\n");
		exit(FAILURE);
	}

}

/**************************************************************************************************************************
*	FUNCTION NAME : insert_file
*
*	DESCRIPTION : inserts the contents of the linked list in the output file
*
*	RETURN VALUE : nothing
*
*************************************************************************************************************************/
void insert_file(FILE **fp,node **start, char *string)
{
	node *temp;
	int len = 0;
	temp = *start;
	while(NULL != temp)
	{
		len = strlen(temp->info);
		if(0 == (len % 2))
		{
			strcat(temp->info, string);
			fprintf(*fp, "%s",temp->info);
			fprintf(*fp, "\n");
		}
		temp = temp->link;
	}

}

