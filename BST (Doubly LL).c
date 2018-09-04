#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *left,*right;
};
typedef struct node node;
void insert(node *root, node *temp)
{
    if(temp->data <= root->data)
    {
        if(root->left !=NULL)
            insert(root->left,temp);
        else
            root->left=temp;
    }
    if(temp->data > root->data)
    {
        if(root->right !=NULL)
            insert(root->right,temp);
        else
            root->right=temp;
    }
}
node* create()
{
    node *newnode;
    newnode=(node *)malloc(sizeof(node));
    printf("\nEnter the data : ");
    scanf("%d",& newnode->data);
    newnode->left=newnode->right=NULL;
    return newnode;
}
void preorder(node *temp)
{
    if(temp!=NULL)
    {
        printf("%d\t",temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}
void inorder(node *temp)
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        printf("%d\t",temp->data);
        inorder(temp->right);
    }
}
void postorder(node *temp)
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
    node *root=NULL,*temp;
    int c;
    do
    {
        temp=create();
        if(root==NULL)
            root=temp;
        else
            insert(root,temp);
        printf("\n1: Continue\n0: Exit\nChoice : ");
        scanf("%d",&c);
    }while(c);
    printf("\nPreorder Traversal :\t");
    preorder(root);
    printf("\nInorder Traversal :\t");
    inorder(root);
    printf("\nPostorder Traversal :\t");
    postorder(root);
    return 0;
}
