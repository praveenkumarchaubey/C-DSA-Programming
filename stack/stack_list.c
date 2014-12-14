/*Program of stack using linked list*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};

struct node *top=NULL;

void push(int item);
int pop();
int peek();
int isEmpty();
void display();

int main()
{
	int choice,item;
	while(1)
	{      	
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Display item at the top\n");
		printf("4.Display all items of the stack\n");
		printf("5.Quit\n");
		printf("Enter your choice : ") ;
		scanf("%d", &choice);

		switch(choice)
		{
		case 1:
			printf("Enter the item to be pushed : ");
			scanf("%d",&item);
			push(item);
			break;
		case 2:
			item=pop();
			printf("Popped item is : %d\n",item);
			break;
		case 3:
			printf("Item at the top is %d\n",peek());
			break;
		case 4:
			display();
			break;
		case 5:
			exit(1);
		default :
			printf("Wrong choice\n");
		}/*End of switch */
	}/*End of while */
return 0;
}/*End of main() */

void push(int item)
{
	struct node *new; //node to be inserted
	new=(struct node *)malloc(sizeof(struct node));
	if(new==NULL)
	{
		printf("Stack Overflow\n");
		return;
	}
	new->info=item;
	new->link=top;
	top=new;
}/*End of push()*/

int pop()
{
	struct node *tmp; //node to be deleted
	int item;
	if( isEmpty() )
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	tmp=top;
	item=tmp->info;
	top=top->link;
	free(tmp);
	return item;
}/*End of pop()*/

int peek()
{
	if( isEmpty() )
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	return top->info;
}/*End of peek() */

int isEmpty()
{
	if(top == NULL)
		return 1;
	else
		return 0;
}/*isEmpty()*/


void display()
{       
	struct node *temp;
	temp=top;
	if(isEmpty())
	{	
		printf("Stack is empty\n");
		return;
	}
	printf("Stack elements :\n\n");
	while(temp!=NULL)
	{
		printf(" %d\n",temp->info);
		temp=temp->link;
	}
	printf("\n");
}/*End of display()*/
