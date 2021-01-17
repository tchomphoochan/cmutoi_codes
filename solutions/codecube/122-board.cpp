#include <cstdio>
#include <queue>
#include <algorithm>

#define N 505

using namespace std;

struct BFSInfo
{
    int i, j, w;
};

int n, m;
int si, sj, ei, ej;

char board[N][N];
bool visited[N][N];

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i) {
        scanf(" ");
        for (int j = 1; j <= m; ++j) {
            scanf("%c", &board[i][j]);
            if (board[i][j] == 'S') {
                si = i; sj = j;
            } else if (board[i][j] == 'E') {
                ei = i; ej = j;
            }
        }
    }

    queue<BFSInfo> S, J, B, P, JB, JP, BP, JBP;

    S.push({si, sj, 0});
    while (!S.empty())
    {
        BFSInfo data = S.front();
        int i = data.i;
        int j = data.j;
        int w = data.w;
        S.pop();
        if (i < 1 || i > n || j < 1 || j > m)
            continue;
        else if (board[i][j] == 'E') {
            printf("%d", w);
            return 0;
        }
        else if (visited[i][j] || board[i][j] == '#'
        || board[i][j] == 'J' || board[i][j] == 'B' || board[i][j] == 'P')
            continue;
        visited[i][j] = true;
        if (board[i][j] == 'j')
            J.push({i, j, w});
        else if (board[i][j] == 'b')
            B.push({i, j, w});
        else if (board[i][j] == 'p')
            P.push({i, j, w});
        else {
            S.push({i-1, j, w+1});
            S.push({i+1, j, w+1});
            S.push({i, j-1, w+1});
            S.push({i, j+1, w+1});
        }
    }

    for (int i = 1; i <= n; ++i)
        fill(visited[i]+1, visited[i]+m+1, false);
    while (!J.empty())
    {
        BFSInfo data = J.front();
        int i = data.i;
        int j = data.j;
        int w = data.w;
        J.pop();
        if (i < 1 || i > n || j < 1 || j > m)
            continue;
        else if (board[i][j] == 'E') {
            printf("%d", w);
            return 0;
        }
        else if (visited[i][j] || board[i][j] == '#'
        || board[i][j] == 'B' || board[i][j] == 'P')
            continue;
        visited[i][j] = true;
        if (board[i][j] == 'b')
            JB.push({i, j, w});
        else if (board[i][j] == 'p')
            JP.push({i, j, w});
        else {
            J.push({i-1, j, w+1});
            J.push({i+1, j, w+1});
            J.push({i, j-1, w+1});
            J.push({i, j+1, w+1});
        }
    }

    for (int i = 1; i <= n; ++i)
        fill(visited[i]+1, visited[i]+m+1, false);
    while (!B.empty())
    {
        BFSInfo data = B.front();
        int i = data.i;
        int j = data.j;
        int w = data.w;
        B.pop();
        if (i < 1 || i > n || j < 1 || j > m)
            continue;
        else if (board[i][j] == 'E') {
            printf("%d", w);
            return 0;
        }
        else if (visited[i][j] || board[i][j] == '#'
        || board[i][j] == 'J' || board[i][j] == 'P')
            continue;
        visited[i][j] = true;
        if (board[i][j] == 'j')
            JB.push({i, j, w});
        else if (board[i][j] == 'p')
            BP.push({i, j, w});
        else {
            B.push({i-1, j, w+1});
            B.push({i+1, j, w+1});
            B.push({i, j-1, w+1});
            B.push({i, j+1, w+1});
        }
    }

    for (int i = 1; i <= n; ++i)
        fill(visited[i]+1, visited[i]+m+1, false);
    while (!P.empty())
    {
        BFSInfo data = P.front();
        int i = data.i;
        int j = data.j;
        int w = data.w;
        P.pop();
        if (i < 1 || i > n || j < 1 || j > m)
            continue;
        else if (board[i][j] == 'E') {
            printf("%d", w);
            return 0;
        }
        else if (visited[i][j] || board[i][j] == '#'
        || board[i][j] == 'J' || board[i][j] == 'B')
            continue;
        visited[i][j] = true;
        if (board[i][j] == 'j')
            JP.push({i, j, w});
        else if (board[i][j] == 'b')
            BP.push({i, j, w});
        else {
            P.push({i-1, j, w+1});
            P.push({i+1, j, w+1});
            P.push({i, j-1, w+1});
            P.push({i, j+1, w+1});
        }
    }

    for (int i = 1; i <= n; ++i)
        fill(visited[i]+1, visited[i]+m+1, false);
    while (!JB.empty())
    {
        BFSInfo data = JB.front();
        int i = data.i;
        int j = data.j;
        int w = data.w;
        JB.pop();
        if (i < 1 || i > n || j < 1 || j > m)
            continue;
        else if (board[i][j] == 'E') {
            printf("%d", w);
            return 0;
        }
        else if (visited[i][j] || board[i][j] == '#' || board[i][j] == 'P')
            continue;
        visited[i][j] = true;
        if (board[i][j] == 'p')
            JBP.push({i, j, w});
        else {
            JB.push({i-1, j, w+1});
            JB.push({i+1, j, w+1});
            JB.push({i, j-1, w+1});
            JB.push({i, j+1, w+1});
        }
    }

    for (int i = 1; i <= n; ++i)
        fill(visited[i]+1, visited[i]+m+1, false);
    while (!JP.empty())
    {
        BFSInfo data = JP.front();
        int i = data.i;
        int j = data.j;
        int w = data.w;
        JP.pop();
        if (i < 1 || i > n || j < 1 || j > m)
            continue;
        else if (board[i][j] == 'E') {
            printf("%d", w);
            return 0;
        }
        else if (visited[i][j] || board[i][j] == '#' || board[i][j] == 'B')
            continue;
        visited[i][j] = true;
        if (board[i][j] == 'b')
            JBP.push({i, j, w});
        else {
            JP.push({i-1, j, w+1});
            JP.push({i+1, j, w+1});
            JP.push({i, j-1, w+1});
            JP.push({i, j+1, w+1});
        }
    }

    for (int i = 1; i <= n; ++i)
        fill(visited[i]+1, visited[i]+m+1, false);
    while (!BP.empty())
    {
        BFSInfo data = BP.front();
        int i = data.i;
        int j = data.j;
        int w = data.w;
        BP.pop();
        if (i < 1 || i > n || j < 1 || j > m)
            continue;
        else if (board[i][j] == 'E') {
            printf("%d", w);
            return 0;
        }
        else if (visited[i][j] || board[i][j] == '#' || board[i][j] == 'J')
            continue;
        visited[i][j] = true;
        if (board[i][j] == 'j')
            JBP.push({i, j, w});
        else {
            BP.push({i-1, j, w+1});
            BP.push({i+1, j, w+1});
            BP.push({i, j-1, w+1});
            BP.push({i, j+1, w+1});
        }
    }

    for (int i = 1; i <= n; ++i)
        fill(visited[i]+1, visited[i]+m+1, false);
    while (!JBP.empty())
    {
        BFSInfo data = JBP.front();
        int i = data.i;
        int j = data.j;
        int w = data.w;
        JBP.pop();
        if (i < 1 || i > n || j < 1 || j > m)
            continue;
        else if (board[i][j] == 'E') {
            printf("%d", w);
            return 0;
        }
        else if (visited[i][j] || board[i][j] == '#')
            continue;
        visited[i][j] = true;
        JBP.push({i-1, j, w+1});
        JBP.push({i+1, j, w+1});
        JBP.push({i, j-1, w+1});
        JBP.push({i, j+1, w+1});
    }

    printf("-1");
    return 0;
}