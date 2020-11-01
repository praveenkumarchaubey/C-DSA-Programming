/*********************************************************************************************************************************
 *	FILE NAME : func.c
 *
 *	DESCRIPTION : contains functions definitions for bst implementation
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
 *	FUNCTION NAME : file_open
 *
 *	DESCRIPTION : opens a file
 *
 *	RETURN VALUE : nothing
 *
 **************************************************************************************************************************************/
void file_open(FILE **fp, char *file_name, char *mode)
{
    *fp = fopen(file_name, mode);
    /*error handling*/
    if(NULL == *fp)
    {
        printf("error in opening file %s\n", file_name);
        exit(FAILURE);
    }
    else
    {
        printf("file %s opened successfully\n", file_name);
    }
}

/****************************************************************************************************************************************
 *	FUNCTION NAME : file_close
 *
 *	DESCRIPTION : closes a file
 *
 *	RETURN VALUE : nothing
 *
 **************************************************************************************************************************************/
void file_close(FILE **fp)
{
    int n;
    n = fclose(*fp);
    /*error handling*/
    if(n == EOF)
    {
        printf("error in closing the file\n");
    }
    else
    {
        printf("file closed successfully\n");
    }
}

/****************************************************************************************************************************************
 *	FUNCTION NAME : insert_bst
 *
 *	DESCRIPTION : inserts a node into bst
 *
 *	RETURN VALUE : nothing
 *
 **************************************************************************************************************************************/
void insert_bst(node **root, char input[], int *duplicates)
{
    node *ptr = *root; //pointer for traversing
    node *parent = NULL; // parent pointer
    node *new; //new node
    new = (node *) malloc(sizeof(node));

    if(NULL != new)
    {
        strcpy(new->info, input);
        new->lchild = NULL;
        new->rchild = NULL;

        if(NULL == ptr)
        {
            *root = new;
        }
        else
        {

            while(NULL != ptr)
            {
                parent = ptr;

                if(strcmp(new->info, ptr->info) < 0)
                {
                    ptr = ptr->lchild;
                }
                else if(strcmp(new->info, ptr->info) > 0)
                {
                    ptr = ptr->rchild;
                }
                else
                {
                    (*duplicates)++;
                    free(new);
                    new = NULL;
                    return;
                }
            }
            if(ptr == NULL)
            {
                if(strcmp(new->info, parent->info) < 0)
                {
                    parent->lchild = new;
                }
                else
                {
                    parent->rchild = new;
                }
            }//end of if
        }//end of else
    }//end of outer if
    else
    {
        printf("error in memory allocation\n");
        exit(FAILURE);
    }
}


/****************************************************************************************************************************************
 *	FUNCTION NAME : insert_file
 *
 *	DESCRIPTION : displays the file contents in sorted order
 *
 *	RETURN VALUE : nothing
 *
 **************************************************************************************************************************************/
void insert_file(node **root, FILE **fp)
{
    node *ptr = *root;
    if(ptr != NULL)
    {
        insert_file(&(ptr->lchild), fp);
        fprintf(*fp, "%s", ptr->info);
        printf("%s", ptr->info);
        insert_file(&(ptr->rchild), fp);
    }
    else
    {
        return;
    }
}

/****************************************************************************************************************************************
 *	FUNCTION NAME : free_bst
 *
 *	DESCRIPTION : free the bst
 *
 *	RETURN VALUE : nothing
 *
 **************************************************************************************************************************************/
void free_bst(node **root)
{
    node *ptr = *root;
    if(ptr != NULL)
    {	
        free_bst(&(ptr->lchild));
        free_bst(&(ptr->rchild));
        free(ptr);
        ptr = NULL;
    }
    else
    {
        return;
    }
}
