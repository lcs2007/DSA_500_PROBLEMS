// Sort binary array in linear time

#include <stdio.h>

void printArray(int arr[], int n) {
    printf("{");
    for (int i = 0; i < n; i++) 
    {
        if (i == n - 1) 
            printf("%d", arr[i]);
        else
            printf("%d, ", arr[i]);
    }
    printf("}\n");
}

int main()
{
    int array[] = {0, 1, 0, 1, 1, 0, 0, 1};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Original binary array: ");

    printArray(array, n);
    
    int count0 = 0;

    for (int i = 0; i < n; i++) 
        if (array[i] == 0) 
            count0++;

    for (int i = 0; i < count0; i++) 
        array[i] = 0;

    for (int i = count0; i < n; i++) 
        array[i] = 1;

    printf("Sorted binary array: ");
    printArray(array, n);
}