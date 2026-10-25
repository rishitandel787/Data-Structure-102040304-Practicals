#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Stack operations
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return -1;
}

char peek() {
    if (top >= 0) {
        return stack[top];
    }
    return -1;
}

// Function to determine operator precedence
int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Function to convert Infix expression to Postfix
void infixToPostfix(char* infix, char* postfix) {
    int i, j = 0;
    
    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        // 1. If the scanned character is an operand (letter/digit), add it to output.
        if (isalnum(c)) {
            postfix[j++] = c;
        }
        // 2. If the character is '(', push it to the stack.
        else if (c == '(') {
            push(c);
        }
        // 3. If the character is ')', pop and output from the stack until '(' is found.
        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            if (top != -1 && peek() == '(') {
                pop(); // Remove '(' from stack
            }
        }
        // 4. An operator is encountered
        else {
            while (top != -1 && precedence(c) <= precedence(peek())) {
                postfix[j++] = pop();
            }
            push(c);
        }
    }

    // Pop all remaining operators from the stack
    while (top != -1) {
        postfix[j++] = pop();
    }
    
    postfix[j] = '\0'; // Null-terminate the postfix string
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter a valid infix expression (e.g., A+B*C): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
