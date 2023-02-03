/*
 *	Program to implement stack using pointer.
 *	Functions:
 *		[1] PUSH()     ---> Insert element at the top of stack.
 *		[2] POP()      ---> Delete element from the top of stack.
 *		[3] PEEK()     ---> Return the top element of the stack.
 *		[4] IS_FULL()  ---> Return true if stack is full else false.
 *		[5] IS_EMPTY() ---> Return true if stack is empty else false.
 *		[6] DISPLAY()  ---> Display the content of stack.
 */

/*
 *	@author: Vivek
 */

#include<stdio.h>
#include<stdlib.h>

#define MAX_STACK_SIZE 50
#define true 1
#define false 0

int is_empty(int);
int is_full(int);
void push(int *, int *, int);
void pop(int *, int *);
void peek(int *, int);
void display(int *, int);

// --<Empty>--
int is_empty(int top)
{
	return top == -1 ? true : false;
}

// --<Full>--
int is_full(int top)
{
	return top == MAX_STACK_SIZE - 1 ? true : false;
}

// --<Push>--
void push(int stack[], int *top, int element)
{
	if(is_full(*top))
	{
		printf("\n+----------------+");
		printf("\n| Stack Overflow |");
		printf("\n+----------------+\n");
		return;
	}
	stack[++*top] = element;
}

// --<Pop>--
void pop(int stack[], int *top)
{
	is_empty(*top) ? display(stack, *top) : printf("\nDeleted element is [%d]\n", stack[(*top)--]);
}

// --<Peek>--
void peek(int stack[], int top)
{
	is_empty(top) ? display(stack, top) : printf("\nPeeked element is [%d]\n", stack[top]);
}

// --<Display>--
void display(int stack[], int top)
{
	if(is_empty(top))
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


int main()
{
	int stack[MAX_STACK_SIZE];
	int top = -1, choice, element;
	
	for(;;)
	{
		printf("\n+---------------+-----------------------+");
		printf("\n|	Choice	|	Operations	|");
		printf("\n+---------------+-----------------------+");
		printf("\n|	[0]	|	EXIT		|");
		printf("\n|	[1]	|	PUSH		|");
		printf("\n|	[2]	|	POP		|");
		printf("\n|	[3]	|	PEEK		|");
		printf("\n|	[4]	|	DISPLAY		|");
		printf("\n+---------------+-----------------------+");
		printf("\nEnter you choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 0: printf("\nEnd of program");
				printf("\nExited\n");
				exit(0);
				break;

			case 1: printf("\nEnter the element: ");
				scanf("%d", &element);
				push(stack, &top, element);
				break;

			case 2: pop(stack, &top);
				break;

			case 3: peek(stack, top);
				break;

			case 4: display(stack, top);
				break;

			default: printf("\nInvalid choice\n");
				 break;
		}
	}

	return 0;
}


