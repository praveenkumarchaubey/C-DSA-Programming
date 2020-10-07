/********************************************************************************************
 *
 *       FILE NAME:      header.h
 *
 *       DESCRIPTION:    Contains header files, macros and function prototypes.
 *
 ************************************************************************************************/

/*********************************************************************************************
 *                               HEADER FILES
 *
 **********************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*********************************************************************************************
 *                                       MACROS
 *
 ************************************************************************************************/
#define SUCCESS 1
#define FAILURE 0
#define MAX 30

/*********************************************************************************************
 *                                       USER DEFINED DATA TYPES
 *
 ************************************************************************************************/
typedef struct bst{
    int info;
    struct bst *lchild; //pointer to the left child
    struct bst *rchild; //pointer to the right child
}tree_node;

typedef struct queue{
    tree_node *info; //pointer to point the tree node
    struct queue *link; //pointer to the next node
}q_node;

/************************************************************************************************
 *
 *                               FUNCTION DECLARATIONS
 *
 **************************************************************************************************/

void pre_order(tree_node **root);
void post_order(tree_node **root);
void in_order(tree_node **root);
void insert_queue(tree_node **ptr, q_node **front, q_node **rear);
void del_queue(q_node **front, q_node **rear);
void level_order(tree_node **root);
void insert_node(tree_node **root);
void search(tree_node **root);
void delete_node(tree_node **root);
void free_tree(tree_node **root);
void case_a(tree_node **root, tree_node *ptr, tree_node *parent);
void case_b(tree_node **root, tree_node *ptr, tree_node *parent);
void case_c(tree_node **root, tree_node *ptr, tree_node *parent);
