#include <stdio.h>

int main() {
    int n;

    // Prompt user for array size
    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[n];
    int *ptr = arr; // Pointer pointing to the base address of the array

    // Input array elements using pointer arithmetic
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", ptr + i);
    }

    // Print array elements in reverse order using pointers
    printf("\nArray elements in reverse order:\n");
    
    // Point the pointer to the last element of the array
    ptr = arr + n - 1;

    // Traverse backwards from the last element to the first
    for (int i = 0; i < n; i++) {
        printf("%d ", *ptr); // Print the value at the current pointer address
        ptr--;               // Move the pointer backward to the previous element
    }
    printf("\n");

    return 0;
}
