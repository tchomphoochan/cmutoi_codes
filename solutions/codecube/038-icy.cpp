#include <cstdio>
#include <queue>

using namespace std;

#define N 1010

int n;
bool can[N][N];
bool used[N][N];

struct ToGo
{
    int r, c, d;
    bool operator<(const ToGo &b) const
    {
        return d > b.d;
    }
};

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x;
            scanf("%d", &x);
            can[i][j] = (x != 1);
        }
    }

    priority_queue<ToGo> togo;
    togo.push({1, 1, 0});
    while (!togo.empty()) {
        auto go = togo.top();
        togo.pop();
        if (used[go.r][go.c])
            continue;
        if (go.r == n && go.c == n) {
            printf("%d", go.d);
            break;
        }
        used[go.r][go.c] = true;

        ToGo left, right, up, down;
        for (int i = go.r-1; i >= 0; --i) { // up
            if (!can[i][go.c]) {
                up = {i+1, go.c, go.d + (go.r-i-1)};
                break;
            }
        }
        for (int i = go.r+1; i <= n+1; ++i) { // down
            if (!can[i][go.c]) {
                down = {i-1, go.c, go.d + (i-go.r-1)};
                break;
            }
        }
        for (int i = go.c-1; i >= 0; --i) { // left
            if (!can[go.r][i]) {
                left = {go.r, i+1, go.d + (go.c-i-1)};
                break;
            }
        }
        for (int i = go.c+1; i <= n+1; ++i) { // right
            if (!can[go.r][i]) {
                right = {go.r, i-1, go.d + (i-go.c-1)};
                break;
            }
        }

        if (!used[left.r][left.c])
            togo.push(left);
        if (!used[right.r][right.c])
            togo.push(right);
        if (!used[up.r][up.c])
            togo.push(up);
        if (!used[down.r][down.c])
            togo.push(down);
    }

    return 0;
}