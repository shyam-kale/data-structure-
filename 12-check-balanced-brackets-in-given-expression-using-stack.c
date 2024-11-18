#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the stack

char stack[MAX];
int top = -1;

// Function to push an element onto the stack
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack is full\n");
    } else {
        stack[++top] = c;
    }
}

// Function to pop an element from the stack
char pop() {
    if (top == -1) {
        return -1; // Return -1 if stack is empty
    } else {
        return stack[top--];
    }
}

// Function to check if the character is an opening bracket
int isOpeningBracket(char c) {
    return c == '(' || c == '{' || c == '[';
}

// Function to check if the character is a closing bracket
int isClosingBracket(char c) {
    return c == ')' || c == '}' || c == ']';
}

// Function to check if two brackets match
int isMatchingPair(char opening, char closing) {
    if (opening == '(' && closing == ')') return 1;
    if (opening == '{' && closing == '}') return 1;
    if (opening == '[' && closing == ']') return 1;
    return 0;
}

// Function to check if the brackets in the given expression are balanced
int areBracketsBalanced(char expression[]) {
    int i = 0;
    char currentChar;

    while ((currentChar = expression[i++]) != '\0') {
        // If it's an opening bracket, push it to the stack
        if (isOpeningBracket(currentChar)) {
            push(currentChar);
        }
        // If it's a closing bracket, check for matching opening bracket
        else if (isClosingBracket(currentChar)) {
            // If stack is empty or brackets don't match, it's unbalanced
            if (top == -1 || !isMatchingPair(pop(), currentChar)) {
                return 0; // Not balanced
            }
        }
    }

    // If stack is empty, all brackets matched
    return top == -1;
}

int main() {
    char expression[MAX];

    printf("Enter an expression: ");
    fgets(expression, sizeof(expression), stdin);

    if (areBracketsBalanced(expression)) {
        printf("The brackets are balanced.\n");
    } else {
        printf("The brackets are not balanced.\n");
    }

    return 0;
}
