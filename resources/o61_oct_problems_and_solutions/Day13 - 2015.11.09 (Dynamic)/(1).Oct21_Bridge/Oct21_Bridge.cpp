#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int north[3005], gSouth[3005];
pair<int, int> dp[3005];

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i)
        scanf("%d", &north[i]);
    for(int i = 1; i <= N; ++i){
        int x;
        scanf("%d", &x);
        gSouth[x] = i;
    }
    int ans = 0;
    for(int i = 1; i <= N; ++i){
        int ma = 0, last = gSouth[north[i]];
        for(int j = 1; j < i; ++j){
            if(dp[j].first > ma && dp[j].second < last)
                ma = dp[j].first;
        }
        dp[i] = make_pair(ma+1, last);
        ans = max(ans, ma+1);
        //printf("(%d,%d)\n", dp[i].first, dp[i].second);
    }
    printf("%d", ans);
    return 0;
}
/*
5
3
1
5
2
4
1
2
5
4
3
*/
