#include <stdio.h>
#include <stdlib.h>

// Define a structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
struct Node* insertNode(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}

// Function to search for a value in the BST
int searchNode(struct Node* root, int value) {
    if (root == NULL) {
        return 0; // Value not found
    }

    if (root->data == value) {
        return 1; // Value found
    }

    if (value < root->data) {
        return searchNode(root->left, value);
    } else {
        return searchNode(root->right, value);
    }
}

// Function to perform an in-order traversal of the BST (for testing purposes)
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int n, value, searchValue;

    // Input the number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Insert nodes into the BST
    printf("Enter the values to insert into the BST:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    // Display the in-order traversal of the BST
    printf("In-order traversal of the BST: ");
    inOrderTraversal(root);
    printf("\n");

    // Input the value to search
    printf("Enter the value to search in the BST: ");
    scanf("%d", &searchValue);

    // Search for the value in the BST
    if (searchNode(root, searchValue)) {
        printf("Value %d is present in the BST.\n", searchValue);
    } else {
        printf("Value %d is not present in the BST.\n", searchValue);
    }

    return 0;
}
