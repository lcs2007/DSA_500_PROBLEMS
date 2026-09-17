// Given an unsorted integer array, find a pair with the given sum in it.

#include <stdio.h>

int findPairWithSum(int arr[], int size, int target) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == target) {
                printf("Pair found: (%d, %d)\n", arr[i], arr[j]);
                return 1; 
            }
        }
    }
    printf("Pair not found.\n");
    return 0; 
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the sum to find: ");
    int target;
    scanf("%d", &target);

    findPairWithSum(arr, n, target);

    return 0;
}

