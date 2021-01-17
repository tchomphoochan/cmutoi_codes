#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int> &A, const pair<int, int> &B){
    if(A.first == B.first)
        return A.second < B.second;
    else
        return A.first < B.first;
}
vector<pair<int ,int> > vec;

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        vec.push_back(make_pair(x, y));
    }
    sort(vec.begin(), vec.end(), cmp);
    for(int i = 0; i < N; ++i)
        printf("%d %d\n", vec[i].first, vec[i].second);
    return 0;
}
