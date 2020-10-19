/******************************************************************************************************
 *	FINE NAME : func.c 
 *
 *	DESCRIPTION : contains function definitions for merging two linked lists 
 *			into one
 *
 *	NAME		ID		DATE		REASON
 *-----------------------------------------------------------------------------------------------------
 *	PRAVEEN CHAUBEY	38263		28/11/2014	RE TEST PPEPERATION	
 *
 **********************************************************************************************************/

/*****************************************************************************************************
 *
 *		HEADER FILES
 *
 ******************************************************************************************************/
#include "header.h"

/********************************************************************************************************
 *
 *	FUNCTION NAME : file_opem
 *	
 *	DESCRIPTION : opens a file for reading in read only mode
 *
 *	RETURN VALUE : nothing
 *
 ***********************************************************************************************************/
void file_open(FILE **fp, char *file_name, char *mode)
{
    *fp = fopen(file_name, mode);

    /*Error handling for fopen*/
    if(NULL == *fp)
    {
        printf("Error in opening File %s\n", file_name);
        exit(FAILURE);
    }
    else
    {
        printf("File %s opened successfully\n", file_name);
    }

}

/********************************************************************************************************
 *
 *	FUNCTION NAME : file_close
 *	
 *	DESCRIPTION : closes an opened file
 *
 *	RETURN VALUE : nothing
 *
 *
 ***********************************************************************************************************/

void file_close(FILE **fp)
{
    int n;
    n = fclose(*fp);
    /*error handling for file closing*/
    if(EOF == n)
    {
        printf("Error in closing File\n");
        exit(FAILURE);
    }
    else
    {
        printf("File closed successfully\n");
    }

}


/********************************************************************************************************
 *
 *	FUNCTION NAME : insert_list
 *	
 *	DESCRIPTION : insert an element into the list
 *
 *	RETURN VALUE : nothing
 *
 ***********************************************************************************************************/
void insert_list(node **start, char name[])
{
    node *new;//new node to be inserted
    node *temp; //temporary pointer

    new = (node *)malloc(sizeof(node));//memory allocation

    if(NULL != new)
    {
        strcpy(new->info, name); //copy the contents in the node
        temp = *start;

        /*if the list is empty*/
        if(NULL == *start)
        {
            new->link = NULL; //last node of the list
            *start = new; //start now points to new
        }
        /*if the list is not empty*/
        else
        {
            /*traverse till end of the list*/
            while(NULL != temp->link)
            {
                temp = temp->link; //increment the pointer
            }
            new->link = NULL; //last node of the list
            temp->link = new; //second last node points to the new node
        }
    }
    /*if memory not available*/
    else
    {
        printf("Error in allocating memory\n");
        exit(FAILURE);
    }

}

/********************************************************************************************************
 *
 *	FUNCTION NAME : display_list
 *	
 *	DESCRIPTION : displays the linked list
 *
 *	RETURN VALUE : nothing
 *
 *
 ***********************************************************************************************************/
void display_list(node **start)
{
    node *temp; //temporary pointer
    temp = *start;
    /*print the list while traversing*/
    while(NULL != temp)
    {
        printf("%s",temp->info);
        temp = temp->link;
    }

}

/********************************************************************************************************
 *
 *	FUNCTION NAME : merge_list
 *	
 *	DESCRIPTION : merges the two given lists
 *
 *	RETURN VALUE : a pointer of type node
 *
 ***********************************************************************************************************/
node *merge_list(node **start1, node **start2)
{
    node *start = NULL; //start pointer for the merged list
    node *temp1 = *start1; //temporary pointer for list 1
    node *temp2 = *start2; //temporary pointer for list 2
    node *temp3; //temporary pointer for merged list

    /*if first element of list 1 is smaller than or equal to first elelemnt of list two*/
    if (strcmp((*start1)->info, (*start2)->info) <= 0)
    {
        start = *start1; //starting point of merged list
        temp1 = temp1->link; //increment the temporary pointer for list 1
    }
    /*if first element of list 2 is smaller than the first elelemnt of list 1*/
    else
    {
        start = *start2; //starting point for merged list
        temp2 = temp2->link; //increment the temporary pointer for list 2
    }

    temp3 = start; 
    /*keep merging till we reach at the end of any one of the list*/
    while(NULL !=temp1 && NULL != temp2)
    {
        if (strcmp(temp1->info, temp2->info) <= 0)
        {
            temp3->link = temp1;
            temp3 = temp3->link;
            temp1 = temp1->link;
        }
        else
        {
            temp3->link = temp2;
            temp3 = temp3->link;
            temp2 = temp2->link;
        }
    }
    /*if list 1 still remains*/
    if(NULL != temp1)
    {
        temp3->link = temp1;
    }
    /*if list two still remains*/
    if(NULL != temp2)
    {
        temp3->link = temp2;
    }
    return start;
}

/********************************************************************************************************
 *
 *	FUNCTION NAME : free_list
 *	
 *	DESCRIPTION : free the dynamically allocated list
 *
 *	RETURN VALUE : nothing
 *
 *
 ***********************************************************************************************************/
void free_list(node **start)
{
    node *temp; //node to be deleted
    while(NULL != *start)
    {
        temp = *start;
        *start = (*start)->link;
        free(temp);
    }
}


/********************************************************************************************************
 *
 *	FUNCTION NAME : write_output
 *	
 *	DESCRIPTION : write the contents of the merged linked list in the output file
 *
 *	RETURN VALUE : nothing
 *
 *
 ***********************************************************************************************************/
void write_output(FILE **fp3, node **start)
{
    node *temp = *start;
    while(NULL != temp)
    {
        fprintf(*fp3,"%s",temp->info);
        temp = temp->link;
    }

}
