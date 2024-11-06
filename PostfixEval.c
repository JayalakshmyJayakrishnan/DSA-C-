#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 100

int stack[MAX];
int top = -1;
int a;
char c;

void push(int value) {
    top++;
    stack[top] = value;
 
}

int pop() {
    a = stack[top];
    top--;
    return a;
}

int operand(char c) { 

    if((c>='a' && c<='z') || (c>='A' && c<='Z')){
    return 1;
}
else {
    return 0;
}
}

int main() {
    char postfix[MAX];
    int i=0, o1, o2, r, a;
    
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);
    
    while(postfix[i]!='\0') {
        c = postfix[i];
        if(operand(c)) {
            printf("Enter the value of %c :", c);
            scanf("%d", &a);
            push(a);
            o2 = pop();
            o1 = pop();
        } else {
            switch(c) {
                case '+' :
                r = o1 + o2;
                break;
                
                case '-' :
                r = abs(o1 - o2);
                break;
                
                case '*' :
                r = o1 * o2;
                break;
                
                case '/' :
                r = o1 / o2;
                break;
                
                case '^' :
                r = (int)pow(o1, o2);
                break;
                
                default:
                printf("Unknown operator encountered!");
                return -1;
                
                
            }
            push(r);
        }i++; 
    }
    r = pop();
    printf("POSTFIX EVALUATION: %d ", r);
   
    return 0;
}
