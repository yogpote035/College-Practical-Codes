#include <stdio.h>

int main()
{
    int n,i;
    int request[100];
    int head;
    int totalSeek = 0;

    printf("Enter number of disk requests: ");
    scanf("%d",&n);

    printf("Enter disk request sequence:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&request[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d",&head);

    printf("\nDisk Movement Order:\n");

    for(i=0;i<n;i++)
    {
        printf("%d -> ",head);

        totalSeek += abs(request[i] - head);

        head = request[i];
    }

    printf("%d\n",head);

    printf("\nTotal Head Movement = %d",totalSeek);

    return 0;
}