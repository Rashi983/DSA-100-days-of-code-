/*Q:Right view of binary tree
Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
1 3 6

Explanation:
At each level, the rightmost node is visible from the right view*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;
    struct Node** nodes = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++)
        nodes[i] = arr[i] == -1 ? NULL : newNode(arr[i]);
    for (int i = 0, j = 1; j < n; i++) {
        if (nodes[i] != NULL) {
            if (j < n) nodes[i]->left = nodes[j++];
            if (j < n) nodes[i]->right = nodes[j++];
        }
    }
    struct Node* root = nodes[0];
    free(nodes);
    return root;
}

struct QueueNode {
    struct Node* node;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

void enqueue(struct Queue* q, struct Node* node) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->node = node;
    temp->next = NULL;
    if (!q->rear) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

struct QueueNode* dequeue(struct Queue* q) {
    if (!q->front) return NULL;
    struct QueueNode* temp = q->front;
    q->front = q->front->next;
    if (!q->front) q->rear = NULL;
    return temp;
}

int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Node* root = buildTree(arr, n);
    struct Queue q = {0};
    enqueue(&q, root);
    while (!isEmpty(&q)) {
        int count = 0;
        struct QueueNode* tempNode = q.front;
        while (tempNode) {
            count++;
            tempNode = tempNode->next;
        }
        struct Node* lastNode = NULL;
        for (int i = 0; i < count; i++) {
            struct QueueNode* nodeTemp = dequeue(&q);
            struct Node* node = nodeTemp->node;
            free(nodeTemp);
            lastNode = node;
            if (node->left) enqueue(&q, node->left);
            if (node->right) enqueue(&q, node->right);
        }
        if (lastNode) printf("%d ", lastNode->data);
    }
    return 0;
}