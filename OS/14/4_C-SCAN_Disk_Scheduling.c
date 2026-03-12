#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,head,size;
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

    // sort
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(request[i]>request[j])
            {
                int temp=request[i];
                request[i]=request[j];
                request[j]=temp;
            }

    int pos;
    for(i=0;i<n;i++)
        if(request[i]>=head)
        {
            pos=i;
            break;
        }

    printf("\nDisk Movement Order:\n");

    // move right
    for(i=pos;i<n;i++)
    {
        printf("%d -> ",head);
        totalSeek+=abs(request[i]-head);
        head=request[i];
    }

    // go to end
    printf("%d -> ",head);
    totalSeek+=abs((size-1)-head);
    head=size-1;

    printf("%d -> ",head);

    // jump to start
    totalSeek+=size-1;
    head=0;

    printf("%d -> ",head);

    // service remaining
    for(i=0;i<pos;i++)
    {
        totalSeek+=abs(request[i]-head);
        printf("%d -> ",head);
        head=request[i];
    }

    printf("%d\n",head);

    printf("\nTotal Head Movement = %d\n",totalSeek);

    return 0;
}