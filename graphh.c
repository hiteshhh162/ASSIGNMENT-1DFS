#include<stdio.h>
#include<stdlib.h>
#define max 10
int graph [max][max];
int vertices=0;
void display ()
{
    int i,j;
    printf("\nAdjacency matrix ...\n");

    for(i=0;i<vertices;i++)
    {
        for (j= 0; j < vertices;j++)
        {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
        
    }
}
void addvertex()
{
    int i;

    if(vertices>=max)
    {
        printf("\nMaximum vertices reached..");
    }
    for(i=0;i<vertices;i++)
    {
        graph[vertices][i]=0;
        graph[i][vertices]=0;
    }
    vertices++;
    printf("\nAdd vertex successfully");

}
void addedges()
{
    int u,v;
    printf("\nEnter source :");
    scanf("%d",&u);

    printf("Enter destination :");
    scanf("%d",&v);

    if(u>=vertices || v>=vertices)
    {
        printf("\nnvalid edges");
        return ;
    }

    graph[u][v]=1;
    graph[v][u]=1;
    printf("\nAdd edges successfully ..");
}
void removeedges()
{
    int u,v;
    printf("\nEnter source :");
    scanf("%d",&u);

    printf("Enter destination :");
    scanf("%d",&v);

    if(u>=vertices || v>=vertices)
    {
        printf("\ninvalid edges");
        return ;
    }

    graph[u][v]=0;
    graph[v][u]=0;
    printf("\nRemove edges successfully ..");
}
void removevertex()
{
    int v,i,j;
    printf("\nEnter vertex :");
    scanf("%d",&v);

    if(v>vertices)
    {
        printf("\nInvalid vertex ...");
        return ;
    }
    for(i=v;i<vertices-1;i++)
    {
        for( j = 0; j < vertices; j++)
        {
            graph[i][j]=graph[i+1][j];
        }
        
    }
    for(i=0;i<vertices-1;i++)
    {
        for(j=v;j<vertices-1;j++)
        {
            graph[i][j]=graph[i][j+1];
        }
    }
    printf("\nRemove vertex successfully");
}
int main ()
{
    int ch;
    while (1)
    {
        printf("\nEnter your choice :\n1-->add vertex\n2-->add edges\n3-->remove vertex \n4-->remove edges \n5-->display\n6-->exit");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            addvertex();
            break;
        case 2:
            addedges();
            break;
        case 3:
            removevertex();
            break;
        case 4:
            removeedges();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
            break;        
        default:
            printf("\nEnter a valid choice ...");
            break;
        }
    }
    return 0;
    
}