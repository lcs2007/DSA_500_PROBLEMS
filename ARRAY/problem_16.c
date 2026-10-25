// Find equilibrium index of an array

#include <stdio.h>

int findEquilibriumIndex(int arr[], int n) {
    int totalSum = 0;
    int found = 0;
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    int leftSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum -= arr[i]; 

        if (leftSum == totalSum) {
            printf("Equilibrium index found at position: %d\n", i); 
            found = 1;
        }

        leftSum += arr[i];
    }

    if (!found) {
        printf("No equilibrium index found in the array.\n");
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("The input array is: {");
    for (int i = 0; i < n; i++) {
        if (i == n - 1) 
            printf("%d", arr[i]);
        else
            printf("%d, ", arr[i]);
    }

    printf("}\n");

    findEquilibriumIndex(arr, n);
    
    return 0;
}