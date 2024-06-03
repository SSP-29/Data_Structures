//Open Hashing  Linear Probing//
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Define the structure for the hash table
typedef struct HashTable {
    int size;
    Node** table;
} HashTable;

// Create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Create a hash table
HashTable* createTable(int size) {
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
    hashTable->size = size;
    hashTable->table = (Node**)malloc(size * sizeof(Node*));
    for (int i = 0; i < size; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

// Hash function
unsigned int hashFunction(HashTable* hashTable, int value) {
    return value % hashTable->size;
}

// Insert a value into the hash table
void insert(HashTable* hashTable, int value) {
    unsigned int index = hashFunction(hashTable, value);
    Node* newNode = createNode(value);
    newNode->next = hashTable->table[index];
    hashTable->table[index] = newNode;
}

// Search for a value in the hash table
Node* search(HashTable* hashTable, int value) {
    unsigned int index = hashFunction(hashTable, value);
    Node* temp = hashTable->table[index];
    while (temp != NULL) {
        if (temp->value == value) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Delete a value from the hash table
void delete(HashTable* hashTable, int value) {
    unsigned int index = hashFunction(hashTable, value);
    Node* temp = hashTable->table[index];
    Node* prev = NULL;
    
    while (temp != NULL && temp->value != value) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) {
        return; // Value not found
    }
    
    if (prev == NULL) {
        hashTable->table[index] = temp->next;
    } else {
        prev->next = temp->next;
    }
    
    free(temp);
}

// Print the hash table
void printTable(HashTable* hashTable) {
    for (int i = 0; i < hashTable->size; i++) {
        printf("Bucket %d: ", i);
        Node* temp = hashTable->table[i];
        while (temp != NULL) {
            printf("%d -> ", temp->value);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Free the memory allocated for the hash table
void freeTable(HashTable* hashTable) {
    for (int i = 0; i < hashTable->size; i++) {
        Node* temp = hashTable->table[i];
        while (temp != NULL) {
            Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
    free(hashTable->table);
    free(hashTable);
}

// Example usage
int main() {
    HashTable* hashTable = createTable(5); // Creating a table with 5 buckets

    // Insert values into the hash table
    insert(hashTable, 10);
    insert(hashTable, 20);
    insert(hashTable, 30);
    insert(hashTable, 40);
    insert(hashTable, 50);

    // Print the hash table
    printTable(hashTable);

    // Search for a value
    Node* foundNode = search(hashTable, 89);
    if (foundNode != NULL) {
        printf("Value %d found in the hash table.\n", foundNode->value);
    } else {
        printf("Value not found in the hash table.\n");
    }

    // Delete a value
    delete(hashTable, 40);
    printf("After deleting :\n");
    printTable(hashTable);

    // Free the allocated memory
    freeTable(hashTable);

    return 0;
}
