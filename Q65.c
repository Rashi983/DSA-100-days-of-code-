/*Q:Cycle detection in undirected graph
Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO*/

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

    node = newNode(u);
    node->next = adj[v];
    adj[v] = node;
}

int dfs(struct Node** adj, int v, int parent, int* visited) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        int u = temp->v;

        if (!visited[u]) {
            if (dfs(adj, u, v, visited)) return 1;
        } else if (u != parent) {
            return 1;
        }

        temp = temp->next;
    }

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

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(adj, i, -1, visited)) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}