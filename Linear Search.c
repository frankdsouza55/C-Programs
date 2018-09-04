/*Programmer: Frank G. D'Souza*/
/*Title: C program to implement Linear Search*/
#include<stdio.h>
int main()
{
    int a[10],n,x,i;
    printf("\nEnter no of elements : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("\nEnter number to be searched : ");
    scanf("%d",&x);
    for(i=0;i<n;i++)
        if(a[i]==x)
        {
            printf("\n%d found at location %d",x,i);
            break;
        }
    if(i==n)
        printf("\nElement not found");
    return 0;
}
