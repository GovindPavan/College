//Program to implement stack and queue using Linked List
#include <stdio.h>
#include <stdlib.h>

//Node
struct node
{
	int info;
	struct node *link;
};
struct node *top=NULL, *front=NULL, *rear=NULL;

void push(int info)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->info = info;
	new_node->link = NULL;
	if (new_node == NULL)
		printf("\nStack Overflow ! ");  //malloc will return a NULL pointer if there is no memory left to allocate
	else
	{
		if(top == NULL)
			top = new_node;
		else
		{
			new_node->link = top;
			top = new_node;
		}
	}
}

void pop()
{
	int temp=0;
	struct node *del_node = top;
	if(top == NULL)
		printf("\nStack Undeflow !");
	else
	{
		top = top->link;
		printf("\nThe element popped is : %d ",del_node->info);
		free(del_node);
	}
}

void display (int ch)
{
	struct node *temp;
	int i;
	if (ch == 1)
	{
		if (top == NULL)
			printf("\nStack is Empty !");
		else
		{
			printf("\nStack : \n");
			for (temp = top;temp!=NULL;temp=temp->link)
				printf("%d ",temp->info);
		}
	}
	else
	{
		if ((front == NULL) && (rear == NULL))
			printf("\nQueue is Empty !");
		else
		{
			printf("\nQueue : \n");
			for (temp = front;temp!=NULL;temp=temp->link)
				printf("%d ",temp->info);
		}

	}
}

void enqueue(int info)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->info = info;
	new_node->link = NULL;
	if (new_node == NULL)
		printf("\nQueue is Full ! ");  //malloc will return a NULL pointer if there is no memory left to allocate
	else if ((front == NULL) && (rear == NULL))
		front = rear = new_node;
	else
	{
		rear->link = new_node;
		rear = new_node;
	}
}

void dequeue ()
{
	struct node *del_node = front;
	if ((front == NULL) && (rear == NULL))
		printf("\nQueue is Empty ! ");
	else if (front == rear)
	{
		printf("\nThe element deleted is : %d ",del_node->info);
		front = rear = NULL;
	}
	else
	{
		front = front->link;
		printf("\nThe element deleted is : %d ",del_node->info);
		free(del_node);
	}
}

void main()
{
	int info, ch;
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
						case 1 : printf("\nEnter the element to be pushed : ");
								 scanf("%d",&info);
								 push(info);
							 	 display(1);
							 	 break;
						case 2 : pop();
							 	 display(1);
							 	 break;
						case 3 : display(1);
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
						case 1 : printf("\nEnter the element to be inserted : ");
								 scanf("%d",&info);
								 enqueue(info);
							 	 display(2);
							 	 break;
						case 2 : dequeue();
							 	 display(2);
							 	 break;
						case 3 : display(2);
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