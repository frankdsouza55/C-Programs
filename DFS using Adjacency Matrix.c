#include<stdio.h>
int adj_mat[10][10],visited[10]={0},n;
void dfs(int i)
{
    int j;
    printf("%d ",i);
    visited[i]=1;
    for(j=0;j<n;j++)
        if((!visited[j]) && (adj_mat[i][j]==1))
            dfs(j);
}
int main()
{
    int i,j;
    printf("\nEnter no of vertices : ");
    scanf("%d",&n);
    printf("\nEnter Adjacency matrix of graph \n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&adj_mat[i][j]);
    printf("\nDFS traversal is : ");
    dfs(0);
    return 0;
}
/*Inputs
    5
    0 1 0 0 1
    1 0 1 1 0
    0 1 0 0 0
    0 1 0 0 0
    1 0 0 0 0
*/
