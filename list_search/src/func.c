/**********************************************************************************************************
 *	FILE NAME : func.c
 *
 *	DESCRIPTION : contains function definitions
 *
 *	NAME		ID 	DATE		REASON
 *------------------------------------------------------------------------------------------------------
 *	PRAVEEN CHAUBEY	38263	2/12/14		RE TEST PREPERATION
 *
 *********************************************************************************************************/

/***************************************************************************************************************
 *
 *			HEADER FILES
 *
 *****************************************************************************************************************/
#include "header.h"

/*******************************************************************************************************************
 *	FUNCTION NAME : file_open
 *
 *	DESCRIPTON : opens a file
 *
 *	RETURN VALUE : nothng
 *
 ***********************************************************************************************************************/
void file_open(FILE **fp, char *file_name, char *mode)
{
    *fp = fopen(file_name, mode);
    /*error handling*/
    if(NULL == *fp)
    {
        printf("Error in opening the file %s\n", file_name);
        exit(FAILURE);
    }
    else
    {
        printf("File %s opened successfully\n", file_name);
    }

}

/*******************************************************************************************************************
 *	FUNCTION NAME : file_close
 *
 *	DESCRIPTON : closes an opened file
 *
 *	RETURN VALUE : nothng
 *
 ***********************************************************************************************************************/
void file_close(FILE **fp)
{
    int n;
    n = fclose(*fp);
    /*Error handling*/
    if(EOF == n)
    {
        printf("Error in closing the file\n");
        exit(FAILURE);
    }
    else
    {
        printf("File closed Successfully\n");
    }
}

/*******************************************************************************************************************
 *	FUNCTION NAME : insert_list
 *
 *	DESCRIPTON : inserts data into linked list at the end.
 *
 *	RETURN VALUE : nothng
 *
 ***********************************************************************************************************************/
void insert_list(node **start, char input[])
{
    node *new;//new node
    node *temp;//temporary node

    new = (node *) malloc(sizeof(node)); //memory allocation
    /*if memory allocation is successfull*/
    if(NULL != new)
    {
        strcpy(new->info, input); //copy data into new node
        new->link = NULL; //make new node as the last node

        /*if list is empty*/
        if(NULL == *start)
        {
            *start = new;
        }
        /*if the list is not empty*/
        else
        {
            temp = *start;
            /*traverse the list till end*/
            while(NULL != temp->link)
            {
                temp = temp->link;
            }
            temp->link = new; //inserts the node at the end
        }
    }
    /*if memory allocation fails*/
    else
    {
        printf("Error in memory allocation\n");
        exit(FAILURE);
    }

}


/*******************************************************************************************************************
 *	FUNCTION NAME : free_list
 *
 *	DESCRIPTON : free the linked list
 *
 *	RETURN VALUE : nothng
 *
 ***********************************************************************************************************************/
void free_list(node **start)
{
    node *temp; //temporary node
    while(NULL != *start)
    {
        temp = *start;
        *start = (*start)->link;
        free(temp);
    }
}

/*******************************************************************************************************************
 *	FUNCTION NAME : search_keyword
 *
 *	DESCRIPTON : searches a keyword in the list, if found write it into the output file
 *
 *	RETURN VALUE : nothng
 *
 ***********************************************************************************************************************/
void search_keyword(node **start, char keyword[], FILE **fp)
{
    node *temp;//temporary pointer
    temp = *start;

    if(NULL == *start)
    {
        printf("List is empty\n");
        exit(FAILURE);
    }
    while(NULL != temp)
    {
        /*if the keyword is present in the string*/
        if(NULL != strstr(temp->info, keyword))
        {
            fprintf(*fp, "%s", temp->info);
            fprintf(*fp, "\n");
            temp = temp->link;
        }
        /*if keyword not found*/
        else
        {
            temp = temp->link;
        }
    }
}

/*******************************************************************************************************************
 *	FUNCTION NAME : display_list
 *
 *	DESCRIPTON : display the linked list
 *
 *	RETURN VALUE : nothng
 *
 ***********************************************************************************************************************/
void display_list(node **start)
{
    node *temp; //temporary node
    temp = *start;
    while(NULL != temp)
    {
        printf("%s",temp->info);
        printf("\n");
        temp = temp->link;
    }
    printf("\n");
}

/*******************************************************************************************************************
 *	FUNCTION NAME : remove_new_line
 *
 *	DESCRIPTON : removes the new line
 *
 *	RETURN VALUE : nothng
 *
 ***********************************************************************************************************************/
void remove_new_line(char str[])
{
    int len = 0;
    len = strlen(str);
    if(str[len-1] == '\n')
    {
        str[len-1] = '\0';
    }
}

