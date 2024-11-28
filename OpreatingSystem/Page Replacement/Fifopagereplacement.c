#include <stdio.h>

int main() {
    int n, frames, page_faults = 0;
    int pages[100], memory[10];
    int i, j, k, pos = 0, found;

    printf("Enter the number of page requests: ");
    scanf("%d", &n);
    printf("Enter the page requests:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }
    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    // Initialize memory slots with -1 (indicating empty slots)
    for (i = 0; i < frames; i++) {
        memory[i] = -1;
    }
    printf("\nPage request\tPage slots\tStatus\n");

    // FIFO page replacement process
    for (i = 0; i < n; i++) {
        found = 0;
        // Check if page is already in memory
        for (j = 0; j < frames; j++) {
            if (memory[j] == pages[i]) {
                found = 1;
                break;
            }
        }
        // If page not found in memory, replace page
        if (!found) {
            memory[pos] = pages[i];
            pos = (pos + 1) % frames;  // Move to the next frame position
            page_faults++;
            // Print page slots and status
            printf("%d\t\t", pages[i]);
            for (k = 0; k < frames; k++) {
                if (memory[k] != -1) {
                    printf("%d ", memory[k]);
                } else {
                    printf("- ");
                }
            }
            printf("\t\tPage Fault\n");
        } else {
            // Page found, no page fault
            printf("%d\t\t", pages[i]);
            for (k = 0; k < frames; k++) {
                if (memory[k] != -1) {
                    printf("%d ", memory[k]);
                } else {
                    printf("- ");
                }
            }
            printf("\t\tNo Page Fault\n");
        }
    }
    // Print the total number of page faults
    printf("\nTotal number of page faults: %d\n", page_faults);
    return 0;
}
