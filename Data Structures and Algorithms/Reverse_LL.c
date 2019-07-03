//Program to reverse a linked list
#include <stdio.h>
#include <stdlib.h>

//Creating the node
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
		temp = start;
		while (temp -> link != NULL)
			temp = temp->link;
		temp->link = new_node;
	}
	return start;
}

void * reverse_LL(struct node *start)
{
	struct node *p1,*p2,*p3;

	if(start->link == NULL)
		return start;

	p1 = start;
	p2 = start->link;
	p3 = p2->link;

	p1->link = NULL; 	//For First node
	p2->link = p1;
	
	while (p3 != NULL)
	{
		//Rearranging pointers
		p1 = p2;
		p2 = p3;
		p3 = p3->link;    //Updation

		//Switching
		p2->link = p1;
	}
	//New start pointer
	start = p2;   //Since p3 == NULL
	return start;
}

void display(struct node *start)
{
	struct node *temp=NULL;
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
	struct node *start=NULL;
	int i,n,info;
	printf("\nEnter the number of elements : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter element %d : ",i+1);
		scanf("%d",&info);
		start = (struct node  *)create_node(start,info);
	}
	display(start);
	start = reverse_LL(start);
	display(start);
}