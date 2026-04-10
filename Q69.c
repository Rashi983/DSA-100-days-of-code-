/*Q:Dijkstraâ€™s Algorithm (Shortest Path)
Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int v, w;
} Edge;

typedef struct {
    int node, dist;
} HeapNode;

typedef struct {
    HeapNode *arr;
    int size;
} MinHeap;

MinHeap* createHeap(int cap) {
    MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));
    h->arr = (HeapNode*)malloc(sizeof(HeapNode) * cap);
    h->size = 0;
    return h;
}

void swap(HeapNode* a, HeapNode* b) {
    HeapNode t = *a;
    *a = *b;
    *b = t;
}

void push(MinHeap* h, int node, int dist) {
    int i = h->size++;
    h->arr[i].node = node;
    h->arr[i].dist = dist;

    while (i && h->arr[(i - 1) / 2].dist > h->arr[i].dist) {
        swap(&h->arr[i], &h->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

HeapNode pop(MinHeap* h) {
    HeapNode root = h->arr[0];
    h->arr[0] = h->arr[--h->size];

    int i = 0;
    while (1) {
        int l = 2 * i + 1, r = 2 * i + 2, smallest = i;

        if (l < h->size && h->arr[l].dist < h->arr[smallest].dist)
            smallest = l;
        if (r < h->size && h->arr[r].dist < h->arr[smallest].dist)
            smallest = r;

        if (smallest == i) break;

        swap(&h->arr[i], &h->arr[smallest]);
        i = smallest;
    }

    return root;
}

int empty(MinHeap* h) {
    return h->size == 0;
}

typedef struct Node {
    int v, w;
    struct Node* next;
} Node;

Node* createNode(int v, int w) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->v = v;
    n->w = w;
    n->next = NULL;
    return n;
}

void addEdge(Node** adj, int u, int v, int w) {
    Node* n = createNode(v, w);
    n->next = adj[u];
    adj[u] = n;
}

void dijkstra(Node** adj, int n, int src, int* dist) {
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    MinHeap* h = createHeap(n * n);
    push(h, src, 0);

    while (!empty(h)) {
        HeapNode cur = pop(h);
        int u = cur.node;
        int d = cur.dist;

        if (d > dist[u]) continue;

        Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(h, v, dist[v]);
            }

            temp = temp->next;
        }
    }
}