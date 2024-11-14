#include <stdio.h>
#include <stdlib.h>

// Define the structure for a circular queue node
struct Node {
    int data;
    struct Node* next;
};

// Define the front and rear of the circular queue
struct Node* front = NULL;
struct Node* rear = NULL;

// Function to enqueue an element to the circular queue
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL) {
        // If queue is empty, both front and rear are the new node
        front = rear = newNode;
        rear->next = front;  // Make it circular by linking to front
    } else {
        // Add new node at the end of the queue and make it circular
        rear->next = newNode;
        rear = newNode;
        rear->next = front;  // Link back to the front
    }
    printf("%d enqueued to the circular queue.\n", value);
}

// Function to dequeue an element from the circular queue
void dequeue() {
    if (front == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    // If only one node is present
    if (front == rear) {
        printf("%d dequeued from the circular queue.\n", front->data);
        free(front);
        front = rear = NULL;  // Reset the queue to empty
    } else {
        struct Node* temp = front;
        printf("%d dequeued from the circular queue.\n", front->data);
        front = front->next;  // Move front to the next node
        rear->next = front;   // Maintain circular link
        free(temp);
    }
}

// Function to display the elements in the circular queue
void displayQueue() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp = front;
    printf("Circular Queue: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);  // Stop when we come back to the front
    printf("\n");
}

int main() {
    int choice, value;

    do {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}
