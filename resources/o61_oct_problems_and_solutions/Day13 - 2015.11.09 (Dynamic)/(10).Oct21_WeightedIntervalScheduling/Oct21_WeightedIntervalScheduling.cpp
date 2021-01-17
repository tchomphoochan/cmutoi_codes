#include <cstdio>
#include <algorithm>
using namespace std;

class WORK{
public:
    int s, t, w, num;
    WORK(int s, int t, int w, int num){
        this->s = s;
        this->t = t;
        this->w = w;
        this->num = num;
    }
};

int dp[1005], idx[1005];
vector<WORK> vec;
bool cmp(const WORK &A, const WORK &B){
    return A.t < B.t;
}

int main(){
    int N;
    scanf("%d", &N);
    vec.push_back(WORK(0, 0, 0, 0));
    for(int i = 1; i <= N; ++i){
        int s, t, w;
        scanf("%d%d%d", &s, &t, &w);
        vec.push_back(WORK(s, t, w, i));
    }
    sort(vec.begin(), vec.end(), cmp);
    int ma = 0, cur = 0;
    for(int i = 1; i <= N; ++i){
        int maNow = 0;
        for(int j = 1; j < i; ++j){
            if(vec[j].t <= vec[i].s && dp[j] > maNow){
                maNow = dp[j];
                idx[i] = j;
            }
        }
        dp[i] = maNow+vec[i].w;
        //printf("(%d) %d\n", i, dp[i]);
        if(dp[i] > ma){
            ma = dp[i];
            cur = i;
        }
    }
    printf("%d\n", ma);
    vector<int> ans;
    while(cur != 0){
        ans.push_back(cur);
        cur = idx[cur];
    }
    printf("%d\n", ans.size());
    for(int i = ans.size()-1; i >= 0; --i)
        printf("%d ", vec[ans[i]].num);
    return 0;
}
