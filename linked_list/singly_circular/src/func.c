/********************************************************************************************
*
*       FILE NAME:      func.c
*
*       DESCRIPTION:    Contains function definition for link list creation, updation
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
*       FUNCTION  NAME: create
*
*       DESCRIPTION:    creates a linked list
*
*       RETURN VALUE:   NOTHING
*
************************************************************************************************/


void create(node **start)
{
        int num;
        int i;

	if(*start==NULL)
	{
	        printf("\nPlease Enter The number of elements you want to have in Linked-list\n");
	        scanf("%d",&num);

	        if(num==0)
	        {
	                printf("Please enter a natural number\n");
	        }
	        else
	        {
	                insert_empty(start);//for num=1
	                //for num greater than 1
	                for (i=2; i<=num; i++)
	                {
	                        insert_end(start);
	
	                }
	        }
	}
	else
	{
		printf("Sorry....!!! A list has already been created. A new List Cannot be created\n");
	}
}//end create


/********************************************************************************************
*
*       FUNCTION  NAME: insert_empty
*
*       DESCRIPTION:    insert element in an empty linked list
*
*       RETURN VALUE:   NOTHING
*
************************************************************************************************/

void insert_empty(node **start)
{
        node *new;
        new = (node *) malloc(sizeof(node)); //memory allocation

        //error handling
        if(new==NULL)
        {
                printf("Memory Not Available\n");
                exit(0);

        }
	if(*start==NULL)
	{
        	printf("\nPlease Enter the data\n");
        	scanf("%d",&(new->info));

		*start = new;
        	(*start)->link = *start;
	}
	else
	{
		printf("List is not empty, this operation cannot be performed\n");
	}

}//end of insert_empty

/********************************************************************************************
*
*       FUNCTION  NAME: insert_beginning
*
*       DESCRIPTION:    insert element at the beginning
*
*       RETURN VALUE:   NOTHING
*
************************************************************************************************/

void insert_beginning(node **start)
{
        node *new;
	node *temp;

	if(*start==NULL)
	{
		insert_empty(start);
	}

	else
	{
		 new = (node *) malloc(sizeof(node)); //memory allocation
        	//error handling
        	if(new==NULL)
        	{
                	printf("Memory Not Available\n");
                	exit(0);
        	}
		else
		{
        		printf("\nPlease Enter the data\n");
        		scanf("%d",&(new->info));

        		temp = *start;

			//traverse the list till end
			while(temp->link!=*start)
			{
				temp=temp->link;
			}

			new->link= temp->link;
			temp->link= new;
			*start=new;
		}//end of inner else
	}//end of outer else
}//end of insert_beginning


/********************************************************************************************
*
*       FUNCTION  NAME: insert_end
*
*       DESCRIPTION:    insert element at the end
*
*       RETURN VALUE:   NOTHING
*
************************************************************************************************/

void insert_end(node **start)
{
        node *new;
        node *temp;

	if(*start==NULL)
	{
		insert_empty(start);
	}
	
	else
	{
        	new = (node *) malloc(sizeof(node)); //memory allocation

        	//error handling
        	if(new==NULL)
        	{
                	printf("Memory Not Available\n");
                	exit(0);

        	}

        	printf("\nPlease Enter the data\n");
        	scanf("%d",&(new->info));

        	temp = *start;

        	//traversing the list till the end points to the first
        	while(temp->link!=*start)
        	{
                	temp = temp->link;
        	}
        
        	new->link = temp->link;
		temp->link = new;
	}

}//end of insert_end

/********************************************************************************************
*
*       FUNCTION  NAME: insert_after
*
*       DESCRIPTION:    insert element after any given info item
*
*       RETURN VALUE:   NOTHING
*
************************************************************************************************/

void insert_after(node **start)
{
        node *new; //new node
        node *temp; //temporary node
        int item; //item after which node to be inserted
        int data; //data to be inserted
	int flag=0; //flag to check that a data has been inserted or not


        printf("\nPlease Enter the data which you want to insert\n");
        scanf("%d",&data);

        printf("\nPlease Enter the data element after which the given data is to be inserted\n");
        scanf("%d",&item);

        temp = *start;

        //traverse while item after which the data to be inserted does not appear
        do
        {
        	if(temp->info==item)
                {

                 	new = (node *) malloc(sizeof(node)); //memory allocation

                         //error handling
                         if(new==NULL)
                          {
                           	printf("Memory Not Available\n");
                                exit(0);

                           }
                           else
                           {
                            	new->info = data;
                                new->link = temp->link;
                                temp->link = new;
				flag=1;
				break;
                            }
		}

                else
                {
                	temp=temp->link;
                }

	}while(temp!=*start);//end of while

	if(1!=flag)
	{
        	printf("\nData element after which the data is to be inserted not found\n");
	}

}//end of insert_after



/********************************************************************************************
*
*       FUNCTION  NAME: insert_before
*
*       DESCRIPTION:    insert element before any given info item
*
*       RETURN VALUE:   NOTHING
*
************************************************************************************************/

