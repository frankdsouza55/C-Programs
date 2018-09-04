/*Expt No: 8*/
/*Programmer: Frank G. D'Souza*/
/*Title: C program to implement Binary Search Tree using Link lists*/
#include<stdio.h>
#include<malloc.h>
int f=1,s=0,n=0,d;
struct node
{
    int data;
    struct node *left,*right;
}*root=NULL,*t1,*t2;
void insert(struct node *root,struct node *temp)
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
struct node* create()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data : ");
    scanf("%d",& newnode->data);
    newnode->left=newnode->right=NULL;
    return newnode;
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
        else if(x>temp->data)
            search(x,temp->right);
        else
            search(x,temp->left);
    }
}
void sum(struct node *temp)
{
    if(temp!=NULL)
    {
        s+=temp->data;
        sum(temp->left);
        sum(temp->right);
    }
}
void count(struct node *temp)
{
    if(temp!=NULL)
    {
        n++;
        count(temp->left);
        count(temp->right);
    }
}
int min(struct node *temp)
{
    if(temp->left==NULL)
        return temp->data;
    else
        return min(temp->left);
}
int max(struct node *temp)
{
    if(temp->right==NULL)
        return temp->data;
    else
        return max(temp->right);
}
void delete1(struct node *t);
void search1(struct node *t,int x)
{
    if(x>t->data)
    {
        t1=t;
        search1(t->right,x);
    }
    else if(x<t->data)
    {
        t1=t;
        search1(t->left,x);
    }
    else if(x==t->data)
        delete1(t);
}
void delete1(struct node *t)
{
    if(t->left==NULL && t->right==NULL)
    {
        if(t1->left==t)
        {
            t1->left=NULL;
            free(t);
        }
        if(t1->right==t)
        {
            t1->right=NULL;
            free(t);
        }
    }
    else if(t->left==NULL)
    {
        if(t1==t)
        {
            root=t->right;
            t1=root;
        }
        else if(t1->right==t)
            t1->right=t->right;
        else
            t1->left=t->right;
        free(t);
    }
    else if(t->right==NULL)
    {
        if(t1==t)
        {
            root=t->left;
            t1=root;
        }
        else if(t1->left==t)
            t1->left=t->left;
        else
            t1->right=t->left;
        free(t);
    }
    else if(t->left!=NULL && t->right!=NULL)
    {
        t2=root;
        int k=min(t->right);
        search1(root,k);
        t->data=k;
    }
}
void delete()
{
    int x;
    if(root==NULL)
    {
        printf("\nTree is empty");
        return;
    }
    printf("\nEnter element to be deleted : ");
    scanf("%d",&x);
    t1=t2=root;
    search1(root,x);
}
int depth(struct node *temp)
{
    if(temp==NULL)
        return 0;
    int l=depth(temp->left);
    int r=depth(temp->right);
    if (l>r)
       return(l+1);
   else
        return(r+1);
}
int main()
{
    struct node *temp;
    int c,x;
    do
    {
        printf("\n1: Add node\n2: Preorder traversal\n3: Inorder traversal");
        printf("\n4: Postorder traversal\n5: Search\n6: Delete\n7: Find depth");
        printf("\n8: Count nodes\n9: Min & max element\n10: Sum of all nodes\n0: Exit\nChoice : ");
        scanf("%d",&c);
        switch(c)
        {
            case 1: temp=create();
                    if(root==NULL)
                        root=temp;
                    else
                        insert(root,temp);
                    break;
            case 2: printf("\nPreorder Traversal :\t");
                    preorder(root);
                    break;
            case 3: printf("\nInorder Traversal :\t");
                    inorder(root);
                    break;
            case 4: printf("\nPostorder Traversal :\t");
                    postorder(root);
                    break;
            case 5: printf("\nEnter element to be searched : ");
                    scanf("%d",&x);
                    f=1;
                    search(x,root);
                    if(f)
                        printf("\n%d not found\n",x);
                    break;
            case 6: delete();
                    break;
            case 7: printf("\nDepth = %d",depth(root));
                    break;
            case 8: count(root);
                    printf("\nNumber of nodes = %d\n",n);
                    n=0;
                    break;
            case 9: printf("\nThe minimum element = %d and maximum = %d\n",min(root),max(root));
                    break;
            case 10:sum(root);
                    printf("\nSum = %d\n",s);
                    s=0;
                    break;
            case 0: return 0;
            default:printf("\nInvalid input\n");
        }
    }while(c);
}
