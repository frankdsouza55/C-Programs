/*Expt No: 9f*/
/*Programmer: Frank G. D'Souza*/
/*Title: C program to implement Selection Sort*/
#include<stdio.h>
int main()
{
    int a[100],n,i,j,t,s,p;
    printf("\nEnter the size of the array : ");
    scanf("%d",&n);
    printf("\nEnter the elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<n;i++)
    {
        s=a[i];
        p=i;
        for(j=i+1;j<n;j++)
            if(s>a[j])
            {
                s=a[j];
                p=j;
            }
        if(a[i-1]>a[p])
        {
            t=a[i-1];
            a[i-1]=a[p];
            a[p]=t;
        }
    }
    printf("\nSorted array\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    return 0;
}
