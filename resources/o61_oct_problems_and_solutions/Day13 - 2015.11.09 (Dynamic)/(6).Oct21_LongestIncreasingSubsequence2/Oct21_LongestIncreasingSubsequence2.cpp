#include <cstdio>
#include <vector>
using namespace std;

int arr[100005];
vector<int> LIS;

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i)
        scanf("%d", &arr[i]);
    for(int i = 1; i <= N; ++i){
        int pos = lower_bound(LIS.begin(), LIS.end(), arr[i])-LIS.begin();
        if(pos == LIS.size())
            LIS.push_back(arr[i]);
        else
            LIS[pos] = arr[i];
    }
    printf("%d\n", LIS.size());
    return 0;
}

