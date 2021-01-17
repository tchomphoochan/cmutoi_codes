#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
typedef pair<int, int> pii;

const int INF = 1e9;
const int N = 210;
const int M = 28;

int n, m;
int dp[N][N][M];
int cost[M][M];
int type[M];
vector<pii> ways[M];
char str[N];

void solve()
{
    int ans = INF;
    char ac = 'a';
    for (int z = 1; z <= n; ++z) {
        for (int i = 0; i < n-z+1; ++i) {
            int j = i+z-1;
            for (int _ = 0; _ < m; ++_) {
                int c = type[_];
                dp[i][j][c] = INF;
                if (z == 1) {
                    if (c == str[i]-'a')
                        dp[i][j][c] = 0;
                    continue;
                }
                for (int k = i; k < j; ++k) {
                    for (size_t __ = 0; __ < ways[c].size(); ++__) {
                        //for (auto w : ways[c]) {
                            pii w = ways[c][__];
                            int f, s;
                            f = w.first;
                            s = w.second;
                            dp[i][j][c] = min(dp[i][j][c], dp[i][k][f] + dp[k+1][j][s] + cost[f][s]);
                        //}
                    }
                }
                if (z == n && dp[i][j][c] < ans) {
                    ans = dp[i][j][c];
                    ac = c+'a';
                }
            }
        }
    }
    printf("%d-%c\n", ans, ac);

}

int main()
{
    while (true) {

        scanf("%d", &m);
        if (m == 0) break;

        for (int i = 0; i < m; ++i) {
            scanf(" %c", &type[i]);
            type[i] -= 'a';
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                int t;
                char _, g;
                scanf(" %d%c%c", &t, &_, &g);
                ways[(int)g-'a'].push_back(mp(type[i], type[j]));
                cost[type[i]][type[j]] = t;
            }
        }

        int q;
        scanf("%d", &q);
        while (q--) {
            scanf(" %s", str);
            n = strlen(str);
            solve();
        }
        
        printf("\n");

        for (int i = 0; i < m; ++i)
            ways[type[i]].clear();

    }
    return 0;
}