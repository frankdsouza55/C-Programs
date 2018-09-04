/*Programmer: Frank G. D'Souza*/
/*Title: C program to implement Tree Search*/
#include<stdio.h>
#include<malloc.h>
int f=1,s=0,n=0,d;
struct node
{
    int data;
    struct node *left,*right;
}*root=NULL;
struct node * create()
{
    int x;
    printf("\nEnter data (-1 for no data) : ");
    scanf("%d",&x);
    if(x==-1)
        return NULL;
    else
    {
        struct node *newnode;
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=x;
        printf("\nEnter left child of %d : ",x);
        newnode->left=create();
        printf("\nEnter right child of %d : ",x);
        newnode->right=create();
        return newnode;
    }
}
void search(int x, struct node *temp)
{
    if(temp!=NULL)
    {
        if(x==temp->data)
        {
            printf("\n%d found\n",x);
            f=0;
            return;
        }
        search(x,temp->left);
        search(x,temp->right);
    }
}
void preorder(struct node *temp)
{
    if(temp!=NULL)
    {
        printf("%d\t",temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}
int main()
{
    int c,x;
    root=create();
    do
    {
        printf("\n1: Search\n2: Display preorder traversal\n0: Exit\nChoice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1: printf("\nEnter element to be searched : ");
                    scanf("%d",&x);
                    f=1;
                    search(x,root);
                    if(f)
                        printf("\n%d not found\n",x);
                    break;
            case 2: printf("\nPreorder Traversal :\t");
                    preorder(root);
                    break;
            case 0: return 0;
        }
    }while(c);
}
