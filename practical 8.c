#include <stdio.h>
#include <stdlib.h>

// Define the structure for a BST node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the Binary Search Tree
struct Node* insert(struct Node* root, int value) {
    // If the tree is empty, return a new node
    if (root == NULL) {
        return createNode(value);
    }

    // Otherwise, recur down the tree
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    // Return the unchanged node pointer
    return root;
}

// 1. Inorder Traversal (Left -> Root -> Right)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// 2. Preorder Traversal (Root -> Left -> Right)
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// 3. Postorder Traversal (Left -> Right -> Root)
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL;

    printf("=== Binary Search Tree Construction & Traversal ===\n\n");

    // Constructing the BST by inserting elements
    // Elements to insert: 50, 30, 20, 40, 70, 60, 80
    int values[] = {50, 30, 20, 40, 70, 60, 80};
    int n = sizeof(values) / sizeof(values[0]);

    printf("Inserting elements into BST: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", values[i]);
        root = insert(root, values[i]);
    }
    printf("\n\n");

    // Demonstrating Traversals
    printf("--- Tree Traversals ---\n");

    printf("1. Inorder Traversal (Sorted order): ");
    inorderTraversal(root);
    printf("\n");

    printf("2. Preorder Traversal (Root first): ");
    preorderTraversal(root);
    printf("\n");

    printf("3. Postorder Traversal (Root last): ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
