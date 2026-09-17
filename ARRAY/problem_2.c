// Given an integer array, check if it contains a subarray having zero-sum.

#include <stdio.h>

int sumArray(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) 
        sum += arr[i];
    return sum; 
}

void printArray(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) 
    {
        if (i == n - 1) 
            printf("%d", arr[i]);
        else
            printf("%d, ", arr[i]);
    }
    printf("]\n");
}

int main() 
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("The entered array is: ");
    printArray(arr, n);

    int found = 0;
    for (int i = 2; i <= n; i++) 
    {
        for (int j = 0; j <= n - i; j++) 
        {
            int subArraySum = sumArray(arr + j, i);
            if (subArraySum == 0) 
            {
                (found == 0) ? printf("Subarrays with zero-sum exists.\nThe subarrays with a sum of 0 are: \n") : printf("");
                found = 1;
                printArray(arr + j, i);
            }
        }
    }

    if (!found) {
        printf("No subarray with zero-sum found.\n");
    }
}