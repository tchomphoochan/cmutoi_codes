#include <cstdio>

int arr[1005], tmp[1005];

void MergeSort(int L, int R){
    if(L == R)
        return;
    int mid = (L+R)/2;
    MergeSort(L, mid);
    MergeSort(mid+1, R);
    int i = L, j = mid+1, idx = L;
    while(i <= mid && j <= R){
        if(arr[i] <= arr[j])
            tmp[idx++] = arr[i++];
        else
            tmp[idx++] = arr[j++];
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
    printf("----------------Merge Sort----------------\n");
    printf("Enter N: ");
    scanf("%d", &N);
    printf("Enter Val: ");
    for(int i = 0; i < N; ++i)
        scanf("%d", &arr[i]);
    printf("==========================================\n");
    printf("Sorting:");
    MergeSort(0, N-1);
    for(int i = 0; i < N; ++i)
        printf(" %d", arr[i]);
    printf("\n==========================================\n");
    return 0;
}
