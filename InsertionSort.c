#include<stdio.h>
int main()
{
 int n, i, j, temp;
 printf("Enter the no. of elements: \n");
 scanf("%d", &n);
 int a[n];
 printf("\nEnter the elements: \n");
 for(i=0;i<n;i++)
 {
 scanf("%d", &a[i]);
 }
 for(i=1;i<n;i++)
 {
 temp = a[i];
 j = i - 1;
 while(j>=0 && a[j]>temp)
 {
 a[j+1] = a[j];
 j = j - 1;
 }
 a[j+1] = temp;
 }
 printf("\nSorted array: \n");
 for(i=0;i<n;i++)
 {
 printf("%d\t", a[i]);
 }
}
