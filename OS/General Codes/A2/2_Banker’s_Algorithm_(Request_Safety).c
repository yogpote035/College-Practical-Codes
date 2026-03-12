#include<stdio.h>

int main()
{
    int n,m,i,j,p;
    
    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter number of resource types: ");
    scanf("%d",&m);

    int alloc[n][m],max[n][m],need[n][m];
    int avail[m],request[m];

    printf("\nEnter Allocation Matrix\n");
    for(i=0;i<n;i++)
    for(j=0;j<m;j++)
    scanf("%d",&alloc[i][j]);

    printf("\nEnter Max Matrix\n");
    for(i=0;i<n;i++)
    for(j=0;j<m;j++)
    scanf("%d",&max[i][j]);

    printf("\nEnter Available Resources\n");
    for(i=0;i<m;i++)
    scanf("%d",&avail[i]);

    // Calculate Need matrix
    for(i=0;i<n;i++)
    for(j=0;j<m;j++)
        need[i][j]=max[i][j]-alloc[i][j];

    printf("\nNeed Matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            printf("%d ",need[i][j]);
        printf("\n");
    }

    // Accept request
    printf("\nEnter process number making request: ");
    scanf("%d",&p);

    printf("Enter request vector:\n");
    for(i=0;i<m;i++)
    scanf("%d",&request[i]);

    // Resource request algorithm
    for(i=0;i<m;i++)
    {
        if(request[i] > need[p][i])
        {
            printf("Error: Request exceeds need\n");
            return 0;
        }

        if(request[i] > avail[i])
        {
            printf("Resources not available. Process must wait.\n");
            return 0;
        }
    }

    // Pretend allocation
    for(i=0;i<m;i++)
    {
        avail[i] -= request[i];
        alloc[p][i] += request[i];
        need[p][i] -= request[i];
    }

    // Safety Algorithm
    int finish[n],safeSeq[n],work[m];
    
    for(i=0;i<m;i++)
        work[i]=avail[i];

    for(i=0;i<n;i++)
        finish[i]=0;

    int count=0;

    while(count<n)
    {
        int found=0;

        for(i=0;i<n;i++)
        {
            if(finish[i]==0)
            {
                int flag=1;

                for(j=0;j<m;j++)
                {
                    if(need[i][j] > work[j])
                    {
                        flag=0;
                        break;
                    }
                }

                if(flag)
                {
                    for(j=0;j<m;j++)
                        work[j]+=alloc[i][j];

                    safeSeq[count++]=i;
                    finish[i]=1;
                    found=1;
                }
            }
        }

        if(found==0)
            break;
    }

    if(count==n)
    {
        printf("\nSystem is in SAFE state\nSafe Sequence: ");
        for(i=0;i<n;i++)
            printf("P%d ",safeSeq[i]);
    }
    else
    {
        printf("\nSystem is NOT in safe state. Request cannot be granted.");
    }

    return 0;
}


// sample Input
// Processes = 5
// Resources = 3

// Allocation
// 0 1 0
// 2 0 0
// 3 0 2
// 2 1 1
// 0 0 2

// Max
// 7 5 3
// 3 2 2
// 9 0 2
// 2 2 2
// 4 3 3

// Available
// 3 3 2

// Request Process
// 1

// Request
// 1 0 2



// sample output
// Need Matrix
// 7 4 3
// 1 2 2
// 6 0 0
// 0 1 1
// 4 3 1

// System is in SAFE state
// Safe Sequence: P1 P3 P4 P0 P2