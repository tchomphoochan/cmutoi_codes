#include <cstdio>
#include <vector>
#include <queue>
#define INF 10000000000
using namespace std;

int gen(char a){
    if(a >= 'A' && a <= 'Z')
        return a-'A';
    if(a >= 'a' && a <= 'z')
        return a-'a'+26;
}
int inQ[55], dp[55];
vector<pair<int, int> > G[55];
void shortestPath(int st){
    queue<int> q;
    q.push(st);
    dp[st] = 0;
    inQ[st] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        inQ[u] = false;
        for(int i = 0; i < G[u].size(); ++i){
            int v = G[u][i].first, w = G[u][i].second;
            if(dp[u] + w < dp[v]){
                dp[v] = dp[u]+w;
                if(!inQ[v]){
                    q.push(v);
                    inQ[v] = true;
                }
            }
        }
    }
}

int main(){
    int E;
    scanf("%d", &E);
    for(int i = 0; i <= 54; ++i)
        dp[i] = INF;
    for(int i = 0; i < E; ++i){
        char x[5], y[5];
        int w, xG, yG;
        scanf("%s%s%d", x, y, &w);
        xG = gen(x[0]);
        yG = gen(y[0]);
        G[xG].push_back(make_pair(yG, w));
        G[yG].push_back(make_pair(xG, w));
    }
    shortestPath('Z'-'A');
    int mi = INF, home = -1;
    for(int i = 0; i < 25; ++i){
        if(dp[i] < mi){
            mi = dp[i];
            home = i;
        }
    }
    printf("%c %d", home+'A', mi);
    return 0;
}
/*
5
A d 6
B d 3
C e 9
d Z 8
e Z 3
*/
