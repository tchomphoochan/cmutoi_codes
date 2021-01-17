#include <cstdio>

int sum[100005];
int BIS(int L, int R, int f){
    int mid, idx = 0;
    while(L <= R){
        mid = (L+R)/2;
        if(sum[mid] <= f){
            idx = mid;
            L = mid+1;
        }
        else{
            R = mid-1;
        }
    }
    return idx;
}


int main(){
    int N, Q;
    scanf("%d%d", &N, &Q);
    for(int i = 1; i <= N; ++i){
        scanf("%d", &sum[i]);
        sum[i]+=sum[i-1];
    }
    while(Q--){
        int M;
        scanf("%d", &M);
        int pos = BIS(1, N, M);
        printf("%d\n", pos);
    }
    return 0;
}
