#include <stdio.h>

#define INF 9999

int main()
{
    int n, cost[10][10], distance[10], visited[10];
    int i, j, source, min, next;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    source = source - 1;

    for(i = 0; i < n; i++)
    {
        distance[i] = cost[source][i];
        visited[i] = 0;
    }

    distance[source] = 0;
    visited[source] = 1;

    for(i = 1; i < n; i++)
    {
        min = INF;

        for(j = 0; j < n; j++)
        {
            if(visited[j] == 0 && distance[j] < min)
            {
                min = distance[j];
                next = j;
            }
        }

        visited[next] = 1;

        for(j = 0; j < n; j++)
        {
            if(visited[j] == 0 &&
               distance[next] + cost[next][j] < distance[j])
            {
                distance[j] = distance[next] + cost[next][j];
            }
        }
    }

    printf("\nShortest paths from vertex %d:\n", source + 1);

    for(i = 0; i < n; i++)
    {
        printf("Vertex %d = %d\n", i + 1, distance[i]);
    }

    return 0;
}