void insert_before(node **start)
{
        node *new;//new node
        node *temp;//temporary node
        int item;//item before which node to be inserted
        int data;//data to be inserted
	int flag=0; //flag to check that a data has been inserted or not

        if(*start==NULL)
        {
                printf("List is empty. This operation cannot be performed\n");
        }
	
	else
	{
	        printf("\nPlease Enter the data which you want to insert\n");
	        scanf("%d",&data);
	
	        printf("\nPlease Enter the data element before which the given data is to be inserted\n");
	        scanf("%d",&item);
	
		temp = *start;

	        //if the node to be inserted is before the first node
	        if((temp)->info == item)
	        {

	                new = (node *) malloc(sizeof(node)); //memory allocation
	
	                //error handling
	                if(new==NULL)
	                {
	                        printf("Memory Not Available\n");
	                        exit(0);
	                }
	                else
	                {
				while(temp->link!=*start)
				{
					temp=temp->link;
				}

	                        new->info = data;
	                        new->link = temp->link;
				temp->link = new;
	                        *start = new;
				flag=1;
	                }
	        }
	

	        //traverse while item before which the data to be inserted does not appear
		else{
	        	while(temp->link!=*start)
	                	{
	                	        if(temp->link->info==item)
	                        	{
	
	                        	        new = (node *) malloc(sizeof(node)); //memory allocation

	                        	        //error handling
	                        	        if(new==NULL)
	                        	        {
	                        	                printf("Memory Not Available\n");
	                        	                exit(0);
	
	                        	        }
	                        	        else
	                        	        {
	                        	                new->info = data;
	                        	                new->link = temp->link;
	                        	                temp->link = new;
							flag=1;
							break;
	                        	        }
	                        	}
	
	                        	else
	                        	{
	                        	        temp=temp->link;
	                        	}
	
	                	}//end of while
			}//end of inner else
		if(1!=flag)
		{
	        	printf("\nData element before which the data is to be inserted not found\n");
		}

	}//end of outer else
	

}//end of insert_before

/********************************************************************************************
*
*       FUNCTION  NAME: delete_node
*
*       DESCRIPTION:    delete element from the list
*
*       RETURN VALUE:   Nothing
*
************************************************************************************************/

void delete_node(node **start)
{
        node *temp; //temporary variable to hold the address of the node to be deleted
        node *ptr;
        int data; //data to be deleted
	int flag=0; //flag to detect whether a node is deleated or not

        printf("\nPlease Enter the data which is to be deleted\n");
        scanf("%d",&data);

        if(*start==NULL)
        {
                printf("\nlist is empty. Data cannot be Deleted\n");
        }

	else
	{
		//deletion of only node
		if((*start)->link==*start)
		{	
			if((*start)->info==data)
			{
				temp=*start;
				free(temp);
				*start=NULL;
				flag=1;
			}//end of inner if
		}//end of if
	        
		//deletion of first node
	        else if(((*start)->link!=*start) && ((*start)->info==data))
        	{
                	temp = *start;
			ptr = *start;
			while(ptr->link != *start)
			{
				ptr=ptr->link;
			}
                	ptr->link = (*start)->link;
			*start = (*start)->link;
                	free(temp);
			flag=1;
        	}// end else if

		

        	/*Deletion in between or at the end*/
		else
		{
        		ptr = *start;
        		while(ptr->link!=*start)
        		{
                		if(ptr->link->info==data)
                		{
                        		temp=ptr->link;
                        		ptr->link=temp->link;
                        		free(temp);
					flag=1;
					break;
	                	}
				else
				{
 		        	       	ptr=ptr->link; //traverse the list
				}
 	       		}//end of while
		}//end of else

		if(1!=flag)
		{
 		       	printf("\nThe data you want to delete does not exists\n");
		}
	}//end of else
}//end of delete


/********************************************************************************************
*
*       FUNCTION  NAME: display
*
*       DESCRIPTION:    displays  a linked list
*
*       RETURN VALUE:   Nothing
*
************************************************************************************************/


void display(node **start)
{
        node *temp;
        if(*start==NULL)
        {
                printf("\nList is empty\n");
        }
	else
	{
        	temp=*start;
        	printf("List is :\n");
        	do
        	{
                	printf("%d ",temp->info);
                	temp=temp->link;
        	}while(temp!=*start);
        	printf("\n\n");
	}//end of else
}/*End of display() */


/********************************************************************************************
*
*       FUNCTION  NAME: count
*
*       DESCRIPTION:    counts the number of elements in a linked list
*
*       RETURN VALUE:   Nothing
*
************************************************************************************************/


void count(node **start)
{
        node *temp;
        int count=0;
        if(*start==NULL)
        {
                printf("List is empty\n");
        }
	else
	{
        	temp=*start;
        	do
        	{
                	temp=temp->link;
                	count++;
        	}while(temp != *start);
        	printf("\nThe number of elements in the link list are %d\n",count);
	}
}/*End of count() */

/********************************************************************************************
*
*       FUNCTION  NAME: Free_list
*
*       DESCRIPTION:    Free The memory allocated dynamically
*
*       RETURN VALUE:   Nothing
*
************************************************************************************************/


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


