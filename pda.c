#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

// Stack implementation
char stack[MAX];
int top = -1;

// Function to push an element to the stack
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = c;
}

// Function to pop an element from the stack
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

// Function to check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Function to check for balanced parentheses
int checkBalancedParentheses(char *input) {
    int i;
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == '(') {
            push('('); // Push '(' onto the stack
        } else if (input[i] == ')') {
            if (isEmpty()) {
                return 0; // Unbalanced parentheses
            }
            pop(); // Pop '(' from the stack
        }
    }
    return isEmpty(); // If stack is empty, parentheses are balanced
}

int main() {
    char input[MAX];

    printf("Enter a string of parentheses: ");
    scanf("%s", input);

    if (checkBalancedParentheses(input)) {
        printf("The input string has balanced parentheses.\n");
    } else {
        printf("The input string does NOT have balanced parentheses.\n");
    }

    return 0;
}
