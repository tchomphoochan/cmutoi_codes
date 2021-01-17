#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int arr[1005];
int q[1005];

int main(){
    int N, Q;
    scanf("%d%d", &N, &Q);
    for(int i = 1; i <= N; ++i)
        scanf("%d", &arr[i]);
    while(Q--){
        int M;
        scanf("%d", &M);
        int ma = 0, sum = 0, fir = 0, las = 0;
        for(int i = 1; i <= N; ++i){
            while(fir < las && sum+arr[i] > M){
                sum-=q[fir++];
            }
            if(sum+arr[i] <= M){
                sum+=arr[i];
                q[las++] = arr[i];
            }
            ma = max(ma, las-fir);
        }
        printf("%d\n", ma);
    }
    return 0;
}
