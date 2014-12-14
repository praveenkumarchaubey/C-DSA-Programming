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
		printf("please provide first input file name\n");
		exit(FAILURE);
	}
	if(NULL == argv[2])
	{
		printf("please provide second input file name\n");
		exit(FAILURE);
	}

	FILE *fp1; //first input file pointer
	FILE *fp2; // second input file pointer

	char input[MAX];//to store input stings
	memset(input,0,MAX*sizeof(char));//initializing input by null
	char *token = NULL;//pointer to strings for storing tokens
	node *start = NULL; //start pointer for list
	int position;

	file_open(&fp1, argv[1], "r");//open first input file in read only mode
	file_open(&fp2, argv[2], "r");//open second input file in read only mode

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
		memset(input,0,MAX*sizeof(char));//initializing input by null
	}//end of while(1)

	printf("\n**************************LIST CONTENTS****************\n\n");
	display_list(&start);//display the list

	position = 1;
	memset(input,0,MAX*sizeof(char));//initializing input by null
	while(1)
	{
		fgets(input, (MAX-1)*sizeof(char), fp2); //reading one string at a time
		/*check for end of file*/
		if(feof(fp2))
		{
			break;
		}

		/*tokenizing the read string*/
		token = strtok(input, "	,. \n:;?");
		while(NULL != token)
		{
			insert_list_position(&start,token, &position);
			token = strtok(NULL, "	,. \n:;?");
			position = position + 2;
		}
		memset(input,0,MAX*sizeof(char));//initializing input by null
	}//end of while(1)

	printf("\n**************************updated LIST CONTENTS****************\n\n");
	display_list(&start);//display the list

	/*closeing all open files*/
	file_close(&fp1);
	file_close(&fp2);

	free_list(&start);//free the linked list
	return SUCCESS;
}
