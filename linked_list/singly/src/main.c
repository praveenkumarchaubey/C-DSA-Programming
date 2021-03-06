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
                printf("\t1.Create List\n");
                printf("\t2.Display\n");
                printf("\t3.Count\n");
                printf("\t4.Search\n");
                printf("\t5.Add to empty list / Add at beginning\n");
                printf("\t6.Add at end\n");
                printf("\t7.Add after node\n");
                printf("\t8.Add before node\n");
                printf("\t9.Add at position\n");
                printf("\t10.Delete\n");
                printf("\t11.Quit\n\n");
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
                        search(&start);
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
                        insert_position(&start);
                        break;

                 case 10:
                        delete_node(&start);
                        break;

                 case 11:
                         break;

                 default:
                         printf("Wrong choice\n");

                }/*End of switch */

        }while(11!=choice); //End of while

        free_list(&start);
return 0;
}//end of main
