/*
 *	Program to implement stack using structure.
 *	Functions:
 *		[1] PUSH    ---> Insert element at the top of stack.
 *		[2] POP     ---> Delete element from the top of stack.
 *		[3] PEEK    ---> Return the top element of the stack.
 *		[4] FULL    ---> Return true if stack is full else false.
 *		[5] EMPTY   ---> Return true if stack is empty else false.
 *		[6] DISPLAY ---> Display the content of stack.
 */

/*
 *	@author: Vivek
 */

#include<stdio.h>
#include<stdlib.h>

#define MAX_STACK_SIZE 10
#define true 1
#define false 0

typedef struct 
{
	int stack[MAX_STACK_SIZE];
	int top;
}QUEUE;

int is_full();
int is_empty();
void push(QUEUE*,int);
void pop();
void peek();
void display();
// --<Full>--
int is_full(QUEUE q)
{
	return (q.top == MAX_STACK_SIZE - 1 ? true : false);
}

// --<Empty>--
int is_empty(QUEUE q)
{
	return (q.top == -1 ? true : false);
}

// --<Push>--
void push(QUEUE *q, int element)
{
	if(is_full(*q))
	{
		printf("\n+----------------+");
		printf("\n| Stack Overflow |");
		printf("\n+----------------+\n");
		return;
	}
	q->stack[++q->top] = element;
}

// --<Pop>--
void pop(QUEUE *q)
{
	is_empty(*q) ? display(*q) : printf("\nPopped item is [%d]\n", q->stack[q->top--]);
}

// --<Peek>--
void peek(QUEUE q)
{
	is_empty(q) ? display(q) : printf("\nPeeked element is [%d]", q.stack[q.top]);
}

// --<Display>--
void display(QUEUE q)
{
	if(is_empty(q))
	{
		printf("\n+-----------------+");
		printf("\n| Stack Underflow |");
		printf("\n+-----------------+\n");
		return;
	}
	printf("\n");
	for(int i = q.top; i >= 0; i--)
		printf("[%d]\t", q.stack[i]);
	printf("\n");
}

int main()
{
	QUEUE q;
	q.top = -1;
	int choice, element;

	for(;;)
	{
		printf("\n+---------------------------------------+");
		printf("\n|	Choice	| 	Operations	|");
		printf("\n+---------------+-----------------------+");
		printf("\n|	[0]	|	EXIT		|");
		printf("\n|	[1]	| 	PUSH		|");
		printf("\n|	[2]	|	POP		|");
		printf("\n|	[3]	|	PEEK		|");
		printf("\n|	[4]	|	DISPLAY		|");
		printf("\n+---------------+-----------------------+");
		printf("\nEnter yuor choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 0: printf("\nEnd of program");
				printf("\nExited\n");
				exit(0);
				break;

			case 1: printf("\nEnter the element: ");
				scanf("%d", &element);
				push(&q, element);
				break;

			case 2: pop(&q);
				break;

			case 3: peek(q);
				break;

			case 4: display(q);
				break;

			default: printf("\nInvalid choice\n");
				 break;
		}
	}

	return 0;
}
