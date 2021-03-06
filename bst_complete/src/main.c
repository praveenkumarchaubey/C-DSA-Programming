/********************************************************************************************
 *
 *       FILE NAME:      main.c
 *
 *       DESCRIPTION:    Contains the main program for implementong a BST list with add
 *                       and delete feature
 *
 ************************************************************************************************/

/***********************************************************************************************
 *                       HEADER FILES
 *
 *************************************************************************************************/
#include "header.h"

/**********************************************************************************************
 *
 *       FUNCTION NAME:  main.c
 *
 *       DESCRIPTION:    Contains the calls to various functions for implementing a BST
 *
 *       RETURN VALUES: SUCCESS or FAILURE
 *
 ************************************************************************************************/

int main()
{
    int choice;//For storing user choice
    tree_node *root = NULL; //pointer to the root
    do
    {
        printf("***************************************************************************\n");
        printf("\t\tMENUE\n");
        printf("****************************************************************************\n");
        printf("\t1.Create Tree\n");
        printf("\t2.Search an Item\n");
        printf("\t3.Pre Order Traversal\n");
        printf("\t4.Post Order Traversal\n");
        printf("\t5.Inorder Traversal\n");
        printf("\t6.Level Order Traversal\n");
        printf("\t7.Delete A Node\n");
        printf("\t8.Quit\n\n");
        printf("********************************************************************************\n\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                insert_node(&root);
                break;

            case 2:
                search(&root);
                break;

            case 3:
                pre_order(&root);
                break;

            case 4:
                post_order(&root);
                break;

            case 5:
                in_order(&root);
                break;

            case 6:
                level_order(&root);
                break;

            case 7:
                delete_node(&root);
                break;

            case 8:
                break;

            default:
                printf("Wrong choice\n");

        }/*End of switch */

    }while(8!=choice); //End of while

    free_tree(&root);

    return 0;

}//end of main
