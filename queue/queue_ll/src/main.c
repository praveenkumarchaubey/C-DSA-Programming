/********************************************************************************************	
*	NAME:      func.c
*
*       DESCRIPTION:    Contains function definition for SIMPLE QUEUE creation, updation
*                       and deletion
*
************************************************************************************************/

/***********************************************************************************************
*                       HEADER FILES
*
*************************************************************************************************/
                #include "header.h"


/********************************************************************************************
*
*       FUNCTION  NAME:  main
*
*       DESCRIPTION:    calls different functions
*
*       RETURN VALUE:   FAILURE OR SUCCESS
*
************************************************************************************************/

int main()
{
	node *front=NULL;
	node *rear=NULL;
	int choice;
	do
	{
		printf("***************************************************\n");
		printf("\t\tMENUE\n");
		printf("*******************************************************\n");
		printf("\t1.Insert Element\n");
		printf("\t2.Delete Element\n");
		printf("\t3.Display Element\n");
		printf("\t4.Quit\n");
		printf("\n");
		printf("Please enter your choice\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1 : insert(&front, &rear);
				 break;

			case 2 : delete(&front, &rear);
				 break;
				 
			case 3 : display(&front, &rear);
				 break;

			case 4 : 
				 break;
			
			default : printf("Wrong Choice\n");
				  break;

		}//end of switch

	}while(choice!=4);//end while

	free_list(&front, &rear);

	return 0;
}//end of main

