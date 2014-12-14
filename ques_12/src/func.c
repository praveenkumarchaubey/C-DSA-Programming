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

		/*if the list is empty*/
		if(NULL == *start)
		{
			new->link = new;
			*start = new;
		}

		/*if list is not empty*/
		else
		{
			temp = *start;
			/*traverse the list till end*/
			while(*start != temp->link)
			{
				temp = temp->link;
			}
			new->link = temp->link;
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
        node *temp; //pointer to point the node to be deleted
	node *ptr;
	ptr = (*start)->link;

	//traverse till end node
	while(ptr!= *start)
	{
		temp = ptr;
		(*start)->link = ptr->link;
		ptr=ptr->link;
		free(temp);
	}

	//free the only node 
	if((*start)->link == *start)
	{
		free(ptr);
		*start=NULL;
	}
	
}//end free_list
/*******************************************************************************************
*	FUNCTION NAME : display_list
*
*	DESCRIPTION : display the list 
*
*	RETURN VALUE : nothing
*
**************************************************************************************************/
void display_list(node **start)
{
        node *temp;
        temp=*start;
        do
        {
                printf("%s\n",temp->info);
                temp=temp->link;
        }while(temp!=*start);
}/*End of display() */

/*******************************************************************************************
*	FUNCTION NAME : insert_list_position
*
*	DESCRIPTION : insert an element into the linked list
*
*	RETURN VALUE : nothing
*
**************************************************************************************************/
void insert_list_position(node **start, char *token, int *position)
{
	node *new;//new node to be inserted
	node *temp; //temporary node for traversing
	new = (node *) malloc(sizeof(node));//allocating memory to the new node
	int i;

	/*if memory allocation is successfull*/
	if(NULL != new)
	{
		strcpy(new->info,token);//inserting data into the new node

		/*if list is not empty*/
		if(*start != NULL)
		{
			temp = *start;
			while(*start != temp->link)
			{
				/*traverse the list till end*/
				for(i=1; i< *position; i++)
				{
					temp = temp->link;
				}
				new->link = temp->link;
				temp->link = new; //last node points to the new node

				if(temp->link->link == *start)
				{
					*position = -1;
					temp = *start;
				}
				break;
			}
		}
	}
	/*if memory allocation fails*/
	else
	{
		printf("Error in allocating memory\n");
		exit(FAILURE);
	}

}

