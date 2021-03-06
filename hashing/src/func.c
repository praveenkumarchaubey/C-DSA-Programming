/***********************************************************************************************************************************************
 *	FILE NAME : func.c
 *
 *	DESCRIPTION : contains function definitions for implementing the given problem statement
 *
 *	NAME			ID	DATE		REASON
 *-------------------------------------------------------------------------------------------------------------------------------------------------
 *	PRAVEEN CHAUBEY		38263	1/12/14		RE TEST PREPERATION
 *
 ***************************************************************************************************************************************************/

/****************************************************************************************************************************************************
 *
 *					HEADER FILES
 *
 ***************************************************************************************************************************************************/
#include "header.h"

/***********************************************************************************************************************************************
 *	FUNCTION NAME : file_open
 *
 *	DESCRIPTION : opens a file
 *
 *	RETURN VALUE : nothing
 *
 **************************************************************************************************************************************************/
void file_open(FILE **fp, char *file_name, char *mode)
{
    *fp = fopen(file_name, mode);
    /*error handling for file opening*/
    if(NULL == *fp)
    {
        printf("Error in opening the file %s\n",file_name);
        exit(FAILURE);
    }
    else
    {
        printf("File %s opened successfully\n",file_name);
    }
}

/***********************************************************************************************************************************************
 *	FUNCTION NAME : file_close
 *
 *	DESCRIPTION : closes a file
 *
 *	RETURN VALUE : nothing
 *
 **************************************************************************************************************************************************/
void file_close(FILE **fp)
{
    int n;
    n = fclose(*fp);
    /*error handling for file closing*/
    if(EOF == n)
    {
        printf("Error in closing the file\n");
    }
    else
    {
        printf("File closed successfully\n");
    }
}

/***********************************************************************************************************************************************
 *	FUNCTION NAME : insert_table
 *
 *	DESCRIPTION : inserts into hash table reading from the file
 *
 *	RETURN VALUE : nothing
 *
 **************************************************************************************************************************************************/
void insert_table(node *names[], char string[])
{
    int h; //hash table index
    node *new; //new node

    h = hash(string); //calculating the hash table index

    new = (node *) malloc(sizeof(node)); //allocating memory to the new node
    if(NULL != new)
    {
        /*inserts the new node at the beginning of the list*/
        strcpy(new->info, string);
        new->link = names[h];
        names[h] = new;
    }
    else
    {
        printf("Error in memory allocation\n");
        exit(FAILURE);
    }
}


/***********************************************************************************************************************************************
 *	FUNCTION NAME : delete_table
 *
 *	DESCRIPTION : deletes a string from the table
 *
 *	RETURN VALUE : nothing
 *
 **************************************************************************************************************************************************/
void delete_table(node *names[], char string[])
{
    int h;
    node *temp; //node to be deleted.
    node *ptr; //temprary node for traversing

    h = hash(string); //getting the hash table index

    if(NULL == names[h])
    {
        printf("string not found\n");
        return;
    }
    else
    {
        /*if node to be deleted is the first node*/
        if(0 == strcmp(names[h]->info, string))
        {
            temp = names[h];
            names[h] = names[h]->link;
            free(temp);
        }
        /*deleting a node in between or at the end*/
        else
        {
            temp = names[h];
            while(NULL != temp->link)
            {
                if(0 == strcmp(temp->link->info, string))
                {
                    ptr = temp->link;
                    temp->link = ptr->link;
                    free(ptr);
                    break;
                }

                else if(NULL == temp->link)
                {
                    printf("\nstring not found\n");
                }
                else
                {
                    temp = temp->link;
                }
            }//end of while
        }//end of inner else
    }//end of outer else
}//end of delete_table

/***********************************************************************************************************************************************
 *	FUNCTION NAME : insert_file
 *
 *	DESCRIPTION : inserts into the file reading from the table
 *
 *	RETURN VALUE : nothing
 *
 **************************************************************************************************************************************************/
void insert_file(node *names[], FILE **fp)
{
    int i; //loop count
    node *temp; //temporary node for taversing

    printf("\n\n************************OUTPUT.TXT*********************\n");
    for(i= 0; i < SIZE; i++)
    {
        if(NULL != names[i])
        {
            temp = names[i];
            while(NULL != temp)
            {
                printf("%s", temp->info);
                fprintf(*fp,"%s", temp->info);
                temp = temp->link;
            }
        }
    }//end of for()
}

/***********************************************************************************************************************************************
 *	FUNCTION NAME : hash
 *
 *	DESCRIPTION : generates a hash table index
 *
 *	RETURN VALUE : hash table index
 *
 **************************************************************************************************************************************************/
int hash(char string[])
{
    int len = 0; //key length
    int i; //loop count
    int key = 0; //acii value of key
    len = strlen(string);
    for (i = 0; i< len; i++)
    {
        key = key + string[i]; 
    }
    return (key % SIZE);
}

/***********************************************************************************************************************************************
 *	FUNCTION NAME : free_table
 *
 *	DESCRIPTION : free the table
 *
 *	RETURN VALUE : node
 *
 **************************************************************************************************************************************************/
void free_table(node *names[])
{
    int i; //loop count
    node *temp; //temporary node for taversing

    for(i= 0; i < SIZE; i++)
    {
        if(NULL != names[i])
        {
            while(NULL != names[i])
            {
                temp = names[i];
                names[i] = names[i]->link;
                free(temp);
            }
        }
    }//end of for()
}
