#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define F first
#define S second

const int N = 20;

int n;
bool pick[N];
int a[N], b[N];
double ans = 20e6;

void bf(int i)
{
    if (i == n) {
        int ca = 0, cb = 0;
        double ta = 0, tb = 0;
        for (int j = 0; j < n; ++j) {
            if (!pick[j]) {
                ++ca;
                ta += a[j];
            } else {
                ++cb;
                tb += b[j];
            }
        }
        ta -= ta*(ca/100.0);
        tb -= tb*(cb/100.0);
        ans = min(ans, ta+tb);
    } else {
        pick[i] = false;
        bf(i+1);
        pick[i] = true;
        bf(i+1);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i)
        scanf("%d", &b[i]);
    bf(0);
    printf("%.2f\n", ans);

    return 0;
}