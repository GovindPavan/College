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
	struct node *temp=NULL;
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->link = NULL;
	new_node->info = info;

	if(start == NULL)
		start = new_node;
	else
	{
		for(temp=start; temp->link != NULL; temp=temp->link);  //Traversing to the end of LL
		temp->link = new_node;
	}
	return start;
}

void display(struct node *start)
{
	printf("\n");
	struct node *temp=NULL;
	for(temp=start;temp!=NULL;temp=temp->link)
		printf("%d ",temp->info);
}

void * sort_LL(struct node *start)
{
	int temp=0;
	struct node *temp1,*temp2,*small_ptr;
	//Implementing Selection Sort
	for(temp1=start; temp1!=NULL; temp1=temp1->link)
	{
		small_ptr = temp1;               //Assuming that the first element is the smallest
		for(temp2=temp1->link; temp2!=NULL; temp2=temp2->link)
		{
			if(temp2->info < small_ptr->info)
				small_ptr = temp2;       //small_ptr will have the smallest element in the list
		}
		if(temp1 != small_ptr)           //If assumption is wrong, Swap!
		{
			temp = temp1->info;
			temp1->info = small_ptr->info;
			small_ptr->info = temp;
		}
	}
	return start;
}

void main()
{
	int i,n,info;
	struct node *start = NULL,*temp;
	printf("\nEnter the number of elements : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the element for Node#%d : ",i+1);
		scanf("%d",&info);
		start = (struct node *)create_node(start,info);
	}
	printf("\nGiven List : ");
	display(start);
	printf("\nSorted List : ");
	start = (struct node *)sort_LL(start);
	display(start);
	printf("\nSmallest element : %d",start->info);
	for(temp=start; temp->link!=NULL; temp=temp->link);
	printf("\nGreatest element : %d",temp->info);
}