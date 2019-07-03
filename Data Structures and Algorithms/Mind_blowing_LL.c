#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	int exp;
	struct node *link;
};

struct node * create_node(struct node *start, int info)
{
	if(start == NULL)
	{
		struct node *new_node = (struct node *)malloc(sizeof(struct node));
		new_node->link = NULL;
		new_node->info = info;
		return new_node;
	}
	else start->link = create_node(start->link, info);
	return start;
}

struct node * delete_node (struct node *start , int info)
{
	if(start == NULL) return start;
	else if (start->info == info)return start->link;
	else start->link = delete_node(start->link,info);
	return start;
}

void display (struct node *start)
{
	if(start == NULL) return;
	printf("%d ",start->info);
	display(start->link);
}

void main()
{
	int n,info,i;
	struct node *start=NULL;
	printf("\nEnter the number of nodes : ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("\nEnter the info of Node #%d : ",i+1);
		scanf("%d",&info);
		start = create_node(start,info);

	}
	printf("\n");
	display(start);
	printf("\nEnter the info of node to be deleted  : ");
	scanf("%d",&info);
	start = delete_node(start,info);
	printf("\n");
	display(start);
}