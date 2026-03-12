#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,time=0,min,pos;
    int at[10],bt1[10],bt2[10],bt[10],pr[10];
    int ct[10],tat[10],wt[10],done[10]={0};
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

        printf("Priority: ");
        scanf("%d",&pr[i]);

        bt2[i] = rand()%5 + 1;          // random next CPU burst
        bt[i] = bt1[i] + 2 + bt2[i];    // total burst (BT1 + IO + BT2)
    }

    printf("\nGantt Chart:\n|");

    for(i=0;i<n;i++)
    {
        min = 999;
        pos = -1;

        for(j=0;j<n;j++)
        {
            if(at[j] <= time && done[j]==0 && pr[j] < min)
            {
                min = pr[j];
                pos = j;
            }
        }

        if(pos == -1)   // CPU idle
        {
            time++;
            i--;
            continue;
        }

        printf(" P%d |",pos+1);

        time += bt[pos];
        ct[pos] = time;
        done[pos] = 1;
    }

    printf("\n\nP\tAT\tBT1\tBT2\tPR\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avgwt += wt[i];
        avgtat += tat[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt1[i],bt2[i],pr[i],ct[i],tat[i],wt[i]);
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
// First CPU Burst: 5
// Priority: 2

// Process P2
// Arrival Time: 0
// First CPU Burst: 4
// Priority: 1

// Process P3
// Arrival Time: 0
// First CPU Burst: 3
// Priority: 3

// sample o/p
// | P2 | P1 | P3 |

// P   AT  BT1  BT2  PR  CT  TAT  WT
// P1  0   5    2    2   14  14   5
// P2  0   4    1    1   7   7    0
// P3  0   3    3    3   22  22   14

// Average Waiting Time = 6.33
// Average Turnaround Time = 14.33