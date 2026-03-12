#include <stdio.h>

int main()
{
    int i,j;

    int allocation[5][3] = {
        {0,1,0},
        {2,0,0},
        {3,0,2},
        {2,1,1},
        {0,0,2}
    };

    int max[5][3] = {
        {7,5,3},
        {3,2,2},
        {9,0,2},
        {2,2,2},
        {4,3,3}
    };

    int need[5][3];
    int available[3];

    printf("Enter Available Resources (A B C): ");
    scanf("%d %d %d",&available[0],&available[1],&available[2]);

    printf("\nAllocation Matrix\n");
    for(i=0;i<5;i++)
    {
        for(j=0;j<3;j++)
            printf("%d ",allocation[i][j]);
        printf("\n");
    }

    printf("\nMax Matrix\n");
    for(i=0;i<5;i++)
    {
        for(j=0;j<3;j++)
            printf("%d ",max[i][j]);
        printf("\n");
    }

    for(i=0;i<5;i++)
    {
        for(j=0;j<3;j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    printf("\nNeed Matrix\n");
    for(i=0;i<5;i++)
    {
        for(j=0;j<3;j++)
            printf("%d ",need[i][j]);
        printf("\n");
    }

    printf("\nAvailable Resources\n");
    for(i=0;i<3;i++)
        printf("%d ",available[i]);

    return 0;
}

// sample input
// 3 3 2

// Sample output
// Allocation Matrix
// 0 1 0
// 2 0 0
// 3 0 2
// 2 1 1
// 0 0 2

// Max Matrix
// 7 5 3
// 3 2 2
// 9 0 2
// 2 2 2
// 4 3 3

// Need Matrix
// 7 4 3
// 1 2 2
// 6 0 0
// 0 1 1
// 4 3 1

// Available Resources
// 3 3 2