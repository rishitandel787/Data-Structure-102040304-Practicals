#include <stdio.h>

#define MAX_SIZE 100

// Function to print/traverse the array
void traverseArray(int arr[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element at a specific position
void insertElement(int arr[], int *n, int element, int pos) {
    if (*n >= MAX_SIZE) {
        printf("Error: Array Overflow!\n");
        return;
    }
    if (pos < 0 || pos > *n) {
        printf("Error: Invalid position!\n");
        return;
    }
    // Shift elements to the right
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = element;
    (*n)++;
    printf("Inserted %d at index %d.\n", element, pos);
}

// Function to search for an element and return its index
int searchElement(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // Found
        }
    }
    return -1; // Not found
}

// Function to delete an element from a specific position
void deleteElement(int arr[], int *n, int pos) {
    if (*n <= 0) {
        printf("Error: Array Underflow!\n");
        return;
    }
    if (pos < 0 || pos >= *n) {
        printf("Error: Invalid position!\n");
        return;
    }
    int deletedValue = arr[pos];
    // Shift elements to the left
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    printf("Deleted %d from index %d.\n", deletedValue, pos);
}

int main() {
    int arr[MAX_SIZE];
    int n = 0;

    // 1. Array Creation & Initialization
    printf("=== 1. Array Creation ===\n");
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    n = 4; // Current number of elements
    traverseArray(arr, n);
    printf("\n");

    // 2. Traversal Operation
    printf("=== 2. Traversal Operation ===\n");
    traverseArray(arr, n);
    printf("\n");

    // 3. Insertion Operation
    printf("=== 3. Insertion Operation ===\n");
    insertElement(arr, &n, 25, 2); // Insert 25 at index 2
    traverseArray(arr, n);
    printf("\n");

    // 4. Search Operation
    printf("=== 4. Search Operation ===\n");
    int target = 30;
    int index = searchElement(arr, n, target);
    if (index != -1) {
        printf("Element %d found at index %d.\n", target, index);
    } else {
        printf("Element %d not found.\n", target);
    }
    printf("\n");

    // 5. Deletion Operation
    printf("=== 5. Deletion Operation ===\n");
    deleteElement(arr, &n, 1); // Delete element at index 1
    traverseArray(arr, n);

    return 0;
}
