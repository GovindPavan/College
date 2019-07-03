//Program to implement a linked list
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *link;
}*start=NULL,*temp;

void create_node(int n)
{
	struct node *new_node;
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> link = NULL;
	new_node -> info = n;
	if(start == NULL)
		start = new_node;
	else
	{
		temp = start;
		while (temp -> link != NULL)
			temp = temp->link;
		temp->link = new_node;
	}
}

int list_len()
{
	int i=0;
	temp = start;
	while (temp != NULL)
	{
		i++;
		temp = temp->link;
	}
	return i;
}

void insert_node(int n, int pos)
{
	// 0 - start
	// n - at end n>list_len(list)
	if (pos == 0)
	{
		struct node *new_node;
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node -> link = start;
		new_node -> info = n;
		start = new_node;
	}
	else if (pos > list_len())
	{
		struct node *new_node;
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node -> link = NULL;
		new_node -> info = n;
		temp = start;
		while(temp->link != NULL)
			temp = temp->link;
		temp->link = new_node;
	}
	else
	{
		int i=1;
		temp = start;
		while (temp != NULL)
		{
			i++;
			if (i == pos)
			{
				struct node *new_node;
				new_node = (struct node *)malloc(sizeof(struct node));
				new_node -> info = n;
				new_node->link = temp->link;
				temp->link = new_node;
				break;	
			}
			temp = temp->link;
		}
	}
}

void delete_node(int pos)
{
	struct node *temp1 = start,*temp2;
	int i=1;
	while (temp1 != NULL)
	{
		if(i == pos-1)
		{
			temp2 = temp1->link;
			temp1->link = temp2->link;
			break;
		}
		temp1 = temp1->link;
		i++;
	}	
}

void display()
{
	printf("\nList : ");
	printf("\n");
	temp = start;
	while (temp != NULL)
	{
		printf("%d ",temp->info);
		temp = temp->link;
	}
}

void main()
{
	int i=0,n=0,ele=0,pos=0,ch=0;
	printf("\nEnter number of elements : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter element %d : ",i+1);
		scanf("%d",&ele);
		create_node(ele);
	}
	printf("\n");
	temp = start;
	while (temp != NULL)
	{
		printf("%d ",temp->info);
		temp = temp->link;
	}
	
	printf("\nEnter your choice : ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1 : //Insertion
				 printf("\nEnter element to insert : ");
				 scanf("%d",&ele);
				 printf("\nEnter position to insert the element : ");
				 scanf("%d",&pos);
				 insert_node(ele,pos);
				 display();
				 break;
		case 2 : //Deletion
				 printf("\nEnter position to be deleted : ");
				 scanf("%d",&pos);
				 delete_node(pos);
				 display();
				 break;
		case 3 : //Display
				 display();
				 break;
		default: printf("\nInvalid choice ! ");
				 break;
	}
	
	
}
