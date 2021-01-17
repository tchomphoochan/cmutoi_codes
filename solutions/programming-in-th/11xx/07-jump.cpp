#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1000010;
const int INF = 1e9;

int n, k, p;
int b[N];

bool check(int x)
{
    int d = k;
    for (int i = 0; i < n; ++i) {
        if (b[i] > x) {
            if (--d < 0)
                return false;
            i += p-1;
        }
    }
    return true;
}

int main()
{
    scanf("%d%d%d", &n, &k, &p);
    int l = INF, r = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
        l = min(l, b[i]);
        r = max(r, b[i]);
    }

    while (l < r) {
        int mid = (l+r)/2;
        if (check(mid))
            r = mid;
        else
            l = mid+1;
    }

    printf("%d", r);
    return 0;
}