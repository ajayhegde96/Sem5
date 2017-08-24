#include <stdio.h>
#include <stdlib.h>
int queue[50];
int front=0;
int rear=0;
void push(int v)
{
	if(front>rear){
		printf("Queue FULL\n");
		return;
	}
	else
	{
		queue[rear]=v;
		rear+=1;
	}

}
int main()
{
	int v;
	printf("\n No of vertices ");
	scanf("%d",&v);
	int graph[v+1][v+1];
	for(int i=1;i<=v;i++){
		for(int j=1;j<=v;j++){
			graph[i][j]=0;
		}
	}
	int x,y;
	printf("Enter pair having edge ");
	scanf("%d %d",&x,&y);
	graph[x][y]=1;
	graph[y][x]=1;
	int n;
	while(1){
		printf("\nContinue? ");
		scanf("%d",&n);
		if(n!=1)
		break;
		printf("Enter pair having edge ");
	scanf("%d %d",&x,&y);
	graph[x][y]=1;
	graph[y][x]=1;
	}
	for(int i=1;i<=v;i++){
		for(int j=1;j<=v;j++){
			printf("%d ",graph[i][j]);
		}
		printf("\n");
	}
	int visited[v+1];
	for(int i=0;i<50;i++){
	queue[i]=-1;
	}
	for(int i=1;i<=v;i++){
		visited[i]=0;
	}
	queue[front]=1;
	rear++;
	visited[1]=1;
	while(front<=rear){
		int a=queue[front];
		for(int j=1;j<=v;j++){
			if(graph[a][j]==1&&visited[j]!=1){
				push(j);
				visited[j]=1;
			}
		}
		front++;
	}
printf("BFS ORDER\n");
for(int i=0;queue[i]!=-1;i++)
	printf("%d ",queue[i]);
printf("\n");
}