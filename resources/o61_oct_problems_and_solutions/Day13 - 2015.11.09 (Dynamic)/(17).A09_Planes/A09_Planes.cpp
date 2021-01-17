#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class TIME{
public:
    int s, t, val;
    TIME(){}
    TIME(int s, int t, int val){
        this->s = s;
        this->t = t;
        this->val = val;
    }
};

TIME dp[305];
vector<pair<int, int> > planes;
bool cmp(const pair<int, int> &A, const pair<int, int> &B){
    if(A.first == B.first)
        return A.second > B.second;
    return A.first < B.first;
}
bool valid(int i, int j, TIME &ma){
    return ((planes[i].first >= planes[j].second && planes[i].second <= dp[j].t) ||
            (planes[i].first >= planes[j].first && planes[i].second < planes[j].second ))
            && dp[j].s <= planes[i].first && dp[j].t >= planes[i].second && dp[j].val > ma.val;
}

int main(){
    int totalCase;
    scanf("%d", &totalCase);
    while(totalCase--){
        int N;
        scanf("%d", &N);
        planes.clear();
        for(int i = 0; i < N; ++i){
            int x, y;
            scanf("%d%d", &x, &y);
            planes.push_back(make_pair(x, y));
        }
        sort(planes.begin(), planes.end(), cmp);
        dp[0] = TIME(planes[0].first, planes[0].second, 1);
        int ans = 0;
        for(int i = 1; i < N; ++i){
            TIME ma = TIME(planes[i].first, planes[i].second, 0);
            for(int j = 0; j < i; ++j){
                if(valid(i, j, ma)){
                    //printf("%d->%d (%d)\n", dp[j].s, dp[j].t, dp[j].val);
                    ma = dp[j];
                }
            }
            dp[i] = ma;
            dp[i].val++;
            ans = max(ans, dp[i].val);
        }
        printf("%d\n", ans);
    }
    return 0;
}
/*
2
4
1 10
2 5
3 7
6 9
3
10 12
10 15
13 17
*/
