#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 1e8;
const int N = 100010;

int l[N], r[N], p[N], deep[N], mn[N], mx[N];

int main()
{
    int n;
    scanf("%d", &n);
    fill(mn, mn+n+1, INF);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &l[i], &r[i]);
        if (l[i] != -1)
            p[l[i]] = i;
        if (r[i] != -1)
            p[r[i]] = i;
        deep[i] = deep[p[i]]+1;
    }

    int cnt = 0;
    for (int i = n; i >= 1; --i) {

        int mnl = l[i] == -1 ? deep[i]+1 : mn[l[i]];
        int mnr = r[i] == -1 ? deep[i]+1 : mn[r[i]];

        int mxl = l[i] == -1 ? deep[i]+1 : mx[l[i]];
        int mxr = r[i] == -1 ? deep[i]+1 : mx[r[i]];

        mn[i] = min(mnl, mnr);
        mx[i] = max(mxl, mxr);

        if (mx[i]-mn[i] > 1) {
            cnt = -1;
            break;
        }

        if (mnl-1 == mxr || mnl == mxr) {

        } else if (mnr-1 == mxl || mnr == mxl) {
            ++cnt;
        } else {
            cnt = -1;
            break;
        }
    }

    printf("%d", cnt);
    return 0;
}