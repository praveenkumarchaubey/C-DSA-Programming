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
*	DESCRIPTION : contains main function swhich call other functions for implementing the given problem statement
*
*	RETURN VALUE : SUCCESS
*
**************************************************************************************************************************************************/
int main(int argc, char *argv[])
{
	/*error handling for command line arguments*/
	if(NULL == argv[1])
	{
		printf("Please provide first input file name\n");
		exit(FAILURE);
	}

	if(NULL == argv[2])
	{
		printf("Please provide second input file name\n");
		exit(FAILURE);
	}

	if(NULL == argv[3])
	{
		printf("Please provide output file name\n");
		exit(FAILURE);
	}

	FILE *fp1; //file pointer for first input file
	FILE *fp2; //file pointer for second input file
	FILE *fp3; //file pointer for output file

	int index; //array index

	char string[MAX];//for storing strings
	memset(string,0,MAX*sizeof(char));//initializing input to null

	char *arr[MAX]; //array for storing names
	/*initializing array of pointers to null*/
	for (index=0; index<MAX-1; index++)
	{
		arr[index] = NULL;
	}

	file_open(&fp1, argv[1], "r");//opening first input file in read only mode
	file_open(&fp2, argv[2], "r");//opening second input file in read only mode
	file_open(&fp3,argv[3], "w");//opening output file in write only mode

	index = 0;
	/*reading from first input file & storing it in array*/
	while(1)
	{
		fgets(string, (MAX-1)*sizeof(char), fp1); //reading from the first input file
		/*error handling for end of file*/
		if(feof(fp1))
		{
			break;
		}
		insert_array(arr, string, index);
		++index;
	}

	/*reading from second input file and storing it in array*/
	while(1)
	{
		fgets(string, (MAX-1)*sizeof(char), fp2); //reading from the second input file
		/*error handling for end of file*/
		if(feof(fp2))
		{
			break;
		}
		insert_array(arr, string, index);
		++index;
	}

	printf("\n");
	printf("***************array before sorting*************************\n");
	display_array(arr, index);
	printf("\n\n");

	
	quicksort(arr, 0, index-1);//sorting the array
	printf("*******************array after sorting****************************\n");
	display_array(arr, index);
	printf("\n\n");


	insert_file(arr, index, &fp3);//read from the ds and store it in output file

	file_close(&fp1); //closing first input file
	file_close(&fp2); //closing second input file
	file_close(&fp3); //closing output file

	free_array(arr, index); //free the link list

	return SUCCESS;
}
