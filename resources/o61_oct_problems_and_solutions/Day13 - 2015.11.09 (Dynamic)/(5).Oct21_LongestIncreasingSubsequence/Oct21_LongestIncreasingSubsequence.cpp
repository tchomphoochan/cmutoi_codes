#include <cstdio>
#include <vector>
using namespace std;

int arr[1005], FRONT[1005];
vector<int> LIS, IDX;

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i)
        scanf("%d", &arr[i]);
    for(int i = 1; i <= N; ++i){
        int pos = lower_bound(LIS.begin(), LIS.end(), arr[i])-LIS.begin();
        if(pos == LIS.size()){
            LIS.push_back(arr[i]);
            IDX.push_back(i);
        }
        else{
            LIS[pos] = arr[i];
            IDX[pos] = i;
        }
        if(pos != 0)
            FRONT[i] = IDX[pos-1];
    }
    int cur = IDX[IDX.size()-1];
    vector<int> ans;
    while(cur != 0){
        ans.push_back(cur);
        cur = FRONT[cur];
    }
    printf("%d\n", LIS.size());
    for(int i = ans.size()-1; i >= 0; --i)
        printf("%d ", arr[ans[i]]);
    return 0;
}
