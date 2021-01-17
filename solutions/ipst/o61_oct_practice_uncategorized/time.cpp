#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int T = 12;

int dist(int x1, int y1, int x2, int y2)
{
    int dx = x1-x2;
    int dy = y1-y2;
    int tt = dx*dx + dy*dy;
    return (int)ceil(sqrt(tt*1.0));
}

int x[T], y[T], d[T];

int main()
{
    int n, m, t;
    scanf("%d%d%d", &n, &m, &t);

    int seq[T];
    for (int i = 0; i < t; ++i) {
        scanf("%d%d%d", &x[i], &y[i], &d[i]);
        seq[i] = i;
    }
    
    int ans = dist(0, 0, n-1, m-1);
    do {

        int lastx = 0, lasty = 0;
        int cand = 0;
        for (int i = 0; i < t; ++i) {
            cand += dist(lastx, lasty, x[seq[i]], y[seq[i]]) - d[seq[i]];
            lastx = x[seq[i]], lasty = y[seq[i]];
            ans = min(ans, cand + dist(lastx, lasty, n-1, m-1));
        }

    } while (next_permutation(seq, seq+t));

    printf("%d\n", ans);
    return 0;
}