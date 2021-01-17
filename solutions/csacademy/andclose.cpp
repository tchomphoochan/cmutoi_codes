#include <bits/stdc++.h>

using namespace std;

const int N = 1<<21;
int seq[N], dp[N];

int main()
{
    for (int i = 0; i < N; ++i)
        seq[i] = i;
    sort(seq, seq+N, [&] (int a, int b) {
        return __builtin_popcount(a) > __builtin_popcount(b);
    });

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        dp[x] = ~x;
    }
    for (int x : seq) {
        for (int i = 0; i < 21; ++i) {
            int v = x|(1<<i);
            dp[x] |= dp[v];
        }
    }

    int cnt = 1;
    for (int i = 1; i < N; ++i) {
        if (dp[i] == ~i)
            ++cnt;
    }
    printf("%d\n", cnt);

    return 0;
}
