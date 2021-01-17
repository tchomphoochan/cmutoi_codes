#include <cstdio>
#include <algorithm>
#define RD 0
#define LD 1
#define RR 2
#define LL 3
using namespace std;

int N, bombLimit, rew[101][201], dp[101][200][101][4];

int slide(int state, int pos, int bombUse, int di){
    if(state == N+1 || pos > N*2-1 || pos < 1)
        return 0;
    if(dp[state][pos][bombUse][di] != 0)
        return dp[state][pos][bombUse][di];
    /*
    if(di == LL && pos == 0){
        dp[state][pos][bombUse][di] = max(dp[state][pos][bombUse][LD], slide(state+1, pos, bombUse, LD));
        return dp[state][pos][bombUse][LD];
    }
    if(di == RR && pos == 2*state-1){
        dp[state][pos][bombUse][di] = max(dp[state][pos][bombUse][RD], slide(state+1, pos+2, bombUse, RD));
        return dp[state][pos][bombUse][RD];
    }
    */
    int ma = 0;
    if(bombUse < bombLimit){
        if(di == RD){
            if(pos > state)
                ma = max(ma, slide(state, pos-1, bombUse+1, LD));
            if(pos >= state && pos != state*2-1)
                ma = max(ma, slide(state, pos+1, bombUse+1, RR));
        }
        else if(di == LD){
            if(pos < state)
                ma = max(ma, slide(state, pos+1, bombUse+1, RD));
            if(pos <= state && pos != 1)
                ma = max(ma, slide(state, pos-1, bombUse+1, LL));
        }
    }
    if(di == RD){
        if(pos >= state)
            ma = max(ma, slide(state+1, pos+2, bombUse, RD));
        else
            ma = max(ma, slide(state, pos+1, bombUse, RD));
    }
    else if(di == LD){
        if(pos <= state)
            ma = max(ma, slide(state+1, pos, bombUse, LD));
        else
            ma = max(ma, slide(state, pos-1, bombUse, LD));
    }
    else if(di == RR){
        if(pos == state*2-1)
            ma = max(ma, slide(state+1, pos+2, bombUse, RD));
        else
            ma = max(ma, slide(state, pos+1, bombUse, RR));
    }
    else if(di == LL){
        if(pos == 1)
            ma = max(ma, slide(state+1, pos, bombUse, LD));
        else
            ma = max(ma, slide(state, pos-1, bombUse, LL));
    }
    return dp[state][pos][bombUse][di] = ma + rew[state][pos];
}

int main(){
    scanf("%d%d", &N, &bombLimit);
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= i*2-1; ++j)
            scanf("%d", &rew[i][j]);
    }
    printf("%d", max(slide(1, 1, 0, LD), slide(1, 1, 0, RD)));
    return 0;
}
