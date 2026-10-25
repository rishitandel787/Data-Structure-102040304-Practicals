#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Stack Operations
void push(int val) {
    if (top < MAX - 1) {
        stack[++top] = val;
    } else {
        printf("Stack Overflow!\n");
    }
}

int pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack Underflow!\n");
        return -1;
    }
}

// Function to evaluate postfix expression
int evaluatePostfix(char* exp) {
    int i;

    for (i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        // Skip whitespace if any
        if (c == ' ' || c == '\t') {
            continue;
        }

        // 1. If the scanned character is an operand (digit), push it to the stack
        if (isdigit(c)) {
            push(c - '0'); // Convert char to actual integer value
        }
        // 2. If the character is an operator, pop two operands from the stack
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int val2 = pop(); // Second operand
            int val1 = pop(); // First operand

            switch (c) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': 
                    if (val2 == 0) {
                        printf("Error: Division by zero!\n");
                        exit(1);
                    }
                    push(val1 / val2); 
                    break;
            }
        }
    }
    // The final result remains on top of the stack
    return pop();
}

int main() {
    char exp[MAX];

    printf("Enter a postfix expression (e.g., 23*5+ for (2*3)+5): ");
    scanf("%s", exp);

    int result = evaluatePostfix(exp);
    printf("Evaluated Result: %d\n", result);

    return 0;
}
