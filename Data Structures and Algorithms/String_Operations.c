//Program to perfrom string operations

#include<stdio.h>
#include<stdlib.h>   //For malloc() and free()

//Function to find patterns on a parent string
int str_patt(char *par, char *patt, int *index)
{
	int lenp=0,i=0,j,match,pos=0,temp;
	while(*(patt+lenp) != '\0')
		lenp++;
	while(*(par+i) != '\0')
	{
		j=0,match=0;
		while (*(par+i) == *(patt+j))
		{
			match++;
			if (match == 1)
				temp=i;
			i++;
			j++;
			if (match == lenp)
			{
				*(index+pos)=temp+1;
				pos++;
				i--;
			}
		}
		i++;
	}
	return pos;
}

//Function to perform string comparison
int str_comp(char *str1, char *str2)
{
	int len=0,i=0;
	while(*(str1+len) != '\0')
		len++;
	for  (i=0;i<len;i++)
	{
		if ( *(str1+i) == *(str2+i))
			continue;
		else if ( *(str1+i) > *(str2+i))
			return 1;
		else if ( *(str1+i) < *(str2+i))
			return -1;
	}
	if (i == len)
		return 0;
	
}

//Function to reverse the string
void str_revr(char *str)
{
	int len=0,i=0,l;
	char temp;
	while(*(str+len) != '\0')
		len++;
	for(i=0,l=len-1;i<l;i++,l--)
	{
		//Swapping the i'th and l'th characters
		temp = *(str+i);
		*(str+i) = *(str+l);
		*(str+l) = temp;
	}

}

//Concatenate the substring sub to parent string par
void str_conc(char *par, char *sub)
{
	int lenp=0,lens;
	//Calculate the length of parent strings
	while(*(par+lenp) != '\0')
		lenp++;
	for(lens=0;*(sub+lens) != '\0';lenp++,lens++)
		*(par+lenp) = *(sub+lens);	
	*(par+lenp)='\0';
}


void main()
{
  int ch,i;
  char *str1 = (char *)malloc(50*sizeof(char));
  char *str2 = (char *)malloc(50*sizeof(char));
  int *index = (int *)malloc(10*sizeof(int));
  printf("MENU\n");
  printf("____\n");
  printf("1. String Reversal\n2. String Concatenation\n3. String Comparison\n4. String Pattern Matching(Max pattern repetetions : 10)\n");
  printf("Enter your choice : ");
  scanf("%d",&ch);

  switch (ch)
  {
  	case 1 :printf("\nEnter your string : ");
  			getchar();
  			scanf("%[^\n]",str1);
  			str_revr(str1);
  			printf("The reversed string is : %s",str1);
  			break;
  	case 2 :printf("\nEnter your parent string : ");
  			getchar();
  			scanf("%[^\n]",str1);
  			printf("\nEnter your sub string : ");
  			getchar();
  			scanf("%[^\n]",str2);
  			str_conc(str1,str2);
  			printf("The Concatenated string is : %s",str1);
  			break;
  	case 3 :printf("\nEnter first string : ");
  			getchar();
  			scanf("%[^\n]",str1);
  			printf("\nEnter second string : ");
  			getchar();
  			scanf("%[^\n]",str2);
  			printf("The Comparison of string 1 w.r.t string 2 results in : %d",str_comp(str1,str2));
  			break;
  	case 4 :printf("\nEnter your parent string : ");
  			getchar();
  			scanf("%[^\n]",str1);
  			printf("\nEnter the pattern string : ");
  			getchar();
  			scanf("%[^\n]",str2);
  			int items = str_patt(str1,str2,index);
  			if (items)
  			{
  				printf("\nPattern found at position(s) :");
  				for(i=0;i<items;i++)
  					 printf(" %d",*(index+i));
  			}
  			else
  				printf("\nSorry, Pattern not found !");

  			break;
  	default:printf("\nInvalid choice ! ");
  }

  free(str1);
  free(str2);
  free(index);
}
