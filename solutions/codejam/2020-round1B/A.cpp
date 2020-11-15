/**
 * Code Jam 2020 Round 1B
 * A. Expogo
 * 
 * aquablitz11 (2020-04-19)
 * Finding a direct greedy solution is hard. Instead, we mathematically compute
 * the distance from (x1,y1) to (x2,y2) in step k. Then, using this information,
 * we can greedily choose the move that respects this distance metric.
 * (If the distance suddenly grows, then we know we are taking the wrong path.)
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

ll dist(ll x1, ll y1, ll x2, ll y2, ll k)
{
    if (x1 == x2 && y1 == y2)
        return 0;
    //printf("%d %d %d %d %d\n", x1, y1, x2, y2, k);
    ll x = abs(x1-x2);
    ll y = abs(y1-y2);
    ll diag = x+y;
    //printf("%d\n", diag);
    if (x % k != 0 || y % k != 0 || diag % k != 0) return INF;
    diag /= k;
    if (diag % 2 == 0) return INF;
    ll sum = 0;
    for (ll i = 0; ; ++i) {
        sum += (1<<i);
        if (diag <= sum) {
            return i+1;
        }
    }
}

char dc[4] = {'W', 'E', 'S', 'N'};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        ll tx, ty;
        scanf("%lld%lld", &tx, &ty);
        printf("Case #%d: ", t);
        ll sx = 0, sy = 0, d = dist(sx, sy, tx, ty, 1);
        if (d == INF) {
            printf("IMPOSSIBLE\n", t);
            continue;
        }
        for (ll k = 0; sx != tx || sy != ty; ++k) {
            //printf("At %d %d\n", sx, sy);
            bool ok = false;
            for (int t = 0; t < 4 && !ok; ++t) {
                ll nx = sx+(1<<k)*dx[t];
                ll ny = sy+(1<<k)*dy[t];
                if (dist(nx, ny, tx, ty, (1<<(k+1))) == d-k-1) {
                    ok = true;
                    sx = nx;
                    sy = ny;
                    printf("%c", dc[t]);
                }
            }
        }
        printf("\n");
    }

    return 0;
}