#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define F first
#define S second

const int N = 1010;
int m[N], f[N];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &m[i], &f[i]);
    for (int i = 0; i < n; ++i) {
        for (int j = i; j <= i+k && j < n && m[i] > 0; ++j) {
            if (m[i] >= f[j]) {
                m[i] -= f[j];
                f[j] = 0;
            } else {
                f[j] -= m[i];
                m[i] = 0;
            }
        }
        for (int j = i; j <= i+k && j < n && f[i] > 0; ++j) {
            if (f[i] >= m[j]) {
                f[i] -= m[j];
                m[j] = 0;
            } else {
                m[j] -= f[i];
                f[i] = 0;
            }
        }
        if (m[i] > 0 || f[i] > 0) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");

    return 0;
}