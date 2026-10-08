#include <stdio.h>

int main()
{
    int bucket, output, n;
    int packet[10];
    int i, remaining;

    printf("Enter bucket size: ");
    scanf("%d", &bucket);

    printf("Enter output rate: ");
    scanf("%d", &output);

    printf("Enter number of packets: ");
    scanf("%d", &n);

    printf("Enter packet sizes:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &packet[i]);
    }

    remaining = 0;

    printf("\nPacket\tIncoming\tSent\tRemaining\n");

    for(i = 0; i < n; i++)
    {
        if(packet[i] > bucket)
        {
            printf("%d\t%d\t\tDropped\t%d\n",
                   i + 1, packet[i], remaining);
        }
        else
        {
            remaining = remaining + packet[i];

            if(remaining > bucket)
            {
                printf("%d\t%d\t\tDropped\t%d\n",
                       i + 1, packet[i], remaining - packet[i]);
                remaining = remaining - packet[i];
            }
            else
            {
                if(remaining >= output)
                {
                    remaining = remaining - output;

                    printf("%d\t%d\t\t%d\t%d\n",
                           i + 1, packet[i], output, remaining);
                }
                else
                {
                    printf("%d\t%d\t\t%d\t%d\n",
                           i + 1, packet[i], remaining, 0);
                    remaining = 0;
                }
            }
        }
    }

    return 0;
}
