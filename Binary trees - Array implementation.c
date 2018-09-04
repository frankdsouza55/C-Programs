//Array implementation of binary trees
#include<stdio.h>
#include<math.h>
//#define depth 3
//int size;
//size=pow(2,depth+1)-1;
int arr[15],size=15,depth=3;
void create(int n)
{
    int x;
    printf("\nEnter data (-1 for no data) : ");
    scanf("%d",&x);
    if(x==-1)
        arr[n]=-1;
    else
    {
        arr[n]=x;
        printf("\nEnter left child of %d : ",x);
        create(2*n+1);
        printf("\nEnter right child of %d : ",x);
        create(2*n+2);
    }
}
int main()
{
    int i;
    create(0);
    for(i=0;i<size;i++)
        printf("%d\t",arr[i]);
    return 0;
}
