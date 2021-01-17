/**
 * toi8_electricity
 * 
 * aquablitz11 (2020)
 */

#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

const int N = 500010;
const int inf = 1e9;

int A[N], dp[N];

int main() {

    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &A[i]);

    // dp[i] = min(dp[i-1], dp[i-2], ... dp[i-k]) + A[i]

    deque<pii> Q;
    dp[1] = A[1];
    for (int i = 2; i <= n; ++i) {
        while (!Q.empty() && Q.back().first > dp[i-1])
            Q.pop_back();
        Q.push_back({dp[i-1], i-1});
        while (!Q.empty() && Q.front().second < i-k)
            Q.pop_front();
        dp[i] = A[i] + Q.front().first;
    }

    printf("%d\n", dp[n]);
    return 0;

}