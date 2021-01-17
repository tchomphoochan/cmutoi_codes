#include <cstdio>
#define MOD 2009

int dp[55][55];

int main(){
    for(int i = 1; i <= 50; ++i)
        dp[i][0] = dp[i][i-1] = 1;
    for(int i = 3; i <= 50; ++i){
        for(int j = 1; j < i-1; ++j){
            dp[i][j]+=dp[i-1][j-1];
            for(int m = 1; m < i-1; ++m){
                for(int l = 0; l < m; ++l){
                    int m2 = i-m-1, l2 = j-l-1;
                    dp[i][j]+=(dp[m][l]*dp[m2][l2]);
                    dp[i][j]%=MOD;
                }
            }
            dp[i][j]+=dp[i-1][j];
            dp[i][j]%=MOD;
        }
    }
    /*
    for(int i = 1; i <= 10; ++i){
        for(int j = 0; j < i; ++j)
            printf("%d ", dp[i][j]);
        printf("\n");
    }
    //*/
    int Q;
    scanf("%d", &Q);
    while(Q--){
        int N, K, sum = 0;
        scanf("%d%d", &N, &K);
        printf("%d\n", dp[N][K]);
    }
    return 0;
}
