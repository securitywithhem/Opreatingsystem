#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, total_head_movement = 0;
    int head, current_position;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    int requests[n];
    printf("Enter the disk requests:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }
    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);

    current_position = head;
    printf("\nRequest order and head movements:\n");

    // Process each request in the order they appear
    for (i = 0; i < n; i++) {
        // Calculate movement for the current request
        int movement = abs(requests[i] - current_position);
        total_head_movement += movement;

        // Display the movement for this step
        printf("Move from %d to %d with head movement = %d\n", current_position, requests[i], movement);

        // Update the current position to the request's position
        current_position = requests[i];
    }
    // Print the total head movement
    printf("\nTotal head movement: %d\n", total_head_movement);
    return 0;
}
