//Program to implement infix to postfix convertion and evaluation
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

struct dict       	//To implement a key value pair system
{
	char key;
	int value;
}*alp_num;

char *char_stack;	//For infix to postfix convertion
int  *int_stack;	//For postfix evaluation
char *postfix;
char *variables;
int MAX=20,pftop = -1,ctop=-1,itop=-1,len=0;


void int_push(int item)
{
	int_stack[++itop] = item;
}

int int_pop ()
{
	return int_stack[itop--];
}

void char_push(char info)
{
	if (info != '#') char_stack[++ctop]=info;
}

char char_pop ()
{	//Is Empty   ?
	if (ctop == -1) return '#'; 
	else return char_stack[ctop--];
}

void insert(char item)
{
	postfix[++pftop] = item;
	postfix[pftop+1] = '\0';
}

int precedence(char item)                        
{
	if (item == '^') return 3;
	else if (item == '*' || item == '/' ) return 2;
	else if (item == '+' || item == '-' ) return 1;
	else if (item == '(') return 0;
	else return -1;
}

void display()
{	
	printf("\n");
	for(int i=0;i<=ctop;i++) printf("%c",char_stack[i]);
	printf(" : %s",postfix);
}

void put_var (char item)
{
	for(int i=0;i<len;i++) if (variables[i] == item) return;
	variables[len++] = item;
}

void in_to_post_conv(char *buff)
{
	int ele;
	for(int i=0;buff[i] != '\0';i++)
	{
		display();
		if( isalpha(buff[i]) )		
		{
			insert( buff[i] );
			put_var( buff[i] );
		}
		else if (buff[i] == '(')	char_push(buff[i]);
		else if (buff[i] == ')')	for (ele=char_pop(); ele != '(' ; ele=char_pop()) insert(ele);
		else if (buff[i] == '^')	char_push((buff[i]));
		else
		{
			ele = char_pop();
			if ( precedence(ele) < precedence(buff[i]) )
			{
				char_push (ele);
				char_push(buff[i]);
			}
			else if ( precedence(ele) ==  precedence(buff[i]) ) // +*^  -
			{
				insert(ele);
				char_push(buff[i]);
			}
			else
			{
				for ( ; precedence(ele) >= precedence(buff[i]); ele=char_pop() ) insert(ele);
				if (precedence(ele) < precedence(buff[i]))
				{
					char_push(ele);
					char_push(buff[i]);
				}
			}
		}
	}
	for (ele=char_pop(); ele != '#' ; ele=char_pop()) insert(ele);
}

int operate(int b, int a, char op)
{
	switch (op)
	{
		case '+': return b+a;
		case '-': return b-a;
		case '*': return b*a;
		case '/': return b/a;
		case '^': return pow(b,a);
	}
}

int value(char key)
{
	for(int i=0;i<len;i++)	if(alp_num[i].key == key) return alp_num[i].value; 
}

void post_eval()
{
	for(int i=0; postfix[i] != '\0';i++) (isalpha(postfix[i])) ? int_push(value(postfix[i])) : int_push(operate(int_pop(),int_pop(),postfix[i]));
}

void main()
{
	char *buff = (char *)malloc(MAX);
	postfix = (char *)malloc(MAX);
	char_stack = (char *)malloc(MAX);
	variables = (char *)malloc(MAX);

	printf("\nEnter the Infix expression : ");
	scanf ("%[^\n]",buff);
	in_to_post_conv(buff);
	display();

	alp_num = (struct dict *)malloc(len*sizeof(struct dict));
	int_stack = (int *)malloc(len*sizeof(int));

	for (int i = 0; i < len; i++)
	{
		int val;
		printf("\nEnter the value of %c : ",variables[i]);
		scanf("%d",&val);
		alp_num[i].key=variables[i];
		alp_num[i].value=val;
	}
	post_eval();
	printf("\nEvaluation Result : %d",int_pop());
}