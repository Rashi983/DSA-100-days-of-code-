/*Q:Queue using linked list
Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations

Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

int dequeue() {
    if (front == NULL) {
        return -1;
    }

    struct Node* temp = front;
    int value = temp->data;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
    return value;
}

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        char op;
        scanf(" %c", &op);

        if (op == 'E') {
            int x;
            scanf("%d", &x);
            enqueue(x);
        } 
        else if (op == 'D') {
            printf("%d\n", dequeue());
        }
    }

    return 0;
}