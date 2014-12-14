/***********************************************************************************************************************************************
*	FILE NAME : func.c
*
*	DESCRIPTION : contains function definitions for implementing the given problem statement
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
*	FUNCTION NAME : file_open
*
*	DESCRIPTION : opens a file
*
*	RETURN VALUE : nothing
*
**************************************************************************************************************************************************/
void file_open(FILE **fp, char *file_name, char *mode)
{
	*fp = fopen(file_name, mode);
	/*error handling for file opening*/
	if(NULL == *fp)
	{
		printf("Error in opening the file %s\n",file_name);
		exit(FAILURE);
	}
	else
	{
		printf("File %s opened successfully\n",file_name);
	}
}


/***********************************************************************************************************************************************
*	FUNCTION NAME : file_close
*
*	DESCRIPTION : closes a file
*
*	RETURN VALUE : nothing
*
**************************************************************************************************************************************************/
void file_close(FILE **fp)
{
	int n;
	n = fclose(*fp);
	/*error handling for file closing*/
	if(EOF == n)
	{
		printf("Error in closing the file\n");
	}
	else
	{
		printf("File closed successfully\n");
	}
}

/***********************************************************************************************************************************************
*	FUNCTION NAME : insert_array
*
*	DESCRIPTION : inserts an elemnt into the array
*
*	RETURN VALUE : nothing
*
**************************************************************************************************************************************************/
void insert_array(char *arr[MAX], char *string, int index)
{
	int len = 0; //string length

	len = strlen(string); //calculating the string length

	/*allocating memory for storing the strings*/
	arr[index] = malloc((len+1)*sizeof(char));

	/*if memory allocation fails*/
	if(NULL == arr[index])
	{
		printf("Error in memory allocation\n");
		exit(FAILURE);
	}

	/*if memory allocation is successfull*/
	else
	{
		strcpy(arr[index], string);
	}

}

/***********************************************************************************************************************************************
*	FUNCTION NAME : display_array
*
*	DESCRIPTION : display the array
*
*	RETURN VALUE : nothing
*
**************************************************************************************************************************************************/
void display_array(char *arr[MAX], int index)
{
	int i; //loop count
	for(i = 0; i < index; i++)
	{
		printf("%s",arr[i]);
	}

}
/***********************************************************************************************************************************************
*	FUNCTION NAME : free_array
*
*	DESCRIPTION : free the array
*
*	RETURN VALUE : nothing
*
**************************************************************************************************************************************************/
void free_array(char *arr[MAX], int index)
{
	int i;//loop count
	for(i = 0; i < index ; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}
}

/***********************************************************************************************************************************************
*	FUNCTION NAME : insert_file
*
*	DESCRIPTION : reads from the array and store it in the file
*
*	RETURN VALUE : nothing
*
**************************************************************************************************************************************************/
void insert_file(char *arr[MAX], int index, FILE **fp)
{
	int i; //loop count
	for(i = 0; i < index; i++)
	{
		fprintf(*fp, "%s", arr[i]);
	}

}

/***********************************************************************************************************************************************
*	FUNCTION NAME : insertion_sort
*
*	DESCRIPTION : sorts the array
*
*	RETURN VALUE : nothing
*
**************************************************************************************************************************************************/
void insertion_sort(char *arr[MAX], int index)
{
	int i, j;
	char *temp;
	for(i = 0; i < index - 1; i++)
	{
		for(j = i+1; j < index; j++)
		{
			if(strcmp(arr[i], arr[j]) > 0)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}//end of inner for()
	}//end of outer for()
}
