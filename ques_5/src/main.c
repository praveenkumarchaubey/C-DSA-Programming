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
		printf("please provide first input file name\n");
		exit(FAILURE);
	}
	if(NULL == argv[2])
	{
		printf("please provide second input file name\n");
		exit(FAILURE);
	}
	if(NULL == argv[3])
	{
		printf("please provide output file name\n");
		exit(FAILURE);
	}

	FILE *fp1;//file pointer for first input file
	FILE *fp2;//file pointer for second input file
	FILE *fp3;//file pointer for output file

	char input[MAX];//for storing strings read from the file
	memset(input, 0, MAX*sizeof(char));//initializing input to null

	char keyword[10];//for storing keywors read from the file
	memset(keyword, 0, 10*sizeof(char));//initializing keyword to null

	node *start = NULL;//start pointer for the list

	file_open(&fp1, argv[1], "r"); //open first input file for reading
	file_open(&fp2, argv[2], "r"); //open second input file for reading
	file_open(&fp3, argv[3], "w"); //open output file for writing

	/*reading from input1.txt and storing it into the linked list*/
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

	/*reading the keyword from input2.txt, searching in linked list and if found printing it in output.txt*/
	while(1)
	{
		/*use only fscanf to read the keyword, else you won't get the correct output*/
		fscanf(fp2, "%s", keyword); 
		if(feof(fp2))
		{
			break;
		}
		search_keyword(&start, keyword, &fp3);
	}
	
	/*closing all input files*/
	file_close(&fp1);
	file_close(&fp2);
	file_close(&fp3);

	/*free the linked list*/
	free_list(&start);

	return SUCCESS;
}
