// Given an unsorted integer array, find a pair with the given sum in it.

#include <stdio.h>

int sortArray(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return 0;
}

int findPairWithSum(int* arr, int n, int target) {
    sortArray(arr, n);
    int left = 0;
    int right = n - 1;
    int found = 0;

    while (left < right) {
        int currentSum = arr[left] + arr[right];
        if (currentSum == target) {
            printf("Pair found: (%d, %d)\n", arr[left], arr[right]);
            left++;
            right--;
            found = 1;
        } else if (currentSum < target) {
            left++;
        } else {
            right--;
        }
    }

    if (!found) {
        printf("Pair not found.\n");
    }
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

    int target;
    printf("Enter the target sum: ");
    scanf("%d", &target);

    sortArray(arr, n);

    findPairWithSum(arr, n, target);

    return 0;
}

