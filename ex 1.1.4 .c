#include <stdio.h>
#include <stdlib.h>
#include <limits.h>



void kruskalMST(int **cost, int V) {

	struct Edge
    {
        int u, v, w;
    };

    struct Edge edges[10000], temp;
    int parent[100];
    int edgeCount = 0;

    // Store all edges from upper triangular matrix
    for (int i = 0; i < V; i++)
    {
        for (int j = i + 1; j < V; j++)
        {
            if (cost[i][j] != 9999)
            {
                edges[edgeCount].u = i;
                edges[edgeCount].v = j;
                edges[edgeCount].w = cost[i][j];
                edgeCount++;
            }
        }
    }

    // Sort edges by weight (Bubble Sort)
    for (int i = 0; i < edgeCount - 1; i++)
    {
        for (int j = 0; j < edgeCount - i - 1; j++)
        {
            if (edges[j].w > edges[j + 1].w)
            {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    // Initialize parent array
    for (int i = 0; i < V; i++)
        parent[i] = i;

    int edgeNo = 0;
    int minCost = 0;

    // Kruskal's Algorithm
    for (int i = 0; i < edgeCount && edgeNo < V - 1; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;

        // Find root of u
        int ru = u;
        while (parent[ru] != ru)
            ru = parent[ru];

        // Find root of v
        int rv = v;
        while (parent[rv] != rv)
            rv = parent[rv];

        // If no cycle, include edge
        if (ru != rv)
        {
            parent[ru] = rv;

            printf("Edge %d:(%d, %d) cost:%d\n", edgeNo, u, v, edges[i].w);

            minCost += edges[i].w;
            edgeNo++;
        }
    }

    printf("Minimum cost= %d\n", minCost);
	
}


int main() {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        cost[i] = (int *)malloc(V * sizeof(int));

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);

    kruskalMST(cost, V);

    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);

    return 0;
}
