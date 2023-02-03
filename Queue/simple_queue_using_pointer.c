/*
 *	Implementation of queue using array, with pointer.
 *	Funtions:
 *		[1] Enqueue()  ---> Insert element at the end of queue.
 *		[2] Dequeue()  ---> Delete element at the begining of queue.
 *		[3] Requeue()  ---> Delete the element at the begining and insert the same element at rear.
 *		[4] Unqueue()  ---> Delete the element.
 *		[5] IS_FULL()  ---> Return true if queue is full else false.
 *		[6] IS_EMPTY() ---> Return true if queue is empty else false.
 *		[7] DISPLAY()  ---> Display the content of queue.
 */

/*
 *	@author: Vivek
 */

#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 10
#define true 1
#define false 0

int is_empty(int, int);
int is_full(int);
void enqueue(int *, int *, int);
int dequeue(int *, int *, int);
void requeue(int *, int *, int *);
void unqueue(int *, int *, int);
void display(int *, int, int);
void display_overflow();

// --<Empty>--
int is_empty(int front, int rear)
{
	return front == rear ? true : false;
}

// --<Full>--
int is_full(int rear)
{
	return rear == MAX_QUEUE_SIZE - 1 ? true : false;
}

// --<Enqueue>--
void enqueue(int queue[], int *rear, int element)
{
	is_full(*rear) ? display_overflow() : (queue[++(*rear)] = element);
}

// --<Dequeue>--
int dequeue(int queue[], int *front, int rear)
{
	return is_empty(*front, rear) ? false : queue[++(*front)];
}

// --<Requeue>--
void requeue(int queue[], int *front, int *rear)
{
	if(is_full(*rear))
	{
		display_overflow();
		return;
	}
	else if(is_empty(*front, *rear))
	{
		display(queue, *front, *rear);
		return;
	}
	enqueue(queue, rear, dequeue(queue, front, *rear));
	display(queue, *front, *rear);
}

// --<Unqueue>--
void unqueue(int queue[], int *front, int rear)
{
	is_empty(*front, rear) ? display(queue, *front, rear) : queue[++(*front)];
}

// --<Display>--
void display(int queue[], int front, int rear)
{
	if(is_empty(front, rear))
	{
		printf("\n+-----------------+");
		printf("\n| Queue Underflow |");
		printf("\n+-----------------+");
		return;
	}
	printf("\n");
	for(int i = front + 1; i <= rear; i++)
		printf("[%d]\t", queue[i]);
	printf("\n");
}


// --<Display overflow>--
void display_overflow()
{
	printf("\n+-----------------+");
	printf("\n| Queue  Overflow |");
	printf("\n+-----------------+");
	return;
}

int main()
{	
	int queue[MAX_QUEUE_SIZE];
	int front, rear, choice, element;
	front = rear = -1;

	for(;;)
	{
		printf("\n+---------------+-----------------------+");
		printf("\n|	Choice	|	Operations	|");
		printf("\n+---------------+-----------------------+");
		printf("\n|	[0]	|	Exit		|");
		printf("\n|	[1]	|	Enqueue		|");
		printf("\n|	[2]	|	Dequeue		|");
		printf("\n|	[3]	|	Requeue		|");
		printf("\n|	[4]	|	Unqueue		|");
		printf("\n|	[5]	|	Display		|");
		printf("\n+---------------+-----------------------+");
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
				enqueue(queue, &rear, element);
				break;

			case 2: dequeue(queue, &front, rear) == false ? display(queue, front, rear) : printf("\nDeleted element is [%d]\n", queue[front]);
				break;

			case 3: requeue(queue, &front, &rear);
				break;

			case 4: unqueue(queue, &front, rear);
				break;

			case 5: display(queue, front, rear);
				break;

			default: printf("\nInvalid Choice\n");
				 break;
		}
	}
	return 0;
}
