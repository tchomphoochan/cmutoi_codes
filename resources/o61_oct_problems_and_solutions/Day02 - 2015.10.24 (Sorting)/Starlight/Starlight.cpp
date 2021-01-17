#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > vec;
bool cmpX(const pair<int, int> &A, const pair<int, int> &B){
    if(A.first == B.first)
        return A.second < B.second;
    else
        return A.first < B.first;
}
bool cmpY(const pair<int, int> &A, const pair<int, int> &B){
    if(A.second == B.second)
        return A.first < B.first;
    else
        return A.second < B.second;
}

int main(){
    int S, N;
    scanf("%d%d", &S, &N);
    for(int i = 0; i < N; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        vec.push_back(make_pair(x, y));
    }
    sort(vec.begin(), vec.end(), cmpX);
    double maX = max(vec[0].first, S-vec[N-1].first);
    for(int i = 1; i < N; ++i)
        maX = max(maX, (vec[i].first-vec[i-1].first)/2.00);
    sort(vec.begin(), vec.end(), cmpY);
    double maY = max(vec[0].second, S-vec[N-1].second);
    for(int i = 1; i < N; ++i)
        maY = max(maY, (vec[i].second-vec[i-1].second)/2.00);
    double miUse = min(maX, maY);
    printf("%.3f", miUse);
    return 0;
}
