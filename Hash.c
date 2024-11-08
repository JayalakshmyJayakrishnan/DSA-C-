#include <stdio.h>
#include <stdlib.h> 
#define SIZE 10 
int hashTable[SIZE];
int EMPTY = -1;  	
void initHashTable() {
	for (int i = 0; i < SIZE; i++) {
    	hashTable[i] = EMPTY;
	}
}
int hashFunction(int key) {
	return key % SIZE;
}
 
void insertKey(int key) {
	int index = hashFunction(key);
	int originalIndex = index;
	while (hashTable[index] != EMPTY) {
    	index = (index + 1) % SIZE;
    	if (index == originalIndex) {
        	printf("Hash table is full. Cannot insert key %d\n", key);
        	return;
 	}
	}
 
	hashTable[index] = key;
	printf("Key %d inserted at index %d\n", key, index);
}
void deleteKey(int key) {
	int index = hashFunction(key);
	int originalIndex = index;
	while (hashTable[index] != key) {
    	index = (index + 1) % SIZE;
    	if (hashTable[index] == EMPTY || index == originalIndex) {
        	printf("Key %d not found\n", key);
        	return;
    	}
	}
 
	hashTable[index] = EMPTY;
	printf("Key %d deleted from index %d\n", key, index);
}
void displayHashTable() {
	printf("\n**HASH TABLE**\n");
	for (int i = 0; i < SIZE; i++) {
    	if (hashTable[i] != EMPTY) {
        	printf("%d:%d\n", i, hashTable[i]);
    	} else {
     	   printf("%d:\n", i);
    	}
	}
}
 
int main() {
	int choice, key;
	initHashTable();
 
	while (1) {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
    	printf("Choose any Option: ");
    	scanf("%d", &choice);
 
    	switch (choice) {
        	case 1:
            	printf("Enter the key:");
            	scanf("%d", &key);
            	insertKey(key);
            	break;
        	case 2:
            	printf("Enter the key:");
          	  scanf("%d", &key);
            	deleteKey(key);
            	break;
        	case 3:
            	displayHashTable();
            	break;
        	case 4:
            	printf("TRY AGAIN!\n");
            	exit(0);
            	break;
        	default:
            	printf("Invalid choice! Please choose again.\n");
    	} 
}
	return 0;
}
 
