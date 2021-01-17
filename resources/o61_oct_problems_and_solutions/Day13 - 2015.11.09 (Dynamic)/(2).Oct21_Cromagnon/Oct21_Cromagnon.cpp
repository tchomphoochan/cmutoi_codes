#include <cstdio>
#define MOD 2009

int mul[25][25], arr[105], dp[105][105][25];

int main(){
    int K;
    scanf("%d", &K);
    for(int i = 0; i < K; ++i)
        for(int j = 0; j < K; ++j)
            scanf("%d", &mul[i][j]);
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i){
        scanf("%d", &arr[i]);
        dp[i][i][arr[i]]++;
        //dp[i-1][i][mul[arr[i-1]][arr[i]]]++;
    }
    for(int i = N-1; i >= 1; --i){
        for(int j = i+1; j <= N; ++j){
            for(int k = i; k < j; ++k){
                for(int m = 0; m < K; ++m){
                    if(dp[i][k][m]){
                        for(int l = 0; l < K; ++l){
                            if(dp[k+1][j][l]){
                                //printf("%d->%d(%d) & %d->%d(%d) == %d->%d(%d)\n", i, k, m, k+1, j, l, i, j, mul[m][l]);
                                dp[i][j][mul[m][l]]+=(dp[i][k][m]*dp[k+1][j][l]);
                                dp[i][j][mul[m][l]]%=MOD;
                            }
                        }
                    }
                }
            }
        }
    }
    for(int i = 0; i < K; ++i){
        printf("%d\n", dp[1][N][i]%MOD);
    }
    return 0;
}
