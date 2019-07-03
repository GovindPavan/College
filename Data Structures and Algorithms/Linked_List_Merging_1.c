/*
Program to merge two sorted singly linked list to form another sorted list
Author : Edwin Charles
*/

#include <stdio.h>
#include <malloc.h>

struct node
{
    int num;
    struct node *link;
}*start1=NULL,*start2=NULL,*start3=NULL;

void createLists()
{
    int n,i;
    struct node *new_node,*temp;
    printf("Enter first list details: ");
    printf("\nNo. of nodes: ");
    scanf("%d",&n);
    printf("Enter no.s in ascending order: ");
    for(i=0;i<n;i++)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        scanf("%d",&new_node->num);
        new_node->link = NULL;
        if(start1==NULL)
            start1=new_node;
        else
        {
            temp=start1;
            while(temp->link!=NULL)
                temp = temp->link;
            temp->link = new_node;
        }
    }
    printf("Enter second list details: ");
    printf("\nNo. of nodes: ");
    scanf("%d",&n);
    printf("Enter no.s in ascending order: ");
    for(i=0;i<n;i++)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        scanf("%d",&new_node->num);
        new_node->link = NULL;
        if(start2==NULL)
            start2=new_node;
        else
        {
            temp=start2;
            while(temp->link!=NULL)
                temp = temp->link;
            temp->link = new_node;
        }
    }
    
}
void merge()
{
    struct node *temp1,*temp2,*temp3,*new_node;
    temp1 = start1;
    temp2 = start2;
    temp3 = start3;
    while(temp1!=NULL&&temp2!=NULL)
    {
        
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->link=NULL;
        if(temp1->num < temp2->num)
        {
            
            new_node->num=temp1->num;
            if(start3==NULL)
            {
                start3=new_node;
                temp3=start3;
            }
            else
            {
                temp3->link=new_node;
                temp3=new_node;
            }
          temp1=temp1->link;
        }    
            
        else if(temp2->num<temp1->num)
        {
            
            new_node->num=temp2->num;
            if(start3==NULL)
            {start3=new_node;
             temp3=start3;
            }
            else
            {
            
            temp3->link=new_node;
            temp3=new_node;
            }
          temp2=temp2->link;
       }
       else
       {
            
            new_node->num=temp1->num;
            if(start3==NULL)
            {start3=new_node;
             temp3=start3;
            }
            else
            {
            
            temp3->link=new_node;
            temp3=new_node;
            }
          temp1=temp1->link;
          temp2=temp2->link;
       }
    }
    while(temp1!=NULL)
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->link=NULL;
        new_node->num=temp1->num;
        temp3->link=new_node;
        temp3=new_node;
        temp1=temp1->link;
        
    }
    while(temp2!=NULL)
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->link=NULL;
        new_node->num=temp2->num;
        temp3->link=new_node;
        temp3=new_node;
        temp2=temp2->link;
        
    }    
}
void display(struct node *temp)
{
    while(temp!=NULL)
    {
        printf("%d ",temp->num);
        temp = temp->link;
    }
}
void main()
{
    createLists();
    merge();
    display(start1);
    display(start2);
    display(start3);
}
