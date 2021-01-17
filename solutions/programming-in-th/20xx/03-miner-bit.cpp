#include <cstdio>
#include <algorithm>

#define N 100010

int n;
int food[N];
int dp[256];
int ndp[256];

inline int score2(int state, int f)
{
    bool used[] = {true, false, false, false};
    int count = 0;
    if (!used[f]) {
        used[f] = true;
        ++count;
    }
    if (!used[state&0x3]) {
        used[state&0x3] = true;
        ++count;
    }
    if (!used[(state&0xc)>>2]) {
        used[(state&0xc)>>2] = true;
        ++count;
    }
    return count;
}

inline int score1(int state, int food)
{
    return score2(state>>4, food);
}

inline int change1(int state, int to)
{
    int state2 = state & 0x0f;
    state <<= 2;
    state &= 0xc0;
    state |= (to << 4);
    return state | state2;
}

inline int change2(int state, int to)
{
    int state1 = state & 0xf0;
    int state2 = state & 0x0f;
    state2 <<= 2;
    state2 &= 0x0f;
    state2 |= to;
    return state1 | state2;
}

int main()
{
    scanf("%d ", &n);
    for (int i = 0; i < n; ++i) {
        char c;
        scanf("%c", &c);
        food[i] = c == 'M' ? 1 : (c == 'F' ? 2 : 3);
    }

    for (int i = n-1; i >= 0; --i) {

        for (int j = 0; j <= 255; ++j) {

            int give1 = score1(j, food[i]) + dp[change1(j, food[i])];
            int give2 = score2(j, food[i]) + dp[change2(j, food[i])];

            ndp[j] = std::max(ndp[j], std::max(give1, give2));

        }

        std::copy(ndp, ndp+256, dp);
        std::fill(ndp, ndp+256, 0);
    }

    printf("%d", dp[0]);
    return 0;
}