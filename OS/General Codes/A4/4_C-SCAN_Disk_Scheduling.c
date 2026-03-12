#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,head,size,pos=0;
    int request[100];
    int totalSeek=0;

    printf("Enter number of disk requests: ");
    scanf("%d",&n);

    printf("Enter disk request sequence:\n");
    for(i=0;i<n;i++)
        scanf("%d",&request[i]);

    printf("Enter initial head position: ");
    scanf("%d",&head);

    printf("Enter disk size: ");
    scanf("%d",&size);

    // sort requests
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(request[i]>request[j])
            {
                int temp=request[i];
                request[i]=request[j];
                request[j]=temp;
            }

    for(i=0;i<n;i++)
        if(request[i]>=head)
        {
            pos=i;
            break;
        }

    printf("\nDisk Movement Order:\n");
    printf("%d -> ",head);

    // move right
    for(i=pos;i<n;i++)
    {
        totalSeek += abs(request[i]-head);
        head=request[i];
        printf("%d -> ",head);
    }

    // move to end
    totalSeek += abs((size-1)-head);
    head=size-1;
    printf("%d -> ",head);

    // jump to beginning
    totalSeek += size-1;
    head=0;
    printf("%d -> ",head);

    // service remaining
    for(i=0;i<pos;i++)
    {
        totalSeek += abs(request[i]-head);
        head=request[i];
        printf("%d -> ",head);
    }

    printf("\n\nTotal Head Movement = %d\n",totalSeek);

    return 0;
}

// Enter number of disk requests: 7
// Enter disk request sequence:
// 82 170 43 140 24 16 190
// Enter initial head position: 50
// Enter disk size: 200

// Expected Output
// Disk Movement Order:
// 50 -> 82 -> 140 -> 170 -> 190 -> 199 -> 0 -> 16 -> 24 -> 43

// Total Head Movement = 391