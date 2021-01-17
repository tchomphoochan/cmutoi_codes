#include <cstdio>
#include <algorithm>
using namespace std;

int N, rock[105], dp[105][105];
int chooseRock(int L, int R){
    if(R-L+1 == 2)
        return dp[L][R] = max(rock[L], rock[R]);
    else{
        if(dp[L][R] != 0)
            return dp[L][R];
        else{
            int LL = rock[L] + chooseRock(L+2, R);
            int LR = rock[L] + chooseRock(L+1, R-1);
            int RR = rock[R] + chooseRock(L, R-2);
            int RL = rock[R] + chooseRock(L+1, R-1);
            return dp[L][R] = max(LL, max(LR, max(RR, RL)));
        }
    }
}

int main(){
    scanf("%d", &N);
    for(int i = 1; i <= 2*N; ++i)
        scanf("%d", &rock[i]);
    printf("%d", chooseRock(1, 2*N));
    return 0;
}
/*
2
1 20 19 2

3
1 2 102 103 3 101
*/
