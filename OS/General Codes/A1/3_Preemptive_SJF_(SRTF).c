#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,time=0,completed=0,smallest;
    int at[10],bt1[10],bt2[10],bt[10],rt[10];
    int ct[10],tat[10],wt[10];
    float avgwt=0,avgtat=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\nProcess P%d\n",i+1);

        printf("Arrival Time: ");
        scanf("%d",&at[i]);

        printf("First CPU Burst: ");
        scanf("%d",&bt1[i]);

        bt2[i] = rand()%5 + 1;           // random next CPU burst
        bt[i] = bt1[i] + 2 + bt2[i];     // total burst (BT1 + IO + BT2)

        rt[i] = bt[i];                   // remaining time
    }

    printf("\nGantt Chart:\n|");

    while(completed < n)
    {
        smallest = -1;

        for(i=0;i<n;i++)
        {
            if(at[i] <= time && rt[i] > 0)
            {
                if(smallest == -1 || rt[i] < rt[smallest])
                {
                    smallest = i;
                }
            }
        }

        if(smallest == -1)
        {
            time++;
            continue;
        }

        printf(" P%d |",smallest+1);

        rt[smallest]--;
        time++;

        if(rt[smallest] == 0)
        {
            ct[smallest] = time;
            completed++;
        }
    }

    printf("\n\nP\tAT\tBT1\tBT2\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avgwt += wt[i];
        avgtat += tat[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt1[i],bt2[i],ct[i],tat[i],wt[i]);
    }

    avgwt /= n;
    avgtat /= n;

    printf("\nAverage Waiting Time = %.2f",avgwt);
    printf("\nAverage Turnaround Time = %.2f",avgtat);

    return 0;
}


// Enter number of processes: 3

// Process P1
// Arrival Time: 0
// First CPU Burst: 6

// Process P2
// Arrival Time: 1
// First CPU Burst: 3

// Process P3
// Arrival Time: 2
// First CPU Burst: 2

// sample o/p

// P   AT  BT1  BT2  CT  TAT  WT
// P1  0   6    3    21  21   10
// P2  1   3    2    12  11   4
// P3  2   2    4    16  14   6