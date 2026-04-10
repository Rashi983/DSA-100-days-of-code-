/*Q:Cycle detection in directed graph
Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int v;
    struct Node* next;
};

struct Node* newNode(int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->v = v;
    node->next = NULL;
    return node;
}

void addEdge(struct Node** adj, int u, int v) {
    struct Node* node = newNode(v);
    node->next = adj[u];
    adj[u] = node;
}

int dfs(struct Node** adj, int v, int* visited, int* recStack) {
    visited[v] = 1;
    recStack[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        int u = temp->v;

        if (!visited[u]) {
            if (dfs(adj, u, visited, recStack))
                return 1;
        } else if (recStack[u]) {
            return 1;
        }

        temp = temp->next;
    }

    recStack[v] = 0;
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node** adj = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) adj[i] = NULL;

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int* visited = (int*)calloc(n, sizeof(int));
    int* recStack = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(adj, i, visited, recStack)) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}