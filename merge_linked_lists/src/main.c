/******************************************************************************************************
 *	FINE NAME : main.c 
 *
 *	DESCRIPTION : contains main function which calls other functions for merging two linked lists 
 *			into one
 *
 *	NAME		ID		DATE		REASON
 *-----------------------------------------------------------------------------------------------------
 *	PRAVEEN CHAUBEY	38263		28/11/2014	RE TEST PPEPERATION	
 *
 **********************************************************************************************************/


/********************************************************************************************************
 *
 *			HEADER FILES
 *
 *********************************************************************************************************/
#include "header.h"

/********************************************************************************************************
 *
 *	FUNCTION NAME : main.c
 *	
 *	DESCRIPTION : cantains calls to various other functions required
 *
 *	RETURN VALUE : SUCCESS
 *
 ***********************************************************************************************************/

int main(int argc, char *argv[])
{
    /*Error handling for command line arguments*/
    if(4 != argc)
    {
        printf("Insufficient Number of Arguments\n");
        exit(FAILURE);
    }

    if(NULL == argv[1])
    {
        printf("Please Provide first Input file\n");
        exit(FAILURE);
    }

    if(NULL == argv[2])
    {
        printf("Please provide second input file\n");
        exit(FAILURE);
    }

    if(NULL == argv[3])
    {
        printf("Please provide output file\n");
        exit(FAILURE);
    }

    FILE *fp1; //file pointer for input1.txt
    FILE *fp2; //file pointer for input2.txt
    FILE *fp3; //file pointer for output.txt

    char name[MAX];//variable for storing names
    memset(name,0,MAX*sizeof(char));//intializing name

    node *start1 = NULL; //starting point for first linked list
    node *start2 = NULL; //starting point for second linked list
    node *start = NULL; //starting point for the merged linked list

    file_open(&fp1, argv[1], "r"); //open first input file in read only mode

    /*Read from input file line by line and store it in linked list*/
    while(1)
    {
        fgets(name, (MAX-1)*sizeof(char), fp1);
        if(feof(fp1))
        {
            break;
        }
        insert_list(&start1, name);
    }

    printf("Contents Of First input file\n");
    display_list(&start1);//display the first linked list
    printf("\n\n");

    file_open(&fp2, argv[2], "r"); //open second input file in read only mode

    /*Read from input file line by line and store it in linked list*/
    while(1)
    {

        fgets(name, (MAX-1)*sizeof(char), fp2);
        if(feof(fp2))
        {
            break;
        }
        insert_list(&start2, name);

    }

    printf("Contents Of Second input file\n");
    display_list(&start2);//display second list
    printf("\n\n");

    start = merge_list(&start1, &start2); //merge the two linked list
    printf("*******************Merged List**********\n\n");
    display_list(&start); //displaying the contents of merged list
    printf("\n\n");

    file_open(&fp3, argv[3], "w"); //open output file in write only mode
    write_output(&fp3, &start); //write the contents of merged list in output file

    /*close all the open files*/
    file_close(&fp1);
    file_close(&fp2);
    file_close(&fp3);

    /*Free the list*/
    free_list(&start);

    return SUCCESS;
}
