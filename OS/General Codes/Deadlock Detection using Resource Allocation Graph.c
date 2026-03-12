#include <stdio.h>

int n;
int graph[10][10];
int visited[10], stack[10];

int dfs(int v)
{
    visited[v] = 1;
    stack[v] = 1;

    for(int i=0;i<n;i++)
    {
        if(graph[v][i])
        {
            if(!visited[i] && dfs(i))
                return 1;

            else if(stack[i])
                return 1;
        }
    }

    stack[v] = 0;
    return 0;
}

int main()
{
    int i,j;

    printf("Enter number of nodes (process + resource): ");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&graph[i][j]);

    for(i=0;i<n;i++)
    {
        if(!visited[i])
        {
            if(dfs(i))
            {
                printf("Deadlock detected\n");
                return 0;
            }
        }
    }

    printf("No Deadlock\n");

    return 0;
}
//  deal lock input
// adjency: 4
// 0 0 1 0
// 0 0 0 1
// 0 1 0 0
// 1 0 0 0

// P1 → R1 → P2 → R2 → P1

// no deadlock 
// adjency: 4
// 0 0 1 0
// 0 0 0 1
// 0 0 0 0
// 0 0 0 0

// P1 → R1
// P2 → R2