#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *link;
};

void * create_CLL (struct node *last)
{
	int n,info,i;
	struct node *new_node,*temp;
	printf("\nEnter the number of elements : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter element %d : ",i+1);
		scanf("%d",&info);
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node->info = info;
		new_node->link = NULL;
		if(last == NULL)
		{
			last = new_node;
			last->link = new_node;
		}
		else
		{
			new_node->link = last->link;
			last->link = new_node;
			//last = new_node;
		}

	}
	return last;
}


void display(struct node *last)
{
	if(last == NULL)
	{
		printf("\nList is empty !");
		return;
	}
	struct node *temp = last->link;
	printf("\n");
	printf("The list is : \n");
	while(temp != last)
	{
		printf("%d  ",temp->info);
		temp=temp->link;
	}
	printf("%d  ",last->info);
}

void * insert_node(struct node *last)
{
	int info,pos,i,count=0;
	printf("\nEnter the information : ");
	scanf("%d",&info);
	printf("\nEnter the position : ");
	scanf("%d",&pos);
	struct node *temp;
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->info = info;
	new_node->link = NULL;

	//Counting the total number of elements in the list
	for(temp=last->link;temp!=last;temp=temp->link)
	{
		count++;
	}
	count++;


	if(pos<=1)
	{
		//Insert at beginning
		new_node->link = last->link;
		last->link = new_node;
	}
	else if (pos > count+1)
		printf("\nInvalid position !");
	else if (pos == count+1)
	{
		//Insertion at last
		new_node->link = last->link;
		last->link = new_node;
		last=new_node;
	}
	else
	{
		temp=last->link;
		for(i=1;i<=count;i++)
		{
			if(i == pos-1)
			{
				new_node->link = temp->link;
				temp->link = new_node;
			}
			temp=temp->link;
		}
	}
	return last;
}

int list_len(struct node *last)
{
	int i=0;
	struct node *temp;
	for(temp=last->link;temp != last;temp=temp->link)
		i++;

	return ++i;
}

void * delete_node(struct node *last)
{
	struct node *temp = last->link,*del_node;
	int i,pos,count=0;
	printf("\nEnter the position to be deleted : ");
	scanf("%d",&pos);

	if(last == NULL)
	{
		printf("\nThe list is empty!");
		return last;
	}

	//Counting the total number of elements in the list
	for(temp=last->link;temp!=last;temp=temp->link)
	{
		count++;
	}
	count++;
	

	if(pos<=1)
	{
		//Only 1 node in list
		if(count == 1)
		{
			free(last);
			last = NULL;
		}
		else
		{
			//Deleting the first node
			del_node = last->link;
			last->link = last->link->link;
			free(del_node);
		}
	}
	else if (pos > count)
		printf("\nPosition not available ! ");
	else if (pos == count)
	{
		for(temp=last->link;temp->link != last; temp=temp->link);
		del_node = temp->link;
		temp->link = temp->link->link;
		free(del_node);
		last = temp;
	}
	else
	{
		temp = last->link;
		for(i=1;i<=count;i++)
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
	return last;
}

void main()
{	
	struct node *last;
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
					 last=NULL;
					 last = (struct node *)create_CLL(last);
					 display(last);
					 break;
			case 2 : //Insertion
					 last = (struct node *)insert_node(last);
					 printf("\nAfter Insertion : ");
					 display(last);
					 break;
			case 3 : //Deletion
					 last = (struct node *)delete_node(last);
					 printf("\nAfter Deletion : ");
					 display(last);
					 break; /*
			case 4 : //Search
					 if(ch=search_node(start))
					 	printf("\nItem found at position : %d",ch);
					 else
					 	printf("\nItem not found ! ");
					 break; */
			case 5 : //Counting
					 printf("\nThe length of linked list is : %d",list_len(last));
					 break;
		/*	case 6 : //Reverse
					 start = (struct node *)reverse_LL(start);
					 printf("\nAfter Reversing : ");
					 display(start);
					 break;
			*/
			case 7 : //Display
					 display(last);
					 break;
			case 8 : //Exit
					 exit(0);
			default: printf("\nInvalid choice ! ");
					 break;
		}

	}while(1);
}