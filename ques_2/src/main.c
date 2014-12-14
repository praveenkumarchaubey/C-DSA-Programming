/*********************************************************************************************
*	FILE NAME : main.c
*
*	DESCRIPTION : contains main function which calls different functions for implementing
*			the given problem statement
*
*	NAME			ID	DATE		REASON
*-----------------------------------------------------------------------------------------------
*	Praveen Chaubey		38263	1/12/14 	Re test preperation
*
*************************************************************************************************/

/*********************************************************************************************
*
*		HEADER FILES
*
********************************************************************************************/
#include "header.h"

/*******************************************************************************************
*	FUNCTION NAME : main.c
*
*	DESCRIPTION : contains calls to various other functions for implementing the given problem
*			statement
*
*	RETURN VALUE : SUCCESS
*
**************************************************************************************************/
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
		printf("please provide output file name\n");
		exit(FAILURE);
	}

	FILE *fp1; //input file pointer
	FILE *fp2; //output file pointer

	char input[MAX];//to store input stings
	memset(input,0,MAX*sizeof(char));//initializing input by null
	char *token = NULL;//pointer to strings for storing tokens
	node *start = NULL; //start pointer for list

	file_open(&fp1, argv[1], "r");//open input file in read only mode
	file_open(&fp2, argv[2], "w");//open output file in write only mode

	while(1)
	{
		fgets(input, (MAX-1)*sizeof(char), fp1); //reading one string at a time
		/*check for end of file*/
		if(feof(fp1))
		{
			break;
		}

		/*tokenizing the read string*/
		token = strtok(input, "	,. \n:;");
		while(NULL != token)
		{
			insert_list(&start,token);
			token = strtok(NULL, "	,. \n:;");
		}
	}//end of while(1)

	insert_file(&start, &fp2);//read from the list and store in the output file in reverse order

	/*closeing all open files*/
	file_close(&fp1);
	file_close(&fp2);

	free_list(&start);//free the linked list
	return SUCCESS;
}
