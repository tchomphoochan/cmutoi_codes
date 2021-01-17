/**
 * toi10_map
 * 
 * aquablitz11 (2017)
 * 100/100
 */

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Data
{
    int n;
    char c;
};

#define N 40010
#define M 410

vector<Data> G[N];
int board[M][M];

struct BFSData
{
    int n, r, c;
};

char opp(char c)
{
    if (c == 'L')
        return 'R';
    else if (c == 'R')
        return 'L';
    else if (c == 'U')
        return 'D';
    else if (c == 'D')
        return 'U';
}

bool visited[N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n*m-1; ++i) {
        int u, v;
        char c;
        scanf("%d %c%d", &u, &c, &v);
        G[u].push_back({v, c});
        G[v].push_back({u, opp(c)});
    }

    int l, r, u, d;
    l = r = u = d = 201;
    queue<BFSData> togo;
    togo.push({0, 201, 201});
    while (!togo.empty()) {
        BFSData dt = togo.front();
        togo.pop();
        if (visited[dt.n])
            continue;    
        visited[dt.n] = true;
        board[dt.r][dt.c] = dt.n;
        l = min(l, dt.c);
        r = max(r, dt.c);
        u = min(u, dt.r);
        d = max(d, dt.r);
        for (auto v : G[dt.n]) {
            if (visited[v.n])
                continue;
            if (v.c == 'L')
                togo.push({v.n, dt.r, dt.c+1});
            else if (v.c == 'R')
                togo.push({v.n, dt.r, dt.c-1});
            else if (v.c == 'U')
                togo.push({v.n, dt.r+1, dt.c});
            else if (v.c == 'D')
                togo.push({v.n, dt.r-1, dt.c});
        }
    }

    for (int i = u; i <= d; ++i) {
        for (int j = l; j <= r; ++j) {
            printf("%d", board[i][j]);
            if (j != r)
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}