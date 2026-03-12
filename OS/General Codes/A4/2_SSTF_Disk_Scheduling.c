#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,head,totalSeek=0;
    int request[100],visited[100]={0};

    printf("Enter number of disk requests: ");
    scanf("%d",&n);

    printf("Enter disk request sequence:\n");
    for(i=0;i<n;i++)
        scanf("%d",&request[i]);

    printf("Enter initial head position: ");
    scanf("%d",&head);

    printf("\nDisk Movement Order:\n");

    for(i=0;i<n;i++)
    {
        int min=9999,pos=-1;

        for(j=0;j<n;j++)
        {
            if(!visited[j])
            {
                int distance=abs(request[j]-head);

                if(distance<min)
                {
                    min=distance;
                    pos=j;
                }
            }
        }

        visited[pos]=1;

        printf("%d -> ",head);

        totalSeek += abs(request[pos]-head);

        head=request[pos];
    }

    printf("%d\n",head);

    printf("\nTotal Head Movement = %d\n",totalSeek);

    return 0;
}