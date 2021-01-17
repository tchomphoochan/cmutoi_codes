#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int n, m;
int s[N], t[N];

int lis(int s[], int n)
{
    int ans[N] = {};
    int len = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 0) continue;
        if (len == 0) {
            ans[++len] = s[i];
            continue;
        }
        if (s[i] < ans[1]) {
            ans[1] = s[i];
        } else if (s[i] > ans[len]) {
            ans[++len] = s[i];
        } else {
            auto ptr = lower_bound(ans+1, ans+len+1, s[i]) - ans;
            ans[ptr] = s[i];
        }
    }
    return len;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int mxv;
        scanf("%d%d%d", &mxv, &n, &m);
        int mp[N] = {};
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &s[i]);
            mp[s[i]] = i;
            s[i] = i;
        }
        for (int i = 1; i <= m; ++i) {
            scanf("%d", &t[i]);
            t[i] = mp[t[i]];
        }
        /*for (int i = 1; i <= n; ++i)
            printf("%d ", s[i]);
        printf("\n");
        for (int i = 1; i <= n; ++i)
            printf("%d ", t[i]);
        printf("\n");*/
        printf("%d\n", lis(t, m));

    }

    return 0;
}