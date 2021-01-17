#include <iostream>
#include <algorithm>

using namespace std;

#define bound(r, c) (r >= 0 && r < n && c >= 0 && c < m)

int n, m;
bool visited[30][30] = {};

int dfs(int r, int c)
{
    if (!bound(r, c) || visited[r][c])
        return 0;
    
    visited[r][c] = true;
    return 1 + dfs(r - 1, c) + dfs(r + 1, c) + dfs(r, c - 1) + dfs(r, c + 1);
}

int main()
{
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char got;
            cin >> got;

            if (got == '#')
            {
                visited[i][j] = true;
                if (bound(i - 1, j))
                    visited[i - 1][j] = true;
                if (bound(i + 1, j))
                    visited[i + 1][j] = true;
                if (bound(i, j - 1))
                    visited[i][j - 1] = true;
                if (bound(i, j + 1))
                    visited[i][j + 1] = true;
            }
        }
    }

    int best = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            best = max(best, dfs(i, j));
    }

    cout << best;
}