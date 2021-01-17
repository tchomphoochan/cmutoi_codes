#include <cstdio>

#define INF 1e9
#define N 1000010
#define K 20

int p, m, k;
int type[K];
int dp[N];
int from[N];
int aUse[K];
int bUse[K];

int main()
{
    scanf("%d%d%d", &p, &m, &k);
    for (int i = 0; i < k; ++i)
        scanf("%d", &type[i]);
    
    for (int i = 1; i <= m; ++i) {
        dp[i] = INF;
        for (int t = 0; t < k; ++t) {
            if (i - type[t] >= 0) {
                int newAns = dp[i - type[t]] + 1;
                if (newAns < dp[i]) {
                    dp[i] = newAns;
                    from[i] = t;
                }
            }
        }
    }

    int paid = p;
    int change = 0;
    int coinA = INF;
    int coinB = INF;
    for (int i = p; i <= m; ++i) {
        int j = i - p;
        if (dp[i] + dp[j] < coinA+coinB) {
            coinA = dp[i];
            coinB = dp[j];
            paid = i;
            change = j;
        }
    }

    printf("%d %d", coinA, coinB);

    while (paid > 0) {
        int t = from[paid];
        ++aUse[t];
        paid -= type[t];
    }
    printf("\n%d", aUse[0]);
    for (int i = 1; i < k; ++i)
        printf(" %d", aUse[i]);

    while (change > 0) {
        int t = from[change];
        ++bUse[t];
        change -= type[t];
    }
    printf("\n%d", bUse[0]);
    for (int i = 1; i < k; ++i)
        printf(" %d", bUse[i]);

    return 0;
}