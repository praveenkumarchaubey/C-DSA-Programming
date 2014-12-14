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
	if(*start!=NULL)
	{
        	printf("\nPlease Enter The number of elements you want to have in Linked-list\n");
        	scanf("%d",&num);

        	if(num==0)
        	{
                	printf("Please enter a natural number\n");
        	}
        	else
        	{
                	insert_beginning(start);//for num=1
                	//for num greater than 1
                	for (i=2; i<=num; i++)
                	{
                	        insert_end(start);

                	}//end of for
        	}//end of inner else

	}//end if

	else
	{
		printf("Sorry...!!! A list has already been created. A new list cannot be created\n");
	}// end of else

}//end create




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
	else
	{
        	printf("\nPlease Enter the data\n");
       	 	scanf("%d",&(new->info));


        	new->link = *start;
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
       		printf("\nPlease Enter the data\n");
        	scanf("%d",&(new->info));
		
		/*if the list is not empty*/
		if(*start!=NULL)
		{
    		    	temp = *start;

        		//traversing the list till the end
        		while(temp->link!=NULL)
        		{
                		temp = temp->link;
        		}

        		temp->link = new;
        		new->link = NULL;
		}

		/*if the list is empty*/
		else
		{
			new->link = *start;
        		*start = new;
		}	
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
        node *new;//new node
        node *temp;//temporary node
        int item;//item after which node to be inserted
        int data;//data to be inserted
	int flag=0;

	/*if the list is not empty*/
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
	
        	        }while(temp->link!=NULL);//end of while
		if(1!=flag)
		{	
        		printf("\nData element after which the data is to be inserted not found\n");
		}// end if
	}//end main if
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

        if(*start==NULL)
        {
                printf("List is empty\n");
        }

	else
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
        	                new->link = *start;
        	                *start = new;
        	        }
        	}//end if

		else
		{
	
			temp = *start;

	        	//traverse while item before which the data to be inserted does not appear
		        while(temp->link!=NULL)
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
		                                }
		                        }
	
		                        else
		                        {
		                                temp=temp->link;
		                        }
	
		                }//end of while
		        printf("\nData element before which the data is to be inserted not found\n");
		}// end of inner else
	}// end of main else
}//end of insert_before

/********************************************************************************************
*
*       FUNCTION  NAME: insert_position
*
*       DESCRIPTION:    insert element at any given position
*
*       RETURN VALUE:   NOTHING
*
************************************************************************************************/

void insert_position(node **start)
{
        node *new;//new node
        node *temp;//temporary node
        int pos = 0;//position after which node to be inserted
        int i;

        new = (node *) malloc(sizeof(node)); //memory allocation
        //error handling
        if(new==NULL)
        {
                printf("Memory Not Available\n");
                exit(0);
        }
        else
        {

                printf("\nPlease Enter the data which you want to insert\n");
                scanf("%d",&(new->info));
        }

        printf("\nPlease Enter the position after which the given data is to be inserted\n");
        scanf("%d",&pos);

        if(pos==1)
        {
                new->link = *start;
                *start = new;

        }

        //traverse while position at which the data to be inserted does not appear
        else
        {
                temp = *start;
                for(i=1; ((i<pos-1)&&(temp!=NULL)); i++)
                temp = temp->link;
        }


        if(temp==NULL)
        {
                printf("\nthere are less than %d element in the list",pos);
        }
        else
        {
                new->link = temp->link;
                temp->link = new;
        }



}//end of insert_position



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
        node *ptr;
        int data; //data to be deleted
	int flag=0; //flag to determine that a deletion has taken place or not
        printf("\nPlease Enter the data which is to be deleted\n");
        scanf("%d",&data);

        if(*start==NULL)
        {
                printf("\nlist is empty\n");
        }
	else
	{
        	//deletion of first node
        	if((*start)->info==data)
        	{
                	temp = *start;
                	*start=(*start)->link;
                	free(temp);
			int flag=1;
        	}
			
        	/*Deletion in between or at the end*/
		else
		{
        		ptr = *start;
        		while(ptr->link!=NULL)
        		{
                		if(ptr->link->info==data)
                		{
                		        temp=ptr->link;
                		        ptr->link=temp->link;
                		        free(temp);
					flag=1;
                		}
                		ptr=ptr->link; //traverse the list
        		}//end of while
		}
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
        	while(temp!=NULL)
        	{
                	printf("%d ",temp->info);
                	temp=temp->link;
        	}
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
        	while(temp!=NULL)
        	{
                	temp=temp->link;
                	count++;
        	}
        	printf("\nThe number of elements in the link list are %d\n",count);
	}
}/*End of count() */


/********************************************************************************************
*
*       FUNCTION  NAME: search
*
*       DESCRIPTION:    searches  a element in a linked list
*
*       RETURN VALUE:   Nothing
*
************************************************************************************************/


void search(node **start)
{
        node *temp;
        int item;
        int pos=1;

        printf("\nplease enter the item you want to search\n");
        scanf("%d",&item);

        if(*start==NULL)
        {
                printf("\nList is empty\n");
        }
	else
	{
        	temp=*start;
        	while(temp!=NULL)
        	{
                	if(temp->info==item)
                	{
                	        printf("The item %d is found at position %d\n",item,pos);
                	}
                	else
                	{
                	        temp=temp->link;
                	        pos++;
                	}
        	}
        	printf("\nThe item %d could not be found in the list\n",item);
	}//end of else
}/*End of search() */

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
        node *temp;
        while(*start!=NULL)
        {
                temp=*start;
                *start=(*start)->link;
                free(temp);

        }//end while

}//end free_list


