#include <stdio.h>

int main()
{
    int bucket, rate, n, packet, water = 0, i;

    printf("Enter bucket size: ");
    scanf("%d", &bucket);

    printf("Enter output rate: ");
    scanf("%d", &rate);

    printf("Enter number of packets: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        printf("Enter packet size: ");
        scanf("%d", &packet);

        if(water + packet > bucket)
            printf("Packet dropped\n");
        else
        {
            water = water + packet;
            printf("Packet accepted\n");
        }

        if(water >= rate)
            water = water - rate;
        else
            water = 0;

        printf("Remaining packets: %d\n", water);
    }

    return 0;
}
