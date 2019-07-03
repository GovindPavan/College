#include <stdio.h>
#include <stdlib.h>

//Creating the node
struct node
{
	int info;
	struct node *link;
};

//Creating the Linked List
void * create_LL(struct node *start)
{
	int i,n,info;
	printf("\nEnter the number of elements/nodes : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter element %d : ",i+1);
		scanf("%d",&info);

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
	p3 = start->link->link;

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
	if(start == NULL)
	{
		printf("\nList is empty !");
		return;
	}
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

int list_len(struct node *start)
{
	int i=0;
	struct node *temp;
	for(temp=start;temp != NULL;temp=temp->link)
		i++;

	return i;
}

void * insert_node(struct node *start)
{
	int info,pos,i;
	printf("\nEnter the information : ");
	scanf("%d",&info);
	printf("\nEnter the position : ");
	scanf("%d",&pos);
	struct node *temp=start;
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->info = info;
	new_node->link = NULL;

	if(pos <= 1)
	{
		new_node->link = start;
		start = new_node;
	}
	else if (pos > list_len(start)+1)
		printf("\nPosition not available !");
	else
	{
		for (i=1;i<=list_len(start);i++)
		{
			if (i == pos-1)
			{
				new_node->link = temp->link;
				temp->link = new_node;
				break;
			}
			temp = temp->link;
		} 
	}
	return start;
}

void * delete_node(struct node *start)
{
	struct node *temp = start,*del_node;
	int i,pos;
	printf("\nEnter the position to be deleted : ");
	scanf("%d",&pos);

	if(start == NULL)
	{
		printf("\nThe list is empty!");
		return start;
	}

	if(pos<=1)
	{
		//Deleting the first node
		del_node = start;
		start = start->link;
		free(del_node);
	}
	else if (pos > list_len(start))
		printf("\nPosition not available ! ");
	else
	{
		for(i=1;i<=list_len(start);i++)
		{
			if (i == pos-1)
			{
				//Temp is pointing to pos-1 th node
				del_node = temp->link;
				temp->link = temp->link->link;
				free(del_node);
				break;
			}
			temp = temp->link;
		}
	}
	return start;
}

int search_node(struct node *start)
{
	int item,i;
	struct node *temp=start;
	printf("\nEnter the item to be searched : ");
	scanf("%d",&item);
	for(i=0;i<list_len(start);i++)
	{
		if(temp->info == item)
			return i+1;
		temp = temp->link;
	}
	return 0;
}

void main()
{	
	struct node *start;
	int i,n,info,ch;
	do
	{
		printf("\nMENU\n");
		printf("1. Create linked list\n2. Insert node\n3. Delete node\n4. Search node\n5. Count nodes\n6. Reverse list\n7. Display list\n8. Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : //Creation
					 start=NULL;
					 start = (struct node *)create_LL(start);
					 display(start);
					 break;
			case 2 : //Insertion
					 start = (struct node *)insert_node(start);
					 printf("\nAfter Insertion : ");
					 display(start);
					 break;
			case 3 : //Deletion
					 start = (struct node *)delete_node(start);
					 printf("\nAfter Deletion : ");
					 display(start);
					 break;
			case 4 : //Search
					 if(ch=search_node(start))
					 	printf("\nItem found at position : %d",ch);
					 else
					 	printf("\nItem not found ! ");
					 break;
			case 5 : //Counting
					 printf("\nThe length of linked list is : %d",list_len(start));
					 break;
			case 6 : //Reverse
					 start = (struct node *)reverse_LL(start);
					 printf("\nAfter Reversing : ");
					 display(start);
					 break;
			case 7 : //Display
					 display(start);
					 break;
			case 8 : //Exit
					 exit(0);
			default: printf("\nInvalid choice ! ");
					 break;
		}

	}while(1);
}