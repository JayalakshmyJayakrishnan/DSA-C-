#include<stdio.h>
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;
void main(){
 int choice, value;
 while(1) {
 printf("\nQueue operations:\n");
 printf("1. Enqueue:\n");
 printf("2. Dequeue:\n");
 printf("3. Display:\n");
 printf("4. Exit:\n");
 printf("Enter your choice:\n");
 scanf("%d", &choice);
 switch(choice){
 case 1:
 if(rear==MAX-1){
 printf("Queue is full!\n");
 }
 else {
 printf("Enter the value to enqueue:\n");
 scanf("%d", &value);
 if(front==-1) {
 front = 0;
 }
 rear++;
 queue[rear] = value;
 printf("%d enqueue into the queue.\n", value);
 }
 break;
 case 2:
 if(front == -1 || front > rear){
 printf("Queue is empty!\n");
 }
 else {
 printf("%d dequeue from the queue.\n", queue[front]);
 front++;
 if(front > rear) {
 front = rear = -1;
 }
 }
 break;
 case 3:
 if(front == -1) {
 printf("Queue is empty!\n");
 }
 else {
 printf("Queue elements are: ");
 for(int i = front; i <= rear; i++){
 printf("%d ", queue[i]);
 }
 printf("\n");
 }
 break;
 case 4:
 return 0;
 default:
 printf("\nInvalid choice!\n");
 }
 }
}
