#include <stdio.h>
void printTableHeader() {
    printf("+---------+--------------+-----------+---------------+-----------------+\n");
    printf("| Process | Arrival Time | Burst Time | Waiting Time | Turnaround Time |\n");
    printf("+---------+--------------+-----------+---------------+-----------------+\n");
}

void printTableRow(int id, int at, int bt, int wt, int tat) {
    printf("|   P%2d   | %12d | %9d | %13d | %15d |\n", id, at, bt, wt, tat);
    printf("+---------+--------------+-----------+---------------+-----------------+\n");
}
int main() {
    int n, i, j, time = 0, pos;
    int AT[10], BT[10], Priority[10], WT[10], TAT[10], CT[10];
    int total_wt = 0, total_tat = 0;
    float avg_wt, avg_tat;

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input arrival time, burst time, and priority for each process
    for (int i = 0; i < n; i++) {
        printf("Enter the burst time for P%d: ", i + 1);
        scanf("%d", &BT[i]);
        printf("Enter the arrival time for P%d: ", i + 1);
        scanf("%d", &AT[i]);
    }

    printf("Enter the priorities of the processes (lower value indicates higher priority):\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &Priority[i]);
        CT[i] = 0; // Mark all processes as incomplete initially
    }

    printf("\nGantt chart:\n");

    // Start scheduling based on priority
    for (i = 0; i < n; i++) {
        // Find the process with the highest priority that has arrived
        pos = -1; //no process is available at current time
        for (j = 0; j < n; j++) {
            if (AT[j] <= time && !CT[j]) {
                if (pos == -1 || Priority[j] < Priority[pos]) {
                    pos = j;
                }
            }
        }

        if (pos == -1) {
            time++;  // If no process has arrived yet, move the time forward
            i--;     // Repeat the iteration
            continue;
        }

        printf("| P%d ", pos + 1);
        time += BT[pos];  // Time when process completes

        // Calculate turnaround time and waiting time for the selected process
        TAT[pos] = time - AT[pos];  // Turnaround time = completion time - arrival time
        WT[pos] = TAT[pos] - BT[pos];  // Waiting time = turnaround time - burst time

        // Mark process as completed
        CT[pos] = 1;

        total_wt += WT[pos];
        total_tat += TAT[pos];
    }
    printf("|\n");

    // Calculate averages
    avg_wt = (float) total_wt / n;
    avg_tat = (float) total_tat / n;

    // Print the table header
    printTableHeader();

    // Print each process' details in the table
    for (int i = 0; i < n; i++) {
        printTableRow(i + 1, AT[i], BT[i], WT[i], TAT[i]);
    }
    printf("\nAverage waiting time = %.2f", avg_wt);
    printf("\nAverage turnaround time = %.2f\n", avg_tat);
    return 0;
}
