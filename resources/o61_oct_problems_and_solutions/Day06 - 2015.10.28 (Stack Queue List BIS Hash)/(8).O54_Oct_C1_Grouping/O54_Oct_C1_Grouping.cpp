#include <cstdio>
#include <algorithm>
using namespace std;

int arr[10005];

int main(){
    int N, Group;
    int sum = 0, ma = 0;
    scanf("%d%d", &N, &Group);
    for(int i = 0; i < N; ++i){
        scanf("%d", &arr[i]);
        sum+=arr[i];
        ma = max(ma, arr[i]);
    }
    int L = ma, R = sum, mid, idx = -1;
    while(L <= R){
        mid = (L+R)/2;
        int g = 0, sumInGroup = 0;
        for(int i = 0; i < N; ++i){
            if(sumInGroup + arr[i] > mid){
                g++;
                sumInGroup = 0;
            }
            sumInGroup+=arr[i];
        }
        g++;
        if(g == Group){
            idx = mid;
            L = mid+1;
        }
        else if(g > Group)
            L = mid+1;
        else if(g < Group)
            R = mid-1;
    }
    if(idx == -1)
        printf("IMPOSSIBLE");
    else
        printf("%d", idx);
    return 0;
}
