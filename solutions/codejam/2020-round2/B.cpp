/**
 * Code Jam 2020 Round 2
 * B. Security Update
 * 
 * aquablitz11 (2020-05-16)
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 110;
const int M = 1010;
const int INF = 1e6;

int dist[N], par[N], want[N];
bool inlist[N];
int Gix[N][N], ans[M];

int main()
{
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; ++tc) {

        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 2; i <= n; ++i)
            scanf("%d", &want[i]);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                Gix[i][j] = 0;
            }
            inlist[i] = false;
            dist[i] = INF;
        }
        for (int i = 1; i <= m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            Gix[u][v] = i;
            Gix[v][u] = i;
            ans[i] = INF;
        }
        // CHECK RESET EVERYTHING

        int covered = 1;
        dist[1] = 0;
        inlist[1] = true;

        int mxtime = 0;
        while (covered < n) {


            for (int v = 1; v <= n; ++v) {
                if (inlist[v]) continue;
                for (int u = 1; u <= n; ++u) {
                    if (inlist[u] && Gix[u][v] && dist[u] != INF) {
                        inlist[v] = 1;
                        par[v] = u;
                        break;
                    }
                }
            }

            int fnd = 0;
            int ocovered = covered;
            for (int v = 1; v <= n; ++v) {
                if (inlist[v] && dist[v] == INF && -want[v] == ocovered) {
                    int u = par[v];
                    dist[v] = mxtime+1;
                    ans[Gix[u][v]] = (mxtime+1) - dist[u];
                    ++fnd;
                    ++covered;
                }
            }
            if (fnd) {
                ++mxtime;
                continue;
            }

            int mnwant = INF;
            for (int v = 1; v <= n; ++v) {
                if (want[v] > 0 && inlist[v] && dist[v] == INF)
                    mnwant = min(mnwant, want[v]);
            }
            for (int v = 1; v <= n; ++v) {
                if (want[v] == mnwant) {
                    int u = par[v];
                    ans[Gix[u][v]] = mnwant-dist[u];
                    dist[v] = mnwant;
                    mxtime = max(mxtime, dist[v]);
                    ++covered;
                }
            }

        }

        printf("Case #%d:", tc);
        for (int i = 1; i <= m; ++i)
            printf(" %d", ans[i]);
        printf("\n");
    }
    
    return 0;
}