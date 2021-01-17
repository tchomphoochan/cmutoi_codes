/**
 * toi15_budget
 * 
 * aquablitz11 (2020)
 * 100/100
 */

#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using pipii = pair<int, pii>;
using ll = long long;

const int N = 1e6+10;

pii pkg[N];
int par[N];

int root(int u) {
    if (par[u] == u)
        return u;
    return par[u] = root(par[u]);
}
bool merge(int u, int v) {
    u = root(u), v = root(v);
    if (u != v) {
        par[u] = v;
        return true;
    }
    return false;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<pipii> E;
    for (int i = 0; i < n; ++i)
        par[i] = i;
    for (int i = 0; i < m; ++i) {
        int s, t, l, r;
        scanf("%d%d%d%d", &s, &t, &l, &r);
        if (r == 1) l = 0;
        E.push_back(pipii(l, pii(s, t)));
    }
    int p;
    scanf("%d", &p);
    for (int i = 1; i <= p; ++i)
        scanf("%d%d", &pkg[i].first, &pkg[i].second);
    sort(pkg+1, pkg+p+1);
    for (int i = p-1; i >= 0; --i)
        pkg[i].second = min(pkg[i].second, pkg[i+1].second);
    /*for (int i = 0; i <= p; ++i) {
        printf("pkg %d %d\n", pkg[i].first, pkg[i].second)
    }*/
    for (int i = 0; i < m; ++i) {
        int d = E[i].first;
        int x = lower_bound(pkg, pkg+p+1, pii(d, 0))-pkg;
        E[i].first = pkg[x].second;
    }
    sort(E.begin(), E.end());
    ll ans = 0;
    for (int i = 0; i < m; ++i) {
        int u = E[i].second.first;
        int v = E[i].second.second;
        int c = E[i].first;
        if (merge(u, v))
            ans += c;
    }
    printf("%lld\n", ans);
    
    return 0;
}