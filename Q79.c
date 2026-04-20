/*Q:Single Source Shortest Path using Dijkstra’s Algorithm
Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct Node {
    int v, w;
    struct Node* next;
} Node;

typedef struct {
    int v, dist;
} HeapNode;

Node* adj[MAX];
HeapNode heap[MAX * MAX];
int size = 0;

void addEdge(int u, int v, int w) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->v = v;
    node->w = w;
    node->next = adj[u];
    adj[u] = node;
}

void swap(HeapNode* a, HeapNode* b) {
    HeapNode t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int i) {
    while (i && heap[(i - 1) / 2].dist > heap[i].dist) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(int i) {
    int l = 2 * i + 1, r = 2 * i + 2, smallest = i;
    if (l < size && heap[l].dist < heap[smallest].dist)
        smallest = l;
    if (r < size && heap[r].dist < heap[smallest].dist)
        smallest = r;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

void push(int v, int dist) {
    heap[size].v = v;
    heap[size].dist = dist;
    heapifyUp(size);
    size++;
}

HeapNode pop() {
    HeapNode root = heap[0];
    heap[0] = heap[--size];
    heapifyDown(0);
    return root;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    int source;
    scanf("%d", &source);

    int dist[MAX];
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[source] = 0;
    push(source, 0);

    while (size > 0) {
        HeapNode cur = pop();
        int u = cur.v;

        if (cur.dist > dist[u])
            continue;

        Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }
            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++)
        printf("%d ", dist[i]);

    return 0;
}