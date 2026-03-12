#include<stdio.h>

int main()
{
    int n,i,j,start,len,choice;
    int disk[100]={0};

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

            int flag=1;

            for(i=start;i<start+len;i++)
            {
                if(disk[i]==1 || i>=n)
                {
                    flag=0;
                    break;
                }
            }

            if(flag==1)
            {
                for(i=start;i<start+len;i++)
                    disk[i]=1;

                printf("File allocated successfully\n");
            }
            else
                printf("Blocks not available\n");

            break;

        case 2:
            printf("Enter starting block: ");
            scanf("%d",&start);

            printf("Enter length of file: ");
            scanf("%d",&len);

            for(i=start;i<start+len;i++)
                disk[i]=0;

            printf("File deleted\n");
            break;

        case 3:
            printf("\nDisk Blocks Status:\n");

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


// Example Input / Output
// Enter number of disk blocks: 10

// 1.Create File
// 2.Delete File
// 3.Display Disk Status
// 4.Exit

// Enter choice: 1
// Enter starting block: 2
// Enter length of file: 3
// File allocated successfully

// Disk status:

// 0 0 1 1 1 0 0 0 0 0