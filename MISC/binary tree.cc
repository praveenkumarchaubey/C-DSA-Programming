/* Create Binary TREE */
/* CREAT_BT.C */

# include<iostream>
using namespace std;//# include<malloc.h>
struct node
{
	int Info;
	 node *Left_Child;
	 node *Right_Child;
};

 node *Binary_Tree (char *, int, int);
void Output(struct node *, int );

/* Function to insert an element into tree */
node *  Binary_Tree (char *List, int Lower, int Upper)
{
	node *Node;
	int Mid = (Lower + Upper)/2;
	Node = (node *) malloc(sizeof(struct node));

	Node->Info = List [Mid];
	if ( Lower>= Upper)
	{
		Node->Left_Child = NULL;
		Node->Right_Child = NULL;
		return (Node);
	}

	if (Lower <= Mid - 1)
		Node->Left_Child = Binary_Tree (List, Lower, Mid - 1);
	else
		Node->Left_Child = NULL;
	if (Mid + 1 <= Upper)
		Node->Right_Child = Binary_Tree (List, Mid + 1, Upper);
	else
		Node->Right_Child = NULL;
	return(Node);
}

/* Output function */

void Output(node *T, int Level)
{
	int i;
	if (T)
	{
		Output(T->Right_Child, Level+1);
		printf("\n");
		for (i = 0; i < Level; i++)
			printf("   ");
		printf("%c", T->Info);
		Output(T->Left_Child, Level+1);
	}
}

/* Function main */

int main()
{
	char List[100];
	int Number = 0;
	char Info ;
	char choice;
	node *T = (node *) malloc(sizeof(struct node));
	T = NULL;
	printf("\n Input choice 'b' to break:");
	choice = getchar();
	while(choice != 'b')
	{
		printf("\n Input information of the node: ");
		scanf("%c", &Info);
		List[Number++] = Info;
		fflush(stdin);
		printf("\n Input choice 'b' to break:");
		choice = getchar();
	}
	Number --;
	printf("\n Number of elements in the lsit is %d", Number);
	T = Binary_Tree(List, 0, Number);
	Output(T,1);
	return 0;
}
