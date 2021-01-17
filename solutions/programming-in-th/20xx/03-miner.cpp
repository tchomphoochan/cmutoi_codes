#include <cstdio>
#include <algorithm>

#define N 100010

int n;
int food[N];

int dp[4][4][4][4];
int ndp[4][4][4][4];

int main()
{
    scanf("%d ", &n);
    for (int i = 0; i < n; ++i) {
        char c;
        scanf("%c", &c);
        food[i] = c == 'M' ? 1 : (c == 'F' ? 2 : 3);
    }

    for (int i = n-1; i >= 0; --i) {

        for (int a = 0; a < 4; ++a) {
            for (int b = 0; b < 4; ++b) {
                for (int c = 0; c < 4; ++c) {
                    for (int d = 0; d < 4; ++d) {

                        bool used[] = {true, false, false, false};
                        used[a] = true;
                        used[b] = true;
                        used[food[i]] = true;
                        int count1 = 0;
                        for (int j = 1; j < 4; ++j) {
                            if (used[j])
                                ++count1;
                        }
                        used[1] = used[2] = used[3] = false;
                        used[c] = true;
                        used[d] = true;
                        used[food[i]] = true;
                        int count2 = 0;
                        for (int j = 1; j < 4; ++j) {
                            if (used[j])
                                ++count2;
                        }

                        int give1 = count1 + dp[b][food[i]][c][d];
                        int give2 = count2 + dp[a][b][d][food[i]];
                        ndp[a][b][c][d] = std::max(ndp[a][b][c][d],
                        std::max(give1, give2));
                    }
                }
            }
        }

        for (int a = 0; a < 4; ++a) {
            for (int b = 0; b < 4; ++b) {
                for (int c = 0; c < 4; ++c) {
                    for (int d = 0; d < 4; ++d) {
                        dp[a][b][c][d] = ndp[a][b][c][d];
                        ndp[a][b][c][d] = 0;
                    }
                }
            }
        }
    }

    printf("%d", dp[0][0][0][0]);
    return 0;
}