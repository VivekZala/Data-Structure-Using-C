/*
 *	Implementation of stack using array. Using global variables.
 *	Functions:
 *		[1] PUSH()     ---> Insert element.
 *		[2] POP()      ---> Delete element.
 *		[3] PEEK()     ---> Return top element.
 *		[4] IS_FULL()  ---> Return true if stack is full else false.
 *		[5] IS_EMPTY() ---> Return true if stack is empty else false.
 *		[4] DISPLAY()  ---> Display the content of stack.
 */

#include<stdio.h>
#include<stdlib.h>

#define MAX_STACK_SIZE 50
#define true 1
#define false 0
#define and ||

int is_empty();
int is_full();
void push(int);
void pop();
void peek();
void display();

// --<Global variables>--
int stack[MAX_STACK_SIZE];
int top;

// --<Empty>--
int is_empty()
{
	return (top == -1 ? true : false);
}

// --<Full>--
int is_full()
{
	return (top == MAX_STACK_SIZE - 1 ? true : false);
}

// --<PUSH>--
void push(int element)
{
	if(is_full())
	{
		printf("\n+----------------+");
		printf("\n| Stack Overflow |");
		printf("\n+----------------+\n");
		return;
	}
	stack[++top] = element;
}

// --<POP>--
void pop()
{
	is_empty() ? display() : printf("\nPopped element is [%d]\n", stack[top--]);
}

// --<PEEK>--
void peek()
{
	is_empty() ? display() : printf("\nPeeked ele is [%d]\n", stack[top]);
}

// --<DISPLAY>--
void display()
{
	if(is_empty())
	{
		printf("\n+-----------------+");
		printf("\n| Stack Underflow |");
		printf("\n+-----------------+\n");
		return;
	}
	printf("\n");
	for(int i = top; i >= 0; i--)
		printf("[%d]\t", stack[i]);
	printf("\n");
}

// --<main>--
int main()
{
	top = -1;
	int choice, element;
	
	for(;;)
	{
		printf("\n+---------------------------------------+");
		printf("\n|	Choice	|	Operation	|");
		printf("\n+---------------+-----------------------+");
		printf("\n|	[0]	|	EXIT		|");
		printf("\n|	[1]	|	PUSH		|");
		printf("\n|	[2]	|	POP		|");
		printf("\n|	[3]	|	PEEK		|");
		printf("\n|	[4]	| 	DISPLAY		|");
		printf("\n+---------------+-----------------------+\n");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 0: printf("\nEnd of program");
				printf("\nExited\n");
				exit(0);
				break;

			case 1: printf("\nEnter the element to push: ");
				scanf("%d", &element);
				push(element);
				break;

			case 2: pop();
				break;

			case 3: peek();
				break;

			case 4: display();
				break;

			default: printf("\nInvalid choice\n");
			 	break;
		}
	}
	return 0;
}
