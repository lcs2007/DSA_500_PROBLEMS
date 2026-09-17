// Find the duplicate element in a limited range array

#include <stdio.h>

int findDuplicate(int arr[], int n) {
    // Thuật toán Floyd's Tortoise and Hare (Rùa và Thỏ / Tìm chu trình)
    int slow = arr[0];
    int fast = arr[0];

    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    slow = arr[0];
    while (slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int array[n];
    printf("Enter the elements of the array (values between 1 and %d):\n", n - 1);
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

    int duplicate = findDuplicate(array, n);
    
    printf("The duplicate element is: %d\n", duplicate);

    return 0;
}