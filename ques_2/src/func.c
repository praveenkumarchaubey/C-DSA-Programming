/*********************************************************************************************
*	FILE NAME : func.c
*
*	DESCRIPTION : contains function definations
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
#include "header.h"

/*******************************************************************************************
*	FUNCTION NAME : file_open
*
*	DESCRIPTION : opens a file
*
*	RETURN VALUE : nothing
*
**************************************************************************************************/
void file_open(FILE **fp, char *file_name, char *mode)
{
	*fp = fopen(file_name, mode);//opens a file in the given mode

	/*Error handling*/
	if(NULL == *fp)
	{
		printf("Error in opening the file %s\n", file_name);
		exit(FAILURE);
	}
	else
	{
		printf("File %s opens successfully\n",file_name);
	}
}


/*******************************************************************************************
*	FUNCTION NAME : file_close
*
*	DESCRIPTION : closes a file
*
*	RETURN VALUE : nothing
*
**************************************************************************************************/
void file_close(FILE **fp)
{
	int n;
	n = fclose(*fp); //closes an opened file
	/*error handling*/
	if(EOF == n)
	{
		printf("Error in closing the file\n");
	}
	else
	{
		printf("File closed successfully\n");
	}
}

/*******************************************************************************************
*	FUNCTION NAME : insert_list
*
*	DESCRIPTION : insert an element into the linked list
*
*	RETURN VALUE : nothing
*
**************************************************************************************************/
void insert_list(node **start, char *token)
{
	node *new;//new node to be inserted
	node *temp; //temporary node for traversing
	new = (node *) malloc(sizeof(node));//allocating memory to the new node

	/*if memory allocation is successfull*/
	if(NULL != new)
	{
		strcpy(new->info,token);//inserting data into the new node
		new->link = NULL;//new node is the last node

		/*if the list is empty*/
		if(NULL == *start)
		{
			*start = new;
		}

		/*if list is not empty*/
		else
		{
			temp = *start;
			/*traverse the list till end*/
			while(NULL != temp->link)
			{
				temp = temp->link;
			}
			temp->link = new; //last node points to the new node
		}
	}
	/*if memory allocation fails*/
	else
	{
		printf("Error in allocating memory\n");
		exit(FAILURE);
	}

}

/*******************************************************************************************
*	FUNCTION NAME : free_list
*
*	DESCRIPTION : free the linked ist
*
*	RETURN VALUE : nothing
*
**************************************************************************************************/
void free_list(node **start)
{
	node *temp;//temporary variable for storing the node to be freed

	while(NULL != *start)
	{
		temp = *start;
		*start = (*start)->link; //update start pointer
		free(temp); //free the node
	}
}

/*******************************************************************************************
*	FUNCTION NAME : inser_file
*
*	DESCRIPTION : insert only even length words into the file in reverse order 
*
*	RETURN VALUE : nothing
*
**************************************************************************************************/
void insert_file(node **start, FILE **fp)
{
	node *temp; //temporary variable for teaversing the list;
	temp = *start;
	int count = 0; //node count
	int i; //loop count

	/*counting the number of nodes in the list*/
	while(NULL != temp)
	{
		temp = temp->link;
		++count;
	}

	do
	{
		temp = *start;
		/*traversing till the end every time*/
		for(i=count; i>1 ;i--)
		{
			temp = temp->link;
		}
		--count; //decrementing count in every iteration of while loop

		/*check for odd or even length of the string*/
		if(0 == (strlen(temp->info) % 2))
		{
			fprintf(*fp, "%s", temp->info); //writing to the output file
			fprintf(*fp, "\n");
		}
	}while(temp!=*start); //terminating condition
}

