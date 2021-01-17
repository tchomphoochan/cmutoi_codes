#include <cstdio>
#include <algorithm>
using namespace std;

int arr[1005];

int main(){
    int N, A, B;
    int maW = 0;
    scanf("%d%d%d", &N, &A, &B);
    for(int i = 0; i < N; ++i){
        scanf("%d", &arr[i]);
        maW = max(maW, arr[i]);
    }
    int st = max(maW, A), mi = 1000000000, ans;
    for(int W = st; W <= B; ++W){
        int w = 0, sum = 0;
        for(int i = 0; i < N; ++i){
            if(w+arr[i] > W){
                sum+=(W-w);
                w = 0;
            }
            w+=arr[i];
        }
        sum+=(W-w);
        if(sum < mi){
            mi = sum;
            ans = W;
        }
    }
    printf("%d", ans);
    return 0;
}
