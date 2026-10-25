#include <stdio.h>
#include <stdlib.h>

// Define the structure for a circular linked list node
struct Node {
    int data;
    struct Node* next;
};

// ==================== DISPLAY OPERATION ====================
void display(struct Node* head) {
    if (head == NULL) {
        printf("Circular Linked List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// ==================== INSERTION OPERATIONS ====================

// 1. Insert at the Beginning
void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        new_node->next = new_node; // Points to itself
    } else {
        struct Node* temp = *head_ref;
        // Traverse to the last node to update its pointer
        while (temp->next != *head_ref) {
            temp = temp->next;
        }
        new_node->next = *head_ref;
        temp->next = new_node;
        *head_ref = new_node; // Update head
    }
    printf("Inserted %d at the beginning.\n", new_data);
}

// 2. Insert at the End
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        new_node->next = new_node;
    } else {
        struct Node* temp = *head_ref;
        // Traverse to the last node
        while (temp->next != *head_ref) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = *head_ref; // Complete the circle
    }
    printf("Inserted %d at the end.\n", new_data);
}

// 3. Insert After a Given Node
void insertAfterNode(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL.\n");
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    printf("Inserted %d after node %d.\n", new_data, prev_node->data);
}

// ==================== DELETION OPERATIONS ====================

// 1. Delete First Node
void deleteFirst(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = *head_ref;
    
    // If there is only one node in the list
    if (temp->next == *head_ref) {
        printf("Deleted first node with value %d.\n", temp->data);
        free(temp);
        *head_ref = NULL;
        return;
    }

    // Traverse to the last node
    struct Node* last = *head_ref;
    while (last->next != *head_ref) {
        last = last->next;
    }

    *head_ref = temp->next;
    last->next = *head_ref; // Update last node's link to the new head
    printf("Deleted first node with value %d.\n", temp->data);
    free(temp);
}

// 2. Delete Last Node
void deleteLast(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = *head_ref;

    // If there is only one node in the list
    if (temp->next == *head_ref) {
        printf("Deleted last node with value %d.\n", temp->data);
        free(temp);
        *head_ref = NULL;
        return;
    }

    // Traverse until the second last node
    struct Node* prev = NULL;
    while (temp->next != *head_ref) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = *head_ref; // Point second last node to head
    printf("Deleted last node with value %d.\n", temp->data);
    free(temp);
}

// 3. Delete Node After a Given Node
void deleteAfterNode(struct Node** head_ref, struct Node* prev_node) {
    if (*head_ref == NULL || prev_node == NULL) {
        printf("Invalid deletion operation.\n");
        return;
    }

    struct Node* temp = prev_node->next;

    if (temp == prev_node) {
        printf("Only one node exists. Cannot delete after.\n");
        return;
    }

    // If the node to be deleted is the head node, update head
    if (temp == *head_ref) {
        *head_ref = temp->next;
    }

    prev_node->next = temp->next;
    printf("Deleted node with value %d after node %d.\n", temp->data, prev_node->data);
    free(temp);
}

// ==================== MAIN FUNCTION ====================
int main() {
    struct Node* head = NULL;

    printf("=== Singly Circular Linked List Demonstration ===\n\n");

    // Demonstrating Insertions
    printf("--- Insertion Operations ---\n");
    insertAtEnd(&head, 20);       // List: 20
    insertAtBeginning(&head, 10); // List: 10 -> 20
    insertAtEnd(&head, 40);       // List: 10 -> 20 -> 40
    
    // Insert 30 after the node containing 20 (second node)
    insertAfterNode(head->next, 30); // List: 10 -> 20 -> 30 -> 40
    
    display(head);
    printf("\n");

    // Demonstrating Deletions
    printf("--- Deletion Operations ---\n");
    
    deleteFirst(&head);          // Deletes 10 (List: 20 -> 30 -> 40)
    display(head);

    deleteLast(&head);           // Deletes 40 (List: 20 -> 30)
    display(head);

    // Delete node after the head node (deletes node after 20, which is 30)
    deleteAfterNode(&head, head); // List: 20
    display(head);

    return 0;
}

