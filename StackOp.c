#include<stdio.h>
#include<stdlib.h>

#define MAX 3

int i, top = -1;
int stack[MAX];
int value;


void push(int value) {
if(top == MAX - 1){
printf("Overflow condition! %d cannot be pushed!\n", value);
}
else{
top ++;
stack[top] = value;
printf("%d is pushed!\n", value);
}

}
void pop(){
if(top == -1){
printf("Underflow condition! No elements left in the stack to be popped.\n");
}
else{
value = stack[top];
top--;

printf("%d is popped from the stack.\n", value);
   }
   
   }
   
void display(){
if(top == -1){
printf("Underflow condition! The stack is empty.\n");
}
else{    
      printf("The elements in the stack are: \n");
for(int i=top; i>=0; i--){

printf("%d", stack[i]);
printf("\n");
}
}
}    
   
   
   
int main(){
int choice, value;

while(1){
printf("Choose the operation.\n");
printf("1. Push element to stack.\n");
printf("2. Pop element to stack.\n");
printf("3. Display elements.\n");
printf("4. Exit!\n");
printf("Enter your choice:\n");
scanf("%d", &choice);


switch(choice){
case 1:
printf("You've selected push operation.\n");
printf("Enter the element to be pushed: \n");
scanf("%d", &value);

push(value);
break;

case 2:
printf("You've selected pop operation.\n");
printf("Enter the element to be popped \n");
pop();
break;

case 3:
printf("You've selected the display operation.\n");
printf("The elements in the stack are: \n");
display();
break;

case 4:

exit(0);

default:
printf("Invalid request!");
break;     
}    
}
}
