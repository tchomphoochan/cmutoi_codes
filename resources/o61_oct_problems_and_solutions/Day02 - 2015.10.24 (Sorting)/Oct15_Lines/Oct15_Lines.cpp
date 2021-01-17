#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

long long cntInversion = 0;
pair<double, double> arr[100005], tmp[100005];
void MergeSort(int L, int R){
    if(L == R)
        return;
    int mid = (L+R)/2;
    MergeSort(L, mid);
    MergeSort(mid+1, R);
    int i = L, j = mid+1, idx = L;
    while(i <= mid && j <= R){
        if(arr[j].second > arr[i].second){
            cntInversion+=(mid-i+1);
            tmp[idx++] = arr[j++];
        }
        else
            tmp[idx++] = arr[i++];
    }
    while(i <= mid)
        tmp[idx++] = arr[i++];
    while(j <= R)
        tmp[idx++] = arr[j++];
    for(int i = L; i <= R; ++i)
        arr[i] = tmp[i];
}
bool cmp(const pair<double, double> &A, const pair<double, double> &B){
    return A.first > B.first;
}

int main(){
    int N;
    scanf("%d", &N);
    double x0, x1;
    scanf("%lf%lf", &x0, &x1);
    for(int i = 0; i < N; ++i){
        double m, c;
        scanf("%lf%lf", &m, &c);
        arr[i] = make_pair(m*x0+c, m*x1+c);
    }
    sort(arr, arr+N, cmp);
    MergeSort(0, N-1);
    printf("%lld", cntInversion);
    return 0;
}
