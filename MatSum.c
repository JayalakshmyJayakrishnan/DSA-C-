#include <stdio.h>

void main() {
    int r, c, n1 = 0, n2 = 0, ns = 0, a[20][20], b[20][20], t1[20][3], t2[20][3], s[20][3];

    printf("Enter the number of rows and columns of the matrices:\n");
    scanf("%d%d", &r, &c);

    printf("Matrix A:\n");
    printf("Enter the elements of the matrix (%d x %d):\n", r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] != 0) {
                t1[n1][0] = i;
                t1[n1][1] = j;
                t1[n1][2] = a[i][j];
                n1++;
            }
        }
    }

    printf("Matrix B:\n");
    printf("Enter the elements of the matrix (%d x %d):\n", r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &b[i][j]);
            if (b[i][j] != 0) {
                t2[n2][0] = i;
                t2[n2][1] = j;
                t2[n2][2] = b[i][j];
                n2++;
            }
        }
    }

    printf("\nTriplet representation of Matrix A:\n");
    printf("ROW\tCOLUMN\tVALUE\n");
    printf("%d\t%d\t%d\n", r, c, n1);
    for (int i = 0; i < n1; i++) {
        printf("%d\t%d\t%d\n", t1[i][0], t1[i][1], t1[i][2]);
    }

    printf("\nTriplet representation of Matrix B:\n");
    printf("ROW\tCOLUMN\tVALUE\n");
    printf("%d\t%d\t%d\n", r, c, n2);
    for (int i = 0; i < n2; i++) {
        printf("%d\t%d\t%d\n", t2[i][0], t2[i][1], t2[i][2]);
    }

    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (t1[i][0] < t2[j][0] || (t1[i][0] == t2[j][0] && t1[i][1] < t2[j][1])) {
            s[ns][0] = t1[i][0];
            s[ns][1] = t1[i][1];
            s[ns][2] = t1[i][2];
            i++;
        } else if (t2[j][0] < t1[i][0] || (t2[j][0] == t1[i][0] && t2[j][1] < t1[i][1])) {
            s[ns][0] = t2[j][0];
            s[ns][1] = t2[j][1];
            s[ns][2] = t2[j][2];
            j++;
        } else {
            s[ns][0] = t1[i][0];
            s[ns][1] = t1[i][1];
            s[ns][2] = t1[i][2] + t2[j][2];
            i++;
            j++;
        }
        ns++;
    }

    while (i < n1) {
        s[ns][0] = t1[i][0];
        s[ns][1] = t1[i][1];
        s[ns][2] = t1[i][2];
        i++;
        ns++;
    }

    while (j < n2) {
        s[ns][0] = t2[j][0];
        s[ns][1] = t2[j][1];
        s[ns][2] = t2[j][2];
        j++;
        ns++;
    }

    printf("\nTriplet representation of the sum of Matrices A and B:\n");
    printf("ROW\tCOLUMN\tVALUE\n");
    printf("%d\t%d\t%d\n", r, c, ns);
    for (int i = 0; i < ns; i++) {
        printf("%d\t%d\t%d\n", s[i][0], s[i][1], s[i][2]);
    }
}
