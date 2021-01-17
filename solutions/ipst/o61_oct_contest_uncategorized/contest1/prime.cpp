#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 1e6;

int cnt[N+10];
bool comp[N+10];

int main()
{
    comp[1] = true;
    for (int i = 1; i <= N; ++i) {
        if (comp[i]) continue;
        for (int j = i; j <= N; j += i) {
            comp[j] = true;
            int x = j;
            while (x % i == 0) {
                x /= i;
                ++cnt[j];
            }
        }
    }

    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int ansi = 0, ansj = 0, ansv = 0;
    for (int i = b; i >= a; --i) {
        if (cnt[i] <= ansv) continue;
        vector<int> divs;
        for (int j = 1; j <= sqrt(i); ++j) {
            if (i % j == 0) {
                divs.push_back(j);
                if (j*j != i)
                    divs.push_back(i/j);
            }
        }
        sort(divs.begin(), divs.end(), [&] (int x, int y) {
            return cnt[x] > cnt[y];
        });
        for (auto x : divs) {
            int mn = (int)ceil(c*1.0/x);
            int mx = (int)floor(d*1.0/x);
            if (mn <= mx) {
                if (cnt[x] > ansv || (cnt[x] == ansv && i+x*mx > ansi+ansj)) {
                    ansv = cnt[x];
                    ansi = i;
                    ansj = x*mx;
                }
            }
        }
    }
    
    printf("%d %d\n", ansi, ansj);

    return 0;
}