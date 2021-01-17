#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int from;
    int to;
    int weight;
} Edge;

int n, m;
int disjoint[100001] = {};
Edge oedges[1000000];
int edgeIX[1000000] = {};

#define edges(i) (oedges[edgeIX[i]])

int cmpfunc(const void *a, const void *b)
{
    return (oedges[*(int*)a].weight - oedges[*(int*)b].weight);
}

int findSet(int point)
{
    int curr = point;
    while (disjoint[curr] > 0)
        curr = disjoint[curr];
    if (curr != point)
        disjoint[point] = curr;
    return curr;
}

int unionSet(int a, int b)
{
    int ap = findSet(a);
    int bp = findSet(b);
    int ar = -disjoint[ap];
    int br = -disjoint[bp];
    int rank;
    if (ar < br)
    {
        rank = (disjoint[bp] -= disjoint[ap] + 1);
        disjoint[ap] = bp;
    }
    else
    {
        rank = (disjoint[ap] -= disjoint[bp] + 1);
        disjoint[bp] = ap;
    }
    return rank;
}

int main(void)
{
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        edgeIX[i] = i;
        scanf("%d%d%d", &oedges[i].from, &oedges[i].to, &oedges[i].weight);
    }
    qsort(edgeIX, m, sizeof(int), &cmpfunc);

    for (int i = 0; i < m; i++)
    {
        if (findSet(edges(i).from) == findSet(edges(i).to))
            continue;
        
        printf("%d %d\n", edges(i).from, edges(i).to);
        if (unionSet(edges(i).from, edges(i).to) == n - 1)
            break;
    }

    return 0;
}