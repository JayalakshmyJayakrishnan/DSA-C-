#include <stdio.h>

int main() {
    int n1, n2, n3;
    int poly1[100][2], poly2[100][2], poly3[200][2];
    int i, j, k;

    
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n1);
    printf("Enter the terms (coefficient and exponent) in decreasing order of exponents:\n");
    for (i = 0; i < n1; i++) {
        scanf("%d %d", &poly1[i][0], &poly1[i][1]);
    }

    
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n2);
    printf("Enter the terms (coefficient and exponent) in decreasing order of exponents:\n");
    for (i = 0; i < n2; i++) {
        scanf("%d %d", &poly2[i][0], &poly2[i][1]);
    }

    
    i = j = k = 0;
    while (i < n1 && j < n2) {
        if (poly1[i][1] > poly2[j][1]) {
            poly3[k][0] = poly1[i][0];
            poly3[k][1] = poly1[i][1];
            i++;
        } else if (poly1[i][1] < poly2[j][1]) {
            poly3[k][0] = poly2[j][0];
            poly3[k][1] = poly2[j][1];
            j++;
        } else {
            poly3[k][0] = poly1[i][0] + poly2[j][0];
            poly3[k][1] = poly1[i][1];
            i++;
            j++;
        }
        k++;
    }

    
    while (i < n1) {
        poly3[k][0] = poly1[i][0];
        poly3[k][1] = poly1[i][1];
        i++;
        k++;
    }

    
    while (j < n2) {
        poly3[k][0] = poly2[j][0];
        poly3[k][1] = poly2[j][1];
        j++;
        k++;
    }

    n3 = k; 

    printf("First Polynomial:\n");
    for (i = 0; i < n1; i++) {
        if (i > 0 && poly1[i][0] > 0) printf(" + ");
        printf("%dx^%d", poly1[i][0], poly1[i][1]);
    }
    printf("\n");

    
    printf("Second Polynomial:\n");
    for (i = 0; i < n2; i++) {
        if (i > 0 && poly2[i][0] > 0) printf(" + ");
        printf("%dx^%d", poly2[i][0], poly2[i][1]);
    }
    printf("\n");
    
    
    printf("The sum of the polynomials is:\n");
    for (i = 0; i < n3; i++) {
        if (poly3[i][0] != 0) {
            if (i > 0 && poly3[i][0] > 0) {
                printf(" + ");
            }
            printf("%dx^%d", poly3[i][0], poly3[i][1]);
        }
    }
    printf("\n");

    return 0;
}
