#include <stdio.h>

#define INF 999

int main()
{
    int n, cost[10][10], dist[10][10], i, j, k;
    int updated;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0 && i != j)
                cost[i][j] = INF;

            dist[i][j] = cost[i][j];
        }
    }

    do
    {
        updated = 0;

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                for(k = 0; k < n; k++)
                {
                    if(dist[i][j] > dist[i][k] + dist[k][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        updated = 1;
                    }
                }
            }
        }

    } while(updated);

    printf("\nRouting Tables:\n");

    for(i = 0; i < n; i++)
    {
        printf("\nNode %d:\n", i + 1);

        printf("Destination\tDistance\n");

        for(j = 0; j < n; j++)
        {
            printf("%d\t\t%d\n", j + 1, dist[i][j]);
        }
    }

    return 0;
}
