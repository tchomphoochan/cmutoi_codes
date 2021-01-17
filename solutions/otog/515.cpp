#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int INF = 1e9;
const int K = 18;
const int N = 1<<K;
const int L = 7;

int k, l, logk, mid;
ii link[L];

int depth(int u)
{
    for (int i = k-1; i >= 0; --i) {
        if ((1<<i) & u)
            return i;
    }
    exit(1);
}

int ancestor(int u, int k)
{
    int ans = u>>k;
    return ans == 0 ? 1 : ans;
}

int lca(int x, int y)
{
    if (x < y)
        swap(x, y);
    int lx = depth(x);
    int ly = depth(y);

    for (int i = logk; i >= 0; --i) {
        int mov = (1<<i);
        if (lx-mov >= ly) {
            x = ancestor(x, mov);
            lx -= mov;
        }
    }
    
    if (x == y)
        return x;
    
    for (int i = logk; i >= 0; --i) {
        int mov = (1<<i);
        if (ancestor(x, mov) != ancestor(y, mov)) {
            x = ancestor(x, mov);
            y = ancestor(y, mov);
            lx -= mov;
            ly -= mov;
        }
    }

    return ancestor(x, 1);
}

int isSameTree(int x, int y)
{
    return (x < mid) == (y < mid);
}

int dist(int x, int y)
{
    if (!isSameTree(x, y))
        return INF;
    if (x > mid) {
        x -= mid;
        y -= mid;
    }
    int d = lca(x, y);
    int ld = depth(d);
    int lx = depth(x);
    int ly = depth(y);
    return lx+ly-2*ld;
}

int ans;
int pdist[L][L][2][2];

int follow(int x, int y, int uselink)
{
    if (uselink == -1)
        return dist(x, y);
    
    ii &lnk = link[uselink];
    if (isSameTree(lnk.first, x)) {
        int d = dist(x, lnk.first);
        return d + 1 + follow(lnk.second, y, uselink-1);
    } else {
        int d = dist(x, lnk.second);
        return d + 1 + follow(lnk.first, y, uselink-1);
    }
}

int solveold(int x, int y)
{
    ans = dist(x, y);
    do {
        for (int i = 0; i < l; ++i) {
            ans = min(ans, follow(x, y, i));
        }
    } while (next_permutation(link, link+l));
    return ans;
}

int solve(int x, int y)
{
    int ans = dist(x, y);
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < l; ++j) {
            int d1 = dist(x, link[i].first) + pdist[i][j][0][0] + dist(link[j].first, y);
            int d2 = dist(x, link[i].first) + pdist[i][j][0][1] + dist(link[j].second, y);
            int d3 = dist(x, link[i].second) + pdist[i][j][1][0] + dist(link[j].first, y);
            int d4 = dist(x, link[i].second) + pdist[i][j][1][1] + dist(link[j].second, y);
            ans = min(ans, min(min(d1, d2), min(d3, d4)));
        }
    }
    return ans;
}

int main()
{
    int q;
    scanf("%d%d%d", &k, &l, &q);
    mid = 1<<k;
    logk = depth(k);

    for (int i = 0; i < l; ++i) {
        scanf("%d%d", &link[i].first, &link[i].second);
    }
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < l; ++j) {
            pdist[i][j][0][0] = solveold(link[i].first, link[j].first);
            pdist[i][j][0][1] = solveold(link[i].first, link[j].second);
            pdist[i][j][1][0] = solveold(link[i].second, link[j].first);
            pdist[i][j][1][1] = solveold(link[i].second, link[j].second);
        }
    }
    
    while (q--) {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", solve(x, y));
    }

    return 0;
}