/*

Delete N nodes after M nodes of a linked list
Given a linked list and two integers M and N. Traverse the linked list such that you retain M nodes then 
delete next N nodes, continue the same till end of the linked list. 

Examples:

Input:
M = 2, N = 2
Linked List: 1->2->3->4->5->6->7->8
Output:
Linked List: 1->2->5->6

Input:
M = 3, N = 2
Linked List: 1->2->3->4->5->6->7->8->9->10
Output:
Linked List: 1->2->3->6->7->8

Input:
M = 1, N = 1
Linked List: 1->2->3->4->5->6->7->8->9->10
Output:
Linked List: 1->3->5->7->9

*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};


void * create_node(struct Node *start, int n)
{
    struct Node *new_node,*temp;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node -> link = NULL;
    new_node -> info = n;

    if(start == NULL)
        start = new_node;
    else
    {
        //Traversing to the last node
        for (temp=start; temp->link != NULL;temp = temp->link);
        //Inserting at the end
        temp->link = new_node;
    }
    return start;
}


// Function to skip M nodes and then delete N nodes of the linked list.
// Author : Savio Rajan
void * skipMdeleteN(struct Node *start, int M, int N)
{
    struct Node *temp = start, *t;
    int count;
 
    // The main loop that traverses through the whole list
    for (temp=start; temp!= NULL; temp=t) //while (temp != NULL)
    {
        // Skip M nodes
        for (count = 1; count<M && temp!= NULL; count++)
            temp = temp->link;
 
        // If we reached end of list, then return
        if (temp == NULL)
            return start;
 
        // Start from next node and delete N nodes
        t = temp->link;
        for (count = 1; count<=N && t!= NULL; count++)
        {
            struct Node *del_node = t;
            t = t->link;
            free(del_node);
        }
        temp->link = t; // Link the previous list with remaining nodes
    }
    return start;
}

void display(struct Node *start)
{
    printf("\nList : ");
    printf("\n");
    struct Node *temp;
    for (temp=start; temp != NULL; temp=temp->link)
        printf("%d ",temp->info);
}

void main ()
{
    int n,i,M,N,info;
    struct Node *start=NULL;
    printf("\nEnter number of elements : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter element %d : ",i+1);
        scanf("%d",&info);
        start = (struct Node *)create_node(start,info);
    }
    printf("\nEnter number of nodes to be skipped (M) : ");
    scanf("%d",&M);
    printf("\nEnter number of nodes to be deleted (N) : ");
    scanf("%d",&N);
    display(start);
    start = (struct Node *)skipMdeleteN(start,M,N);
    display(start);
}