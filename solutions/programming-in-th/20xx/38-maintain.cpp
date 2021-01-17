#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

struct Edge
{
    int from;
    int to;
    int dist;

    Edge() { }
    Edge(int u, int v, int d)
    {
        from = u;
        to = v;
        dist = d;
    }

    bool operator<(const Edge &other) const
    {
        return dist < other.dist;
    }
};

Edge edgeArr[6000];

//struct cmpfunc : binary_function<int, int, bool>
//{
    bool cmpfunc(const int &a, const int &b)
    {
        return !(edgeArr[a] < edgeArr[b]);
    }
//};

int n, w;
vector<int> *edges;
vector<int> *mst;

int disjoint[201] = {};

int findSet(int point)
{
    if (disjoint[point] <= 0)
        return point;
    
    disjoint[point] = findSet(disjoint[point]);
    return disjoint[point];
}

int rank(int point)
{
    int rep = findSet(point);
    return -disjoint[rep];
}

void unionSet(int a, int b)
{
    int arep = findSet(a);
    int brep = findSet(b);

    if (arep == brep)
        return;

    int arank = rank(arep);
    int brank = rank(brep);

    if (arank < brank)
    {
        disjoint[brep] -= arank + 1;
        disjoint[arep] = brep;
    }
    else
    {
        disjoint[arep] -= brank + 1;
        disjoint[brep] = arep;
    }
}

bool spanning = false;
int kruskal(Edge newEdge)
{
    if (!spanning)
    {
        unionSet(newEdge.from, newEdge.to);
        if (rank(newEdge.from) < n - 1)
            return -1;
        else
            spanning = true;
    }

    memset(disjoint, 0, sizeof(int) * (n + 1));
    mst = new vector<int>();
    (*mst).reserve(w);

    int length = 0;
    while (!(*edges).empty())
    {
        pop_heap((*edges).begin(), (*edges).end(), cmpfunc);
        int i = (*edges)[(*edges).size() - 1];
        const Edge &edge = edgeArr[i];
        (*edges).pop_back();
        if (findSet(edge.from) == findSet(edge.to))
            continue;
        
        length += edge.dist;
        (*mst).push_back(i);
        push_heap((*mst).begin(), (*mst).end(), cmpfunc);
        unionSet(edge.from, edge.to);

        if (rank(edge.from) == n - 1)
            break;
    }

    delete edges;
    edges = mst;
    return (rank(1) != (n - 1) ? -1 : length);
}

int main()
{

    scanf("%d%d", &n, &w);
    edges = new vector<int>;
    (*edges).reserve(w);
    for (int i = 0; i < w; i++)
    {
        int u, v, d;
        scanf("%d%d%d", &u, &v, &d);
        Edge newEdge(u, v, d);
        edgeArr[i] = newEdge;
        (*edges).push_back(i);
        push_heap((*edges).begin(), (*edges).end(), cmpfunc);

        printf("%d\n", kruskal(newEdge));
    }

    return 0;
}