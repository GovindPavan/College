//Program to check whether a string stored in a Circular Doubly Linked List(CDLL) is a palindrome or not.
#include <stdio.h>
#include <stdlib.h>

//Node
struct node
{
	struct node *previous;
	char info;
	struct node *next;
};

void * create_CDLL(struct node *start)
{
	int i,n;
	char info;
	printf("\nEnter the number of characters : ");
	scanf("%d",&n);
	//Allocating array to store the word
	char *buff = (char *)malloc((n+1)*sizeof(char));
	printf("\nEnter the word : ");
	getchar();
	scanf("%[^\n]",buff);
	printf("\n%s",buff);

	for(i=0; buff[i] != '\0' ;i++)
	{
		struct node *new_node,*temp=NULL;
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node -> next = NULL;
		new_node -> info = buff[i];
		new_node -> previous = NULL;

		if(start == NULL) //No linked list exists
		{
			start=new_node;
			new_node->next = new_node;
			new_node->previous = new_node;
		}
		else
		{
			//Traversing to the end of the list
			for (temp = start; temp->next != start;temp = temp->next);
			
			//Inserting at the end
			//Step 1
			new_node->next = start;
			start->previous = new_node;
			//Step 2
			temp->next = new_node;
			new_node->previous = temp;
		}
	}
	return start;

}
void display_CDLL(struct node *start)
{
	struct node *temp;
	printf("\n");
	//Forward Propogation
	for(temp=start; temp->next != start; temp=temp->next)
		printf("%c -> ",temp->info);
	printf("%c",temp->info);
	/*
	//Backward Propogation
	printf("\n");
	for(temp=start->previous; temp != start; temp=temp->previous)
		printf("%c -> ",temp->info);
	printf("%c",temp->info);
	*/
}

int palindrome (struct node *start)
{
	struct node *first, *last, *temp;
	int flag=1;
	//                              condition for odd no.of elements   
	for(first=start, last=start->previous; first != last ; first=first->next, last=last->previous)
	{
		if (first->info != last->info)
		{
			flag=0;
			break;
		}
		else if (first->next == last)  //Condition for even no.of elements
			break;
	}	
	return flag;
}
void main()
{
	struct node *start=NULL;
	start = (struct node *)create_CDLL(start);
	display_CDLL(start);
	if(palindrome(start))
		printf("\nWord is a palindrome ! ");
	else
		printf("\nWord is not a palindrome ! ");
}