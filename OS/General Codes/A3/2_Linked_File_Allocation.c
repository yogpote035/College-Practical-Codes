#include <stdio.h>

int main()
{
    int n,i,choice,start,len;
    int disk[100]={0};
    int next[100];

    printf("Enter number of disk blocks: ");
    scanf("%d",&n);

    while(1)
    {
        printf("\n1.Create File");
        printf("\n2.Delete File");
        printf("\n3.Display Disk Status");
        printf("\n4.Exit");

        printf("\nEnter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {

        case 1:
            printf("Enter starting block: ");
            scanf("%d",&start);

            printf("Enter length of file: ");
            scanf("%d",&len);

            int prev=start;

            if(disk[start]==1)
            {
                printf("Block already allocated\n");
                break;
            }

            disk[start]=1;

            for(i=1;i<len;i++)
            {
                int block;

                printf("Enter next block: ");
                scanf("%d",&block);

                if(disk[block]==1)
                {
                    printf("Block already allocated\n");
                    break;
                }

                disk[block]=1;
                next[prev]=block;
                prev=block;
            }

            next[prev]=-1;

            printf("File allocated using linked allocation\n");

            break;

        case 2:
            printf("Enter starting block of file: ");
            scanf("%d",&start);

            int temp=start;

            while(temp!=-1)
            {
                disk[temp]=0;
                temp=next[temp];
            }

            printf("File deleted\n");

            break;

        case 3:
            printf("\nDisk Status\n");

            for(i=0;i<n;i++)
            {
                printf("%d ",disk[i]);
            }

            printf("\n");

            break;

        case 4:
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}



// Example Run
// Enter number of disk blocks: 10

// 1.Create File
// 2.Delete File
// 3.Display Disk Status
// 4.Exit

// Enter choice: 1
// Enter starting block: 2
// Enter length of file: 3
// Enter next block: 5
// Enter next block: 8
// File allocated using linked allocation

// Disk status:

// 0 0 1 0 0 1 0 0 1 0

// Meaning:

// 2 → 5 → 8 → NULL
// Key Idea

// Example linked structure:

// Block 2 → Block 5 → Block 8 → NULL