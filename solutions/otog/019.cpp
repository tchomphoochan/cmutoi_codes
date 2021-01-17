#include <bits/stdc++.h>

using namespace std;

const int N = 30;

int n, m;
char table[N][N];
char word[N];

bool check(int x, int y, int dx, int dy)
{
    int len = strlen(word);
    for (int i = 0; i < len; ++i) {
        int nx = x+dx*i;
        int ny = y+dy*i;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            return false;
        if (tolower(table[nx][ny]) != tolower(word[i]))
            return false;
    }
    return true;
}

void solve()
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    if (di == 0 && dj == 0)
                        continue;
                    if (check(i, j, di, dj)) {
                        printf("%d %d\n", i, j);
                        return;
                    }
                }
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf(" %s", table[i]);
    }

    int q;
    scanf("%d", &q);
    while (q--) {
        scanf(" %s", word);
        solve();
    }

    return 0;
}