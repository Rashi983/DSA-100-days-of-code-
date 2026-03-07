/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int precedence(char op) {
    if (op == '^') return 3;          // if you ever extend
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int main() {
    char infix[1000];
    if (!fgets(infix, sizeof(infix), stdin)) return 0;

    // remove trailing newline if present
    int len = (int)strlen(infix);
    if (len > 0 && infix[len - 1] == '\n') infix[len - 1] = '\0';

    char stack[1000];
    int top = -1;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (ch == ' ' || ch == '\t') continue;

        // operand (single character: A, b, 7, etc.)
        if (isalnum((unsigned char)ch)) {
            putchar(ch);
        }
        // opening bracket
        else if (ch == '(') {
            stack[++top] = ch;
        }
        // closing bracket: pop until '('
        else if (ch == ')') {
            while (top >= 0 && stack[top] != '(') {
                putchar(stack[top--]);
            }
            if (top >= 0 && stack[top] == '(') top--; // pop '('
        }
        // operator
        else if (isOperator(ch)) {
            // For +,-,*,/ we use left associativity:
            // pop while precedence(stackTop) >= precedence(current)
            // (If you include '^' as right associative, change condition for '^')
            while (top >= 0 && isOperator(stack[top]) &&
                   precedence(stack[top]) >= precedence(ch)) {
                putchar(stack[top--]);
            }
            stack[++top] = ch;
        }
        // ignore any other characters
    }

    // pop remaining operators
    while (top >= 0) {
        if (stack[top] != '(') putchar(stack[top]);
        top--;
    }

    return 0;
}