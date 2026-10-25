#include <stdio.h>

#define MAX 5 // Define maximum capacity of the queue

int queue[MAX];
int front = -1;
int rear = -1;

// 1. Enqueue Operation: Adds an element at the rear of the queue
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot enqueue %d (Queue is full).\n", value);
    } else {
        if (front == -1) {
            front = 0; // If queue is empty, set front to 0
        }
        rear++;
        queue[rear] = value;
        printf("Enqueued %d into the queue.\n", value);
    }
}

// 2. Dequeue Operation: Removes an element from the front of the queue
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Cannot dequeue from an empty queue.\n");
        // Reset pointers if queue is empty
        front = -1;
        rear = -1;
    } else {
        printf("Dequeued %d from the queue.\n", queue[front]);
        front++;
        
        // Reset pointers if the last element was dequeued
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }
}

// 3. Display Operation: Prints all elements from front to rear
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements (front to rear): ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    printf("=== Simple Queue Operations Demonstration ===\n\n");

    // Display initial empty queue
    display();
    printf("\n");

    // Demonstrating Enqueue
    printf("--- Enqueue Operations ---\n");
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    printf("\n");

    // Demonstrating Dequeue
    printf("--- Dequeue Operations ---\n");
    dequeue();
    display();
    printf("\n");

    // Enqueue more elements to show how rear works
    printf("--- Enqueue More Elements ---\n");
    enqueue(40);
    enqueue(50);
    display();

    return 0;
}
