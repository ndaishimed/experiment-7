#include <stdio.h>
#define MAX 100
#define INF 99999

int main() {
    int n, graph[MAX][MAX];
    int selected[MAX];
    int i, j, edges = 0;
    int x, y, min;
    int totalCost = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);

            if (graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }
    for (i = 0; i < n; i++)
        selected[i] = 0;
    selected[0] = 1;
    printf("\nEdges in Minimum Spanning Tree:\n");
    while (edges < n - 1) {
        min = INF;
        x = -1;
        y = -1;
        for (i = 0; i < n; i++) {
            if (selected[i]) {
                for (j = 0; j < n; j++) {
                    if (!selected[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        if (x == -1 || y == -1) {
            printf("MST cannot be formed.\n");
            return 0;
        }

        printf("%d -- %d = %d\n", x, y, min);
        totalCost += min;
        selected[y] = 1;
        edges++;
    }
    printf("Total cost of MST = %d\n", totalCost);

    return 0;
}
