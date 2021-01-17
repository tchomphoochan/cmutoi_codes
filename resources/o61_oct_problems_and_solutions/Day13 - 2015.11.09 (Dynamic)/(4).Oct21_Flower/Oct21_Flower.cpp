#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

class FLOWER{
public:
    int m, val, type;
    FLOWER(){}
};
bool valid(int a, int b){
    if(a < b)
        swap(a, b);
    if((a-1)/2 - b >= 1)
        return false;
    return true;
}

int dp[105][105][105];
FLOWER f[105];

int main(){
    int Money, N, ans = 0;
    scanf("%d%d", &Money, &N);
    for(int i = 0; i < N; ++i)
        scanf("%d%d%d", &f[i].m, &f[i].val, &f[i].type);
    for(int i = 0; i < N; ++i){
        int type0 = 0, type1 = 0;
        if(f[i].type == 0)
            type0++;
        else
            type1++;
        for(int j = Money-f[i].m; j >= 0; --j){
            for(int first = i; first >= 0; --first){
                for(int sec = i-first; sec >= 0; --sec){
                    //printf("%d %d AND %d (%d)\n", i, first, sec, dp[j][first][sec]);
                    //system("pause");
                    if((dp[j][first][sec] || (j == 0 && first == 0 && sec == 0))){
                        dp[j+f[i].m][first+type0][sec+type1] = max(dp[j+f[i].m][first+type0][sec+type1], dp[j][first][sec]+f[i].val);
                        //ans = max(ans, dp[j+f[i].m][first+type0][sec+type1]);
                    }
                }
            }
        }
    }
    for(int j = 0; j <= Money; ++j){
        for(int first = 0; first <= N; ++first){
            for(int sec = 0; sec <= N-first; ++sec){
                if(valid(first, sec))
                    ans = max(ans, dp[j][first][sec]);
            }
        }
    }
    printf("%d", ans);
    return 0;
}
/*
100 6
40 1000 1
20 100 1
10 200 0
20 300 0
30 400 0
30 400 0

100 6
1 100 1
1 200 1
1 300 1
1 400 1
1 500 1
1 1000 1
*/
