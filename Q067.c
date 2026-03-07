/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

// Push into stack
void push(int value) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = top;
    top = newnode;
}

// Pop from stack
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct node *temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

// Check if operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int main() {
    char exp[200];
    
    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    char *token = strtok(exp, " \n");

    while (token != NULL) {
        // If token is a number
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(atoi(token));
        }
        // If token is an operator
        else if (isOperator(token[0])) {
            int b = pop();
            int a = pop();
            int result;

            switch (token[0]) {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    result = a / b;
                    break;
                default:
                    printf("Invalid operator\n");
                    return 1;
            }

            push(result);
        }

        token = strtok(NULL, " \n");
    }

    printf("%d\n", pop());

    return 0;
}