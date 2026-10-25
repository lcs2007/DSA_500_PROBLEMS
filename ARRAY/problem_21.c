// Find the maximum difference between two elements in it such that the smaller element appears before the larger element and print out the pair that satisfies this condition.

#include <stdio.h>

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

    printf("The input array is: {");
    for (int i = 0; i < n; i++) {
        if (i == n - 1) 
            printf("%d", arr[i]);
        else
            printf("%d, ", arr[i]);
    }
    printf("}\n");

    int minElement = arr[0];
    int maxElement = arr[1];
    int maxDiff = arr[1] - arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] - minElement > maxDiff) {
            maxDiff = arr[i] - minElement;
            maxElement = arr[i];
        }
        if (arr[i] < minElement) {
            minElement = arr[i];
        }
    }

    if (maxDiff != -1) {
        printf("The maximum difference between two elements in the array is: %d\n", maxDiff);
        printf("The pair that satisfies this condition is: (%d, %d)\n", minElement, maxElement);
    }

    return 0;
}