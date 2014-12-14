/*********************************************************************************************************************************
*	FILE NAME : main.c
*
*	DESCRIPTION : contains main function for implementing bst
*
*	NAME		ID	DATE	REASON
*--------------------------------------------------------------------------------------------------------------------------------
*PRAVEEN CHAUBEY	38263	7/12/14	CDSA RE TEST
************************************************************************************************************************************/

/*********************************************************************************************************************************
*				HEADER FILES
*
***************************************************************************************************************************************/
#include "header.h"

/****************************************************************************************************************************************
*	FUNCTION NAME : main.c
*
*	DESCRIPTION : main function for implementing bst
*
*	RETURN VALUE : SUCCESS
*
**************************************************************************************************************************************/
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

	FILE *fp1; //file pointer for input file
	FILE *fp2; //file pointer for output file

	file_open(&fp1, argv[1], "r");//opening input file in read mode
	file_open(&fp2, argv[2], "w");//opening output file in write mode

	char input[MAX]; //for storing input file names
	node *root = NULL; //root node of tree
	int count = 0; //name count
	int duplicates = 0;

	while(1)
	{
		memset(input, 0, MAX * sizeof(char));//initializing input
		/*reading from the file*/
		fgets(input, (MAX-1)*sizeof(char), fp1);
		if(feof(fp1))
		{
			break;
		}
		insert_bst(&root, input, &duplicates);
		count++;
	}

	printf("\n\n**********File contents in level order***********\n\n");
	fprintf(fp2, "Total names present in the input file is %d\n", count);
	fprintf(fp2, "Total number of duplicate names present in the input file is %d\n\n", duplicates);
	fprintf(fp2, "\n\n**********File contents in level order***********\n\n");
	insert_file(&root, &fp2);

	file_close(&fp1); //closing input file
	file_close(&fp2); //closing output file
	free_bst(&root);

	return SUCCESS;
}

