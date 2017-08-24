#include <stdio.h>
int push[30];
int pop[30];
int k=0,l=0,V,E;
//int op=0;
int G[30][30];
int visited[30];
void DFS(int i)
{
    int j;
    visited[i]=1;
    push[k++]=i+1;
    for(j=0;j<V;j++)
    {
        //op++;
        if(G[i][j]==1&&visited[j]==0){
            DFS(j);
        }
    }
    pop[l++]=i+1;
 
}
int main()
{
    int i,j,v1,v2;
    printf("Enter the no of edges:");
    scanf("%d",&E);
    printf("Enter the no of vertices:");
    scanf("%d",&V);
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
            G[i][j]=0;
    }
    printf("Enter the edges:\n");
    for(i=0;i<E;i++)
    {
        scanf("%d%d",&v1,&v2);
        G[v1-1][v2-1]=1;
 
    }
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
            printf(" %d ",G[i][j]);
        printf("\n");
    }
    int source;
    printf("Enter the source: ");
    scanf("%d",&source);
    DFS(source-1);
    printf("\nPush Order\n");
    for(i=0;i<k;i++)
        printf("%d ->",push[i]);
    for(i=0;i<V;i++){
	if(visited[i]==0)
	printf("%d ->",i+1);
    }
    printf("\nPop Order\n");
    for(i=0;i<l;i++)
        printf("%d ->",pop[i]);
    for(i=0;i<V;i++){
	if(visited[i]==0)
	printf("%d ->",i+1);
    }
printf("\n");
    //printf("%d",op);
    return 0;

    }

