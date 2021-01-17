#include <cstdio>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "device.h"
using namespace std;

int arr[1505], minMax[5], mid, N;

void quickSelect(int L, int R){
    if(L >= R)
        return;
    int pivot1 = rand()%(R-L+1)+L, pivot2 = rand()%(R-L+1)+L, pivot3 = rand()%(R-L+1)+L;
    int med = Med3(arr[pivot1], arr[pivot2], arr[pivot3]);
    if(arr[pivot1] == med)
        swap(arr[pivot1], arr[L]);
    else if(arr[pivot2] == med)
        swap(arr[pivot2], arr[L]);
    else if(arr[pivot3] == med)
        swap(arr[pivot3], arr[L]);
    int i = L+1, idx = L+1;
    while(i <= R){
        med = Med3(arr[L], arr[i], arr[R+1]);
        if(med == arr[L])
            swap(arr[i], arr[idx++]);
        i++;
    }
    idx--;
    swap(arr[L], arr[idx]);
    if(idx == mid)
        return;
    else if(idx > mid){
        quickSelect(L, idx-1);
        return;
    }
    else if(idx < mid){
        quickSelect(idx+1, R);
        return;
    }
}

int main(){
    srand(time(NULL));
    int cmp, cmp2;
    N = GetN();
    mid = (N+1)/2;
    for(int i = 1; i <= N; ++i)
        arr[i] = i;
    minMax[1] = arr[1];
    minMax[2] = arr[2];
    minMax[3] = 2000;
    for(int i = 3; i <= N; ++i){
        sort(minMax+1, minMax+4);
        minMax[3] = arr[i];
        int med = Med3(minMax[1], minMax[2], minMax[3]);
        for(int j = 1; j <= 3; ++j){
            if(minMax[j] == med){
                minMax[j] = 2000;
                break;
            }
        }
    }
    sort(minMax+1, minMax+4);
    //printf("%d %d %d\n", minMax[1], minMax[2], minMax[3]);
    cmp = minMax[1];
    cmp2 = minMax[2];
    for(int i = 1; i <= N; ++i){
        if(arr[i] == cmp)
            swap(arr[i], arr[N]);
        else if(arr[i] == cmp2)
            swap(arr[i], arr[1]);
    }
    quickSelect(2, N-1);
    Answer(arr[mid]);
    return 0;
}
