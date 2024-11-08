#include <stdio.h>
int main() {
    int numBlocks, numProcesses;
    printf("Enter the number of blocks required: ");
    scanf("%d", &numBlocks);
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);
    if (numProcesses > numBlocks) {
        printf("Only %d blocks available\n", numBlocks);
        printf("Enter the number of processes: ");
        scanf("%d", &numProcesses);
	}
 
    int blockSize[numBlocks], processSize[numProcesses];
    int allocated[numProcesses];
    for (int i = 0; i < numBlocks; i++) {
        printf("Enter block size %d: ", i + 1);
        scanf("%d", &blockSize[i]);
	}
    for (int i = 0; i < numProcesses; i++) {
        printf("Enter process size %d: ", i + 1);
        scanf("%d", &processSize[i]);
        allocated[i] = -1;
	}
    for (int i = 0; i < numProcesses; i++) {
        int bestIdx = -1;
        for (int j = 0; j < numBlocks; j++) {
            if (blockSize[j] >= processSize[i]) {
            	if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx]) {
                	bestIdx = j;
            	}
            }
        }
        if (bestIdx != -1) {
            allocated[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
            printf("%d is allocated at %d.\n", processSize[i], blockSize[bestIdx] + processSize[i]);
        } else {
            printf("	");
            printf("Lack of space for allocating %d\n", processSize[i]);
        }	}
    printf("\nAvail List\n");
    for (int i = 0; i < numBlocks; i++) {
        if (i < numBlocks - 1) {
            printf("%d->", blockSize[i]);
        } else {
            printf("%d", blockSize[i]);
        }}
    printf("\n");
    return 0;
} 
