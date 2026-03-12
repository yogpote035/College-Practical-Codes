#include <stdio.h>

int main()
{
    int n,i,choice,indexBlock,len;
    int disk[100]={0};
    int index[100][10];

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
            printf("Enter index block: ");
            scanf("%d",&indexBlock);

            if(disk[indexBlock]==1)
            {
                printf("Index block already allocated\n");
                break;
            }

            printf("Enter number of blocks needed: ");
            scanf("%d",&len);

            disk[indexBlock]=1;

            printf("Enter block numbers:\n");

            for(i=0;i<len;i++)
            {
                scanf("%d",&index[indexBlock][i]);

                if(disk[index[indexBlock][i]]==1)
                {
                    printf("Block already allocated\n");
                    break;
                }

                disk[index[indexBlock][i]]=1;
            }

            printf("File allocated using indexed allocation\n");

            break;

        case 2:
            printf("Enter index block to delete file: ");
            scanf("%d",&indexBlock);

            printf("Enter number of blocks allocated: ");
            scanf("%d",&len);

            for(i=0;i<len;i++)
            {
                disk[index[indexBlock][i]]=0;
            }

            disk[indexBlock]=0;

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
// Enter index block: 4
// Enter number of blocks needed: 3
// Enter block numbers:
// 2 6 8
// File allocated using indexed allocation

// Disk status:

// 0 0 1 0 1 0 1 0 1 0

// Meaning:

// Index Block = 4
// Blocks = 2, 6, 8