//Program to reverse print a linked list without actually reversing the linked list
#include <stdio.h>
#include <stdlib.h>

//Node
struct node
{
	int info;
	struct node *link;
};

void * create_node(struct node *start, int info)
{
	struct node *new_node,*temp=NULL;
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> link = NULL;
	new_node -> info = info;
	if(start == NULL)
		start = new_node;
	else
	{
		for (temp = start; temp->link != NULL;temp=temp->link);
		temp->link = new_node;
	}
	return start;
}

void display(struct node *start)
{
	struct node *temp=NULL;
	printf("\nList : ");
	printf("\n");
	for (temp = start;temp != NULL;temp=temp->link)
		printf("%d ",temp->info);
}

void reverse_print(struct node *start)
{
	if (start == NULL)
		return;
	reverse_print(start->link);
	printf("%d ", start->info);
}

void main()
{
	struct node *start=NULL;
	int i,n,info;
	printf("\nEnter the number of elements : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter element #%d : ",i+1);
		scanf("%d",&info);
		start = (struct node  *)create_node(start,info);
	}
	display(start);
	printf("\n Reversed : ");
	reverse_print(start);
}