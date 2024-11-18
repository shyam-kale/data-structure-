#include <stdio.h>
#include <string.h>

#define MAX 100 // Maximum size of the string

char stack[MAX];
int top = -1;

// Push a character onto the stack
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack is full\n");
    } else {
        stack[++top] = c;
    }
}

// Pop a character from the stack
char pop() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1; // Return -1 if stack is empty
    } else {
        return stack[top--];
    }
}

// Function to reverse the string
void reverseString(char str[]) {
    int i;
    int length = strlen(str);

    // Push all characters of the string onto the stack
    for (i = 0; i < length; i++) {
        push(str[i]);
    }

    // Pop all characters from the stack and form the reversed string
    for (i = 0; i < length; i++) {
        str[i] = pop();
    }
}

int main() {
    char str[MAX];

    printf("Enter a string: ");
    gets(str); // Read the input string

    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}
