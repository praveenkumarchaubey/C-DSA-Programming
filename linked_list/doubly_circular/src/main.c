/********************************************************************************************
*
*       FILE NAME:      main.c
*
*       DESCRIPTION:    Contains the main program for implementong a linked list with add
*                       and delete feature
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
*       DESCRIPTION:    Contains the calls to various functions for implementing a linked list
*
*       RETURN VALUES: Success Or Failure
*
************************************************************************************************/

int main()
{
        int choice;//For storing user choice
        node *start = NULL; //pointer to the first node
        do
        {
		printf("***************************************************************************\n");
		printf("\t\tMENUE\n");
		printf("****************************************************************************\n");
                printf("\t1.Insert Employee Data\n");
                printf("\t2.Display List\n");
                printf("\t3.Delete Employee Data\n");
                printf("\t4.Quit\n\n");
		printf("********************************************************************************\n\n");
                printf("Enter your choice : ");
                scanf("%d",&choice);

                switch(choice)
                {
                 case 1:
                        create(&start);
                        break;

                 case 2:
                        display(&start);
                        break;

                 case 3:
                        count(&start);
                        break;

  		case 4:
                        insert_empty(&start);
                        break;

                 case 5:
                        insert_beginning(&start);
                        break;

                 case 6:
                        insert_end(&start);
                        break;

                 case 7:
                        insert_after(&start);
                        break;

                 case 8:
                        insert_before(&start);
                        break;

                 case 9:
                        delete_node(&start);
                        break;

                 case 10:
                         break;

                 default:
                         printf("Wrong choice\n");

                }/*End of switch */

        }while(10!=choice); //End of while

        free_list(&start);
return 0;
}//end of main

