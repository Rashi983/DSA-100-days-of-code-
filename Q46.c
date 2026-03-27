/*Q:level order traversal
Problem: Level Order Traversal

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    if (data == -1) return NULL;
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

typedef struct Queue {
    Node** arr;
    int front;
    int rear;
    int size;
} Queue;

Queue* createQueue(int n) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->arr = (Node**)malloc(n * sizeof(Node*));
    q->front = 0;
    q->rear = 0;
    q->size = n;
    return q;
}

void enqueue(Queue* q, Node* node) {
    q->arr[q->rear++] = node;
}

Node* dequeue(Queue* q) {
    return q->arr[q->front++];
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

void levelOrder(Node* root) {
    if (!root) return;
    Queue* q = createQueue(1000);
    enqueue(q, root);
    while (!isEmpty(q)) {
        Node* curr = dequeue(q);
        printf("%d ", curr->data);
        if (curr->left) enqueue(q, curr->left);
        if (curr->right) enqueue(q, curr->right);
    }
    printf("\n");
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    if (N == 0) return 0;

    Node* root = createNode(arr[0]);
    Queue* q = createQueue(N);
    enqueue(q, root);
    int i = 1;

    while (i < N) {
        Node* curr = dequeue(q);
        if (i < N) {
            curr->left = createNode(arr[i++]);
            if (curr->left) enqueue(q, curr->left);
        }
        if (i < N) {
            curr->right = createNode(arr[i++]);
            if (curr->right) enqueue(q, curr->right);
        }
    }

    levelOrder(root);
    return 0;
}