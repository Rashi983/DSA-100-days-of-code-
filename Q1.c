/* Q1: Insert an Element in an Array 

Problem : Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space:

Input:
- First line: integer n
- Second line: n space-separated integers (the array)
- Third line: integer pos (1-based position)
- Fourth line: integer x (element to insert)

Output:
- Print the updated array (n+1 integers) in a single line, space-separated

Example:
Input:
5
1 2 4 5 6
3
3

Output:
1 2 3 4 5 6

Explanation: Insert 3 at position 3, elements [4,5,6] shift right*/

#include <stdio.h>

int main() {
    int n, pos, x, i, a[50];

    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter array elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter position: ");
    scanf("%d", &pos);
    printf("Enter element: ");
    scanf("%d", &x);
    for(i = n; i >= pos; i--)
        a[i] = a[i - 1];

    a[pos - 1] = x;
    printf("Updated array: ");
    for(i = 0; i <= n; i++)
        printf("%d ", a[i]);
    return 0;
}


