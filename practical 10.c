#include <stdio.h>

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ==================== 1. BUBBLE SORT ====================
// Repeatedly swaps adjacent elements if they are in the wrong order
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped;

    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        // If no two elements were swapped by inner loop, the array is sorted
        if (swapped == 0) {
            break;
        }
    }
}

// ==================== 2. SELECTION SORT ====================
// Repeatedly finds the minimum element from the unsorted part and puts it at the beginning
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;

    for (i = 0; i < n - 1; i++) {
        min_idx = i; // Assume the current element is the minimum
        
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j; // Update index of minimum element
            }
        }

        // Swap the found minimum element with the first element
        if (min_idx != i) {
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}

int main() {
    printf("=== Sorting Techniques Demonstration ===\n\n");

    // --- Bubble Sort Demo ---
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    printf("1. Bubble Sort:\n");
    printf("Original array: ");
    printArray(arr1, n1);

    bubbleSort(arr1, n1);

    printf("Sorted array:   ");
    printArray(arr1, n1);
    printf("\n");

    // --- Selection Sort Demo ---
    int arr2[] = {64, 25, 12, 22, 11};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("2. Selection Sort:\n");
    printf("Original array: ");
    printArray(arr2, n2);

    selectionSort(arr2, n2);

    printf("Sorted array:   ");
    printArray(arr2, n2);

    return 0;
}
