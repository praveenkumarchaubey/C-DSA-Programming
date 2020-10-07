/********************************************************************************************
 *
 *       FILE NAME:      main.c
 *
 *       DESCRIPTION:    Contains the main program for implementong a circular queue with add
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
 *       DESCRIPTION:    Contains the calls to various functions for implementing a circular queue
 *
 *       RETURN VALUES: Success Or Failure
 *
 ************************************************************************************************/

int main()
{
    int choice; //For storing user choice
    int array[MAX];
    int front = -1;//front pointer
    int rear = -1; //rear pointer

    do
    {
        printf("***************************************************************************\n");
        printf("\t\tMENUE\n");
        printf("****************************************************************************\n");
        printf("\t1.Insert Item\n");
        printf("\t2.Delete Item\n");
        printf("\t3.Display List\n");
        printf("\t4.Quit\n\n");
        printf("********************************************************************************\n\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                insert_item(&front,&rear,array);
                break;

            case 2:
                delete_item(&front,&rear,array);
                break;

            case 3:
                display(&front,&rear,array);
                break;

            case 4:
                break;

            default:
                printf("Wrong choice\n");

        }/*End of switch */

    }while(4!=choice);//End of while

    return 0;
}//end of main


