//Program to perform polynomial addition and multiplication using Linked list
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int coeff;
	int exp;
	struct node *link;
};

struct node * create_node(int coeff, int exp, struct node *start)
{
	if(start == NULL)
	{
		struct node *new_node = (struct node *)malloc(sizeof(struct node));
		new_node->exp = exp;
		new_node->coeff = coeff;
		new_node->link = NULL;
		return new_node;
	}
	else
	{
		if(start->exp < exp)
		{
			struct node *new_node = (struct node *)malloc(sizeof(struct node));
			new_node->exp = exp;
			new_node->coeff = coeff;
			new_node->link = start;
			return new_node;
		}
		else if (start->exp == exp)
		{
			start->coeff += coeff;
			return start;
		}
		else start->link = create_node(coeff,exp,start->link);
	}
}

void * poly_add(struct node *start1, struct node *start2)
{
	struct node *start=NULL,*temp1=start1,*temp2=start2;

	for (temp1=start1; temp1 != NULL; temp1=temp1->link)
		start = create_node(temp1->coeff,temp1->exp,start);
	for (temp2=start2; temp2 != NULL; temp2=temp2->link)
		start = create_node(temp2->coeff,temp2->exp,start);

	return start;
}

void *  poly_multiply(struct node *start1,struct node *start2)
{
	struct node *start=NULL,*temp1=start1,*temp2=start2;

	for (temp1=start1; temp1 != NULL; temp1=temp1->link)
		for(temp2=start2; temp2 != NULL; temp2=temp2->link)
			start = create_node(temp1->coeff*temp2->coeff,temp1->exp+temp2->exp,start);

	return start;
}

void * poly_input(int n)
{
	int i=0,coeff,exp;
	char ch;
	struct node *start=NULL;
	printf("\nPolynomial #%d",n);
	do
	{	
		printf("\n Enter the coefficient of term #%d : ",i+1);
		scanf("%d",&coeff);
		printf("\n Enter the exponent of term #%d : ",++i);
		scanf("%d",&exp);
		start = create_node(coeff,exp,start);
		printf("\nDo you wish to continue ?(y/n) : ");
		getchar();
		scanf("%c",&ch);
	}while(ch == 'y');
	return start;
}

void display (struct node *start)
{
	struct node *temp=start;
	printf("\n\ny = ");
	for(temp=start;temp!=NULL;temp=temp->link)
	{
		if(temp->link != NULL)
			printf("%dx^%d + ",temp->coeff,temp->exp);
		else
			printf("%dx^%d \n",temp->coeff,temp->exp);
	}

}

void main()
{
	int ch;
	struct node *start1=NULL,*start2=NULL,*start3=NULL;
	do
	{
		printf("\nMENU");
		printf("\n1. Addition\n2. Multiplication\n3. Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			 case 1 : start1 = (struct node *)poly_input(1);
			  		  start2 = (struct node *)poly_input(2);
			  		  start3 = (struct node *)poly_add(start1,start2);
			  		  display(start1);
			  		  display(start2);
			  		  display(start3);
			  		  break;
			 case 2 : start1 = (struct node *)poly_input(1);
			  		  start2 = (struct node *)poly_input(2);
			  		  start3 = (struct node *)poly_multiply(start1,start2);
			  		  display(start1);
			  		  display(start2);
			  		  display(start3);
			  		  break;
			 case 3 : exit(0);
			 		  break;
			default : printf("\nInvalid choice !");
					  break;
		}
	}while(1);
}