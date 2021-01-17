#include <cstdio>

bool dp[15005];

int main(){
    int type[4], N;
    scanf("%d%d%d", &type[0], &type[1], &N);
    dp[0] = true;
    for(int t = 0; t < 2; ++t){
        for(int i = 0; i <= 10000; ++i){
            if(dp[i])
                dp[i+type[t]] = true;
        }
    }
    for(int i = 0; i < N; ++i){
        int x;
        scanf("%d", &x);
        for(int j = x;; ++j){
            if(dp[j]){
                printf("%d\n", j);
                break;
            }
        }
    }
    return 0;
}
