#include <stdio.h>

int main()
{
    int n, graph[10][10], visited[10] = {0};
    int queue[10], front = 0, rear = 0;
    int i, j, source;

    printf("Enter number of hosts: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source host: ");
    scanf("%d", &source);

    source = source - 1;

    queue[rear++] = source;
    visited[source] = 1;

    printf("\nBroadcast Tree:\n");

    while(front < rear)
    {
        source = queue[front++];

        for(i = 0; i < n; i++)
        {
            if(graph[source][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;

                printf("Host %d -> Host %d\n", source + 1, i + 1);
            }
        }
    }

    return 0;
}
