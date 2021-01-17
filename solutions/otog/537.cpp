#include <bits/stdc++.h>

using namespace std;

const int N = 300010;
const int B = 120;

int n, q;
int parent[N];
vector<int> G[N];
int color[N];

vector<int> order;
int cnt[N];
int where[N];

void dfs(int u)
{
    cnt[u] = 1;
    order.push_back(u);
    for (auto v : G[u]) {
        dfs(v);
        cnt[u] += cnt[v];
    }
}

bitset<B> seg[4*N];

void init(int pos, int begin, int end)
{
    if (begin == end) {
        seg[pos].flip(color[order[begin]]);
    } else {
        int mid = (begin+end)/2;
        init(2*pos+1, begin, mid);
        init(2*pos+2, mid+1, end);
        seg[pos] = seg[2*pos+1] ^ seg[2*pos+2];
    }
}

bitset<B> query(int left, int right, int pos, int begin, int end)
{
    if (begin > right || end < left)
        return bitset<B>();
    if (begin >= left && end <= right)
        return seg[pos];
    
    int mid = (begin+end)/2;
    bitset<B> l = query(left, right, 2*pos+1, begin, mid);
    bitset<B> r = query(left, right, 2*pos+2, mid+1, end);
    return l^r;
}

void update(int tg, int upd)
{
    int pos = 0;
    int begin = 0;
    int end = n-1;
    while (begin < end) {
        seg[pos].flip(upd);
        int mid = (begin+end)/2;
        if (tg <= mid) {
            end = mid;
            pos = 2*pos+1;
        } else {
            begin = mid+1;
            pos = 2*pos+2;
        }
    }
    seg[pos].flip(upd);
}

int main()
{
    scanf("%d%d", &n, &q);
    for (int u = 1; u <= n; ++u)
        scanf("%d", &color[u]);
    for (int u = 2; u <= n; ++u) {
        scanf("%d", &parent[u]);
        G[parent[u]].push_back(u);
    }

    dfs(1);
    for (int i = 0; i < n; ++i)
        where[order[i]] = i;

    init(0, 0, n-1);
    while (q--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a == 0) {
            printf("%d\n", query(where[b], where[b]+cnt[b]-1, 0, 0, n-1).count());
        } else {
            update(where[b], color[b]);
            color[b] = a;
            update(where[b], color[b]);
        }
    }

    return 0;
}