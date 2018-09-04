/*Expt No: 9e*/
/*Programmer: Frank G. D'Souza*/
/*Title: C program to implement Insertion Sort*/
#include<stdio.h>
int main()
{
    int a[100],n,i,j,t;
    printf("\nEnter the size of the array : ");
    scanf("%d",&n);
    printf("\nEnter the elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<n;i++)
    {
        t=a[i];
        j=i-1;
        while(t<a[j] && j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=t;
    }
    printf("\nSorted array\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    return 0;
}
