/*
 *	Implementation of queue using array. using global variable.
 *	Function:
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

int is_full();
int is_empty();
void enqueue();
int dequeue();
void requeue();
void unqueue();
void display();
void display_overflow();


// --<Global variable>--
int queue[MAX_QUEUE_SIZE];
int front, rear;

// --<Full>--
int is_full()
{
	return rear == MAX_QUEUE_SIZE - 1 ? true : false;
}

// --<Empty>--
int is_empty()
{
	return front == rear ? true : false;
}

// --<Enqueue>--
void enqueue(int element)
{
	is_full() ? display_overflow() : (queue[++rear] = element);
}

// --<Dequeue>--
int dequeue()
{
	return is_empty() ? false : queue[++front]; 
}

// --<Requeue>--
void requeue()
{
	if(is_full())
	{
		display_overflow();
		return;
	}
	else if(is_empty())
	{
		display();
		return;
	}
	enqueue(dequeue());
	display();
}

// --<Unqueue>--
void unqueue()
{
	is_empty() ? display() : queue[++front];
}

// --<Display>--
void display()
{
	if(is_empty())
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

// --<Display Overflow>--
void display_overflow()
{
	printf("\n+-----------------+");
	printf("\n| Queue Overflow |");
	printf("\n+-----------------+");
	return;

}



int main()
{
	front = rear = -1;
	int choice, element;

	for(;;)
	{
		printf("\n+---------------+-----------------------+");
		printf("\n|	Choice	|	Operation	|");
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
				enqueue(element);
				break;

			case 2: dequeue() == false ? display() : printf("\nDeleted element is [%d]\n", queue[front]);
				break;

			case 3: requeue();
				break;

			case 4: unqueue();
				break;

			case 5: display();
				break;

			default: printf("\nInvalid choice\n");
				 break;
		}
	}
	return 0;
}
