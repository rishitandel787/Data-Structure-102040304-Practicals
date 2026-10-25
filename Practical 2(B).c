#include <stdio.h>

// 1. Call by Value Function
// This function receives a copy of the variable's value.
void modifyByValue(int num) {
    num = num + 10; // Modifies only the local copy
    printf("Inside modifyByValue: num = %d\n", num);
}

// 2. Call by Reference Function
// This function receives the memory address of the variable using a pointer.
void modifyByReference(int *num) {
    *num = *num + 10; // Modifies the actual value at the memory address
    printf("Inside modifyByReference: *num = %d\n", *num);
}

int main() {
    int x = 20;

    // --- DEMONSTRATING CALL BY VALUE ---
    printf("=== Call by Value ===\n");
    printf("Before function call, x = %d\n", x);
    
    modifyByValue(x); // Passing the value of x
    
    printf("After function call, x = %d\n", x);
    printf("(Notice that x did NOT change because only a copy was modified.)\n\n");

    // Reset x for the next demonstration
    x = 20;

    // --- DEMONSTRATING CALL BY REFERENCE ---
    printf("=== Call by Reference ===\n");
    printf("Before function call, x = %d\n", x);
    
    modifyByReference(&x); // Passing the memory address of x using '&'
    
    printf("After function call, x = %d\n", x);
    printf("(Notice that x DID change because we modified its actual memory location.)\n");

    return 0;
}
