//Program to mrege two sorted linked list
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *link;
}*temp=NULL;

void * create_node(struct node *start,int n)
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
	return start;
}

void display(struct node *start)
{
	printf("List : ");
	temp = start;
	while (temp != NULL)
	{
		printf("%d ",temp->info);
		temp = temp->link;
	}
	printf("\n");
}


void * merge(struct node *start1, struct node *start2)
{
	struct node *temp1=start1, *temp2=start2;
	struct node *start3=NULL;

	for(temp1=start1;temp1 != NULL;temp1 = temp1->link)
	{
		for(temp2=start2;temp2 != NULL;temp2 = temp2->link;)
		{
			if (temp1->info > temp2->info)
				start3=(struct node *)create_node(start3,temp2->info);
			else if (temp1->info < temp2->info)
			{
				start3=(struct node *)create_node(start3,temp1->info);
				break;
			}
			else
			{
				start3=(struct node *)create_node(start3,temp1->info);
				temp1=temp1->link;
				start3=(struct node *)create_node(start3,temp2->info);
			}
		}
		if ( (temp1 != NULL) && (temp2 == NULL) )
			start3=(struct node *)create_node(start3,temp1->info);
	}
	
	while ( (temp1 == NULL) && (temp2 != NULL) )
	{
		start3=(struct node *)create_node(start3,temp2->info);
		temp2 = temp2 -> link;
	}
	
	return start3;
}

void main()
{
	struct node *start1=NULL,*start2=NULL;
	int i=0,n=0,ele=0;

	//First sorted list
	printf("\nEnter number of elements on first list : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the sorted element #%d : ",i+1);
		scanf("%d",&ele);
		start1=(struct node *)create_node(start1,ele);
	}
	printf("\n");
	
	//Second sorted list
	printf("\nEnter number of elements on second list : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the sorted element #%d : ",i+1);
		scanf("%d",&ele);
		start2=(struct node *)create_node(start2,ele);
	}
	printf("\n");
	
	printf("\nFirst list : \n");
	display(start1);
	printf("\nSecond list : \n");
	display(start2);

	printf("\n\nMerged list : \n");
	struct node *start3 = (struct node *)merge(start1,start2);
	display(start3); 
}