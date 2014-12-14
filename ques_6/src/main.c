/**********************************************************************************************************
*	FILE NAME : main.c
*
*	DESCRIPTION : contains main function
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
*	FUNCTION NAME : main.c
*
*	DESCRIPTON : calls other functions
*
*	RETURN VALUE : SUCCESS
*
***********************************************************************************************************************/
int main(int argc, char *argv[])
{
	/*error handling for command line arguments*/
	if(NULL == argv[1])
	{
		printf("please provide input file name\n");
		exit(FAILURE);
	}
	if(NULL == argv[2])
	{
		printf("please provide the output file name\n");
		exit(FAILURE);
	}

	FILE *fp1;//file pointer for input file
	FILE *fp2;//file pointer for output file

	char input[MAX];//for storing strings read from the file
	memset(input, 0, MAX*sizeof(char));//initializing input to null
	
	char keyword[MAX];//for storing strings read from the file
	memset(keyword, 0, MAX*sizeof(char));//initializing keyword to null

	node *start = NULL;//start pointer for the list

	file_open(&fp1, argv[1], "r"); //open input file for reading
	file_open(&fp2, argv[2], "w"); //open output file for writing

	/*reading from input.txt and storing it into the linked list*/
	while(1)
	{
		fgets(input, (MAX-1)*sizeof(char), fp1); //using fgets to read full line
		if(feof(fp1))
		{
			break;
		}
		remove_new_line(input);
		insert_list(&start, input);
	}

	printf("\n*************LIST CONTENTS***************\n");
	display_list(&start); //display the linked list

	printf("Please enter the string from where you want to print the list\n");
	fgets(keyword, (MAX-1)*sizeof(char), stdin);
	remove_new_line(keyword);

	/*printing the list and simultaniously inserting it into the output file*/
	insert_file(&start, keyword, &fp2);

	/*closing all opened files*/
	file_close(&fp1);
	file_close(&fp2);

	/*free the linked list*/
	free_list(&start);

	return SUCCESS;
}
