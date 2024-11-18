#include <stdio.h>

#define MAX 10 // Maximum size of the stack

int stack[MAX];
int top = -1; // Stack is initially empty

// Push operation
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack is full\n");
    } else {
        stack[++top] = value;
        printf("%d pushed to stack\n", value);
    }
}

// Pop operation
int pop() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1; // Indicating the stack is empty
    } else {
        return stack[top--];
    }
}

// Peek operation
int peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return stack[top];
    }
}

// Display the stack
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1) {
                    printf("%d popped from stack\n", value);
                }
                break;
            case 3:
                value = peek();
                if (value != -1) {
                    printf("Top element is: %d\n", value);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
