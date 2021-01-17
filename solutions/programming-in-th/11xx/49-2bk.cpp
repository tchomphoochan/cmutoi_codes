#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

const int N = 1010;
const int INF = 1e8;

int n;
int arr[N][N];
int sx=-1, sy, tx, ty;

bool check(int lim)
{
    bool visited[N][N] = {};
    queue<ii> togo;
    togo.push({sx, sy});
    while (!togo.empty()) {
        ii going = togo.front();
        int ux = going.first;
        int uy = going.second;
        togo.pop();
        if (visited[ux][uy])
            continue;
        visited[ux][uy] = true;
        if (ux == tx && uy == ty)
            return true;
        ii nxt[] = {
            {ux-1, uy},
            {ux+1, uy},
            {ux, uy-1},
            {ux, uy+1}
        };
        for (ii v : nxt) {
            int vx = v.first;
            int vy = v.second;
            if (vx < 0 || vx >= n || vy < 0 || vy >= n
            || visited[vx][vy] || arr[vx][vy] > lim)
                continue;
            togo.push({vx, vy});
        }
    }
    return false;
}

int main()
{
    scanf("%d", &n);
    int left = INF, right = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &arr[i][j]);
            left = min(left, arr[i][j]);
            right = max(right, arr[i][j]);
            if (arr[i][j] == 0) {
                if (sx==-1) {
                    sx = i;
                    sy = j;
                } else {
                    tx = i;
                    ty = j;
                }
            }
        }
    }

    while (left < right) {
        int mid = (left+right)/2;
        if (check(mid))
            right = mid;
        else
            left = mid+1;
    }

    printf("%d", right);
    return 0;
}