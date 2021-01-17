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
        //printf("FROM: State%d J%d -> S:%d J:%d\n", state, jump, state+i, i);
        mi = min(mi, rec(state+i, i));
    }
    return dp[state][jump] = mi+arr[state];
}

int main(){
    scanf("%d%d", &N, &K);
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= K; ++j)
            dp[i][j] = -1;
        scanf("%d", &arr[i]);
    }
    int ans = INF;
    for(int i = 1; i < K; ++i)
        ans = min(ans, rec(i, i));
    printf("%d", ans);
    return 0;
}
/*
6 3
1 9 1 1 9 1

6 4
1 9 1 1 9 1
*/
