#include <bits/stdc++.h>
using namespace std;

#define for0(i, n) for (int i = 0; i < (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)

struct num {
    char a, b, c;
    int get() {
        return (int)a*10000 + (int)b*100 + (int)c;
    }
    num operator+(const num &rhs) {
        int _a = (int)a + rhs.a;
        int _b = (int)b + rhs.b;
        int _c = (int)c + rhs.c;
        while (_c >= 100) ++_b, _c -= 100;
        while (_b >= 100) ++_a, _b -= 100;
        return {(char)_a, (char)_b, (char)_c};
    }
    num operator-(const num &rhs) {
        int _a = (int)a - rhs.a;
        int _b = (int)b - rhs.b;
        int _c = (int)c - rhs.c;
        while (_c < 0) --_b, _c += 100;
        while (_b < 0) --_a, _b += 100;
        return {(char)_a, (char)_b, (char)_c};
    }
    num &operator++() {
        ++c;
        if (c == 100) ++b, c = 0;
        if (b == 100) ++a, b = 0;
    }
};

#define tl 0
#define tr 1
#define bl 2
#define br 3
const int N = 300001;
const int C = 3001;
num qs[4][C+1][C+1];
inline int sum(int t, int x1, int y1, int x2, int y2) {
    return qs[t][x2][y2].get() - qs[t][x1-1][y2].get() - qs[t][x2][y1-1].get() + qs[t][x1-1][y1-1].get();
}

int main()
{
    int n, m, x1, y1, x2, y2;
    scanf("%d%d", &n, &m);
    for0(i, n) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        ++qs[tl][x1][y1];
        ++qs[tr][x1][y2];
        ++qs[bl][x2][y1];
        ++qs[br][x2][y2];
    }
    for0(t, 4) for1(i, C) for1(j, C)
        qs[t][i][j] = qs[t][i][j] + qs[t][i-1][j] + qs[t][i][j-1] - qs[t][i-1][j-1];
    
    while (m--) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        int ans = n - sum(tl, x2+1, 1, C, C) - sum(tl, 1, y2+1, C, C) + sum(tl, x2+1, y2+1, C, C)
        - sum(br, 1, 1, C, y1-1) - sum(br, 1, 1, x1-1, C) + sum(br, 1, 1, x1-1, y1-1)
        + sum(bl, 1, y2+1, x1-1, C) + sum(tr, x2+1, 1, C, y1-1);
        printf("%d\n", ans);
    }

    return 0;
}