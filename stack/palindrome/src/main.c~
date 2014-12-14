/********************************************************************************************
*
*       FILE NAME:      main.c
*
*       DESCRIPTION:    Contains the main program for implementong an array using linkedlist
*                       
*
************************************************************************************************/
/***********************************************************************************************
*                       HEADER FILES
*
*************************************************************************************************/
                #include "header.h"

/********************************************************************************************
*
*       FUNCTION NAME:  main.c
*
*       DESCRIPTION:    Contains the calls to various functions for implementing an array
*
*       RETURN VALUES: Success Or Failure
*
************************************************************************************************/

int main(int argc, char *argv[])
{
        if(3!=argc)
        {
                printf("Insufficient Number of arguments\n");
                printf("1.Please provide the input file name as one argument\n");
                printf("2.Please provide the output file name as the other argument\n");
                exit(0);
        }

        FILE *fp1;
        FILE *fp2;
	char str_in[30];
	memset(str_in,0,30);
	char str_out[30];
	memset(str_out,0,30);
	int strcmp_ret;
	int i,j;
	int len;
	node *top = NULL;

	fp1 = fopen(argv[1],"r");
        if(NULL==fp1)
        {
                printf("Error In opening the file %s",argv[1]);
                exit(0);
        }

        fp2 = fopen(argv[2],"w");
        if(NULL==fp2)
        {
                printf("Error In opening the file %s",argv[2]);
                exit(0);
        }


	while(1)
	{

		
		fscanf(fp1,"%s",str_in);

		if(feof(fp1))
		{
			break;
		}

		len = strlen(str_in);

		for(i=0;i<len;i++)
		{
			push(&top,str_in[i]);
		}

		for(i=0;i<len;i++)
		{
			str_out[i] = pop(&top);
		}
		
		strcmp_ret=strcmp(str_in,str_out);
		if(0==strcmp_ret)
		{
			printf("word %s is a palindrome\n",str_in);
			fprintf(fp2,"%s",str_in);
			fprintf(fp2,"\n");
		}
		else
		{
			printf("word %s is not a palindrome\n",str_in);
		}

	}

	i=fclose(fp1);
        if(i==EOF)
        {
                printf("error in closing the file %s\n",argv[1]);
        }
        else
        {
                printf("File %s successfully closed\n",argv[1]);
        }

	j=fclose(fp2);
        if(j==EOF)
        {
                printf("error in closing the file %s\n",argv[2]);
        }
        else
        {
                printf("File %s successfully closed\n",argv[2]);
        }

	free_list(&top);
	return 0;

}
