#include <stdio.h>

int m, n, k;

#define TOTAL 1501 

int place[TOTAL][TOTAL] = {};
int sum[TOTAL][TOTAL] = {};

int TL[TOTAL][TOTAL] = {};
int TR[TOTAL][TOTAL] = {};
int BL[TOTAL][TOTAL] = {};
int BR[TOTAL][TOTAL] = {};

int max(int a, int b) { return a > b ? a : b; }
int max3(int a, int b, int c) { return max(a, max(b, c)); }
int qsum(int t, int l, int b, int r) { return sum[b][r] - sum[t][r] - sum[b][l] + sum[t][l]; }

int down(int c)
{
    int best = 0;
    for (int i = 1; i <= m-k+1; ++i) {
        best = max(best, qsum(i-1, c-1, i+k-1, c+k-1));
    }
    return best;
}

int right(int r)
{
    int best = 0;
    for (int i = 1; i <= n-k+1; ++i) {
        best = max(best, qsum(r-1, i-1, r+k-1, i+k-1));
    }
    return best;
}

int main(void)
{
    // input
    scanf("%d%d%d", &m, &n, &k);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &place[i][j]);
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + place[i][j];
        }
    }

    for (int i = k; i <= m; ++i) {
        // TL
        for (int j = k; j <= n; ++j)
            TL[i][j] = max3(TL[i-1][j], TL[i][j-1], qsum(i-k, j-k, i, j));
        // TR
        for (int j = n-k+1; j >= 1; --j)
            TR[i][j] = max3(TR[i-1][j], TR[i][j+1], qsum(i-k, j-1, i, j+k-1));
    }
    for (int i = m-k+1; i >= 1; --i) {
        // BL
        for (int j = k; j <= n; ++j)
            BL[i][j] = max3(BL[i+1][j], BL[i][j-1], qsum(i-1, j-k, i+k-1, j));
        // BR
        for (int j = n-k+1; j >= 1; --j)
            BR[i][j] = max3(BR[i+1][j], BR[i][j+1], qsum(i-1, j-1, i+k-1, j+k-1));
    }

    int best = 0;
    for (int i = k; i <= m-k; ++i) {
        // case 1 cut
        for (int j = k; j <= n-k; ++j) {
            best = max(best, TL[i][j] + TR[i][j+1] + BR[i+1][1]);
            best = max(best, TR[i-1][1] + BL[i][j] + BR[i][j+1]);
            best = max(best, TL[i][j] + BL[i+1][j] + BR[1][j+1]);
            best = max(best, BL[1][j] + TR[i][j+1] + BR[i+1][j+1]);
        }
        // case 2 horizontal cut
        best = max(best, TR[i][1] + BR[i+k+1][1] + right(i+1));
    }
    // case 2 vertical cut
    for (int j = k; j <= n-k; ++j) {
        best = max(best, BL[1][j] + BR[1][j+k+1] + down(j+1));
    }

    printf("%d", best);

    return 0;
}