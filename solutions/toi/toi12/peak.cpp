/**
 * toi12_peak
 * 
 * aquablitz11 (2017)
 */

#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

#define N 5000010

int h[N];
int u[N];
int ans[N];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &h[i]);
    }

    int c = 0;
    for (int i = 1; i <= n; ++i) {
        if (h[i] > h[i-1] && h[i] > h[i+1]) {
            u[c++] = h[i];
        }
    }

    n = c;
    c = 0;
    sort(u, u+n, greater<int>());
    int lst = 0;
    for (int i = 0; i < n && c < k; ++i) {
        if (lst != u[i]) {
            lst = u[i];
            ans[c++] = u[i];
        }
    }

    if (c == 0) {
        printf("-1\n");
    } else if (c < k) {
        for (int i = c-1; i >= 0; --i)
            printf("%d\n", ans[i]);
    } else {
        for (int i = 0; i < c; ++i)
            printf("%d\n", ans[i]);
    }

    return 0;
}
