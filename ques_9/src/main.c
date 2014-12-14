/***********************************************************************************************************************************************
*	FILE NAME : main.c
*
*	DESCRIPTION : contains function definitions for implementing hashing
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

/******************************************************************************************************************
*	FUNCTION NAME : main.c
*
*	DESCRIPTION : main function for implementing hashing
*
*	RETURN VALUE : SUCCESS
*
************************************************************************************************************************/
int main(int argc, char *argv[])
{
	if(NULL == argv[1])
	{
		printf("please enter input file name\n");
		exit(FAILURE);
	}

	if(NULL == argv[2])
	{
		printf("please enter output file name\n");
		exit(FAILURE);
	}

	char read_string[MAX]; //for storing the read strings
	memset(read_string, 0, MAX * sizeof(char));
	
	char delete_string[MAX]; //for storing the string to be deleted
	memset(delete_string, 0, MAX * sizeof(char));

	FILE *fp1; //file pointer for input file;
	FILE *fp2; //file pointer for output file;

	int i; //loop count
	node *names[SIZE]; //array of pointers of type node;
	/*initializing names to null*/
	for(i = 0; i < SIZE; i++)
	{
		names[i] = NULL;
	}

	file_open(&fp1, argv[1], "r"); //opening the input file for reading
	file_open(&fp2, argv[2], "w"); //opening the output file for writing

	/*reading from the file and storing it in the hash table along with printing it on the standar input*/
	printf("\n*******************INPUT.TXT****************\n");
	while(1)
	{
		fgets(read_string, MAX * sizeof(char), fp1);
		if(feof(fp1))
		{
			break;
		}
		printf("%s", read_string);
		insert_table(names,read_string);
		memset(read_string, 0, MAX * sizeof(char));
	}

	printf("\n\nplease enter the string you want to delete\n");
	fgets(delete_string, (MAX - 1)*sizeof(char), stdin);

	delete_table(names, delete_string); //deletes the required string from the table

	insert_file(names, &fp2); //insert the names in the output file along with the string length

	/*closes all opened files*/
	file_close(&fp1);
	file_close(&fp2);

	free_table(names);

	return SUCCESS;
}
