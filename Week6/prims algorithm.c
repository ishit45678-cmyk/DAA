#include <stdio.h>

int minKey(int key[6], int mstSet[6]) {
    int min = 9999;
    int minIndex = 0;

    for (int v = 0; v < 6; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

int main() {
    int graph[6][6] = {
        {0, 4, 4, 0, 0, 0},
        {4, 0, 2, 0, 0, 0},
        {4, 2, 0, 3, 4, 2},
        {0, 0, 3, 0, 0, 0},
        {0, 0, 4, 0, 0, 0},
        {0, 0, 2, 0, 0, 0}
    };

    int parent[6];
    int key[6];
    int mstSet[6];

    for (int i = 0; i < 6; i++) {
        key[i] = 9999;
        mstSet[i] = 0;
        parent[i] = -1;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < 6 - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;

        for (int v = 0; v < 6; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int totalWeight = 0;

    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 1; i < 6; i++) {
        printf("%d -- %d == %d\n", parent[i], i, key[i]);
        totalWeight += key[i];
    }
    printf("Total weight of MST: %d\n", totalWeight);

    return 0;
}
