#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, m;
int ft[N];

int query(int x)
{
    int ans = 0;
    for (; x > 0; x -= x&-x)
        ans += ft[x];
    return ans;
}

void update(int i, int x)
{
    for (; i <= n; i += i&-i)
        ft[i] += x;
}

int main()
{
    scanf("%d%d", &n, &m);

    while (m--) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int x, y, v;
            scanf("%d%d%d", &x, &y, &v);
            update(x, v);
            update(y+1, -v);
        } else {
            int x;
            scanf("%d", &x);
            printf("%d\n", query(x));
        }
    }

    return 0;
}