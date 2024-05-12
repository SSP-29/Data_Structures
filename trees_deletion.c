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

// Function to delete a binary tree
void deleteTree(struct Node *root) {
    if (root == NULL) {
        return;
    }
    // Postorder traversal to delete each node
    deleteTree(root->left);
    deleteTree(root->right);
    printf("Deleting node: %d\n", root->data); // Optional: print to visualize deletion
    free(root);
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

    // Deleting the binary tree
    deleteTree(root);
    
    return 0;
}
