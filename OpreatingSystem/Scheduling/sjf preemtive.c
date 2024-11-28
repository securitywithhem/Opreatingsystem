#include <stdio.h>
int main() {
    int n, i, j, time = 0, smallest, endTime;
    int total_wt = 0, total_tat = 0;
    int remaining[10], at[10], bt[10], wt[10], tat[10];
    int completed = 0;
    float avg_wt, avg_tat;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input arrival time and burst time for each process
    printf("Enter the arrival times of the processes:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &at[i]);
    }

    printf("Enter the burst times of the processes:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        remaining[i] = bt[i];  // Initialize remaining times as burst times
    }

    // Initialize variables for scheduling
    remaining[9] = 9999;  // Large number to simulate infinite burst time

    printf("\nGantt chart:\n");
    while (completed != n) {
        smallest = 9;
        
        for (i = 0; i < n; i++) {
            if (at[i] <= time && remaining[i] < remaining[smallest] && remaining[i] > 0) {
                smallest = i;
            }
        }

        // Execute the smallest process (preemptive)
        remaining[smallest]--;
        printf("| P%d ", smallest + 1);
        time++;

        if (remaining[smallest] == 0) {  // Process completed
            completed++;
            endTime = time;
            tat[smallest] = endTime - at[smallest];  // Turnaround time = completion time - arrival time
            wt[smallest] = tat[smallest] - bt[smallest];  // Waiting time = turnaround time - burst time

            total_wt += wt[smallest];
            total_tat += tat[smallest];
        }
    }
    printf("|\n");

    // Calculate averages
    avg_wt = (float) total_wt / n;
    avg_tat = (float) total_tat / n;

    // Display results
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage waiting time = %.2f", avg_wt);
    printf("\nAverage turnaround time = %.2f\n", avg_tat);

    return 0;
}