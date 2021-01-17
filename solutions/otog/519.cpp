#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9-1;
const int N = 80010;
const int K = 45;

int n, k;
int arr[N];
int ft[K][N], nv[N];

void update(int i, int j, int x)
{
    for (; j <= n; j += j&(-j)) {
        ft[i][j] += x;
        ft[i][j] %= MOD;
    }
}

int query(int i, int j)
{
    int ans = 0;
    for (; j > 0; j -= j&(-j)) {
        ans += ft[i][j];
        ans %= MOD;
    }
    return ans;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        nv[i] = 1;
    }

    int ans;
    for (int i = 2; i <= k; ++i) {
        ans = 0;
        for (int j = n-1; j >= 0; --j) {
            int cnt = query(i, arr[j]-1);
            update(i, arr[j], nv[j]);
            nv[j] = cnt;
            ans += cnt;
            ans %= MOD;
        }
    }

    printf("%d\n", ans);
    return 0;
}