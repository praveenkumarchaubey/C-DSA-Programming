/********************************************************************************************
*
*       FILE NAME:      func.c
*
*       DESCRIPTION:    Contains function definition for queue creation, updation
*                       and deletion
*
************************************************************************************************/

/***********************************************************************************************
*                       HEADER FILES
*
*************************************************************************************************/
                #include "header.h"


/********************************************************************************************
*
*       FUNCTION  NAME: insert
*
*       DESCRIPTION:    insert element in the queue at the end (rear position)
*
*       RETURN VALUE:   NOTHING
*
************************************************************************************************/


void insert(node **front, node **rear)
{
	node *new;
	new = (node *)malloc(sizeof(node));

	if(NULL == new)
	{
		printf("Memory Not Available. Queue Overflow\n");
		exit(0);
	}
	else
	{
		printf("Please Enter the data item\n");
		scanf("%d",&(new->info));
		new->link = NULL;

		/*if queue is empty*/
		if(*front==NULL)
		{
			*front=new;
			*rear=new;
		}
		else
		{
			(*rear)->link=new;
			*rear = new;
		}

	}

}//end insert


/********************************************************************************************
*
*       FUNCTION  NAME: delete
*
*       DESCRIPTION:    delete element in the queue at the front position
*
*       RETURN VALUE:   Value stored in the element
*
************************************************************************************************/

void delete(node **front, node **rear)
{
	node *temp;
	int item;

	//if queue is empty
	if(*front==NULL)
	{
		printf("Queue Underflow\n");
		exit(0);
	}

	//if there is only one element
	else if((*front)->link==NULL)
	{
		temp = *front;
		item = (*front)->info;
		*front = NULL;
		*rear = NULL;
		free(temp);
		printf("Item Deleted From the queue is %d\n",item);
		
	}

	else
	{
		temp = *front;
		item = (*front)->info;
		*front = (*front)->link;
		free(temp);
		printf("Item Deleted from the queue is %d\n",item);
		
	}

}



/********************************************************************************************
*
*       FUNCTION  NAME: display
*
*       DESCRIPTION:    displays the elements in the queue
*
*       RETURN VALUE:   NOTHING
*
************************************************************************************************/

void display(node **front,node **rear)
{
	node *temp;
	temp=*front;

	printf("The list is\n");
	while(temp!=NULL)
	{
		printf("%d\n",temp->info);
		temp=temp->link;
	}
	printf("\n\n");
}



/********************************************************************************************
*
*       FUNCTION  NAME: free_list
*
*       DESCRIPTION:    displays the elements in the queue
*
*       RETURN VALUE:   NOTHING
*
************************************************************************************************/

void free_list(node **front,node **rear)
{
	node *temp;

	while(*front!=NULL)
	{
		
		temp=*front;
		*front = (*front)->link;
		free(temp);
	}
}
