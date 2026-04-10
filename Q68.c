/*Q:Topological sort(BFS algorithm)
Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm)*/

#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int front = 0, rear = -1;
int n;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

void kahnTopologicalSort() {
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    int count = 0;

    while (!isEmpty()) {
        int u = dequeue();
        printf("%d ", u);
        count++;

        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    enqueue(v);
                }
            }
        }
    }

    printf("\n");
}

int main() {
    int edges, u, v;

    scanf("%d", &n);
    scanf("%d", &edges);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    kahnTopologicalSort();

    return 0;
}