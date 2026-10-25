#include <stdio.h>

#define MAX 5 // Define maximum capacity of the circular queue

int queue[MAX];
int front = -1;
int rear = -1;

// 1. Enqueue Operation: Adds an element to the circular queue
void enqueue(int value) {
    // Check if the circular queue is full
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow! Cannot enqueue %d (Circular Queue is full).\n", value);
    } 
    else {
        // If queue is empty, initialize front and rear to 0
        if (front == -1) {
            front = 0;
            rear = 0;
        } 
        else {
            // Move rear circularly
            rear = (rear + 1) % MAX;
        }
        queue[rear] = value;
        printf("Enqueued %d into the circular queue.\n", value);
    }
}

// 2. Dequeue Operation: Removes an element from the circular queue
void dequeue() {
    // Check if the circular queue is empty
    if (front == -1) {
        printf("Queue Underflow! Cannot dequeue from an empty queue.\n");
    } 
    else {
        printf("Dequeued %d from the circular queue.\n", queue[front]);

        // If there was only one element, reset the queue
        if (front == rear) {
            front = -1;
            rear = -1;
        } 
        else {
            // Move front circularly
            front = (front + 1) % MAX;
        }
    }
}

// 3. Display Operation: Prints all elements in the circular queue
void display() {
    if (front == -1) {
        printf("Circular Queue is empty!\n");
    } 
    else {
        printf("Circular Queue elements (front to rear): ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) {
                break;
            }
            i = (i + 1) % MAX; // Wrap around circularly
        }
        printf("\n");
    }
}

int main() {
    printf("=== Circular Queue Operations Demonstration ===\n\n");

    // Display initial empty queue
    display();
    printf("\n");

    // Demonstrating Enqueue (filling the queue)
    printf("--- Enqueue Operations ---\n");
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    printf("\n");

    // Attempting to enqueue when full
    printf("--- Overflow Check ---\n");
    enqueue(60);
    printf("\n");

    // Demonstrating Dequeue
    printf("--- Dequeue Operations ---\n");
    dequeue();
    dequeue();
    display();
    printf("\n");

    // Demonstrating Circular Wrapping (Enqueueing new elements after dequeue)
    printf("--- Circular Wrapping Demonstration ---\n");
    enqueue(60);
    enqueue(70);
    display();

    return 0;
}

