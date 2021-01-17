#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int N = 1000010;

int fx[N], fy[N], tx[N], ty[N], mnd[N], cnt[2*N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i)
        scanf("%d%d", &fx[i], &fy[i]);
    for (int i = 0; i < m; ++i)
        scanf("%d%d", &tx[i], &ty[i]);
        
    fill(mnd, mnd+m, INF);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int d = abs(fx[i]-tx[j]) + abs(fy[i]-ty[j]);
            mnd[j] = min(mnd[j], d);
        }
    }

    int mx = 0;
    for (int i = 0; i < m; ++i) {
        mx = max(mx, ++cnt[mnd[i]]);
    }

    printf("%d", mx);

    return 0;
}