#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *previous;
	int info;
	struct node *next;
};

int list_len(struct node *start)
{
	int i=0;
	struct node *temp;
	for(temp=start;temp != NULL;temp=temp->next)
		i++;
	return i;
}

void * create_DLL(struct node *start)
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
		new_node -> next = NULL;
		new_node -> info = info;
		new_node -> previous = NULL;

		if(start == NULL)
			start = new_node;
		else
		{
			
			for (temp = start;temp -> next != NULL;temp = temp->next);
			new_node->previous = temp;
			temp->next = new_node;
		}
	}
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
	printf("\nForward : \n");
	for (temp = start;temp != NULL;temp = temp->next)
		printf("%d ",temp->info);
	printf("\nBackward : \n");
	for (temp = start;temp->next != NULL;temp = temp->next);
	for (;temp != NULL;temp = temp->previous)
		printf("%d ",temp->info);
}

void * insert_node(struct node *start)
{
	int info,pos,i;
	printf("\nEnter the information : ");
	scanf("%d",&info);
	printf("\nEnter the position : ");
	scanf("%d",&pos);
	
	struct node *new_node,*temp=start;
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> next = NULL;
	new_node -> info = info;
	new_node -> previous = NULL;

	if(start == NULL)
	{
		printf("\nNo linked list created ! ");
		return start;
	}

	if(pos <= 1)
	{
		new_node->next = start;
		start->previous = new_node;
		start = new_node;
	}
	else if (pos > list_len(start)+1)
		printf("\nPosition not available !");
	else if (pos == list_len(start)+1)
	{
		for(temp=start;temp->next!=NULL;temp=temp->next);
		temp->next = new_node;
		new_node->previous = temp;
	}
	else
	{
		for (i=1;i<=list_len(start);i++)
		{
			if (i == pos-1)
			{
				new_node->next = temp->next;
				temp->next->previous = new_node;
				new_node->previous = temp;
				temp->next = new_node;
				break;
			}
			temp = temp->next;
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
		//Only 1 node in the list
		if(list_len(start) == 1)
		{
			free(start);
			start = NULL;
			return start;
		}
		else
		{
			//Deleting the first node
			del_node = start;
			start->next->previous = NULL;
			start = start->next;
			free(del_node);
		}
	}
	else if (pos > list_len(start))
		printf("\nPosition not available ! ");
	else if (pos == list_len(start))
	{
		for(temp=start;temp->next!=NULL;temp=temp->next);
		del_node = temp;
		temp->previous->next = NULL;
		free(del_node);
	}
	else
	{
		for(i=1;i<=list_len(start);i++)
		{
			if (i == pos-1)
			{
				//Temp is pointing to pos-1 th node
				del_node = temp->next;
				temp->next->next->previous = temp;
				temp->next = temp->next->next;
				free(del_node);
				break;
			}
			temp = temp->next;
		}
	}
	return start;
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
					 start = (struct node *)create_DLL(start);
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
	/*		case 4 : //Search
					 if(ch=search_node(start))
					 	printf("\nItem found at position : %d",ch);
					 else
					 	printf("\nItem not found ! ");
					 break;
	*/		case 5 : //Counting
					 printf("\nThe length of linked list is : %d",list_len(start));
					 break;
	/*		case 6 : //Reverse
					 start = (struct node *)reverse_DLL(start);
					 printf("\nAfter Reversing : ");
					 display(start);
					 break;
	*/		case 7 : //Display
					 display(start);
					 break;
			case 8 : //Exit
					 exit(0);
			default: printf("\nInvalid choice ! ");
					 break;
		}

	}while(1);
}