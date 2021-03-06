/********************************************************************************************
 *
 *       FILE NAME:      func.c
 *
 *       DESCRIPTION:    Contains function definition for insertion in queue, deletion in
 *                       queue and displaing the items in a queue
 *
 ************************************************************************************************/

/***********************************************************************************************
 *                       HEADER FILES
 *
 *************************************************************************************************/
#include "header.h"

/********************************************************************************************
 *
 *       FUNCTION  NAME: insert_item
 *
 *       DESCRIPTION:    insert element in the queue from rear position
 *
 *       RETURN VALUE:   NOTHING
 *
 ************************************************************************************************/
void insert_item(int *rear,int *front,int array[])
{
    int item;//item to be inserted
    printf("Please enter an item to be inserted in the queue\n");
    scanf("%d",&item);

    //if queue is empty
    if(*front == -1)
    {
        *front = 0;
        *rear = 0;
        array[*rear]=item;
        printf("Item inserted Successfully\n");
    }

    else
    {
        /*if queue is full*/
        if(*front == ((*rear) + 1) % MAX)
        {
            printf("Queue is full. No insertion possible\n");
        }

        else
        {
            *rear = ((*rear) + 1) % MAX;
            array[*rear] = item;
            printf("Item inserted Successfully\n");
        }

    }//end of outer else

}//end of insert_item


/********************************************************************************************
 *
 *       FUNCTION  NAME: delete_item
 *
 *       DESCRIPTION:    delete element from the queue from the front position
 *
 *       RETURN VALUE:   Nothing
 *
 ************************************************************************************************/

void delete_item(int *rear,int *front,int array[])
{
    int item;//item deleted from the queue

    //if queue is empty
    if(-1 == *front)
    {
        printf("Queue is empty, N deletion is possible\n");
    }

    else
    { 
        //if there is only one item in the queue
        if(*rear == *front)
        {
            item = array[*front];
            *front = -1;
            *rear = -1;
            printf("Item deleted from the queue is %d\n",item);
        }
        else
        {
            item = array[*front];
            *front = ((*front) + 1) % MAX;
            printf("Item deleted from the queue is %d\n",item);	
        }
    }

}//end of insert_item



/********************************************************************************************
 *
 *       FUNCTION  NAME: display
 *
 *       DESCRIPTION:    displays  a linked list
 *
 *       RETURN VALUE:   Nothing
 *
 ************************************************************************************************/

void display(int *rear,int *front,int array[])
{
    int temp;
    //if queue is empty
    if(-1 == *front)
    {
        printf("Queue is empty\n");
    }

    else
    { 
        printf("\nLIST IS\n");
        //if there is only one item in the queue
        if(*rear == *front)
        {
            printf("%d",array[*front]);
        }
        else
        {
            temp = *front; //initial point
            do
            {
                printf("%d\t",array[temp]);
                temp = (temp + 1) % MAX; //incrementing condition
            }while(temp!=*rear);	
            printf("%d\t",array[temp]);
        }
        printf("\n\n");
    }


}//end of display

