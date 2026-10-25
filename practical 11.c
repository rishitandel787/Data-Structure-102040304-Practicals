#include <stdio.h>

// Function to perform Binary Search
// Returns the index of the target if found, otherwise returns -1
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        // Find the middle index (prevents integer overflow)
        int mid = low + (high - low) / 2;

        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid;
        }

        // If target is greater, ignore the left half
        if (arr[mid] < target) {
            low = mid + 1;
        }
        // If target is smaller, ignore the right half
        else {
            high = mid - 1;
        }
    }

    // Element was not present in the array
    return -1;
}

int main() {
    printf("=== Binary Search Demonstration ===\n\n");

    // Note: Binary Search requires the array to be sorted
    int arr[] = {11, 22, 25, 34, 64, 70, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // Test Case 1: Search for an element present in the array
    int target1 = 34;
    int result1 = binarySearch(arr, size, target1);
    
    if (result1 != -1) {
        printf("Element %d found at index %d.\n", target1, result1);
    } else {
        printf("Element %d not found in the array.\n", target1);
    }

    // Test Case 2: Search for an element NOT present in the array
    int target2 = 50;
    int result2 = binarySearch(arr, size, target2);
    
    if (result2 != -1) {
        printf("Element %d found at index %d.\n", target2, result2);
    } else {
        printf("Element %d not found in the array.\n", target2);
    }

    return 0;
}
