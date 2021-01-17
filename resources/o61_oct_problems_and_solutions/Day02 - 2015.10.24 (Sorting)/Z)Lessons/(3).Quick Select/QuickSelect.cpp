#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;

int arr[55];
void swap(int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
void quickSort(int L, int R){
    if(L >= R)
        return;
    int mid = (L+R)/2;
    int pivot = mid;
    int x = arr[mid], idx = L+1;
    swap(&arr[L], &arr[mid]);
    for(int i = L+1; i <= R; ++i){
        if(arr[i] < x){
            swap(&arr[i], &arr[idx++]);
        }
    }
    idx--;
    swap(&arr[L], &arr[idx]);
    quickSort(L, idx-1);
    quickSort(idx+1, R);
}

int main(){
    int N = 50;
    srand(time(NULL));
    for(int i = 0; i < 50; ++i){
        arr[i] = rand()%1000;
    }
    quickSort(0, N-1);
    for(int i = 0; i < 50; ++i)
        printf("%d ", arr[i]);
    return 0;
}
