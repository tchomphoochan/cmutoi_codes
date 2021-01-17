#include <iostream>
#include <algorithm>

using namespace std;

struct Store
{
    int x, y, z;
    int a, b, c;

    // i fucking need this for permutation
    bool operator<(const Store &other) const
    {
        return this->dist(0, 0, 0) < other.dist(0, 0, 0);
    }

    int dist(int x2, int y2, int z2) const
    {
        return ((x - x2) * (x - x2)) + ((y - y2) * (y - y2)) + ((z - z2) * (z - z2));
    }

    int dist(const Store &other) const
    {
        return dist(other.x, other.y, other.z);
    }
};

Store stores[10];
int n, m, sx, sy, sz;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> sx >> sy >> sz >> m;
    for (int i = 0; i < m; i++)
    {
        Store &s = stores[i];
        cin >> s.x >> s.y >> s.z >> s.a >> s.b >> s.c;
    }

    sort(stores, stores + m);
    int best = 2e9;
    do
    {
        int a = n - stores[0].a;
        int b = n - stores[0].b;
        int c = n - stores[0].c;
        int cost = stores[0].dist(sx, sy, sz);
        for (int i = 0; (i < m - 1) && (a > 0 || b > 0 || c > 0); i++)
        {
            a -= stores[i + 1].a;
            b -= stores[i + 1].b;
            c -= stores[i + 1].c;
            cost += stores[i].dist(stores[i + 1]);
        }
        best = min(best, cost);
    }
    while (next_permutation(stores, stores + m));
    
    cout << best;
}