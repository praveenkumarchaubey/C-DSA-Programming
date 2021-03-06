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
 *	FUNCTION NAME : insert_list
 *
 *	DESCRIPTION : inserts an elemnt into a list at the beginning
 *
 *	RETURN VALUE : nothing
 *
 **************************************************************************************************************************************************/
void insert_list(node **start, char *token)
{
    node *new; //new node
    new = (node *) malloc(sizeof(node)); //allocating memory to the new node
    if(NULL != new)
    {
        strcpy(new->info, token);//copying token into the new node
        new->link = *start;//new node is the last node
        *start = new;
    }
    else
    {
        printf("Error in memory allocation\n");
        exit(FAILURE);
    }

}

/***********************************************************************************************************************************************
 *	FUNCTION NAME : free_list
 *
 *	DESCRIPTION : free the linked list
 *
 *	RETURN VALUE : nothing
 *
 **************************************************************************************************************************************************/
void free_list(node **start)
{
    node *temp;
    while(*start != NULL)
    {
        temp = *start;
        *start = (*start)->link;
        free(temp);
    }

}

/***********************************************************************************************************************************************
 *	FUNCTION NAME : insert_file
 *
 *	DESCRIPTION : reads from the list and store it in reverse order
 *
 *	RETURN VALUE : nothing
 *
 **************************************************************************************************************************************************/
void insert_file(node **start, FILE **fp)
{
    node *temp;//temporary node for traversing
    int len =0;//length of string
    char vowel[MAX]; //for storing strings to count the vowels
    int vowel_count,i;//vowel count

    temp = *start;
    while(temp!= NULL)
    {
        strcpy(vowel, temp->info);
        len = strlen(vowel);
        vowel_count = 0; //initializing vowel count in every count
        for(i=0;i<len;i++)
        {
            if(vowel[i]=='a'||vowel[i]=='e'||vowel[i]=='i'||vowel[i]=='o'||vowel[i]=='u')
                vowel_count++;
        }
        fprintf(*fp,"%s",temp->info);
        fprintf(*fp,"\t");
        fprintf(*fp,"vowel_count: %d",vowel_count);
        fprintf(*fp,"\n");
        temp = temp->link;
    }

}
