#include <stdio.h>

int main()
{
    int a[10][10], v[10] = {0}, q[10];
    int n, s, i, f = 0, r = 0, x;

    printf("Enter number of hosts: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter source host: ");
    scanf("%d", &s);
    s--;

    q[r++] = s;
    v[s] = 1;

    printf("Broadcast Tree:\n");

    while(f < r)
    {
        x = q[f++];

        for(i = 0; i < n; i++)
        {
            if(a[x][i] == 1 && v[i] == 0)
            {
                printf("%d -> %d\n", x + 1, i + 1);
                q[r++] = i;
                v[i] = 1;
            }
        }
    }

    return 0;
}
