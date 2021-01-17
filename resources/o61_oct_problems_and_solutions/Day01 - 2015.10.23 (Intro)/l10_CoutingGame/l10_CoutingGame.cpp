#include <cstdio>
#include <algorithm>
#define INF 1000000000
using namespace std;

bool can[15];
int dp[1005];

int main(){
    int N;
    scanf("%d", &N);
    dp[2] = INF;
    for(int i = 3; i <= 6; ++i)
        dp[i] = 1;
    for(int i = 7; i <= N; ++i){
        for(int j = 2; j <= 5; ++j)
            if(i%j != 0)
                can[j] = true;
            else
                can[j] = false;
        int tmp = i;
        while(tmp > 0){
            can[tmp%10] = false;
            tmp/=10;
        }
        int mi = INF;
        //printf("%dCAN: ", i);
        for(int j = 2; j <= 5; ++j){
            if(can[j]){
                //printf("%d ", j);
                mi = min(mi, dp[i-j]+1);
            }
        }
        dp[i] = mi;
    }
    if(dp[N] == INF)
        printf("-1");
    else
        printf("%d", dp[N]);
    return 0;
}
