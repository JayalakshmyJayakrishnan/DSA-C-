#include<stdio.h>
void main(){
    int a[20], i, n, k, flag =0;
    printf("Enter the size of the elements: ");
    scanf("%d", &n);
    printf("Enter the array elements: \n");
        for(i=0;i<n;i++){
            scanf("%d", &a[i]);
        }
    printf("Enter the element to be searched: ");
    scanf("%d", &k);
        for(i=0;i<n;i++){
            if(a[i]==k){
                flag = 1;
                printf("Search element is found at %d !", i +1);
             }
}
            if(flag==0){
                printf("Element not found!");
            }
       
}
