/**
 * toi6_gem
 * 
 * aquablitz11 (2018)
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 400010;

vector<int> G[N];
int disc[N], low[N], tick;
stack<int> S;
int sccnum[N], num;
bool ins[N];

void tarjan(int u)
{
    S.push(u);
    ins[u] = true;
    disc[u] = low[u] = ++tick;
    for (auto v : G[u]) {
        if (!disc[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (ins[v]) {
            low[u] = min(low[u], low[v]);
        }
    }
    if (disc[u] == low[u]) {
        ++num;
        while (true) {
            int v = S.top(); S.pop();
            ins[v] = false;
            sccnum[v] = num;
            if (v == u) break;
        }
    }
}

int n, m;
void add(int a, int b)
{
    if (a < 0) a = m-a;
    if (b < 0) b = m-b;
    G[a].push_back(b);
}

int main()
{
    int T = 5;
    while (T--) {

        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m+m; ++i) {
            G[i].clear();
            disc[i] = low[i] = 0;
            sccnum[i] = 0;
            ins[i] = false;
        }
        tick = num = 0;

        for (int i = 0; i < n; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            add(-a, b);
            add(-b, a);
        }
        for (int i = 0; i < m/2; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            add(a, -b);
            add(b, -a);
        }
        for (int i = 1; i <= m+m; ++i)
            if (!disc[i]) tarjan(i);
        bool ok = true;
        for (int i = 1; i <= m; ++i) {
            if (sccnum[i] == sccnum[i+m]) {
                ok = false;
                break;
            }
        }
        printf("%c", ok ? 'Y' : 'N');

    }

    return 0;
}
