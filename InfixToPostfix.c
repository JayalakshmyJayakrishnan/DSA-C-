#include <stdio.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int priority(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return 0;
}

int is_operand(char c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main() {
    char infix[MAX], postfix[MAX];
    int i = 0, j = 0;
    
    printf("Enter the infix expression: ");
    scanf("%s", infix);  
    
    while (infix[i] != '\0') {
        if (is_operand(infix[i])) {
            postfix[j++] = infix[i];  
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();  
            }
            pop();  
        } else {
            while (top != -1 && priority(stack[top]) >= priority(infix[i])) {
                postfix[j++] = pop();  
            }
            push(infix[i]);  
        }
        i++;
    }
    
    while (top != -1) {
        postfix[j++] = pop();  
    }
    
    postfix[j] = '\0'; 

    printf("Postfix expression: %s\n", postfix);
    
    return 0;
}

