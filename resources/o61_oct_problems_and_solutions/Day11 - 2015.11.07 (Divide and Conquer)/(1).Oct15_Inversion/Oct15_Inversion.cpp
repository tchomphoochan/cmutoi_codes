#include <cstdio>

int arr[100005], tmp[100005];
long long inversion;

void mergeAndCount(int L, int R){
    if(L == R)
        return;
    int mid = (L+R)/2;
    mergeAndCount(L, mid);
    mergeAndCount(mid+1, R);
    int i = L, j = mid+1, idx = L;
    while(i <= mid && j <= R){
        if(arr[j] < arr[i]){
            inversion+=(mid-i+1);
            tmp[idx++] = arr[j++];
        }
        else
            tmp[idx++] = arr[i++];
    }
    while(i <= mid)
        tmp[idx++] = arr[i++];
    while(j <= R)
        tmp[idx++] = arr[j++];
    for(int k = L; k <= R; ++k)
        arr[k] = tmp[k];
}

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &arr[i]);
    mergeAndCount(0, N-1);
    printf("%lld", inversion);
    return 0;
}
/*
5
10
40
30
50
20
*/
