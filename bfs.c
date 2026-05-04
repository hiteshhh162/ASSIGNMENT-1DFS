#include<stdio.h>
int graph[4][4]={{0,1,0,1},{1,0,1,0},{0,1,0,0},{1,0,0,0}};
int front=0,rear=0,queue[4],visited[4];
void bfs(int start ,int size)
{
    int node,i;
    queue[rear]=start;
    rear++;
    visited[start]=1;
    
    while(front<rear)
    {
        node=queue[front];
        front++;
        printf("%d ",node);
        for(i=0;i<size;i++)
        {
            if(graph[node][i]==1&&visited[i]==0)
            {
                queue[rear]=i;
                rear++;
                visited[i]=1;
            }
        }
    }
}
int main ()
{
    
    int i;
    for(i=0;i<4;i++)
    {
        visited[i]=0;
        
    }
    bfs(0,4);
    return 0;
    
}
