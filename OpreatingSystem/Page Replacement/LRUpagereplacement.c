#include <stdio.h>

int main() {
    int n, frames, page_faults = 0;
    int pages[100], memory[10], recent[10];
    int i, j, k, least_recent, found;

    printf("Enter the number of page requests: ");
    scanf("%d", &n);
    printf("Enter the page requests:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }
    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    // Initialize memory slots and recent array
    for (i = 0; i < frames; i++) {
        memory[i] = -1;    // Indicating empty slots
        recent[i] = 0;     // Track how recently each frame was used
    }

    printf("\nPage request\tPage slots\tStatus\n");

    // LRU page replacement process
    for (i = 0; i < n; i++) {
        found = 0;

        // Check if page is already in memory
        for (j = 0; j < frames; j++) {
            if (memory[j] == pages[i]) {
                found = 1;
                recent[j] = i + 1;  // Update recent usage time for the found page
                break;
            }
        }

        // If page not found in memory, replace page using LRU strategy
        if (!found) {
            least_recent = 0;

            // Find the least recently used page
            for (j = 1; j < frames; j++) {
                if (recent[j] < recent[least_recent]) {
                    least_recent = j;
                }
            }

            memory[least_recent] = pages[i];    // Replace page
            recent[least_recent] = i + 1;       // Update recent usage time
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
            printf("\t\t\tPage Fault\n");
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
            printf("\t\t\tNo Page Fault\n");
        }
    }

    // Print the total number of page faults
    printf("\nTotal number of page faults: %d\n", page_faults);

    return 0;
}
