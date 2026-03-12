#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    int AT[10], BT1[10], BT2[10];
    int CT[10], TAT[10], WT[10];
    int time = 0;
    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter Arrival Time:\n");
    for(i=0;i<n;i++)
        scanf("%d",&AT[i]);

    printf("Enter First CPU Burst Time:\n");
    for(i=0;i<n;i++)
        scanf("%d",&BT1[i]);

    /* Generate second CPU burst randomly */
    for(i=0;i<n;i++)
        BT2[i] = rand()%5 + 1;

    printf("\nSecond CPU Burst (Random):\n");
    for(i=0;i<n;i++)
        printf("P%d = %d\n",i+1,BT2[i]);

    printf("\nGantt Chart:\n|");
 
    for(i=0;i<n;i++)
    {
        if(time < AT[i])
            time = AT[i];

        time = time + BT1[i];  // First CPU burst
        time = time + 2;       // IO waiting
        time = time + BT2[i];  // Second CPU burst

        CT[i] = time;

        printf(" P%d |",i+1);
    }

    printf("\n");

    for(i=0;i<n;i++)
    {
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - (BT1[i] + BT2[i]);

        avgWT += WT[i];
        avgTAT += TAT[i];
    }

    printf("\nProcess\tAT\tBT1\tBT2\tWT\tTAT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,AT[i],BT1[i],BT2[i],WT[i],TAT[i]);
    }

    printf("\nAverage Waiting Time = %.2f",avgWT/n);
    printf("\nAverage Turnaround Time = %.2f\n",avgTAT/n);

    return 0;
}


// sample input
// Enter number of processes: 3

// Process P1
// Arrival Time: 0
// First CPU Burst: 4

// Process P2
// Arrival Time: 1
// First CPU Burst: 3

// Process P3
// Arrival Time: 2
// First CPU Burst: 2


// sample o/p
// Gantt Chart:
// | P1 | P2 | P3 |

// Process AT BT1 BT2 CT TAT WT
// P1      0  4   3   9   9   0
// P2      1  3   2   16  15  8
// P3      2  2   4   24  22  14

// Average Waiting Time = 7.33
// Average Turnaround Time = 15.33