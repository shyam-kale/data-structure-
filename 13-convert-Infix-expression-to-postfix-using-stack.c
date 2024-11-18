#include <stdio.h>
#include <ctype.h> // For isdigit() function
#include <stdlib.h>

#define MAX 100

// Stack structure
char stack[MAX];
int top = -1;

// Function to check if the character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to get the precedence of operators
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

// Function to push an element onto the stack
void push(char c) {
    stack[++top] = c;
}

// Function to pop an element from the stack
char pop() {
    if (top == -1) {
        return -1; // Return -1 if stack is empty
    } else {
        return stack[top--];
    }
}

// Function to convert infix expression to postfix
void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    char currentChar;
    
    while ((currentChar = infix[i++]) != '\0') {
        // If it's an operand (number or letter), add it to the postfix expression
        if (isalnum(currentChar)) {
            postfix[j++] = currentChar;
        }
        // If it's an opening parenthesis, push it onto the stack
        else if (currentChar == '(') {
            push(currentChar);
        }
        // If it's a closing parenthesis, pop until we find an opening parenthesis
        else if (currentChar == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // Pop the opening parenthesis '('
        }
        // If it's an operator
        else if (isOperator(currentChar)) {
            while (top != -1 && precedence(stack[top]) >= precedence(currentChar)) {
                postfix[j++] = pop();
            }
            push(currentChar);
        }
    }

    // Pop any remaining operators from the stack
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    // Convert infix expression to postfix
    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
