// Replace every array element with the product of every other element without using a division operator

#include <stdio.h>

void replaceWithProduct(int arr[], int n) {
    int product[n];

    for (int i = 0; i < n; i++) {
        product[i] = 1;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                product[i] *= arr[j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        arr[i] = product[i];
    }
}

void printArray(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        if (i == n - 1) 
            printf("%d", arr[i]);
        else
            printf("%d, ", arr[i]);
    }
    printf("]\n");
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Array must contain at least two elements.\n");
        return 1; 
    }

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("The input array is: ");
    printArray(arr, n);

    replaceWithProduct(arr, n);

    printf("The modified array is: ");
    printArray(arr, n);

    return 0;
}
