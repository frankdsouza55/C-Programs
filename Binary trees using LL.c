#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *left,*right;
};
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
void preorder(struct node *temp)
{
    if(temp!=NULL)
    {
        printf("%d\t",temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}
void inorder(struct node *temp)
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        printf("%d\t",temp->data);
        inorder(temp->right);
    }
}
void postorder(struct node *temp)
{
    if(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d\t",temp->data);
    }
}
int main()
{
    struct node *root;
    root=create();
    if(root==NULL)
        printf("\nTree is empty");
    else
    {
        printf("\nPreorder Traversal :\t");
        preorder(root);
        printf("\nInorder Traversal :\t");
        inorder(root);
        printf("\nPostorder Traversal :\t");
        postorder(root);
    }
    return 0;
}
