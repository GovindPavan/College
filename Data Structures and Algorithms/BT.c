//Program to implement binary tree
#include <stdio.h>
#include <stdlib.h>
void display (int *bt,int n)
{
	printf("\n");
	for(int i=0;i<n;i++)	printf("%d ",bt[i]);
}

void LNR (int i,int n, int *bt) 			// i is index
{
	if (i < n) 
	{
		LNR(2*i+1,n,bt);					// L
		printf("%d ",bt[i]);				// N
		LNR(2*i+2,n,bt);					// R
	}
}

void NLR (int i,int n, int *bt) 			// i is index
{
	if (i < n) 
	{
		printf("%d ",bt[i]);				// N
		NLR(2*i+1,n,bt);					// L
		NLR(2*i+2,n,bt);					// R
	}
}

void LRN (int i,int n, int *bt) 			// i is index
{
	if (i < n) 
	{
		LRN(2*i+1,n,bt);					// L
		LRN(2*i+2,n,bt);					// R
		printf("%d ",bt[i]);				// N
	}
}

void main()
{
	int *bt = (int *)malloc(50*sizeof(int));
	int i=0;
	char ch='y';
	printf("\nEnter the root node : ");
	scanf("%d",&bt[i]);
	for (i=1;ch == 'y';i++)
	{
		if (i%2 != 0) //Left Node
		{
			printf("\nEnter the left child of %d : ",bt[(int)((i-1)/2)]);
			scanf("%d",&bt[i]);
		}
		else 		 //Right Node
		{
			printf("\nEnter the right child of %d : ",bt[(int)((i-2)/2)]);
			scanf("%d",&bt[i]);
		}
		printf("\nDo you wish to enter more (y/n) ? ");
		getchar();
		scanf("%c",&ch);
	}
	printf("\nArray representation : ");
	display(bt,i);
	printf("\n LNR : ");
	LNR(0,i,bt);
	printf("\n NLR : ");
	NLR(0,i,bt);
	printf("\n LRN : ");
	LRN(0,i,bt);
}