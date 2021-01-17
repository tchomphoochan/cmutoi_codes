#include <cstdio>
#include <algorithm>
#include <deque>

using namespace std;

typedef long long ll;

const int N = 1000010;

ll A[N], qs[N], dp[N];

int main()
{
    int n;
    ll k;
    scanf("%d%lld", &n, &k);

    deque<int> q;
    for (int i = 2; i <= n+1; ++i) {
        scanf("%lld", &A[i]);
        qs[i] = qs[i-1]+A[i];
        while (!q.empty() && dp[i-2]-qs[i-1] >= dp[q.back()-2]-qs[q.back()-1])
            q.pop_back();
        q.push_back(i);
        while (!q.empty() && qs[i]-qs[q.front()-1] > k)
            q.pop_front();
        if (!q.empty())
            dp[i] = qs[i]-qs[q.front()-1]+dp[q.front()-2];
        dp[i] = max(dp[i-1], dp[i]);
    }

    printf("%lld", dp[n+1]);
    return 0;
}