#include <cstdio>
#define MOD 9901

bool cant[1005][1005];
int dp[1005][1005], arr[1005];

int main(){
    int N, M, len = 1;
    scanf("%d%d", &N, &M);
    for(int i = 1; i <= N; ++i){
        int x;
        scanf("%d", &x);
        for(int j = len; j < len+x; ++j)
            arr[j] = i;
        len+=x;
    }
    len--;
    /*
    for(int i = 1; i <= len; ++i)
        printf("%d ", arr[i]);
    printf("\n");
    */
    while(M--){
        int x;
        scanf("%d", &x);
        for(int i = 1; i <= x; ++i)
            cant[arr[x]+1][i] = true;
        for(int i = x; i <= len; ++i)
            cant[arr[x]-1][i] = true;
    }
    dp[1][1] = 1;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= len; ++j){
            if(!cant[i][j+1])
                dp[i][j+1]+=dp[i][j];
            if(!cant[i+1][j+1])
                dp[i+1][j+1]+=dp[i][j];
            dp[i][j+1]%=MOD;
            dp[i+1][j+1]%=MOD;
        }
    }
    /*
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= len; ++j){
            printf("%2d ", dp[i][j]);
        }
        printf("\n");
    }
    //*/
    printf("%d", dp[N][len]%MOD);
    return 0;
}
/*
3 2
3
1
7
2
4

3 2
3
1
7
3
4

4 0
2
2
2
2
*/
