#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(!newNode) {
        printf("Memeory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
    printf("%d is pushed onto the stack.\n", value);
}

void pop(struct Node** top) {
    if(*top == NULL) {
        printf("Stack Underflow condition!\n");
        return;
    }
    struct Node* temp = *top;
    printf("%d is popped from the stack.", temp->data);
    *top=(*top)->next;
    free(temp);
}

void display(struct Node* top) {
    if (top == NULL) {
        printf("The stack is empty.\n");
        return;
    }

    printf("Stack elements are: \n");
    struct Node* current = top;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}
    
int main() {
    struct Node* top = NULL;
    int choice, value;
    
    while(1){
        printf("STACK MENU\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
            printf("Enter the element to be pushed: \n");
            scanf("%d", &value);
            push(&top, value);
            break;
            
            case 2:
            pop(&top);
            break;
            
            case 3:
            display(top);
            break;
            
            case 4:
            printf("Exiting the program.....");
            return 0;
            
            default:
            printf("INVALID REQUEST!\n");
            return -1;
            
            
        }
    }
}   
