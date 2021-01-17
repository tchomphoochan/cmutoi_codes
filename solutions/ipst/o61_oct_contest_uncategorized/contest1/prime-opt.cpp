#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6;

int cnt[N+1];
int divs[3010];

inline int gcd(int a, int b)
{
    while (b != 0) {
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    cnt[1] = 0;
    for (int i = 2; i <= N; ++i) {
        if (cnt[i] != 0) continue;
        for (int j = i; j <= N; j += i) {
            int x = j;
            while (x % i == 0) {
                x /= i;
                ++cnt[j];
            }
        }
    }

    int a, b, c, d;
    while (scanf("%d%d%d%d", &a, &b, &c, &d) != EOF) {
        int ansi = 0, ansj = 0, ansv = 0;
        for (int i = b; i >= a; --i) {
            if (cnt[i] < ansv) continue;
            int cd = 0;
            for (int j = 1; j <= sqrt(i); ++j) {
                if (i % j == 0) {
                    divs[cd++] = j;
                    if (j*j != i)
                        divs[cd++] = (i/j);
                }
            }
            /*sort(divs.begin(), divs.end(), [&] (int x, int y) {
                return cnt[x] > cnt[y];
            });*/
            for (int j = 0; j < cd; ++j) {
                int x = divs[j];
                int mn = (int)ceil(c*1.0/x);
                int mx = (int)floor(d*1.0/x);
                if (mn <= mx) {
                    int c = cnt[x];
                    if (c > ansv || c == ansv && i+x*mx > ansi+ansj) {
                        ansv = c;
                        ansi = i;
                        ansj = x*mx;
                    }
                }
            }
        }
        printf("%d %d\n", ansi, ansj);
    }

    return 0;
}