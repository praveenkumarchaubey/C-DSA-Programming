/*Program of reversing a string using stack*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 20

int top = -1;
char stack[MAX];
char pop();
void push(char);

int main()
{
	char input[MAX];
	memset(input, 0, MAX*sizeof(char));

	char output[MAX];
	memset(output, 0, MAX*sizeof(char));
	int i;

	printf("Enter the string : " );
	fgets(input, (MAX-1)*sizeof(char), stdin);

	/*Push characters of the string input on the stack */
	for(i=0; i < strlen(input); i++)
	{
		push(input[i]);
	}

	/*Pop characters from the stack and store in string str */
	for(i=0; i < strlen(input); i++)
	{
		output[i] = pop();
	}

	printf("Reversed string is : ");
	printf("%s\n",output);
	return 0;
}/*End of main()*/

void push(char item)
{
	if(top == (MAX-1))
	{
		printf("Stack Overflow\n");
		return;
	}
	else
	{
		top = top+1;
		stack[top] = item;
	}
}/*End of push()*/

char pop()
{
	char item;
	if(top == -1)
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	item = stack[top];
	--top;
	return item;
}/*End of pop()*/

