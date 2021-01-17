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

    priority_queue<pii, vector<pii>, greater<pii>> Q;
    dp[1] = A[1];
    Q.push({dp[1], 1});
    for (int i = 2; i <= n; ++i) {
        dp[i] = inf;
        while (!Q.empty() && Q.top().second < i-k)
            Q.pop();
        dp[i] = Q.top().first+A[i];
        Q.push({dp[i], i});
    }

    printf("%d\n", dp[n]);
    return 0;
}