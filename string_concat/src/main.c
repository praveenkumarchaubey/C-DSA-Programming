/**********************************************************************************************************************
 *	FILE NAME : main.c
 *
 *	DESCRIPTION : contains main function
 *
 *	NAME		ID	DATE		REASON
 *---------------------------------------------------------------------------------------------------------------------
 *	PRAVEEN CHAUBEY	38263	2/12/14		RE TEST PREP
 ***************************************************************************************************************************/

/************************************************************************************************************************
 *
 *				HEADER FILES
 *
 **********************************************************************************************************************/
#include "header.h"

/**************************************************************************************************************************
 *	FUNCTION NAME : main
 *
 *	DESCRIPTION : calls other functions for implementing the given problem statement
 *
 *	RETURN VALUE : SUCCESS
 *
 *************************************************************************************************************************/
int main(int argc, char *argv[])
{
    int i;//loop count
    node *start = NULL;//starting point for list
    FILE *fp; //file pointer

    /*error handling for command line arguments*/
    if(4 > argc)
    {
        printf("Insufficient number of arguments\n");

        for(i=1;i<4;i++)
        {
            if(NULL == argv[i])
            {
                printf("Please provide at least %d more input string\n",4-i);
                printf("The last string should be a file name\n");
                exit(FAILURE);
            }
        }
    }

    /*inserting strings in linked lists*/
    for(i=1;i<argc-2;i++)
    {
        insert_list(&start,argv[i]);
    }

    file_open(&fp, argv[argc-1], "w");//opening the output file
    //concatinate last string with the rest of the input elements which are even and insert the concatinated strings in the output file
    insert_file(&fp, &start, argv[argc-2]);
    file_close(&fp); //closing the output file
    free_list(&start);
    return SUCCESS;
}

