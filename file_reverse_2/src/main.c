/***********************************************************************************************************************************************
 *	FILE NAME : main.c
 *
 *	DESCRIPTION : contains main function which calls other functionm for implementing the given problem statement
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
 *	FUNCTION NAME : main.c
 *
 *	DESCRIPTION : contains main function which call other functions for implementing the given problem statement
 *
 *	RETURN VALUE : SUCCESS
 *
 **************************************************************************************************************************************************/
int main(int argc, char *argv[])
{
    /*error handling for command line arguments*/
    if(NULL == argv[1])
    {
        printf("Please provide input file name\n");
        exit(FAILURE);
    }
    if(NULL == argv[2])
    {
        printf("Please provide output file name\n");
        exit(FAILURE);
    }

    FILE *fp1; //file pointer for input file
    FILE *fp2; //file pointer for output file

    char input[MAX];//for storing strings
    memset(input,0,MAX*sizeof(char));//initializing input to null
    char *token = NULL; //for collecting tokens
    node *start = NULL;//start pointer for the list

    file_open(&fp1, argv[1], "r");//opening input file in read only mode
    file_open(&fp2,argv[2], "w");//opening output file in write only mode

    while(1)
    {
        fgets(input, (MAX-1)*sizeof(char), fp1); //reading from the input file 
        /*error handling for end of file*/
        if(feof(fp1))
        {
            break;
        }
        /*tokenizing the read string*/
        token = strtok(input,"	\n,. :;");
        while(NULL != token)
        {
            insert_list(&start, token);
            token = strtok(NULL, "	\n;:,.");
        }
    }

    insert_file(&start,&fp2);//read from the ds and store it in output file
    file_close(&fp1); //closing input file
    file_close(&fp2); //closing output file
    free_list(&start); //free the link list

    return SUCCESS;
}
