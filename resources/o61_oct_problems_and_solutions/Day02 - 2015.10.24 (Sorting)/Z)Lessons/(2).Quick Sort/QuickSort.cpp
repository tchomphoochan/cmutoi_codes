#include <cstdio>
#include <algorithm>
using namespace std;
int arr[1005], N;

void QuickSort(int L, int R){
    if(L >= R)
        return;
    int mid = (L+R)/2;
    int pivot;
    ///Find median of (L, mid, R) to be a pivot
    if(arr[L] < arr[mid]){
        if(arr[mid] < arr[R])
            pivot = mid;
        else if(arr[L] < arr[R])
            pivot = R;
        else
            pivot = L;
    }
    else if(arr[mid] < arr[R]){
        if(arr[R] < arr[L])
            pivot = R;
        else if(arr[mid] < arr[L])
            pivot = L;
        else
            pivot = mid;
    }
    else if(arr[R] < arr[L]){
        if(arr[L] < arr[mid])
            pivot = L;
        else if(arr[R] < arr[mid])
            pivot = mid;
        else
            pivot = R;
    }
    /*
    if(arr[L] <= arr[mid] && arr[mid] <= arr[R] || arr[R] <= arr[mid] && arr[mid] <= arr[L])
        pivot = mid;
    else if(arr[mid] <= arr[L] && arr[L] <= arr[R] || arr[R] <= arr[L] && arr[L] <= arr[mid])
        pivot = L;
    else if(arr[mid] <= arr[R] && arr[R] <= arr[L] || arr[L] <= arr[R] && arr[R] <= arr[mid])
        pivot = R;
    */
    int x = arr[pivot], idx = L+1;
    swap(arr[L], arr[pivot]);
    for(int i = L+1; i <= R; ++i){
        if(arr[i] < x)
            swap(arr[i], arr[idx++]);
    }
    idx--;
    swap(arr[L], arr[idx]);
    QuickSort(L, idx-1);
    QuickSort(idx+1, R);
}

void QuickSort2(int L, int R){
    if(L >= R)
        return;
    int mid = (L+R)/2;
    int pivot;
    ///Find median of (L, mid, R) to be a pivot
    if(arr[L] < arr[mid]){
        if(arr[mid] < arr[R])
            pivot = mid;
        else if(arr[L] < arr[R])
            pivot = R;
        else
            pivot = L;
    }
    else if(arr[mid] < arr[R]){
        if(arr[R] < arr[L])
            pivot = R;
        else if(arr[mid] < arr[L])
            pivot = L;
        else
            pivot = mid;
    }
    else if(arr[R] < arr[L]){
        if(arr[L] < arr[mid])
            pivot = L;
        else if(arr[R] < arr[mid])
            pivot = mid;
        else
            pivot = R;
    }
    int i = L, j = R, x = arr[pivot];
    while(i <= j){
        while(arr[i] < x)
            i++;
        while(arr[j] > x)
            j--;
        if(i <= j)
            swap(arr[i++], arr[j--]);
    }
    if(L < j)
        QuickSort2(L, j);
    if(i < R)
        QuickSort2(i, R);
}

int main(){
    printf("----------------Quick Sort----------------\n");
    printf("Enter N: ");
    scanf("%d", &N);
    printf("Enter Val: ");
    for(int i = 0; i < N; ++i)
        scanf("%d", &arr[i]);
    printf("==========================================\n");
    printf("Sorting:");
    QuickSort2(0, N-1);
    for(int i = 0; i < N; ++i)
        printf(" %d", arr[i]);
    printf("\n==========================================\n");
    return 0;
}
