/*
 *	Implementation of queue using structure.
 *	Functions:
 *		[1] Enqueue()  ---> Insert element at the end of the queue.
 *		[2] Dequeue()  ---> Delete element at the beginging of queue.
 *		[3] Requeue()  ---> Delete the element at the begining and insert the same element at rear.
 *		[4] Unqueue()  ---> Delete the element.
 *		[5] IS_FULL()  ---> Return true if queue is full else false.
 *		[6] IS_EMPTY() ---> Return true if queue is empty else false.
 *		[7] DISPLAY()  ---> Display the content of querue.
 */

/*
 *	@author: Vivek
 */

#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 10
#define true 1
#define false 0

typedef struct
{
	int queue[MAX_QUEUE_SIZE];
	int front, rear;
}QUEUE;

int is_full(QUEUE);
int is_empty(QUEUE);
void enqueue(QUEUE *, int);
int dequeue(QUEUE *);
void requeue(QUEUE *);
void unqueue(QUEUE *);
void display(QUEUE);
void display_overflow();

// --<Full>--
int is_full(QUEUE q)
{
	return q.rear == MAX_QUEUE_SIZE - 1 ? true : false;
}

// --<Empty>--
int is_empty(QUEUE q)
{
	return q.front == q.rear ? true : false;
}

// --<Enqueue>--
void enqueue(QUEUE *q, int element)
{
	is_full(*q) ? display_overflow() : (q->queue[++(q->rear)] = element);
}

// --<Dequeue>--
int dequeue(QUEUE *q)
{
	return is_empty(*q) ? false : q->queue[++(q->front)];
}

// --<Requeue>--
void requeue(QUEUE *q)
{
	if(is_full(*q))
	{
		display_overflow();
		return;
	}
	else if(is_empty(*q))
	{
		display(*q);
		return;
	}
	enqueue(q, dequeue(q));
	display(*q);
}

// --<Unqueue>--
void unqueue(QUEUE *q)
{
	is_empty(*q) ? display(*q) : q->queue[++(q->front)];
}

// --<Display>--
void display(QUEUE q)
{
	if(is_empty(q))
	{
		printf("\n+-----------------+");
		printf("\n| Queue Underflow |");
		printf("\n+-----------------+\n");
		return;
	}
	printf("\n");
	for(int i = q.front + 1; i <= q.rear; i++)
		printf("[%d]\t", q.queue[i]);
	printf("\n");
}

// --<Display overflow>--
void display_overflow()
{
	printf("\n+----------------+");
	printf("\n| Queue Overflow |");
	printf("\n+----------------+\n");
	return;
}



int main()
{
	QUEUE q;
	q.front = q.rear = -1;
	int choice, element;
	for(;;)
	{
		printf("\n+---------------+-----------------------+");
		printf("\n|	Choice	|	Operations 	|");
		printf("\n+---------------+-----------------------+");
		printf("\n|	[0]	|	Exit		|");
		printf("\n|	[1]	|	Enqueue		|");
		printf("\n|	[2]	|	Dequeue		|");
		printf("\n|	[3]	|	Requeue		|");
		printf("\n|	[4]	|	Unqueue		|");
		printf("\n|	[5]	|	Display		|");
		printf("\n+---------------+-----------------------+\n");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 0: printf("\nEnd of program");
				printf("\nExited\n");
				exit(0);
				break;

			case 1: printf("\nEnter the element: ");
				scanf("%d", &element);
				enqueue(&q, element);
				break;

			case 2: dequeue(&q) == false ? display(q) : printf("\nDeleted element is [%d]\n", q.queue[q.front]);
				break;

			case 3: requeue(&q);
				break;

			case 4: unqueue(&q);
				break;

			case 5: display(q);
				break;

			default: printf("\nInvalid choice\n");
				 break;
		}
	}
	return 0;
}
