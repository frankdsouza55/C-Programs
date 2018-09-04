/*Expt No: 9d*/
/*Programmer: Frank G. D'Souza*/
/*Title: C program to implement Bubble Sort*/
#include<stdio.h>
int main()
{
    int a[100],n,i,j,t;
    printf("\nEnter no of elements : ");
    scanf("%d",&n);
    printf("\nEnter the elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<n;i++)
        for(j=0;j<n-1;j++)
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
    printf("\nSorted array\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    return 0;
}
