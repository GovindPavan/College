//Program to implement Binary Search Tree
#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *left;
	int info;
	struct node *right;
};

void * create_node (struct node *start, int info)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->left = NULL;
	new_node->info = info;
	new_node->right=NULL;
	
	if(start == NULL)	start = new_node;
	else
	{
		struct node *x=start,*y=NULL;
		while( x != NULL )
		{
			y=x;
			if(info < y->info) x=y->left;
			else x=y->right;
		}
		if(info < y->info)	y->left=new_node;
		else y->right=new_node;
	}
	return start;
}

int *in_successor, l;
int inorder_successor(int info)
{
	int rtn,i;
	for (i=0; i<l; i++) 
		if(in_successor[i] == info) 
		{
			rtn=in_successor[i+1];
			break;
		}
	for(;i<l;i++)	in_successor[i] = in_successor[i+1];
	l--;
	return rtn;
}

struct node *parent = NULL;
void * find_address (struct node *start, int info)
{
	if(start->info == info) return start;
	else if(info < start->info)
	{
		parent = start;
		find_address(start->left,info);
	}
	else //if(info >= start->info)
	{
		parent = start;
		find_address(start->right,info);
	}
}

void * delete (struct node *start, struct node *del_node)
{
	if(del_node == start) parent = NULL; //since root node has no parent
	//if(del_node.isLeafNode())
	if(del_node->left == NULL && del_node->right == NULL)
	{
		if(parent == NULL)
		{
			free(start);
			start=NULL;
		}
		else
		{	
			if(parent->left == del_node) parent->left = NULL;
			else parent->right = NULL;
		}
	}
	//if(del_node.hasLeftNode())
	else if(del_node->left != NULL && del_node->right == NULL)
	{
		if(parent == NULL)
		{
			start = start->left;
			free(del_node);
		}
		else
		{
			if(parent->left == del_node) parent->left = del_node->left;
			else parent->right = del_node->left;
		}
	}
	//if(del_node.hasRightNode())
	else if(del_node->left == NULL && del_node->right != NULL)
	{
		if(parent == NULL)
		{
			start = start->right;
			free(del_node);
		}
		else
		{
			if(parent->left == del_node) parent->left = del_node->right;
			else parent->right = del_node->right;
		}
	}
	//if(del_node.hasLeftNode() && del_node.hasRightNode())
	else if(del_node->left != NULL && del_node->right != NULL)
	{
		int in_succ = inorder_successor(del_node->info);
		struct node *temp = (struct node *)find_address(start, in_succ);
		start = (struct node *)delete(start,temp);
		del_node->info = in_succ;
	}
	return start;
}

void * delete_node (struct node *start,int info)
{
	struct node *del_node = (struct node *)find_address(start,info);
	start = (struct node *)delete(start,del_node);
	return start;
}

void LNR (struct node *start)
{
	if (start != NULL)
	{
		LNR(start->left);
		printf("%d ",start->info);
		in_successor[l++] = start->info;
		LNR(start->right);
	}
}

void NLR (struct node *start)
{
	if (start != NULL)
	{
		printf("%d ",start->info);
		NLR(start->left);
		NLR(start->right);
	}
}

void LRN (struct node *start)
{
	if (start != NULL)
	{
		LRN(start->left);
		LRN(start->right);
		printf("%d ",start->info);
	}
}

void main()
{
	int ch,info,len=0;
	char op;
	struct node *start = NULL;
	do
	{
		printf("\nMENU\n 1.Insert/Create\n 2.Traverse\n 3.Delete\n 4.Exit ");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : do	 
					 {
					 	printf("\nEnter the element to be  inserted : ");
						scanf("%d",&info);len++;
						start = (struct node *)create_node(start,info);
						printf("\nDo you wish to continue ? (y/n) : ");
						getchar();
						scanf("%c",&op);
					 }while(op == 'y');
					 in_successor = (int *)malloc(len*sizeof(int));
					 break;
			case 2 : printf("\nLNR : "); LNR(start);
					 printf("\nNLR : "); NLR(start);
					 printf("\nLRN : "); LRN(start);
					 break;
			case 3 : l=0;printf("\nLNR : "); LNR(start);
					 if (start == NULL) printf("\nBinary Search Tree is empty !");
					 else 
					 {
					 	printf("\nEnter the node to be deleted : ");
					 	scanf("%d",&info);
					 	start=delete_node(start,info);
					 }
					 break;
			case 4 : exit(0);
		   default : printf("\nInvalid Choice ! ");
		}
	}while(1);
}