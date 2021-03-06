/********************************************************************************************
*
*       FILE NAME:      func.c
*
*       DESCRIPTION:    Contains function definition for push and pop
*                       
*
************************************************************************************************/

/***********************************************************************************************
*                       HEADER FILES
*
*************************************************************************************************/
                #include "header.h"

/********************************************************************************************
*
*       FUNCTION  NAME: push
*
*       DESCRIPTION:    insert element at top of the stack
*
*       RETURN VALUE:   NOTHING
*
************************************************************************************************/

void push(node **top,char ch)
{
        node *new;

        new = (node *) malloc(sizeof(node)); //memory allocation

        //error handling
        if(new==NULL)
        {
                printf("STACK OVERFLOW\n");
                exit(0);

        }
	else
	{
        	new->info = ch;
		new->link= *top;
		*top = new;
	}//end of else
}//end of push



/********************************************************************************************
*
*       FUNCTION  NAME: pop
*
*       DESCRIPTION:    delete element from the list
*
*       RETURN VALUE:   element from top ot the stack
*
************************************************************************************************/



char pop(node **top)
{
        node *temp; //temporary variable to hold the address of the node to be deleted
	char ch;
	if(*top==NULL)
	{
		printf("STACK UNDERFLOW\n");
		exit(0);
	}

	else
	{
		temp = *top;
		ch=(*top)->info;
		*top=(*top)->link;
		free(temp);
		return ch;	
	}
}



/********************************************************************************************
*
*       FUNCTION  NAME: free_list
*
*       DESCRIPTION:    delete element from the list
*
*       RETURN VALUE:   nothing
*
************************************************************************************************/

void free_list(node **top)
{
	node *temp;

	if(*top==NULL)
	{
		exit(0);
	}

	else
	{

	temp=*top;
	*top=(*top)->link;
	free(temp);
	}

}
