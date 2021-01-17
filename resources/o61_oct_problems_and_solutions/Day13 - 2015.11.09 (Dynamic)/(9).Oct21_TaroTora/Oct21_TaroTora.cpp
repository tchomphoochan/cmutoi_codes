#include <cstdio>
#include <algorithm>
#define INF 1100000000
using namespace std;
// + Taro / - Tora

int dp[2][205], N, K;
void Taro(int cur, int next, int j, int v){
    if(j+1 <= 2*K)
        dp[next][j+1] = min(dp[next][j+1], dp[cur][j]+v);
    return;
}
void Tora(int cur, int next, int j, int v){
    if(j-1 >= 0)
        dp[next][j-1] = min(dp[next][j-1], dp[cur][j]+v);
    return;
}

int main(){
    int totalCase = 1;
    while(totalCase--){
        scanf("%d%d", &N, &K);
        for(int i = 0; i <= 2*K; ++i)
            dp[0][i] = dp[1][i] = INF;
        dp[0][K] = 0;
        for(int i = 0; i < N; ++i){
            int a, b;
            int cur = i%2;
            int next = 1-cur;
            scanf("%d%d", &a, &b);
            for(int j = 0; j <= 2*K; ++j){
                if(dp[cur][j] != INF){
                    Taro(cur, next, j, a);
                    Tora(cur, next, j, b);
                    dp[cur][j] = INF;
                }
            }
        }
        int last = N%2, ans = INF;
        for(int i = 0; i <= 2*K; ++i)
            ans = min(ans, dp[last][i]);
        printf("%d\n", ans);
    }
    return 0;
}
/*
4 2
1 2
1 2
1 2
1 2

4 2
5 2
2 5
5 2
2 5
*/
