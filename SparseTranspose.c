#include <stdio.h>

#define MAX_SIZE 10

int main() {
    int a[MAX_SIZE][MAX_SIZE], t[MAX_SIZE * MAX_SIZE][3], b[MAX_SIZE * MAX_SIZE][3];
    int r, c, i, j, k, n = 0;

    // Input matrix dimensions
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    // Input matrix elements
    printf("Enter matrix elements:\n");
    for (i = 0; i < r; ++i) {
        for (j = 0; j < c; ++j) {
            scanf("%d", &a[i][j]);
            if (a[i][j] != 0) {
                t[n][0] = i;    // row
                t[n][1] = j;    // column
                t[n][2] = a[i][j]; // value
                n++;
            }
        }
    }

    // Printing the triplet representation
    printf("\nTriplet representation of sparse matrix:\n");
    printf("Row\tColumn\tValue\n");
    for (i = 0; i < n; ++i) {
        printf("%d\t%d\t%d\n", t[i][0], t[i][1], t[i][2]);
    }

    // Finding transpose of the triplet representation
    for (i = 0; i < n; ++i) {
        b[i][0] = t[i][1];   // transpose column becomes row
        b[i][1] = t[i][0];   // transpose row becomes column
        b[i][2] = t[i][2];   // value remains the same
    }

    // Printing the transpose of the triplet representation
    printf("\nTranspose of the triplet representation:\n");
    printf("Row\tColumn\tValue\n");
    for (i = 0; i < n; ++i) {
        printf("%d\t%d\t%d\n", b[i][0], b[i][1], b[i][2]);
    }

    return 0;
}
