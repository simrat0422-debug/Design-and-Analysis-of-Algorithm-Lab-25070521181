Bellman Ford Algorithm
ex 1.1.7 
#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000
#define MAXV 1000
#define MAXE 10000

typedef struct
{
    int u;
    int v;
    int w;
} Edge;

int main()
{
    int V, E;
    int i, j;
    int src;

    scanf("%d", &V);
    scanf("%d", &E);

    Edge edges[MAXE];

    for(i = 0; i < E; i++)
    {
        scanf("%d %d %d",
              &edges[i].u,
              &edges[i].v,
              &edges[i].w);
    }

    scanf("%d", &src);

    int dist[MAXV + 1];
}
