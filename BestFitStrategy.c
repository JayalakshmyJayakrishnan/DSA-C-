#include <stdio.h>

#define MAX_BLOCKS 10
#define MAX_PROCESSES 10

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[MAX_PROCESSES];

    // Initialize all allocations to -1 (indicating no allocation)
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    // Iterate over each process
    for (int i = 0; i < n; i++) {
        int bestIdx = -1;

        // Find the best fit block for the current process
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx]) {
                    bestIdx = j;
                }
            }
        }

        // If a suitable block is found, allocate it to the process
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    // Display allocation result
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf(" %d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main() {
    int blockSize[MAX_BLOCKS], processSize[MAX_PROCESSES];
    int m, n;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
    printf("Enter the sizes of the memory blocks:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the sizes of the processes:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
    }

    bestFit(blockSize, m, processSize, n);

    return 0;
}

/* SAMPLE OUTPUT
Enter the number of memory blocks: 5
Enter the sizes of the memory blocks:
100 500 200 300 600
Enter the number of processes: 4
Enter the sizes of the processes:
212 417 112 426

Process No.  Process Size  Block No.
1           212           4
2           417           2
3           112           3
4           426           Not Allocated
*/
