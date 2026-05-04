#include<stdio.h>
#include<stdlib.h>
#define max 10
int graph[max][max];
int vertices=0;

void display ()
{
    int i,j;
    printf("\nAdjacency matrix :\n");
    for(i=0;i<vertices;i++)
    {
        for(j=0;j<vertices;j++)
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
        printf("\nvertices maximum reached ..");

    }
    for(i=0;i<vertices;i++)
    {
        graph[vertices][i]=0;
        graph[i][vertices]=0;
    }
    vertices ++;
    printf("\nVertex add successfully .");

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
        printf("\nInvalid edges ...");
        return ;
    }
    graph[v][u]=1;
    graph[u][v]=1;

    printf("\nEdges add successfully ..");
}
void removeedges()
{
    int u,v;
    printf("\nEnter source :");
    scanf("%d",&u);
    printf("Enter destination :");
    scanf("%d",&v);

    if(v>=vertices || u>=vertices)
    {
        printf("\nInvalid edges ...");
        return ;
    }

    graph[v][u]=0;
    graph[u][v]=0;

    printf("\nRemove edges successfully ..");
}
void removevertex()
{
    int v,i,j;
    printf("\nEnter vertex :");
    scanf("%d",&v);

    if(v>=vertices)
    {
        printf("\nInvalid vertex ...");
        return ;

    }
    for(i=v;i<vertices-1;i++)
    {
        for(j=0;j<vertices;j++)
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
    vertices--;
    printf("\nDelete vertex successfully ...");
}
int main ()
{
    int ch;
    while (1)
    {
        printf("\n1-->Add vertex \n2-->add edges\n3-->remove vertex\n4-->remove edges \n5-->display \n6-->exit");
        scanf("%d",&ch);

            switch ((ch))
            {
            case 1:
                /* code */
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

                printf("\nEnter A valid choice ....");
                break;
            }
    }
    
}