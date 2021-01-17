#include <cstdio>
#include <algorithm>
#define INF 2000000000
using namespace std;

int arr[505][505], dp[505][505];

int main(){
    int totalCase;
    scanf("%d", &totalCase);
    while(totalCase--){
        int R, C;
        scanf("%d%d", &R, &C);
        for(int i = 1; i <= R; ++i){
            dp[i][0] = dp[i][C+1] = INF;
            for(int j = 1; j <= C; ++j){
                scanf("%d", &arr[i][j]);
            }
        }
        for(int j = 1; j <= C; ++j)
            dp[1][j] = arr[1][j];
        for(int i = 2; i <= R; ++i){
            for(int j = 1; j <= C; ++j){
                dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i-1][j+1])+arr[i][j];
            }
        }
        /*
        for(int i = 1; i <= R; ++i){
            for(int j = 1; j <= C; ++j)
                printf("%d ", dp[i][j]);
            printf("\n");
        }
        */
        int ans = INF;
        for(int j = 1; j <= C; ++j)
            ans = min(ans, dp[R][j]);
        printf("%d\n", ans);
    }
    return 0;
}
