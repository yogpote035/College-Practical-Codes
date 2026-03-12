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