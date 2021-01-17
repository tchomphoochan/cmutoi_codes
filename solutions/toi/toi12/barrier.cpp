/**
 * toi12_barrier
 * 
 * aquablitz11 (2017)
 */

#include <cstdio>
#include <deque>

using namespace std;

#define INF 2e9
#define N 6000006

typedef long long ll;

int n, w;
int arr[N];
ll sum[N];
deque<int> q;

int main()
{
    scanf("%d%d", &n, &w);

    for (int i = 1; i <= n; ++i)
        scanf("%d", &arr[i]);
    for (int i = n; i >= 0; --i)
        sum[i] = sum[i+1] + arr[i];
    
    ll maxSum = 0;
    int minLen = INF;

    for (int i = 1; i <= n; ++i) {
        while (!q.empty() && q.front() <= i-w)
            q.pop_front();
        while (!q.empty() && sum[q.back()] <= sum[i])
            q.pop_back();
        q.push_back(i);
        ll ans = sum[q.front()] - sum[i+1];
        if (ans > maxSum || (ans == maxSum && i-q.front()+1 < minLen)) {
            minLen = i-q.front()+1;
            maxSum = ans;
        }
    }

    printf("%lld\n%d", maxSum, maxSum == 0 ? 0 : minLen);
    return 0;
}