// Implement a binary tree using array and develop functions to perform traversal, 
// searching, insertion and deletion operations
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef struct {
    int data[MAX_SIZE];
    int size;
} BinaryTree;
void initTree(BinaryTree *tree) {
    tree->size = 0;
}
void insert(BinaryTree *tree, int value) {
    if (tree->size == MAX_SIZE) {
        printf("Tree is full.\n");
        return;
    }
    tree->data[tree->size++] = value;
}
void inOrderTraversal(BinaryTree *tree, int index) {
    if (index >= tree->size)
        return;
    inOrderTraversal(tree, 2 * index + 1);
    printf("%d ", tree->data[index]);
    inOrderTraversal(tree, 2 * index + 2);
}
void preOrderTraversal(BinaryTree *tree, int index) {
    if (index >= tree->size)
        return;
    printf("%d ", tree->data[index]);
    preOrderTraversal(tree, 2 * index + 1);
    preOrderTraversal(tree, 2 * index + 2);
}
void postOrderTraversal(BinaryTree *tree, int index) {
    if (index >= tree->size)
        return;
    postOrderTraversal(tree, 2 * index + 1);
    postOrderTraversal(tree, 2 * index + 2);
    printf("%d ", tree->data[index]);
}
int search(BinaryTree *tree, int value) {
    for (int i = 0; i < tree->size; i++) {
        if (tree->data[i] == value)
            return i;
    }
    return -1;
}
void delete(BinaryTree *tree, int value) {
    int index = search(tree, value);
    if (index == -1) {
        printf("Value not found in the tree.\n");
        return;
    }
    tree->data[index] = tree->data[tree->size - 1];
    tree->size--;
}
int main() {
    BinaryTree tree;
    initTree(&tree);
    int choice, value;
    while (1) {
        printf("\n1. Insert\n2. In-Order Traversal\n3. Pre-Order Traversal\n4. Post-Order Traversal\n5. Search\n6. Delete\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&tree, value);
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