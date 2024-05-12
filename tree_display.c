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

// Function to display a binary tree using inorder traversal
void inorderTraversal(struct Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to display a binary tree using preorder traversal
void preorderTraversal(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to display a binary tree using postorder traversal
void postorderTraversal(struct Node *root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
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

    // Display the binary tree using different traversals
    printf("Binary tree (Inorder traversal): ");
    inorderTraversal(root);
    printf("\n");

    printf("Binary tree (Preorder traversal): ");
    preorderTraversal(root);
    printf("\n");

    printf("Binary tree (Postorder traversal): ");
    postorderTraversal(root);
    printf("\n");

    // Free allocated memory
    // (not necessary in this simple example but good practice)
    free(root);
    
    return 0;
}
