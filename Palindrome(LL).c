#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to insert at the beginning
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Function to reverse the linked list
struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Function to check if the list is a palindrome
int isPalindrome(struct Node* head) {
    struct Node* reversedHead = reverseList(head);
    struct Node* original = head;
    struct Node* reversed = reversedHead;

    while (original != NULL && reversed != NULL) {
        if (original->data != reversed->data) {
            return 0; // Not a palindrome
        }
        original = original->next;
        reversed = reversed->next;
    }
    return 1; // Is a palindrome
}

// Function to display the linked list
void displayList(struct Node* node) {
    if (node == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to free the linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int number, temp;

    printf("Enter a number: ");
    scanf("%d", &number);

    // Split digits of the number into the linked list
    temp = number;
    while (temp > 0) {
        insertAtBeginning(&head, temp % 10);
        temp /= 10;
    }

    // Display the linked list
    displayList(head);

    // Check if the linked list is a palindrome
    if (isPalindrome(head)) {
        printf("The number %d is a palindrome.\n", number);
    } else {
        printf("The number %d is not a palindrome.\n", number);
    }

    // Free the linked list
    freeList(head);

    return 0;
}
