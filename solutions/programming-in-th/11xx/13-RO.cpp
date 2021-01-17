#include <cstdio>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 1e6+10;

int n, k;
char s[N];
unordered_map<ll, int> f;

int main()
{
    scanf("%d%d %s", &n, &k, s+1);
    ll qs = 0;
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'R')
            qs -= k;
        else
            ++qs;
        if (f[qs] == 0 && qs != 0)
            f[qs] = i;
        else
            mx = max(mx, i-f[qs]);
    }

    printf("%d", mx);
    return 0;
}