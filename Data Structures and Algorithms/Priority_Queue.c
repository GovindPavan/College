#include <stdio.h>
#include <stdlib.h>

struct node
{
	int priority;
	int info;
	struct node *link;
};

struct node * create_node (struct node *start)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->link = NULL;
	printf("\nEnter the information : ");
	scanf("%d",&new_node->info);
	printf("\nEnter the priority : ");
	scanf("%d",&new_node->priority);

	if(start)
	{
		if(new_node->priority < start->priority)
		{
			new_node->link = start;
			start = new_node;
		}
		else
		{
			struct node *temp;
			for (temp = start; (temp->link != NULL) && (temp->link->priority <= new_node->priority); temp = temp->link);
			temp->link = new_node;
		}
	}	
	else start = new_node;
	return start;
}

void main()
{
	int n=1,ch;
	char op;
	struct node *start = NULL;
	do
	{
		printf("\nMENU\n 1.Create Queue\n 2.Add Node\n 3.Delete Node\n 4.Display Queue\n 5.Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : do
					 {
						printf("\nNode #%d",n++);
					 	start = create_node(start);
					 	printf("\nDo you wish to continue ?(y/n) : ");
					 	getchar();
					 	scanf("%c",&op);			
					 } while (op == 'y');	
					 break;
			case 2 : printf("\nNode #%d",n++);
					 start = create_node(start);
					 break;
			case 3 : if(start)
					 {
					 	struct node *del_node = start;
					 	start = start->link;
						printf("\nDeleted Node : \n Information : %d\n Priority : %d\n",del_node->info,del_node->priority);
					 	free(del_node);
					 }
					 else printf("\nQueue Empty !");
					 break;
			case 4 : if(start) for (struct node *temp = start; temp != NULL; temp = temp->link) printf("\nInformation : %d\nPriority : %d\n",temp->info,temp->priority);
					 else printf("\nQueue Empty !");
					 break;
			case 5 : exit(0);
		}

	}while(1);
}