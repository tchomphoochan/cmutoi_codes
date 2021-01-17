#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int INF = 1e9;

int n;
int seg[N<<1];

void build()
{
    for (int i = n-1; i > 0; --i)
        seg[i] = seg[i>>1] || seg[i>>1|1];
}

void modify(int p, int val)
{
    for (seg[p += n] = val; p > 1; p >>= 1)
        seg[p>>1] = seg[p] + seg[p^1];
}

int query(int l, int r)
{
    int ans = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) ans += seg[l++];
        if (r&1) ans += seg[--r];
    }
    return ans;
}