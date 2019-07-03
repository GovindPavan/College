//Program to implement the Graph data structure
#include <stdio.h>
#include <stdlib.h>

int top=-1,front=-1,rear=-1;
int *stack,*queue;

struct node
{
	int info;
	struct node *link;
};

void push(int info)
{
	stack[++top]=info;
}

int pop()
{
	if(top == -1) return 999;
	return stack[top--];
}

void enqueue(int info)
{
	if(front == -1 && rear == -1)
		front = rear = 0;
	else rear++;
	queue[rear] = info;
}

int dequeue()
{
	if(front == -1 && rear == -1)
		return 999;
	else if(front == rear)
	{
		front = rear = -1;
		return queue[0];
	}
	else return queue[front--];

}

void display(struct node *graph, int n)
{
	struct node *temp;
	int i;
	for(i=0;i<n;i++)
	{
		for(temp = &graph[i]; temp!=NULL; temp=temp->link) printf("%d->",temp->info);
		printf("NULL\n");
	}
}

void * create_node(struct node *start,int info)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> link = NULL;
	new_node -> info = info;
	struct node *temp;
	//Appending the new node to the end
	if(start == NULL)	return new_node;
	for (temp = start; temp->link != NULL;temp = temp->link);
	temp->link = new_node;
	return start;
}

void * init_graph(struct node *graph, int n)
{
	int i,info;
	char ch;
	for(i=0;i<n;i++)
	{
		//Main element and it's link
		printf("\nEnter element #%d : ",i+1);
		scanf("%d",&graph[i].info);
		graph[i].link=NULL;

		printf("\nIs %d connceted to any other elements : ? (y/n) : ",graph[i].info);
		getchar();
		scanf("%c",&ch);
		while(ch=='y')
		{
			printf("\nEnter the element connected to %d: ",graph[i].info);
			scanf("%d",&info);
			graph[i].link = (struct node *)create_node(graph[i].link,info);
			printf("\nIs %d connceted to any more elements ? (y/n) : ",graph[i].info);
			getchar();
			scanf("%c",&ch);
		}
	}
	return graph;
}

int DFS(struct node *graph, int n, int info)
{
	struct node *temp;
	int i;
	for(i=0;i<n;i++)
	{
		
	}
}

void main()
{
	int n;
	printf("\nEnter the number of elements in your graph : ");
	scanf("%d",&n);
	struct node *graph = (struct node *)malloc(n*sizeof(struct node));
	//Initializing the graph
	graph = (struct node *)init_graph(graph,n);
	printf("\nYour Graph : \n");
	display(graph,n);

	//Stack for DFS and Queue for BFS
	stack = (int *)malloc(n*sizeof(int));
	queue = (int *)malloc(n*sizeof(int));

	printf("\nEnter the element you want to search : ");
	scanf("%d",&info);
	if(DFS(graph, n, info)) printf("\n%d was found !",info);
	else printf("\n%d was not found !",info);
}