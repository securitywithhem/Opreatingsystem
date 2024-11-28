#include <stdio.h>

// Structure to represent a process
typedef struct {
    int pid; // Process ID
    int priority; // Priority of the process
    int burst_time; // Burst time of the process
} Process;

// Function to implement priority scheduling preemptive algorithm
void priority_scheduling_preemptive(Process processes[], int n) {
    int i, j;
    int time = 0; // Current time
    int completed = 0; // Number of completed processes

    // Sort the processes based on their priority
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (processes[i].priority < processes[j].priority) {
                // Swap the processes
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Execute the processes based on their priority
    while (completed < n) {
        for (i = 0; i < n; i++) {
            if (processes[i].burst_time > 0) {
                printf("Process %d is executing at time %d\n", processes[i].pid, time);
                processes[i].burst_time--;
                time++;
            }
            if (processes[i].burst_time == 0) {
                completed++;
            }
        }
    }
}

int main() {
    Process processes[] = {
        {1, 3, 5},
        {2, 2, 3},
        {3, 1, 2},
        {4, 4, 4}
    };
    int n = sizeof(processes) / sizeof(processes[0]);

    priority_scheduling_preemptive(processes, n);

    return 0;
}

