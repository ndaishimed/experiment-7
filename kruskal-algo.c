#include <stdio.h>
#define MAX 100
struct Edge {
    int u, v, weight;
};
int parent[MAX];
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}
void unionSet(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    parent[rootV] = rootU;
}
void sortEdges(struct Edge edges[], int e) {
    int i, j;
    struct Edge temp;
    for (i = 0; i < e - 1; i++) {
        for (j = 0; j < e - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}
int main() {
    int n, e, i, count = 0, totalCost = 0;
    struct Edge edges[MAX];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    printf("Enter edges (source destination weight):\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }
    for (i = 0; i < n; i++)
        parent[i] = i;
    sortEdges(edges, e);
    printf("\nEdges in Minimum Spanning Tree:\n");

    for (i = 0; i < e && count < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find(u) != find(v)) {
            printf("%d -- %d = %d\n", u, v, edges[i].weight);
            totalCost += edges[i].weight;
            unionSet(u, v);
            count++;
        }
    }
    printf("Total cost of MST = %d\n", totalCost);

    return 0;
}
