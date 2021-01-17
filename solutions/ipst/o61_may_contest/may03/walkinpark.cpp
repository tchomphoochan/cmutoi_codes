#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define F first
#define S second
#define forx(i, x, y) for (int i = (x); i <= (y); ++i)
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define rofx(i, x, y) for (int i = x; i >= y; --i)
#define rofn(i, n) for (int i = n-1; i >= 0; --i)
#define rof1(i, n) for (int i = n; i >= 1; --i)
#define fora(x, v) for (auto x : v)
#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)

const int K = 220;

int n, k, q;
vector<int> xcoor, ycoor;

inline vector<int> expand_coord(vector<int> &coor)
{
    sort(all(coor));
    coor.resize(unique(all(coor)) - coor.begin());
    vector<int> ncoor;
    ncoor.pb(1);
    fora(x, coor) {
        if (x != ncoor.back())
            ncoor.pb(x);
        if (x+1 <= n)
            ncoor.pb(x+1);
    }
    return ncoor;
}

inline int getxb(int x) {
    return upper_bound(all(xcoor), x)-1 - xcoor.begin();
}
inline int getyb(int y) {
    return upper_bound(all(ycoor), y)-1 - ycoor.begin();
}

int X[K], Y[K];
bool bhas[K][K], _visited[K][K];
int _dist[K][K], tim[K][K], tick;
int sx, sy, tx, ty;

inline bool &visited(int i, int j) {
    if (tim[i][j] != tick) {
        tim[i][j] = tick;
        _visited[i][j] = false;
        _dist[i][j] = 1e9;
    }
    return _visited[i][j];
}
inline int &dist(int i, int j) {
    if (tim[i][j] != tick) {
        tim[i][j] = tick;
        _visited[i][j] = false;
        _dist[i][j] = 1e9;
    }
    return _dist[i][j];
}

struct State {
    int bx, by, rx, ry, d; // block x,y, real x,y, distance
    State up() {
        State ns;
        if (bx-1 < 0 || bhas[bx-1][by]) {
            ns.d = -1;
        } else {
            ns.bx = bx-1;
            ns.by = by;
            ns.rx = xcoor[bx]-1;
            ns.ry = ry;
            ns.d = d + rx-(xcoor[bx]-1);
        }
        return ns;
    }
    State down() {
        State ns;
        if (bx+1 >= xcoor.size() || bhas[bx+1][by]) {
            ns.d = -1;
        } else {
            ns.bx = bx+1;
            ns.by = by;
            ns.rx = xcoor[bx+1];
            ns.ry = ry;
            ns.d = d + (xcoor[bx+1]-rx);
        }
        return ns;
    }
    State left() {
        State ns;
        if (by-1 < 0 || bhas[bx][by-1]) {
            ns.d = -1;
        } else {
            ns.bx = bx;
            ns.by = by-1;
            ns.rx = rx;
            ns.ry = ycoor[by]-1;
            ns.d = d + ry-(ycoor[by]-1);
        }
        return ns;
    }
    State right() {
        State ns;
        if (by+1 >= ycoor.size() || bhas[bx][by+1]) {
            ns.d = -1;
        } else {
            ns.bx = bx;
            ns.by = by+1;
            ns.rx = rx;
            ns.ry = ycoor[by+1];
            ns.d = d + (ycoor[by+1]-ry);
        }
        return ns;
    }
    const int dist() const {
        return d+abs(rx-tx)+abs(ry-ty);
    }
    bool operator<(const State &rhs) const {
        return dist() > rhs.dist(); // for heap
    }
};

using data = pair<pii, int>;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
inline int calc(int x, int y) {
    return dist(x,y) + abs(tx-x) + abs(ty-y);
}
int main2()
{
    forn(i, k) {
        int x, y;
        scanf("%d%d", &x, &y);
        bhas[x][y] = true;
    }
    while (q--) {
        ++tick;
        scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
        deque<pii> Q;
        dist(sx, sy) = 0;
        Q.push_front({sx, sy});
        while (!Q.empty()) {
            pii u = Q.front();
            Q.pop_front();
            forn(i, 4) {
                int nx = u.F+dx[i];
                int ny = u.S+dy[i];
                int nd = dist(u.F, u.S)+1;
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && !bhas[nx][ny] && nd < dist(nx, ny)) {
                    dist(nx, ny) = nd;
                    if (Q.empty() || nd < dist(Q.front().F, Q.front().S))// calc(nx, ny) < calc(Q.front().F, Q.front().S))
                        Q.push_front(pii(nx, ny));
                    else
                        Q.push_back(pii(nx, ny));
                }
            }
        }
        int ans = dist(tx, ty);
        if (ans >= 1e9) ans = -1;
        printf("%d\n", ans);
    }
    return 0;
}

int main()
{
    scanf("%d%d%d", &n, &k, &q);
    if (n <= 200) {
        main2();
        return 0;
    }
    forn(i, k) {
        int x, y;
        scanf("%d%d", &x, &y);
        X[i] = x, Y[i] = y;
        xcoor.pb(x);
        ycoor.pb(y);
    }
    xcoor = expand_coord(xcoor);
    ycoor = expand_coord(ycoor);
    forn(i, k) {
        int x = X[i], y = Y[i];
        bhas[getxb(x)][getyb(y)] = true;
    }
    while (q--) {
        ++tick;
        scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
        priority_queue<State> Q;
        Q.push({getxb(sx), getyb(sy), sx, sy, 0});
        dist(getxb(sx), getyb(sy)) = 0;
        int ans = 1e9;
        int txb = getxb(tx), tyb = getyb(ty);
        while (!Q.empty()) {
            State u = Q.top();
            Q.pop();
            //if (u.dist() > 300000)
                //continue;
            if (u.bx == txb && u.by == tyb) {
                //printf("block (%d,%d), position (%d,%d), dist = %d\n", u.bx, u.by, u.rx, u.ry, u.d);
                ans = min(ans, u.dist());
                //printf("setmin! min now = %d\n", ans);
                break;
            }
            if (visited(u.bx,u.by))
                continue;
            //printf("at block (%d,%d), position (%d,%d), dist = %d\n", u.bx, u.by, u.rx, u.ry, u.d);
            visited(u.bx,u.by) = true;
            State vs[] = {u.up(), u.down(), u.left(), u.right()};
            fora(&v, vs) {
                if (v.d != -1 && !visited(v.bx,v.by) && v.d < dist(v.bx,v.by)) {
                    dist(v.bx,v.by) = v.d;
                    Q.push(v);
                }
            }
        }
        if (ans >= 1e9) ans = -1;
        printf("%d\n", ans);
    }

    return 0;
}