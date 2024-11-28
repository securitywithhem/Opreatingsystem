#include <stdio.h>

int main()
{
    int n, m, i, j, k;
    int allocation[10][10], max[10][10], need[10][10], available[10], safeSequence[10];
    int finish[10], work[10];
    int count = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of types of resource: ");
    scanf("%d", &m);

    printf("Enter the allocation matrix:\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d: ", i);
        for (j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter the need/Request matrix:\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d: ", i);
        for (j = 0; j < m; j++)
        {
            scanf("%d", &need[i][j]);
        }
    }

    printf("Enter the available resources:\n");
    for (j = 0; j < m; j++)
    {
        scanf("%d", &available[j]);
    }

    for (i = 0; i < n; i++)
    {
        finish[i] = 0;
    }

    for (i = 0; i < m; i++)
    {
        work[i] = available[i];
    }

    while (count < n)
    {
        int found = 0;
        for (i = 0; i < n; i++)
        {
            if (!finish[i])
            {
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        break;
                    }
                }
                if (j == m)
                {
                    for (k = 0; k < m; k++)
                    {
                        work[k] += allocation[i][k];
                    }
                    safeSequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (!found)
        {
            printf("The system is not in a safe state.\n");
            return 0;
        }
    }

    printf("The system is in a safe state.\nSafe sequence: ");
    for (i = 0; i < n; i++)
    {
        printf("P%d ", safeSequence[i]);
    }
    printf("\n");

    return 0;
}