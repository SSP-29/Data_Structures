#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node
struct Node *insert(struct Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to search for a value in the binary tree
struct Node *search(struct Node *root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

int main() {
    struct Node *root = NULL;
    // Insert some values into the tree
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 8);
    insert(root, 12);
    insert(root, 18);

    int searchValue = 12;
    struct Node *result = search(root, searchValue);
    if (result != NULL) {
        printf("Value %d found in the binary tree.\n", searchValue);
    } else {
        printf("Value %d not found in the binary tree.\n", searchValue);
    }

    // Free allocated memory
    // (not necessary in this simple example but good practice)
    free(root);
    
    return 0;
}
