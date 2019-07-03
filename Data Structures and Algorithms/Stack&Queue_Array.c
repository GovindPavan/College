//Program to implement stack and queue using array
#include <stdio.h>
#include <stdlib.h>

//Global Declarations
int MAX;
int *buff;

int push(int top)
{
	int info;
	printf("\nEnter the element to be pushed : ");
	scanf("%d",&info);
	if (top == (MAX-1))
		printf("\nStack Overflow !");
	else
		*(buff+(++top)) = info;
	return top;
}

int pop (int top)
{
	if (top == -1)
		printf("\nStack Underflow !");
	else 
		top--;
	return top;
}

void display (int front, int ch, int rear)
{
	int i,top=front;
	if (ch == 1)
	{
		printf("\nStack : \n");
		for (i=top;i>=0;i--)
			printf("%d ",*(buff+i));
	}
	else
	{
		printf("\nQueue : \n");
		for (i=front;i<=rear;i++)
			printf("%d ",*(buff+i));
	}
}

void enqueue (int *front, int *rear)
{
	int info;
	printf("\nEnter the element to be pushed : ");
	scanf("%d",&info);
	if (*rear == MAX-1)
		printf("\nQueue Full !");
	else if (*rear == -1 && *front == -1)
	{
		*rear = *front = 0;
		*(buff) = info;
	}
	else
	{
		(*rear)++;
		*(buff + *rear) = info;
	}
}

void dequeue (int *front, int *rear)
{
	if (*front == -1)
		printf("\nQueue is Empty !");
	else if (*rear == *front)
		*rear = *front = -1;
	else
		(*front)++;
}

void main()
{
	int top=-1, info, ch;
	int front=-1, rear=-1;
	printf("\nEnter the MAX value for stack/queue : ");
	scanf("%d",&MAX);
	buff = (int *)malloc(MAX*sizeof(int));

	printf("\nMENU");
	printf("\n 1. Stack\n 2. Queue\n 3. Exit");
	printf("\nEnter your choice : ");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1 :do
				{
					printf("\nMENU\n1. Push\n2. Pop\n3. Display\n4. Exit");
					printf("\nEnter your choice : ");
					scanf("%d",&ch);
					switch(ch)
					{
						case 1 : top = push(top);
							 	 display(top,1,0);
							 	 break;
						case 2 : top = pop(top);
							 	 display(top,1,0);
							 	 break;
						case 3 : display(top,1,0);
								 break;
						case 4 : exit(0);
						default: printf("\nInvalid Choice !");
					}
				}while(1);
				break;
		case 2 :do
				{
					printf("\nMENU\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
					printf("\nEnter your choice : ");
					scanf("%d",&ch);
					switch(ch)
					{
						case 1 : enqueue(&front, &rear);
							 	 display(front,2,rear);
							 	 break;
						case 2 : dequeue(&front, &rear);
							 	 display(front,2,rear);
							 	 break;
						case 3 : display(front,2,rear);
								 break;
						case 4 : exit(0);
						default: printf("\nInvalid Choice !");
					}
				}while(1);
				break;
		case 3 :exit(0);
		default: printf("\nInvalid Choice !");
	}

}
