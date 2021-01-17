#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
vector<int> G[N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int a, b, g1, g2;
            scanf("%d%d%d%d", &a, &b, &g1, &g2);
        } else {
            int a, b, c;
            scanf("%d%d%d%d", &a, &b, &c);
        }
    }

    return 0;
}