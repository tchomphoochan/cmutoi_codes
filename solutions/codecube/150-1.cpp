#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int N = 100010;
const int L2 = 20;
const int L3 = 15;
const int L5 = 10;

int arr[N], dp[L2][L3][L5], ndp[L2][L3][L5];

void factorize(int x, int &f2, int &f3, int &f5)
{
    f2 = 0, f3 = 0, f5 = 0;
    while (x % 2 == 0) {
        x /= 2;
        ++f2;
    }
    while (x % 3 == 0) {
        x /= 3;
        ++f3;
    }
    while (x % 5 == 0) {
        x /= 5;
        ++f5;
    }
}

int main()
{
    int n, t;
    scanf("%d%d", &n, &t);

    for (int i = 0; i < L2; ++i) {
        for (int j = 0; j < L3; ++j) {
            for (int k = 0; k < L5; ++k)
                dp[i][j][k] = ndp[i][j][k] = INF;
        }
    }

    dp[0][0][0] = 0;
    int score = 0, turn = 0;
    for (int ix = 0; ix < n; ++ix) {
        scanf("%d", &arr[ix]);
        int f2, f3, f5;
        factorize(arr[ix], f2, f3, f5);
        if (dp[f2][f3][f5] < INF) {
            ++score;
            turn += dp[f2][f3][f5];
        } else {

            ndp[f2][f3][f5] = 1;
            for (int cnt = 1, c2 = f2, c3 = f3, c5 = f5;
            c2 < L2 && c3 < L3 && c5 < L5;
            c2 += f2, c3 += f3, c5 += f5, ++cnt) {
                for (int i = 0; i < L2; ++i) {
                    for (int j = 0; j < L3; ++j) {
                        for (int k = 0; k < L5; ++k) {
                            if (i-c2 >= 0 && j-c3 >= 0 && k-c5 >= 0)
                                ndp[i][j][k] = min(ndp[i][j][k], dp[i-c2][j-c3][k-c5]+cnt);
                        }
                    }
                }
            }

            for (int i = 0; i < L2; ++i) {
                for (int j = 0; j < L3; ++j) {
                    for (int k = 0; k < L5; ++k)
                        dp[i][j][k] = min(dp[i][j][k], ndp[i][j][k]);
                }
            }

        }
    }

    if (t == 1)
        printf("%d\n", score);
    else
        printf("%d %d\n", score, turn);

    return 0;
}