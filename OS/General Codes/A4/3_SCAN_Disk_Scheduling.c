#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,head,size,direction;
    int request[100];
    int totalSeek = 0;

    printf("Enter number of disk requests: ");
    scanf("%d",&n);

    printf("Enter disk request sequence:\n");
    for(i=0;i<n;i++)
        scanf("%d",&request[i]);

    printf("Enter initial head position: ");
    scanf("%d",&head);

    printf("Enter disk size: ");
    scanf("%d",&size);

    printf("Enter direction (1 = right, 0 = left): ");
    scanf("%d",&direction);

    // Sort requests
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(request[i] > request[j])
            {
                int temp=request[i];
                request[i]=request[j];
                request[j]=temp;
            }
        }
    }

    int pos;

    for(i=0;i<n;i++)
    {
        if(head < request[i])
        {
            pos=i;
            break;
        }
    }

    printf("\nDisk Movement Order:\n");

    if(direction==1) // Right
    {
        for(i=pos;i<n;i++)
        {
            printf("%d -> ",head);
            totalSeek += abs(request[i]-head);
            head=request[i];
        }

        totalSeek += abs((size-1)-head);
        head=size-1;

        for(i=pos-1;i>=0;i--)
        {
            printf("%d -> ",head);
            totalSeek += abs(request[i]-head);
            head=request[i];
        }
    }
    else // Left
    {
        for(i=pos-1;i>=0;i--)
        {
            printf("%d -> ",head);
            totalSeek += abs(request[i]-head);
            head=request[i];
        }

        totalSeek += abs(head-0);
        head=0;

        for(i=pos;i<n;i++)
        {
            printf("%d -> ",head);
            totalSeek += abs(request[i]-head);
            head=request[i];
        }
    }

    printf("%d\n",head);

    printf("\nTotal Head Movement = %d\n",totalSeek);

    return 0;
}

// Example Input
// Enter number of disk requests: 5
// Enter disk request sequence:
// 98 183 37 122 14
// Enter initial head position: 53
// Enter disk size: 200
// Enter direction (1=right): 1

// Example Output
// Disk Movement Order:
// 53 -> 98 -> 122 -> 183 -> 199 -> 37 -> 14

// Total Head Movement = 331