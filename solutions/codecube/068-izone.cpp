#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+10;

int n, m, col[N];
int ft[3][N];

void update(int ft[], int i, int x)
{
    for (; i <= n; i += i&-i)
        ft[i] += x;
}

int query(int ft[], int i)
{
    int ans = 0;
    for (; i > 0; i -= i&-i)
        ans += ft[i];
    return ans;
}

void build(int ft[])
{
    for (int i = 1; i <= n; ++i)
        if (i+(i&-i) <= n)
            ft[i+(i&-i)] += ft[i];
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        col[i] = (i-1)%3;
        ++ft[col[i]][i];
    }
    build(ft[0]);
    build(ft[1]);
    build(ft[2]);

    while (m--) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int i;
            char x;
            scanf("%d %c", &i, &x);
            if (x == 'R') x = 0;
            else if (x == 'G') x = 1;
            else x = 2;
            update(ft[col[i]], i, -1);
            col[i] = x;
            update(ft[col[i]], i, 1);
        } else {
            int l, r;
            scanf("%d%d", &l, &r);
            int mx = 0, ix = 0, cnt = 0;
            for (int i = 0; i < 3; ++i) {
                int val = query(ft[i], r) - query(ft[i], l-1);
                if (val > mx) {
                    ix = i;
                    mx = val;
                    cnt = 1;
                } else if (val == mx) {
                    ++cnt;
                }
            }
            if (cnt != 1)
                printf("None\n");
            else if (ix == 0)
                printf("R\n");
            else if (ix == 1)
                printf("G\n");
            else
                printf("B\n");
        }
    }

    return 0;
}