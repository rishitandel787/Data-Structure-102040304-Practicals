#include <stdio.h>

#define MAX 5 // Define maximum capacity of the stack

int stack[MAX];
int top = -1; // Initialize top to -1 indicating an empty stack

// 1. Push Operation: Adds an element to the top of the stack
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d (Stack is full).\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}

// 2. Pop Operation: Removes the top element from the stack
void pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop from an empty stack.\n");
    } else {
        printf("Popped %d from the stack.\n", stack[top]);
        top--;
    }
}

// 3. Peek Operation: Returns the top element without removing it
void peek() {
    if (top == -1) {
        printf("Stack is empty! No top element.\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}

// 4. Display Operation: Prints all elements in the stack from top to bottom
void display() {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements (top to bottom):\n");
        for (int i = top; i >= 0; i--) {
            printf("| %d |\n", stack[i]);
        }
        printf("-----\n");
    }
}

int main() {
    printf("=== Stack Operations Demonstration ===\n\n");

    // Display initial empty stack
    display();
    printf("\n");

    // Demonstrating Push
    printf("--- Pushing Elements ---\n");
    push(10);
    push(20);
    push(30);
    display();
    printf("\n");

    // Demonstrating Peek
    printf("--- Peek Operation ---\n");
    peek();
    printf("\n");

    // Demonstrating Pop
    printf("--- Popping Element ---\n");
    pop();
    display();
    printf("\n");

    // Demonstrating Peek after Pop
    printf("--- Peek After Pop ---\n");
    peek();

    return 0;
}
