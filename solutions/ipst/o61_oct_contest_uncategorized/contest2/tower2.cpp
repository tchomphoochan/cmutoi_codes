#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int INF = 2e9;

int h[N];

int main()
{
    // subtask 1
    int n, m;
    scanf("%d%d", &n, &m);

    int curmx = 0;
    while (m--) {
        int a, b, x;
        scanf("%d%d%d", &a, &b, &x);
        for (int i = a; i <= b; ++i)
            h[i] += x;
        int mx = -INF;
        for (int i = 1; i <= n; ++i)
            mx = max(mx, h[i]);
        h[n+1] = INF+1;
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (h[i] == mx && h[i] != h[i+1])
                ++cnt;    
        }
        printf("%d %d\n", mx, cnt);
    }

    return 0;
}