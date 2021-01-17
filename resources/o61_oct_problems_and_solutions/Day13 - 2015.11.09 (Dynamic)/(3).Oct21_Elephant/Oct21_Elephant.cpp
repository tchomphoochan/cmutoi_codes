#include <cstdio>
#include <algorithm>
using namespace std;

int arr[100005], dp[100005];

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i)
        scanf("%d", &arr[i]);
    /// 1th and 2nd place can't jump
    dp[3] = arr[3];
    int ma = 0, ans = 0;
    for(int i = 4; i <= N; ++i){
        ma = max(ma, dp[i-3]);
        dp[i] = ma+arr[i];
        ans = max(ans, dp[i]);
    }
    /*
    for(int i = 1; i <= N; ++i)
        printf("%d ", dp[i]);
    */
    printf("%d", ans);
    return 0;
}
