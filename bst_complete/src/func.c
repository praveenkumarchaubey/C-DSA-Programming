/********************************************************************************************
 *
 *       FILE NAME:      func.c
 *
 *       DESCRIPTION:    Contains function definition for bst creation, traversal
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
 *       FUNCTION  NAME: pre_order
 *
 *       DESCRIPTION:    traverses a tree recursively
 *
 *       RETURN VALUE:   NOTHING
 *
 ************************************************************************************************/
void pre_order(tree_node **root)
{
    tree_node *ptr;
    ptr = *root;

    if(ptr != NULL)
    {
        printf("%d",ptr->info);
        printf("\n");
        pre_order(&(ptr->lchild));
        pre_order(&(ptr->rchild));
    }
    else
    {
        return;
    }

}


/********************************************************************************************
 *
 *       FUNCTION  NAME: post_order
 *
 *       DESCRIPTION:    traverses a tree recursively
 *
 *       RETURN VALUE:   NOTHING
 *
 ************************************************************************************************/
void post_order(tree_node **root)
{
    tree_node *ptr;
    ptr = *root;
    if(ptr!=NULL)
    {
        post_order(&(ptr->lchild));
        post_order(&(ptr->rchild));
        printf("%d",ptr->info);
    }
    else
    {
        return;
    }
    printf("\n");

}

/********************************************************************************************
 *
 *       FUNCTION  NAME: in_order
 *
 *       DESCRIPTION:    traverses a tree recursively
 *
 *       RETURN VALUE:   NOTHING
 *
 ************************************************************************************************/
void in_order(tree_node **root)
{
    tree_node *ptr;
    ptr = *root;
    if(ptr!=NULL)
    {
        in_order(&(ptr->lchild));
        printf("%d",ptr->info);
        printf("\n");
        in_order(&(ptr->rchild));
    }
    else
    {
        return;
    }
}


/********************************************************************************************
 *
 *       FUNCTION  NAME: insert_queue
 *
 *       DESCRIPTION:    insert an element in the queue from the rear position
 *
 *       RETURN VALUE:   NOTHING
 *
 ************************************************************************************************/
void insert_queue(tree_node **ptr, q_node **front, q_node **rear)
{
    q_node *new;
    new = (q_node *) malloc(sizeof(q_node));
    if(new == NULL)
    {
        printf("Memory Not Available\n");
        return;
    }
    else
    {
        if(*front == NULL)
        {
            new->info = *ptr;
            new->link = NULL;
            *front = new;
            *rear = new;
        }

        else
        {
            new->info = *ptr;
            new->link = NULL;
            (*rear)->link = new;
            *rear = new;

        }
    }
}

/********************************************************************************************
 *
 *       FUNCTION  NAME: del_queue
 *
 *       DESCRIPTION:    delete an element from the queue from the front position
 *
 *       RETURN VALUE:   NOTHING
 *
 ************************************************************************************************/
void del_queue(q_node **front, q_node **rear)
{
    q_node *temp;
    if(*front == NULL)
    {
        printf("Queue Underflow\n");
    }

    else if((*front)->link == NULL)
    {
        temp = *front;
        printf("%d",(*front)->info->info);
        printf("\n");
        *front = NULL;
        *rear = NULL;
        free(temp);
    }

    else
    {
        temp = *front;
        printf("%d",(*front)->info->info);
        printf("\n");
        *front = (*front)->link;
        free(temp);
    }

}

/********************************************************************************************
 *
 *       FUNCTION  NAME: level_order
 *
 *       DESCRIPTION:    traverses the bst in level order
 *
 *       RETURN VALUE:   NOTHING
 *
 ************************************************************************************************/
void level_order(tree_node **root)
{
    tree_node *ptr;
    q_node *front = NULL;
    q_node *rear = NULL;

    ptr = *root;

    if(ptr == NULL)
    {
        printf("Tree is empty\n");
    }

    else
    {
        insert_queue(&ptr, &front, &rear);

        while(front!=NULL) //till queue is not empty
        {
            ptr = front->info;
            del_queue(&front, &rear);

            if(ptr->lchild != NULL)
                insert_queue(&(ptr->lchild), &front, &rear);

            if(ptr->rchild != NULL)
                insert_queue(&(ptr->rchild), &front, &rear);
        }

    }

}
/********************************************************************************************
 *
 *       FUNCTION  NAME: insert_node
 *
 *       DESCRIPTION:    insert element in the tree
 *
 *       RETURN VALUE:   NOTHING
 *
 ************************************************************************************************/
void insert_node(tree_node **root)
{
    tree_node *new; //new node to be inserted
    tree_node *ptr; // ptr for traversing down the tree
    tree_node *parent; //ptr for keeping the address or the parent node
    new = (tree_node *) malloc(sizeof(tree_node));
    ptr = *root;
    parent = NULL;
    if(new != NULL)
    {
        printf("please enter the data you want to insert:\n");
        scanf("%d",&(new->info));
        new->lchild = NULL;
        new->rchild = NULL;

        if(ptr == NULL)
            *root = new;
        else
        {
            while(ptr != NULL)
            {
                parent = ptr; //maintain a parent pointer
                if(new->info < ptr->info)
                    ptr = ptr->lchild;

                else if(new->info > ptr->info)
                    ptr = ptr->rchild;

                else
                {
                    printf("Duplicate Keys are not allowed\n");
                    return;
                }
            }


            if(ptr == NULL)
            {
                if(new->info < parent->info)
                    parent->lchild = new;

                else
                    parent->rchild = new;
            }
        }
    }

    else
    {
        printf("Memory Not Available\n");
        return;
    }


}//end of insert fumction

