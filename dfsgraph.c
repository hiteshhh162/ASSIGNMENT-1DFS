/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
int graph [4][4]={{0,1,0,1},{1,0,1,0},{0,1,0,0},{1,0,0,0}};
int visited[4];
void dfs(int curr)
{
        int i;
        visited[curr]=1;
        printf("%d ",curr);
        for(i=0;i<4;i++)
        {
            if(graph[curr][i]==1&&visited[i]==0)
            {
                dfs(i);
            }
        }
    
}

int main()
{
    int i;
    for(i=0;i<4;i++)
    {
            visited[i]=0;
    }
    dfs(0);
    

    return 0;
}