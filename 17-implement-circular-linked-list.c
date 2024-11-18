#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = newNode; // Point to itself initially, forming a circular link
    return newNode;
}

// Function to insert a node at the beginning
void insertBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) { // Traverse until we reach the head node
            temp = temp->next;
        }
        temp->next = newNode;  // Link last node to the new node
        newNode->next = *head; // New node points to the head node
        *head = newNode;       // Update the head to the new node
    }
    printf("%d inserted at the beginning.\n", data);
}

// Function to insert a node at the end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) { // Traverse until we reach the head node
            temp = temp->next;
        }
        temp->next = newNode;  // Link the last node to the new node
        newNode->next = *head; // New node points to the head node
    }
    printf("%d inserted at the end.\n", data);
}

// Function to display the list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("List contents: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);  // Stop when we reach the head node again
    printf("(head)\n");
}

// Function to delete a node by value
void deleteNode(struct Node** head, int data) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If the node to be deleted is the head node
    if (temp != NULL && temp->data == data) {
        if (temp->next == *head) { // Only one node in the list
            free(temp);
            *head = NULL;
        } else {
            while (temp->next != *head) { // Find the last node
                temp = temp->next;
            }
            temp->next = (*head)->next;  // Last node points to the second node
            free(*head);                 // Free the old head node
            *head = temp->next;          // Update head to the second node
        }
        printf("%d deleted from the list.\n", data);
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // If the node was not found
    if (temp == NULL) {
        printf("%d not found in the list.\n", data);
        return;
    }

    // Unlink the node from the list
    prev->next = temp->next;
    free(temp);
    printf("%d deleted from the list.\n", data);
}

int main() {
    struct Node* head = NULL; // Initialize an empty list
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Display list\n");
        printf("4. Delete a node\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertBeginning(&head, value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
