#include <cstdio>
#define MOD 9241

int dp[105][105];

int main(){
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[2][0] = 2;
    dp[2][1] = 1;
    for(int i = 3; i <= 100; ++i){
        dp[i][0] = (dp[i-1][0] + dp[i-2][0])%MOD;
        for(int j = 1; j < i; ++j){
            dp[i][j] = dp[i-1][j] + dp[i-2][j] + dp[i-2][j-1];
            for(int k = 3; i-k >= 0; ++k){
                dp[i][j]+=dp[i-k][j-2]*2;
                dp[i][j]%=MOD;
            }
            dp[i][j]%=MOD;
        }
    }
    /*
    for(int i = 0; i <= 10; ++i){
        for(int j = 0; j <= i; ++j)
            printf("%d ", dp[i][j]);
        printf("\n");
    }
    //*/
    int Q;
    scanf("%d", &Q);
    while(Q--){
        int N, K, sum = 0;
        scanf("%d%d", &N, &K);
        for(int i = 0; i <= K; ++i)
            sum = (sum+dp[N][i])%MOD;
        printf("%d\n", sum);
    }
    return 0;
}
