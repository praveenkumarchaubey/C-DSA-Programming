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

        	        }//end of for
        	}//end of else
	}//end of if

	else
	{
		printf("Sorry...!!! A list has been already created. A new list cannot be created\n");
	}


}//end create


/********************************************************************************************
*
*       FUNCTION  NAME: insert_empty
*
*       DESCRIPTION:    insert element in an empty list
*
*       RETURN VALUE:   NOTHING
*
************************************************************************************************/

void insert_empty(node **start)
{

	if(*start==NULL)
	{
        	node *new;
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


        		new->next = new;
			new->prev = new;
        		*start = new;
		}
	}//end of if

	else
	{
		printf("The list is not empty, This operation Cannot be performed.\n");
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
        new = (node *) malloc(sizeof(node)); //memory allocation
	
        //error handling
        if(new==NULL)
        {
                printf("Memory Not Available\n");
                exit(0);

        }
	
	/*if the list is not empty*/
	else if(*start!=NULL)
	{
        	printf("\nPlease Enter the data\n");
	        scanf("%d",&(new->info));

	
        	new->prev = (*start)->prev;
		new->next = *start;
		(*start)->prev->next = new;
		(*start)->prev = new;	
        	*start = new;
	}//end of elseif

	/*If the list is empty*/
	else
	{
		new->next = new;
		new->prev = new;
		*start = new;
	}//end of else
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
        new = (node *) malloc(sizeof(node)); //memory allocation

        //error handling
        if(new==NULL)
        {
                printf("Memory Not Available\n");
                exit(0);

        }
	else
	{
		if(*start!=NULL)
		{
        		printf("\nPlease Enter the data\n");
        		scanf("%d",&(new->info));

        		temp = *start;

        		//traversing the list till the end
        		while(temp->next != *start)
        		{
                		temp = temp->next;
        		}

        		new->next = temp->next;
        		new->prev = temp;
			temp->next->prev = new;
			temp->next = new;
		}
		/*If the list is empty*/
		else
		{
			new->next = new;
			new->prev = new;
        		*start = new;
		}//end of inner else
	}//end of main else

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
        node *new;//new node
        node *temp;//temporary node
        int item;//item after which node to be inserted
        int data;//data to be inserted
	int flag=0;//flag to determine that an insertion has taken place or not

	if(*start!=NULL)
	{
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
               	                        new->next = temp->next;
                	                new->prev = temp;
					temp->next->prev= new;
					temp->next=new;
					flag=1;
					break;
                	         }
			}
			/*Increment the pointer*/
                	else
                	{
                                temp=temp->next;
               	        }

               	}while(temp!=*start);//end of while

		if(1!=flag)
		{
        		printf("\nData element after which the data is to be inserted not found\n");
		}
	}//end of if

	else
	{
		printf("List is empty. This operation cannot be performed\n");
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
        int item;//item after which node to be inserted
        int data;//data to be inserted
	int flag=0;//flag to determine that an insertion has taken place or not
       
	if(*start!=NULL)
	{
        	printf("\nPlease Enter the data which you want to insert\n");
        	scanf("%d",&data);

        	printf("\nPlease Enter the data element before which the given data is to be inserted\n");
       	 	scanf("%d",&item);

        	//if the node to be inserted is before the first node
        	if((*start)->info == item)
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
                	        new->prev = (*start)->prev;
				new->next = *start;
				(*start)->prev->next=new;
				(*start)->prev=new;
                	        *start = new;
				flag=1;
                	}
		}//end if

		/*If node to be inserted is not before the first node*/	
		else
		{
 			temp = (*start)->next; //initially place temp on the second node

        		//traverse while item before which the data to be inserted does not appear
        		while(temp!=*start)
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
                		                        new->next = temp;
							new->prev = temp->prev;
							temp->prev->next= new;
                		                        temp->prev = new;
							flag=1;
							break;
                		                }
                		        }//end of if

                		        else
                		        {
                		                temp=temp->next;
                		        }

                		}//end of while
		}//end of inner else
		if(1!=flag)
		{
        		printf("\nData element before which the data is to be inserted not found\n");
		}
	}//end of main if
	else
        {
                printf("List is empty. This operation cannot be performed.\n");
        }


}//end of insert_before

/********************************************************************************************
*
*       FUNCTION  NAME: delete_node
*
*       DESCRIPTION:    delete element from the list
*
*       RETURN VALUE:   NOTHING
*
************************************************************************************************/

void delete_node(node **start)
{
        node *temp; //temporary variable to hold the address of the node to be deleted
	int flag=0; //flag to check that a node has been deleted or not
        int data; //data to be deleted

        
	if(*start!=NULL)
	{
		printf("\nPlease Enter the data which is to be deleted\n");
		scanf("%d",&data);

		//deletion of first node
        	if((*start)->info==data)
		{
			/*If first node is the only node*/
			if((*start)->next== *start)
			{
	                	temp = *start;
	                	free(temp);
				*start = NULL;
				flag=1;
	        	}

	        	//deletion of first node
	        	else
			{
	                	temp = *start;
				(*start)->next->prev = (*start)->prev;
				(*start)->prev->next = (*start)->next; 
				*start=(*start)->next;
	                	free(temp);
				flag=1;
	        	}
		}//end if

		else
		{
        		temp = (*start)->next; //position temp on the second node

			 /*Deletion in between the nodes or the end node*/
			while(temp!= *start)
		        {
		                if(temp->info==data)
		                {
		                        temp->next->prev = temp->prev;
		                        temp->prev->next = temp->next;
		                        free(temp);
					flag=1;
					break;
		                }
				else
				{
		                	temp=temp->next; //traverse the list
				}
		        }//end of while

		}//end of else		
	
		if(1!=flag)
		{
        		printf("\nThe data you want to delete does not exists\n");
		}

	}//end of main if

	else
        {
                printf("\nlist is empty. No Deletion is possible\n");
        }

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
        	        temp=temp->next;
        	}while(temp!=*start);
        	printf("\n\n");
	}
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
                	temp=temp->next;
                	count++;
        	}while(temp!=*start);
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
	ptr = (*start)->next;

	//traverse till end node and free the node one by one
	while(ptr!= *start)
	{
		temp = ptr;
		ptr->next->prev = ptr->prev;
		ptr->prev->next = ptr->next;
		ptr = ptr->next;
                free(temp);
	}

	//free the only node 
	
	if((*start)->next== *start)
	{
		temp = *start;
	        free(temp);
		*start = NULL;
	}

}//end free_list



