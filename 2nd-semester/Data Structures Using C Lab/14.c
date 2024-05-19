// Implement a binary search tree using array and develop functions to perform traversal, 
// searching, insertion and deletion operations
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
#define EMPTY -1
typedef struct {
    int data[MAX_SIZE];
} BST;
void initBST(BST *tree) {
    for (int i = 0; i < MAX_SIZE; i++) {
        tree->data[i] = EMPTY;
    }
}
int insert(BST *tree, int value) {
    int index = 0;
    while (index < MAX_SIZE) {
        if (tree->data[index] == EMPTY) {
            tree->data[index] = value;
            return index;
        } else if (value < tree->data[index]) {
            index = 2 * index + 1;
        } else if (value > tree->data[index]) {
            index = 2 * index + 2;
        } else {
            return -1; // Duplicate value
        }
    }
    return -1; // Tree is full
}
void inOrderTraversal(BST *tree, int index) {
    if (index >= MAX_SIZE || tree->data[index] == EMPTY) return;
    inOrderTraversal(tree, 2 * index + 1);
    printf("%d ", tree->data[index]);
    inOrderTraversal(tree, 2 * index + 2);
}
void preOrderTraversal(BST *tree, int index) {
    if (index >= MAX_SIZE || tree->data[index] == EMPTY) return;
    printf("%d ", tree->data[index]);
    preOrderTraversal(tree, 2 * index + 1);
    preOrderTraversal(tree, 2 * index + 2);
}
void postOrderTraversal(BST *tree, int index) {
    if (index >= MAX_SIZE || tree->data[index] == EMPTY) return;
    postOrderTraversal(tree, 2 * index + 1);
    postOrderTraversal(tree, 2 * index + 2);
    printf("%d ", tree->data[index]);
}
int search(BST *tree, int value) {
    int index = 0;
    while (index < MAX_SIZE && tree->data[index] != EMPTY) {
        if (value == tree->data[index]) {
            return index;
        } else if (value < tree->data[index]) {
            index = 2 * index + 1;
        } else {
            index = 2 * index + 2;
        }
    }
    return -1; // Value not found
}
void delete(BST *tree, int value) {
    int index = search(tree, value);
    if (index == -1) {
        printf("Value not found in the tree.\n");
        return;
    }
    int largestIndex, largestValue;
    if (tree->data[2 * index + 1] != EMPTY) {
        // Node has a left child
        largestIndex = 2 * index + 1;
        while (tree->data[2 * largestIndex + 2] != EMPTY) {
            largestIndex = 2 * largestIndex + 2;
        }
        largestValue = tree->data[largestIndex];
        delete(tree, largestValue);
        tree->data[index] = largestValue;
    } else if (tree->data[2 * index + 2] != EMPTY) {
        // Node has a right child but no left child
        largestIndex = 2 * index + 2;
        while (tree->data[2 * largestIndex + 1] != EMPTY) {
            largestIndex = 2 * largestIndex + 1;
        }
        largestValue = tree->data[largestIndex];
        delete(tree, largestValue);
        tree->data[index] = largestValue;
    } else {
        // Node is a leaf
        tree->data[index] = EMPTY;
    }
}
int main() {
    BST tree;
    initBST(&tree);
    int choice, value;
    while (1) {
        printf("\n1. Insert\n2. In-Order Traversal\n3. Pre-Order Traversal\n4. Post-Order Traversal\n5. Search\n6. Delete\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                if (insert(&tree, value) == -1) {
                    printf("Insertion failed. Tree might be full or value already exists.\n");
                }
                break;
            case 2:
                printf("In-Order Traversal: ");
                inOrderTraversal(&tree, 0);
                printf("\n");
                break;
            case 3:
                printf("Pre-Order Traversal: ");
                preOrderTraversal(&tree, 0);
                printf("\n");
                break;
            case 4:
                printf("Post-Order Traversal: ");
                postOrderTraversal(&tree, 0);
                printf("\n");
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                int result = search(&tree, value);
                if (result != -1) {
                    printf("Value found at index %d\n", result);
                } else {
                    printf("Value not found.\n");
                }
                break;
            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete(&tree, value);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}