#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next;
}*top1=NULL,*top2=NULL;
void push(int x, int y)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(y)
    {
        if(top1==NULL)
            top1=newnode;
        else
        {
            newnode->next=top1;
            top1=newnode;
        }
    }
    else
    {
        if(top2==NULL)
            top2=newnode;
        else
        {
            newnode->next=top2;
            top2=newnode;
        }
    }

}
int main()
{
    int n,r=0;
    printf("\nEnter a number : ");
    scanf("%d",&n);
    while(n)
    {
        push(n%10,1);
        n/=10;
    }
    while(top1!=NULL)
    {
        push(top1->data,0);
        top1=top1->next;
    }
    while(top2!=NULL)
    {
        r=r*10+top2->data;
        top2=top2->next;
    }
    printf("\nReversed number = %d",r);
    return 0;
}
