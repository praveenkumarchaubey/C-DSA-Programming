/* Deleting in Binary Tree */
#include<iostream>
using namespace std;
struct NODE
{
	int Info;
	struct NODE*Left_Child;
	struct NODE*Right_Child;
};
int depth;
void Output(struct NODE*,int);
struct NODE*Delet_Node(struct NODE*,int);
struct NODE*Create_Tree(int,struct NODE*);
struct NODE*DELE(struct NODE*,struct NODE*);
/* Output function */
void Output(NODE*T,int Level)
{ 
	int i;
	if(T)
	{
		Output(T->Right_Child,Level+1);
		cout<<"\n";
		for(i=0;i<Level;i++)
			cout<<"\t";
		printf("%c",T->Info);
		Output(T->Left_Child,Level+1);
	}
}
/* Delete a node in the binary tree */
NODE*DELE(NODE*Node1,NODE*Node)
{
	NODE*DNode;
	if (Node1->Right_Child!=NULL)
		Node1->Right_Child=DELE(Node1->Right_Child,Node);
	else
	{
		DNode=Node1;
		Node->Info=Node1->Info;
		Node1=Node1->Left_Child;
		free(DNode);
	}
	return Node1;
}
/* Deletion in binary tree */
NODE*Delet_Node(NODE*Node,int Info)
{
	NODE*Temp;
	if(Node==NULL)
	{
		cout<<"\n Information does not exist in the above tree";
		return Node;
	}
	else
	{
		if(Info<Node->Info)
			Node->Left_Child=Delet_Node(Node->Left_Child,Info);
		else
			if(Info>Node->Info)
				Node->Left_Child=Delet_Node(Node->Right_Child,Info);
			else
			{
				Temp=Node;
				if(Temp->Right_Child==NULL)
				{
					Node=Temp->Left_Child;
					free(Temp);
				}
				else
					if(Temp->Left_Child==NULL)
					{
						Node=Temp->Right_Child;
						free(Temp);
					}
					else
						Temp->Left_Child=DELE(Temp->Left_Child,Temp);
			}
	}
	return Node;
}
/* Create binary tree */
struct NODE*Create_Tree(int Info,struct NODE*Node)
{
	if(Node==NULL)
	{
		Node=(struct NODE*)malloc(sizeof(struct NODE));
		Node->Info=Info;
		Node->Left_Child=NULL;
		Node->Right_Child=NULL;
		return Node;
	}
	/* Test for the left child */
	if (Info<Node->Info)
		Node->Left_Child=Create_Tree(Info,Node->Left_Child);
	else
	/* Test for the right child */
		if(Info>=Node->Info)
			Node->Right_Child=Create_Tree(Info,Node->Right_Child);
	return Node;
}
/* Function main */
int main()
{
	int Number=0,Info,depth;
	char choice;
	NODE*T=( NODE*)malloc(sizeof(NODE));
	T=NULL;
	cout<<"\n Input choice 'b' to break:";
	choice=getchar();
	while(choice!='b')
	{
		fflush(stdin);
		cout<<"\n Input information of the node: ";
		scanf("%c",&Info);
		T=Create_Tree(Info,T);
		Number++;
		fflush(stdin);
		cout<<"\n Input choice 'b' to break:";
		choice=getchar();
	}
	fflush(stdin);
	printf("\n Number of elements in the list is %d", Number);
	cout<<"\n Tree is \n";
	Output(T,1);
	printf("\n Input the information to which want remove from the above tree: ");
	scanf("%c",&Info);
	T=Delet_Node(T,Info);
	cout<<"\n Tree after deletion of a node: ";
	Output(T,1);
}
