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

        /*if list is empty*/
        if(NULL == *start)
        {
            *start = new;
            new->link = *start; //make new node points to start
        }

        /*if the list is not empty*/
        else
        {
            temp = *start;
            /*traverse the list till end*/
            while(temp->link != *start)
            {
                temp = temp->link;
            }
            new->link = temp->link; //make the new node points to the starting node
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
    node *ptr; //temporary node to be deleted
    node *temp; // temporay node for traversing

    temp = (*start)->link;
    /*deleting all the nodes accept the starting node*/
    while(temp != *start)
    {
        ptr  = temp;
        (*start)->link = temp->link;
        temp = temp->link;
        free(ptr);
    }
    /*deleting the only node*/
    if(temp->link == *start)
    {
        free(temp);
        *start = NULL;
    }

}


/*******************************************************************************************************************
 *	FUNCTION NAME : insert_file
 *
 *	DESCRIPTON : searches the given keyword in the list, if found write the list starting from the given keyword
 *			into the output file as well as on the standard output.
 *
 *	RETURN VALUE : nothng
 *
 ***********************************************************************************************************************/
void insert_file(node **start, char keyword[], FILE **fp)
{
    node *temp;//temporary pointer
    node *ptr; //temporary starting point
    temp = *start;

    if(NULL == *start)
    {
        printf("List is empty\n");
        exit(FAILURE);
    }
    do
    {
        /*if the keyword is present in the string*/
        if(NULL != strstr(temp->info, keyword))
        {
            ptr = temp;
            printf("\n********************LIST from given starting point*************\n");
            do
            {
                fprintf(*fp, "%s", temp->info);//storing in output file
                fprintf(*fp, "\n");

                printf("%s", temp->info);//displaying on standard output
                printf("\n");

                temp = temp->link;

            }while(temp != ptr); //end of inner do while loop

            printf("\n\n");
            break; //after printing come out of the main do while loop
        }
        /*if keyword not found*/
        else
        {
            temp = temp->link;
        }

    }while(temp != *start); //end of outer do while loop

    if(temp == *start)
    {
        printf("Keyword not found\n\n");
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
    do
    {
        printf("%s",temp->info);
        printf("\n");
        temp = temp->link;
    }while(temp != *start);
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

