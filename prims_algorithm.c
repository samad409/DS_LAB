#include <stdio.h>

int a,b,u,v,n,i,j,ne=1;

int visited[10]={0},min,mincost=0,cost[10][10];

int main()

{

        printf("\nEnter the number of nodes:");

        scanf("%d",&n);

        printf("\nEnter the adjacency matrix:\n");

        for(i=0;i<=n-1;i++)

                for(j=0;j<=n-1;j++)

                {

                        scanf("%d",&cost[i][j]);

                        if(cost[i][j]==0)

                                cost[i][j]=999;

                }

                visited[1]=1;

                printf("\n");

                while(ne<n)

                {

                for(i=0,min=999;i<=n-1;i++)

                        for(j=0;j<=n-1;j++)

                                if(cost[i][j]<min)

                                        if(visited[i]!=0)

                                        {

                                                min=cost[i][j];

                                                a=u=i;

                                                b=v=j;

                                        }

                                if(visited[u]==0||visited[v]==0)

                                {

                                        printf("\nEdge %d:(%d,%d) cost:%d",ne++,a,b,min);

                                        mincost+=min;

                                        visited[b]=1;

                                }

                                cost[a][b]=cost[b][a]=999;

                }

                printf("\nMinimum cost:%d\n",mincost);

                return 0;

}
