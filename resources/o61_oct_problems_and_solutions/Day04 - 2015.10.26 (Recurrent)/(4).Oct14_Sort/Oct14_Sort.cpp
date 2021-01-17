#include <cstdio>
using namespace std;

int arr[1005], tmp[1005];
class point{
public:
    int idx, i, j;
    point(int idx, int i, int j){
        this->idx = idx;
        this->i = i;
        this->j = j;
    }
};

point mergeArr(int idx, int i, int j, int mid, int R){
    if(i > mid || j > R)
        return point(idx, i, j);
    if(arr[i] < arr[j]){
        tmp[idx] = arr[i];
        return mergeArr(idx+1, i+1, j, mid, R);
    }
    else{
        tmp[idx] = arr[j];
        return mergeArr(idx+1, i, j+1, mid, R);
    }
}
void recCmpI(int idx, int i, int mid){
    if(i > mid)
        return;
    tmp[idx] = arr[i];
    recCmpI(idx+1, i+1, mid);
}
void recCmpJ(int idx, int j, int R){
    if(j > R)
        return;
    tmp[idx] = arr[j];
    recCmpI(idx+1, j+1, R);
}
void copyToTmp(int i, int R){
    if(i > R)
        return;
    arr[i] = tmp[i];
    copyToTmp(i+1, R);
}
void mergeSort(int L, int R){
    if(L == R)
        return;
    int mid = (L+R)/2;
    mergeSort(L, mid);
    mergeSort(mid+1, R);
    point P = mergeArr(L, L, mid+1, mid, R);
    recCmpI(P.idx, P.i, mid);
    recCmpJ(P.idx, P.j, R);
    copyToTmp(L, R);
}

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &arr[i]);
    mergeSort(0, N-1);
    for(int i = 0; i < N; ++i)
        printf("%d\n", arr[i]);
    return 0;
}
