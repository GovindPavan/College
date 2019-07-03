//Program to depict different ways of sorting

#include<stdio.h>
#include<stdlib.h>

void bubble_sort(int *ar,int n)
{
	int i=0,j=0;
	for (i=0;i<n;i++)           //Condition could be written better
	{
		for (j=0;j<n-1;j++)
		{
			if( *(ar+j) > *(ar+j+1))
			{
				*(ar+j) = *(ar+j) + *(ar+j+1);
				*(ar+j+1) = *(ar+j) - *(ar+j+1);
				*(ar+j) = *(ar+j) - *(ar+j+1);
			}
		}
	}
}

void insertion_sort(int *ar, int n)
{
	int i,j,item=0;
	for (i=1;i<n;i++)
	{
		item=*(ar+i);                          //Item to be put in the sorted part
		for (j=i-1;j>=0 && *(ar+j)>item;j--)
		{
			*(ar+j) = *(ar+j) + *(ar+j+1);
			*(ar+j+1) = *(ar+j) - *(ar+j+1);
			*(ar+j) = *(ar+j) - *(ar+j+1);	
		}
	}
}

void selection_sort(int *ar, int n)
{
	int i,min_pos,j;
	for (i=0;i<n;i++)
	{
		min_pos = i;
		for (j=i+1;j<n;j++)
		{
			if (*(ar+min_pos)>*(ar+j))
				min_pos=j;
		}
		if(min_pos != i)
		{
			*(ar+min_pos) = *(ar+min_pos) + *(ar+i);
			*(ar+i) = *(ar+min_pos) - *(ar+i);
			*(ar+min_pos) = *(ar+min_pos) - *(ar+i);
		}
	}
}

void main()
{
  int n,ch,i;
  printf("\nEnter the number of elements : ");
  scanf("%d",&n);
  int *buff = malloc(n*sizeof(int));
  printf("\nEnter %d elements : ",n);
  for(i=0;i<n;i++) scanf("%d",(buff + i));
  for(i=0;i<n;i++) printf("%d \t",*(buff + i));
  do
  {
  	printf("\n\nMENU");
		printf("\n1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\n4. Exit\n");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch (ch)
		{
			case 1 : bubble_sort(buff,n);
					 printf("\n");
					 for(i=0;i<n;i++) printf("%d \t",*(buff + i));
					 	break;
			case 2 : insertion_sort(buff,n);
					 printf("\n\n\n");
					 for(i=0;i<n;i++) printf("%d \t",*(buff + i));
						break;
			case 3 : selection_sort(buff,n);
					 printf("\n");
					 for(i=0;i<n;i++) printf("%d \t",*(buff + i));
						 break;
			case 4 : exit(0);
		 default : printf("\nInvalid Choice !");
							 break;
		}
  }while(1);

}
