/**
 * Code Jam 2020 Round 1B
 * B. Blindfolded Bullseye
 * 
 * aquablitz11 (2020-04-20)
 * The subtasks really aid the thinking process on this problem.
 * 
 * First subtask: The circle is so large and is confined in the rectangle,
 * so the bullseye could only be in the [-5,5]x[-5,5] area in the middle.
 * 
 * Second subtask: Now the middle is too large. However, note that the circle is large enough
 * so if you throw darts along x=0 and y=0 you will definitely hit some point in the circle.
 * Because we know the radius r, now we can try hitting darts in the middle area,
 * restricitng ourselves to points we know could possibly be the circle (using the distance metric).
 * 
 * Third subtask: Now the circle is small enough that x=0, y=0 is not enough.
 * We choose (+/- inf/2, +/- inf/2) and (0,0). We know at least one of these points will hit the circle.
 * Then, we can binary search on x/y line going through this point to figure out 4 (or 3) edge points of the circle.
 * Having three points, we can determine formulaically where the center is,
 * or even simpler, just approximate and then test out every point near the supposed center.
 * (I did not get this subtask during the contest because I was too busy trying to determine this algebraically.)
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9;


int cnt = 0;
int hit(int x, int y)
{
    //fprintf(stderr, "%d %d\n", x, y);
    ++cnt;
    printf("%d %d\n", x, y);
    fflush(stdout);
    char str[100];
    scanf("%s", str);
    if (!strcmp(str, "CENTER")) {
        fprintf(stderr, "answer %d %d\n", x, y);
        return 2;
    } else if (!strcmp(str, "HIT"))
        return 1;
    else if (!strcmp(str, "WRONG"))
        exit(0);
    else
        return 0;
}

bool check(int x, int y, int r, int tx, int ty)
{
    ll dx = x-tx;
    ll dy = y-ty;
    return dx*dx + dy*dy <= (ll)r*r;
}

int T, A, B;
bool solve()
{
    ll tryx[5] = {0, -INF/2, -INF/2, INF/2, INF/2};
    ll tryy[5] = {0, -INF/2, INF/2, -INF/2, INF/2};
    ll x, y;
    for (int i = 0; i < 5; ++i) {
        x = tryx[i], y = tryy[i];
        int h = hit(x,y);
        if (h==2) return true;
        if (h==1) break;
    }
    fprintf(stderr, "x=%lld, y=%lld\n", x, y);
    
    // binary search from left
    ll b = -INF, e = y;
    ll lefty = INF;
    while (b <= e) {
        ll m = (b+e)/2;
        int h = hit(x, m);
        if (h == 2) return true;
        if (h) {
            lefty = min(lefty, m);
            e = m-1;
        } else
            b = m+1;
    }

    // binary search from right
    b = y, e = INF;
    ll righty = -INF;
    while (b <= e) {
        ll m = (b+e)/2;
        int h = hit(x, m);
        if (h == 2) return true;
        if (h) {
            righty = max(righty, m);
            b = m+1;
        } else
            e = m-1;
    }

    // binary search from top
    b = -INF, e = x;
    ll topx = INF;
    while (b <= e) {
        ll m = (b+e)/2;
        int h = hit(m, y);
        if (h == 2) return true;
        if (h) {
            topx = min(topx, m);
            e = m-1;
        } else
            b = m+1;
    }

    // binary search from bottom
    b = x, e = INF;
    ll botx = -INF;
    while (b <= e) {
        ll m = (b+e)/2;
        int h = hit(m, y);
        if (h == 2) return true;
        if (h) {
            botx = max(topx, m);
            b = m+1;
        } else
            e = m-1;
    }

    fprintf(stderr, "left=%lld, right=%lld, top=%lld, bot=%lld\n", lefty, righty, topx, botx);
    ll rx = (topx+botx)/2;
    ll ry = (lefty+righty)/2;
    fprintf(stderr, "try %d %d\n", rx, ry);
    for (ll i = rx-6; i <= rx+6; ++i) {
        for (ll j = ry-6; j <= ry+6; ++j) {
            if (i >= -INF && i <= INF && j >= -INF && j <= INF) {
                fprintf(stderr, "find in %d %d\n", i, j);
                int h = hit(i, j);
                if (h == 2) return true;
            }
        }
    }

    return false;
}

int main()
{
    scanf("%d%d%d", &T, &A, &B);
    while (T--) {
        cnt = 0;
        if (A == B && A >= (int)1e9-100) {
            int minx, miny;
            for (int x = -INF; ; ++x) {
                if (hit(x, 0)) {
                    minx = x;
                    break;
                }
            }
            for (int y = -INF; ; ++y) {
                if (hit(0, y)) {
                    miny = y;
                    break;
                }
            }
            int mxy;
            for (int y = INF; ; --y) {
                if (hit(0, y)) {
                    mxy = y;
                    break;
                }
            }
            fprintf(stderr, "%d %d %d\n", miny, mxy, minx);
            bool ok = false;
            int r = min(A,B);
            for (int x = -INF+r; x <= INF-r; ++x) {
                for (int y = -INF+r; y <= INF-r; ++y) {
                    if (check(x, y, r, minx, 0) && !check(x, y, r, minx-1, 0)
                    && check(x, y, r, 0, miny) && !check(x, y, r, 0, miny-1)) {
                        if (hit(x, y) == 2) {
                            ok = true;
                            break;
                        }
                    }
                }
                if (ok) break;
            }
        } else {
            if (!solve())
                break;
        }
    }
    
    return 0;
}