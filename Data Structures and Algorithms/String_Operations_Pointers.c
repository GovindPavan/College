//Program to perfrom string operations using pointers and buffers

#include<stdio.h>
#include<stdlib.h>   //For malloc() and free()

//Function to find patterns on a parent string
int str_patt(char *par, char *patt)
{
	int lenp=0,i=0,j,match,count=0,temp;
	while(*(patt+lenp) != '\0')
		lenp++;
	
	//Main loop for parent string
	while(*(par+i) != '\0')
	{
		j=0,match=0;
		while (*(par+i) == *(patt+j))
		{
			//printf("%d:%c == %c:%d\n",i,*(par+i),*(patt+j),j);
			match++;
			if (match == 1)
				temp=i;       //temp holds the index value of the first matching character
			i++;
			j++;
			if (match == lenp)
			{
				printf("%d ",(temp+1));
				count++;
			}
		}
		if(match > 0)		//If there was atleast a one character match, then i = temp
			i=temp;
		i++;
	}
	return count;
}

//Function to perform string comparison
int str_comp(char *str1, char *str2)
{
	int len1=0,len2=0,i=0;
	while(*(str1+len1) != '\0')
		len1++;
	while(*(str2+len2) != '\0')
		len2++;
	if (len1 == len2)
	{
		for  (i=0;i<len1;i++)
		{
			if ( *(str1+i) == *(str2+i))
				continue;
			else if ( *(str1+i) > *(str2+i))
				return 1;
			else if ( *(str1+i) < *(str2+i))
				return -1;
		}
		if (i == len1)
			return 0;
	}
	else
		return 1;
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

int slen(char *buff)
{
	int len=0;
	while (*(buff+len) != '\0')
  				len++;
  	return len;
}


void main()
{
  int ch,i,len;
  do
  {
	  char *buff = (char *)malloc(50*sizeof(char));
	  printf("MENU\n");
	  printf("----\n");
	  printf("1. String Reversal\n2. String Concatenation\n3. String Comparison\n4. String Pattern Matching\n5. Exit\n");
	  printf("Enter your choice : ");
	  scanf("%d",&ch);

	  switch (ch)
	  {
	  	case 1 :printf("\nEnter your string : ");
	  			getchar();
	  			scanf("%[^\n]",buff);
	  			str_revr(buff);
	  			printf("The reversed string is : %s\n",buff);
	  			break;
	  	case 2 :printf("\nEnter the first string : ");
	  			getchar();
	  			scanf("%[^\n]",buff);
	  			char *str1 = (char *)malloc((slen(buff)+1)*sizeof(char));
	  			for(i=0;*(buff+i) != '\0';i++)
	  				*(str1+i) = *(buff+i);
	  			*(str1+i) = '\0';
	  			printf("\nEnter the second string : ");
	  			getchar();
	  			scanf("%[^\n]",buff);
	  			char *str2 = (char *)realloc(str1,(slen(str1)+slen(buff)+1)*sizeof(char));
	  			for(len=0;*(buff+len) != '\0';len++,i++)
	  			  	*(str2+i) = *(buff+len);
	  			*(str2+i)='\0';
	  			printf("The Concatenated string is : %s\n",str2);
	  			free(str2);
	  			break;
	  	case 3 :printf("\nEnter first string : ");
	  			getchar();
	  			scanf("%[^\n]",buff);
	  			str1 = (char *)malloc((slen(buff)+1)*sizeof(char));
	  			for(i=0;*(buff+i) != '\0';i++)
	  				*(str1+i) = *(buff+i);
	  			*(str1+i) = '\0';
	  			i++;
	  			printf("\nEnter second string : ");
	  			getchar();
	  			scanf("%[^\n]",buff);
	  			str2 = (char *)realloc(str1,(slen(str1)+slen(buff)+2)*sizeof(char));
	  			for(len=0;*(buff+len) != '\0';len++,i++)
	  			  	*(str2+i) = *(buff+len);
	  			*(str2+i)='\0';
	  			printf("The Comparison of string 1 w.r.t string 2 resulted in : %d\n",str_comp(str2,(str2+i-len)));
	  			free(str2);
	  			break;
	  	case 4 :printf("\nEnter your parent string : ");
	  			getchar();
	  			scanf("%[^\n]",buff);
	  			str1 = (char *)malloc((slen(buff)+1)*sizeof(char));
	  			for(i=0;*(buff+i) != '\0';i++)
	  				*(str1+i) = *(buff+i);
	  			*(str1+i) = '\0';
	  			i++;
	  			printf("\nEnter pattern string : ");
	  			getchar();
	  			scanf("%[^\n]",buff);
	  			str2 = (char *)realloc(str1,(slen(str1)+slen(buff)+2)*sizeof(char));
	  			for(len=0;*(buff+len) != '\0';len++,i++)
	  			  	*(str2+i) = *(buff+len);
	  			*(str2+i)='\0';
	  			printf("\n%d pattern(s) found !\n",str_patt(str2,str2+i-len));
	  			free(str2);
	  			break;
	  	case 5 :printf("\nThank you and have a nice day !\n");
	  			break;
	  	default:printf("\nInvalid choice !\n");
	  }

	  free(buff);
	}while (ch != 5);
}