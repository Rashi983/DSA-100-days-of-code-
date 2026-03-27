/*Q:Reverse a queue using stack
Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    int queue[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &queue[i]);
    }
    
    int stack[N];
    int top = -1;
    for (int i = 0; i < N; i++) {
        stack[++top] = queue[i];
    }
    
    for (int i = 0; i < N; i++) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
    return 0;
}
