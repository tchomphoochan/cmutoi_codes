/**
 * Code Jam 2020 Qualification Round
 * A. Vestigium
 *
 * aquablitz11 (2020-04-04)
 * Direct implementation
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t<= T; ++t) {
        int n;
        scanf("%d", &n);
        int A[N][N] = {}, row[N][N] = {}, col[N][N] = {};
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                scanf("%d", &A[i][j]);
                if (i == j)
                    sum += A[i][j];
                ++row[i][A[i][j]];
                ++col[j][A[i][j]];
            }
        }
        int r = 0, c = 0;
        for (int i = 1; i <= n; ++i) {
            bool rok = true, cok = true;
            for (int j = 1; j <= n; ++j) {
                if (row[i][j] != 1) rok = false;
                if (col[i][j] != 1) cok = false;
            }
            if (!rok) ++r;
            if (!cok) ++c;
        }
        printf("Case #%d: %d %d %d\n", t, sum, r, c);

    }
    
    return 0;
}