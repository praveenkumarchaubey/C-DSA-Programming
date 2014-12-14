/********************************************************************************************
*
*       FILE NAME:      func.c
*
*       DESCRIPTION:    Contains function definition for insertion, deletion in priority
*                       queue and displaing the items in a queue
*
************************************************************************************************/

/***********************************************************************************************
*                       HEADER FILES
*
*************************************************************************************************/
                #include "header.h"

/********************************************************************************************
*
*       FUNCTION  NAME: insert_item
*
*       DESCRIPTION:    insert element in the priority queue depending upon priority
*
*       RETURN VALUE:   NOTHING
*
************************************************************************************************/
void insert_item(node **front)
{
	node *new;
	node *temp;
	char item[MAX];
	memset(item, 0, MAX*sizeof(char));

	new = (node *) malloc(sizeof(node));

	if(NULL != new)
	{
		printf("Please enter an item to be inserted in the queue\n");
		while('\n'!=getchar());
		fgets(item, (MAX-1)*sizeof(char), stdin);

		strcpy(new->info,item);
		

		printf("Please enter the priority you want the item to be in the queue\n");
		scanf("%d",&(new->priority));

		/*if queue is empty, or new element has a heigher priority than the front element*/
		/*insertion at the beginning*/
		if((*front == NULL) || ((*front)->priority) < (new->priority))
		{
			new->link = *front;
			*front = new;
		}

		else
		{
			temp = *front; 
			while((temp->link !=NULL) && ((temp->link->priority) >= (new->priority)))
			{
				temp = temp->link;
			}
	
			new->link = temp->link;
			temp->link = new;
		}
	}

	else
	{
		printf("Queue is Full. No insertion is possible\n");
	}

}//end of insert_item


/********************************************************************************************
*
*       FUNCTION  NAME: delete_item
*
*       DESCRIPTION:    delete element from the queue from the front position
*
*       RETURN VALUE:   Nothing
*
************************************************************************************************/

void delete_item(node **front)
{
	node *temp; //node to be deleted

	//if queue is empty
	if(NULL == *front)
	{
		printf("Queue is empty. No deletion possible\n");
	}

	else
	{ 
			printf("Item deleted from the queue is %s\n",(*front)->info);
			temp = *front;
			*front = (*front)->link;
			free(temp);
			
	}

}//end of delete_item



/********************************************************************************************
*
*       FUNCTION  NAME: display
*
*       DESCRIPTION:    displays  a linked list
*
*       RETURN VALUE:   Nothing
*
************************************************************************************************/

void display(node **front)
{
	node *temp;
	//if queue is empty
	if(NULL == *front)
	{
		printf("Queue is empty\n");
	}

	else
	{ 
		printf("\nLIST IS\n");
		temp = *front;

		while(NULL != temp)
		{
			printf("%s",temp->info);
			temp = temp->link;		
		}
		printf("\n\n");
	}

}//end of display

/********************************************************************************************
*
*       FUNCTION  NAME: free_list
*
*       DESCRIPTION:    Free's the memory allocated to the queue
*
*       RETURN VALUE:   Nothing
*
************************************************************************************************/
void free_list(node **front)
{
	node *temp;

	while(*front!=NULL)
	{
		temp = *front;
		*front = (*front)->link;
		free(temp);
	}
}//end of free_list

