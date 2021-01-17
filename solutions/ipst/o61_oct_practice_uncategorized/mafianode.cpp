#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int INF = 1e9;
const int N = 1000010;

int n, score[N];
pii seg[N<<1];

void update(int p, int x)
{
    for (seg[p += n-1].first += x; p > 1; p >>= 1)
        seg[p>>1] = max(seg[p], seg[p^1]);
}

void build()
{
    for (int i = 0; i < n; ++i)
        seg[n+i] = {0, i};
    for (int i = n-1; i > 0; --i)
        seg[i] = max(seg[i<<1], seg[i<<1|1]);
}

int main()
{
    int l, r;
    scanf("%d%d%d", &n, &l, &r);
    build();
    for (int q = 0; q < l+r; ++q) {
        char t;
        int x, y;
        scanf(" %c", &t);
        if (t == 'L') {
            scanf("%d%d", &x, &y);
            update(y, 1);
        } else if (t == 'C') {
            scanf("%d%d", &x, &y);
            update(y, 3);
        } else if (t == 'R') {
            printf("%d\n", seg[1].second+1);
        } else if (t == 'D') {
            update(seg[1].second+1, -INF);
        }
    }

    return 0;
}