#include <cstdio>
#include <algorithm>
#define SIZE 3000
#define INF 1000000000
using namespace std;

int arr[SIZE+5], dp[SIZE+5][SIZE+5], N, K;

int rec(int state, int jump){
    if(jump > K)
        return INF;
    if(state >= N+1)
        return 0;
    //printf("S:%d Jump:%d\n", state, jump);
    if(dp[state][jump] != -1)
        return dp[state][jump];
    int mi = INF;
    for(int i = 1; i <= K-jump; ++i){
        //printf("NOW: State%d J%d -> S:%d J:%d\n", state, jump, state+i, i);
        mi = min(mi, rec(state+i, i));
    }
    return dp[state][jump] = mi+arr[state];
}

int main(){
    scanf("%d%d", &N, &K);
    for(int i = 1; i <= N; ++i){
        scanf("%d", &arr[i]);
    }
    dp[0][0] = 0;
    dp[1][1] = arr[1];
    for(int i = 2; i <= N; ++i){
        for(int j = 1; j < K && i-j >= 0; ++j){
            dp[i][j] = INF;
            //printf("(%d,%d) -> ", i, j);
            for(int k = 1; k+j <= K && k <= i-j; ++k){
                //printf("(%d,%d)%d ", i-j, k, dp[i-j][k]);
                dp[i][j] = min(dp[i][j], dp[i-j][k]+arr[i]);
            }
            //printf("\n");
        }
    }
    int ans = INF;
    for(int i = N-K+1; i <= N; ++i){
        for(int j = 1; j < K; ++j){
            if(dp[i][j] < ans){
                ans = dp[i][j];
                //printf("%d %d\n", i, j);
            }
        }
    }
    printf("%d", ans);
    return 0;
}
/*
#include <cstdio>
#define SIZE 3000
#define INF 1000000000

int arr[SIZE+5], dp[2][(SIZE*1000)+5];

int min(int a, int b){
    return a<b? a:b;
}
int max(int a, int b){
    return a>b? a:b;
}

int main(){
    int N, K;
    scanf("%d%d", &N, &K);
    for(int i = 1; i <= N; ++i)
        scanf("%d", &arr[i]);
    dp[0] = 0;
    for(int i = 1; i <= N; ++i){
        dp[i] = INF;
        for(int j = max(i-K+1, 0); j < i; ++j){
            dp[i] = min(dp[i], arr[i]+dp[j]);
        }
    }
    int ans = INF;
    for(int i = N-K+1; i <= N; ++i)
        ans = min(ans, dp[i]);
    printf("%d", dp[N]);
    return 0;
}
*/
/*
6 3
1 9 1 1 9 1

6 4
1 9 1 1 9 1
*/

