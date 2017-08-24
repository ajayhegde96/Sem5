#include <stdio.h>
#include <stdlib.h>
int main()
{
	int v;
	printf("\n No of vertices ");
	scanf("%d",&v);
	int graph[v][v];
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
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
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			printf("%d ",graph[i][j]);
		}
		printf("\n");
	}
}
