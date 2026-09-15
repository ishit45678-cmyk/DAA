#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int src, dest, weight;
} Edge;

int parent[MAX], rank_[MAX];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

int unionSet(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if (rx == ry)
        return 0;
    if (rank_[rx] < rank_[ry]) {
        parent[rx] = ry;
    } else if (rank_[rx] > rank_[ry]) {
        parent[ry] = rx;
    } else {
        parent[ry] = rx;
        rank_[rx]++;
    }
    return 1;
}

int sortEdges(Edge arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].weight > arr[j + 1].weight) {
                Edge temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return 0;
}

int main() {
    int V = 6;
    int E = 9;
    Edge edges[MAX];

    edges[0] = (Edge){0, 1, 4};
    edges[1] = (Edge){0, 2, 4};
    edges[2] = (Edge){1, 2, 2};
    edges[3] = (Edge){1, 0, 4};
    edges[4] = (Edge){2, 0, 4};
    edges[5] = (Edge){2, 1, 2};
    edges[6] = (Edge){2, 3, 3};
    edges[7] = (Edge){2, 5, 2};
    edges[8] = (Edge){2, 4, 4};

    sortEdges(edges, E);

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank_[i] = 0;
    }

    Edge result[MAX];
    int e = 0, i = 0;
    int totalWeight = 0;

    while (e < V - 1 && i < E) {
        Edge nextEdge = edges[i++];
        int x = find(nextEdge.src);
        int y = find(nextEdge.dest);
        if (x != y) {
            result[e++] = nextEdge;
            unionSet(x, y);
            totalWeight += nextEdge.weight;
        }
    }

    printf("Edges in the Minimum Spanning Tree:\n");
    for (i = 0; i < e; i++) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
    }
    printf("Total weight of MST: %d\n", totalWeight);

    return 0;
}
