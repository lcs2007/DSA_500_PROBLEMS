// Find all subarray having a given sum, print the subarrays and return the array with the maximum length among them

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
    int n, targetSum;
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

    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    int found = 0;
    int maxLength = 0;
    int maxSubarrayStart = -1;
    int maxSubarrayEnd = -1;

    for (int i = 0; i < n; i++) 
    {
        for (int j = i; j < n; j++) 
        {
            int subArraySum = sumArray(arr + i, j - i + 1);
            if (subArraySum == targetSum) 
            {
                (found == 0) ? printf("Subarrays with the given sum exist.\nThe subarrays with a sum of %d are: \n", targetSum) : printf("");
                found = 1;
                printArray(arr + i, j - i + 1);

                if (j - i + 1 > maxLength) 
                {
                    maxLength = j - i + 1;
                    maxSubarrayStart = i;
                    maxSubarrayEnd = j;
                }
            }
        }
    }

    if (!found) {
        printf("No subarray with the given sum found.\n");
    } else {
        printf("The longest subarray with the given sum is: ");
        printArray(arr + maxSubarrayStart, maxLength);
    }

    return 0;
}