#include <cstdio>
#include <algorithm>
#include <cstring>
#define INF 1500000000
using namespace std;

int dp[1004][28][28];
char inp[1005];

int main(){
    int totalCase;
    /*
    for(int i = 0; i <= 3; ++i){
        for(int j = 0; j < 26; ++j){
            printf("%c -> %c (%d) (%d)\n", i+'A', j+'A', abs(j-i), 26-abs(j-i));
        }
    }
    */
    scanf("%d", &totalCase);
    while(totalCase--){
        memset(dp, 0, sizeof(dp));
        scanf("%s", &inp);
        for(int i = 0; inp[i] != NULL; ++i){
            for(int j = 0; j < 26; ++j){
                for(int k = 0; k < 26; ++k){
                    dp[i][j][k] = INF;
                }
            }
        }
        dp[0][inp[0]-'A'][0] = dp[0][0][inp[0]-'A'] = min(inp[0]-'A', 26-(inp[0]-'A'));
        int len = 1;
        for(int i = 1; inp[i] != NULL; ++i){
            int Old = inp[i-1]-'A';
            int New = inp[i]-'A';
            //printf("%c->%c\n", Old+'A', New+'A');
            for(int j = 0; j < 26; ++j){
                if(dp[i-1][Old][j] != INF){
                    //printf("F:%c S:%c (%d)\n", Old+'A', j+'A', dp[i-1][Old][j]);
                    dp[i][Old][New] = min(dp[i][Old][New], min(abs(j-New), 26-abs(j-New))+dp[i-1][Old][j]);
                    dp[i][New][j] = min(dp[i][New][j], min(abs(Old-New), 26-abs(Old-New))+dp[i-1][Old][j]);
                }
                if(dp[i-1][j][Old] != INF){
                    dp[i][New][Old] = min(dp[i][New][Old], min(abs(j-New), 26-abs(j-New))+dp[i-1][j][Old]);
                    dp[i][j][New] = min(dp[i][j][New], min(abs(Old-New), 26-abs(Old-New))+dp[i-1][j][Old]);
                }
            }
            len++;
        }
        int ans = INF, last = inp[len-1]-'A';
        //printf("LEN: %d %c\n", len-1, last+'A');
        for(int j = 0; j < 26; ++j){
            ans = min(ans, min(dp[len-1][last][j], dp[len-1][j][last]));
        }
        printf("%d\n", ans);
    }
    return 0;
}
