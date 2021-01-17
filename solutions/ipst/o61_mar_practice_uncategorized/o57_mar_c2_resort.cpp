#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

#define X second
#define Y first

const int N = 1010;
pii tree[N];

int main()
{
    int n, m, t;
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 1; i <= n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        tree[i] = {y, x};
    }
    sort(tree+1, tree+n+1);

    int ans = 1e6;
    for (int h = 1; h <= m; ++h) {

        int j = 1, cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (tree[i].X < h)
                ++cnt;
            while (j < i && (cnt > t || tree[j].X >= h)) {
                if (tree[j].X < h)
                    --cnt;
                ++j;
            }
            if (cnt >= t) {
                ans = min(ans, h*(tree[i].Y-tree[j].Y+1));
            }
        }

    }

    printf("%d\n", ans);
    return 0;
}