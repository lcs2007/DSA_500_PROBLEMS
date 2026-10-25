// Find the maximum product of two integers in an array

#include <stdio.h>

int maxProduct(int arr[], int n) {
    if (n < 2) {
        printf("Array must contain at least two elements.\n");
        return -1; 
    }

    int max1 = arr[0] > arr[1] ? arr[0] : arr[1];
    int max2 = arr[0] <= arr[1] ? arr[0] : arr[1];

    for (int i = 2; i < n; i++) {
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] > max2) {
            max2 = arr[i];
        }
    }

    return max1 * max2;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Array must contain at least two elements.\n");
        return 1; 
    }

    int array[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("The input array is: {");
    for (int i = 0; i < n; i++) {
        if (i == n - 1) 
            printf("%d", array[i]);
        else
            printf("%d, ", array[i]);
    }
    printf("}\n");

    int product = maxProduct(array, n);
    
    if (product != -1) {
        printf("The maximum product of two integers in the array is: %d\n", product);
    }

    return 0;
}