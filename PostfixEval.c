#include <stdio.h>
#include <math.h>  
#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    top++;
    stack[top] = value;
}

int pop() {
    int a = stack[top];
    top--;
    return a;
}

int operand(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char postfix[MAX], c;
    int i = 0, o1, o2, r, a;

    printf("Enter the postfix expression: ");
    scanf("%s", postfix);  

    while (postfix[i] != '\0') {
        c = postfix[i];
        if (operand(c)) {  
            printf("Enter the value of %c: ", c);
            scanf("%d", &a);
            push(a);
        } else {  
            o2 = pop();
            o1 = pop();
            switch (c) {
                case '+':
                    r = o1 + o2;
                    break;
                case '-':
                    r = o1 - o2;
                    break;
                case '*':
                    r = o1 * o2;
                    break;
                case '/':
                    r = o1 / o2;
                    break;
                case '^':  
                    r = pow(o1, o2);
                    break;
                default:
                    printf("Unknown operator encountered.\n");
                    return -1;
            }
            push(r);  
        }
        i++;
    }

    r = pop();  
    printf("\nEvaluation = %d\n", r);

    return 0;
}

