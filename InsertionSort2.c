#include <stdio.h>
int main() {
    int a[10], i, j, n, key;

    printf("Enter the size of the elements: ");
    scanf("%d", &n);

    printf("Enter the %d elements: \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Array before sorting: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

  
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;

       
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }

    printf("Array after sorting: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;  
}