/********************************************************************************************
 *
 *       FUNCTION  NAME: delete_node
 *
 *       DESCRIPTION:    delete element from the tree
 *
 *       RETURN VALUE:   NOTHING
 *
 ************************************************************************************************/
void delete_node(tree_node **root)
{
    int key;
    printf("please enter the node to be deleted\n");
    scanf("%d",&key);

    tree_node *ptr = *root;
    tree_node *parent = NULL;

    if(ptr == NULL)
    {
        printf("Tree is empty\n");
        return;
    }

    else
    {
        while(ptr != NULL)
        {
            if(key == ptr->info)
            {
                break;
            }

            parent = ptr;

            if(key < ptr->info)
            {
                ptr = ptr->lchild;
            }
            else
            {
                ptr = ptr->rchild;
            }
        }

        if(ptr == NULL)
        {
            printf("key %d not found\n", key);
        }


        else if(ptr->lchild != NULL && ptr->rchild != NULL)
        {
            case_a(root, ptr, parent);
        }

        else if(ptr->lchild == NULL)
        {
            case_b(root, ptr, parent);
        }

        else if(ptr->rchild == NULL)
        {
            case_b(root, ptr, parent);
        }

        else
        {
            case_c(root, ptr, parent);
        }

    }


}

/********************************************************************************************
 *
 *       FUNCTION  NAME: case_a
 *
 *       DESCRIPTION:    if the node to be deleted has two childs
 *
 *       RETURN VALUE:   Nothing
 *
 ************************************************************************************************/
void case_a(tree_node **root, tree_node *ptr, tree_node *parent)
{
    tree_node *succ;
    tree_node *par_succ;

    par_succ = ptr;
    succ = ptr->rchild;

    while(succ->lchild != NULL)
    {
        par_succ = succ;
        succ = succ->lchild;
    }

    ptr->info = succ->info;
    if(succ->rchild != NULL)
    {
        case_b(root, succ, par_succ);
    }
    else
    {
        case_c(root, succ, par_succ);
    }


}

/********************************************************************************************
 *
 *       FUNCTION  NAME: case_b
 *
 *       DESCRIPTION:    if the node to be deleted has only one child
 *
 *       RETURN VALUE:   Nothing
 *
 ************************************************************************************************/
void case_b(tree_node **root, tree_node *ptr, tree_node *parent)
{
    tree_node *child;

    if(ptr->lchild != NULL)
    {
        child = ptr->lchild;
    }
    else
    {
        child = ptr->rchild;
    }

    if(parent == NULL)
    {
        *root = child;
    }

    else if(ptr == parent->lchild)
    {
        parent->lchild = child;
    }
    else
    {
        parent->rchild = child;
    }

    free(ptr);

}

/********************************************************************************************
 *
 *       FUNCTION  NAME: case_c
 *
 *       DESCRIPTION:    if the node to be deleted has no child
 *
 *       RETURN VALUE:   Nothing
 *
 ************************************************************************************************/
void case_c(tree_node **root, tree_node *ptr, tree_node *parent)
{
    if(parent == NULL)
    {
        *root = NULL;
    }

    if(ptr == parent->lchild)
    {
        parent->lchild = NULL;
    }

    else
    {
        parent->rchild = NULL;
    }

    free(ptr);

}

/********************************************************************************************
 *
 *       FUNCTION  NAME: search
 *
 *       DESCRIPTION:    searches  an element in the tree
 *
 *       RETURN VALUE:   Nothing
 *
 ************************************************************************************************/
void search(tree_node **root)
{
    int key;
    printf("Please enter an item to be searched\n");
    scanf("%d",&key);

    tree_node *ptr;
    ptr = *root;

    while(ptr != NULL)
    {
        if(key < ptr->info)
        {
            ptr = ptr->lchild;
        }


        else if(key > ptr->info)
        {
            ptr = ptr->rchild;
        }

        else
        {
            printf("Key Found\n");
            return;
        }

    }

    if(ptr==NULL)
    {
        printf("Key Not found");
    }

}//end of search

/********************************************************************************************
 *
 *       FUNCTION  NAME: Free_tree
 *
 *       DESCRIPTION:    Free The memory allocated dynamically
 *
 *       RETURN VALUE:   Nothing
 *
 ************************************************************************************************/


void free_tree(tree_node **root)
{
    tree_node *ptr;
    ptr = *root;
    if(ptr == NULL)
    {
        return;
    }

    else
    {
        free_tree(&(ptr->lchild));
        free_tree(&(ptr->rchild));
        free(ptr);
        root = NULL;
    }

}


