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
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode; // If list is empty, new node becomes the head
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode; // Insert at the end
    }
    printf("%d inserted at the end of the list.\n", data);
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("List contents: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
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
        *head = temp->next; // Move the head to the next node
        free(temp); // Free the memory
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
        printf("1. Insert at end\n");
        printf("2. Display list\n");
        printf("3. Delete a node\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
