#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > vec;
int bis(int L, int R, int f){
    int idx = -1, mid;
    while(L <= R){
        mid = (L+R)/2;
        if(vec[mid].first <= f){
            L = mid+1;
            idx = mid;
        }
        else
            R = mid-1;
    }
    return idx;
}

int main(){
    int N, M, x;
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        a++;
        b--;
        vec.push_back(make_pair(a, 1));
        vec.push_back(make_pair(b+1, -1));
    }
    sort(vec.begin(), vec.end());
    printf("P:%d V:%d\n", vec[0].first, vec[0].second);
    for(int i = 1; i < vec.size(); ++i){
        vec[i].second+=vec[i-1].second;
        printf("P:%d V:%d\n", vec[i].first, vec[i].second);
    }
    int sum = 0;
    for(int i = 0; i < M; ++i){
        scanf("%d", &x);
        int pos = bis(0, vec.size()-1, x);
        //printf("%d (%d,%d)\n", pos, vec[pos].first, vec[pos].second);
        if(pos != -1){
            sum+=vec[pos].second;
            sum%=2007;
        }
    }
    printf("%d", sum);
    return 0;
}
