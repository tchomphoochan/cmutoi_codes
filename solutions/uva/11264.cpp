#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1e17;
const int N = 1010;

ll c[N];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int cnt = 2;
        ll sum = 1;
        for (int i = 1; i <= n; ++i)
            scanf("%lld", &c[i]);
        for (int i = 2; i < n; ++i) {
            if (c[i]+sum < c[i+1]) {
                ++cnt;
                sum += c[i];
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}