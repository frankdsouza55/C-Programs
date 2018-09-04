/*Programmer: Frank G. D'Souza*/
/*Title: C program to implement Binary Search*/
#include<stdio.h>
int main()
{
    int a[10],n,x,i=0,l=0,m,h;
    printf("\nEnter no of elements : ");
    scanf("%d",&n);
    h=n-1;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("\nEnter number to be searched : ");
    scanf("%d",&x);
    i=0;
    while(l<=h)
    {
        i++;
        m=(l+h)/2;
        if(a[m]==x)
        {
            printf("\nFound at position %d",m);
            break;
        }
        else if(a[m]>x)
            h=m-1;
        else
            l=m+1;
    }
    if(l>h)
        printf("\nElement not found");
    return 0;
}
