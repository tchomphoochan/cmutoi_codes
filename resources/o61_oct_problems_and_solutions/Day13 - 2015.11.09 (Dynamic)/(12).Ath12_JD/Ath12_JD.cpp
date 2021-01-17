#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> LIS;
pair<int, int> arr[100005];
bool cmp(const pair<int, int> &A, const pair<int, int> &B){
    if(A.first == B.first)
        return A.second < B.second;
    return A.first < B.first;
}
int bis(int L, int R, int fnd){
    //printf("L%d R%d\n", L, R);
    if(R == -1)
        return 0;
    if(LIS[R] <= fnd)
        return R+1;
    int mid, idx = 0, tmpR = R;
    while(L <= R){
        mid = (L+R)/2;
        if(LIS[mid] > fnd){
            idx = mid;
            R = mid-1;;
        }
        else
            L = mid+1;
    }
    //printf("IDX %d %d -> %d %d\n", idx, tmpR, LIS[idx], fnd);
    return idx;
}

int main(){
    int N;
    while(scanf("%d", &N) && N){
        LIS.clear();
        for(int i = 0; i < N; ++i)
            scanf("%d%d", &arr[i].first, &arr[i].second);
        sort(arr, arr+N, cmp);
        for(int i = 0; i < N; ++i){
            int pos = bis(0, LIS.size()-1, arr[i].second);
            /*
            for(int j = 0; j < LIS.size(); ++j)
                printf("%d ", LIS[j]);
            printf("\nPOS:%d\n", pos);
            */
            if(pos == LIS.size())
                LIS.push_back(arr[i].second);
            else
                LIS[pos] = arr[i].second;
        }
        printf("%d\n", LIS.size());
    }
    return 0;
}
/*
2
1 3
2 4
3
1 3
2 2
3 1
3
1 1
1 1
1 1
4
1 2
7 6
3 9
5 4
0
*/
