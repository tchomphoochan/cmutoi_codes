#include <cstdio>
#include <vector>
#include <queue>
#include <ctime>
#include <cstdlib>
#define INF 1000000000
using namespace std;

class NODE{
public:
    int v, w;
    NODE(int v, int w){
        this->v = v;
        this->w = w;
    }
};
vector<NODE> G[1005];
int N, D[1005], qS[1005], DP[1005];
queue<int> q;
bool inQ[1005];

void shortestPath(){
    for(int i = 1; i <= N; ++i)
        DP[i] = INF;
    q.push(0);
    inQ[0] = true;
    DP[0] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        inQ[u] = false;
        for(int i = 0; i < G[u].size(); ++i){
            int v = G[u][i].v, w = G[u][i].w;
            if(DP[u]+w < DP[v]){
                DP[v] = DP[u]+w;
                if(!inQ[v]){
                    q.push(v);
                    inQ[v] = true;
                }
            }
        }
    }
}

int main(){
    srand(time(NULL));
    int a, b, h;
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i){
        //D[i] = rand()%100;
        //printf("%d ", D[i]);
        scanf("%d", &D[i]);
        qS[i] = D[i]+qS[i-1];
    }
    //a = rand()%20, b = rand()%20, h = rand()%20;
    //printf("\n%d %d %d\n", a, b, h);
    scanf("%d%d%d", &a, &b, &h);
    for(int i = 0; i < N; ++i){
        for(int j = i+1; j <= N; ++j){
            int w = a+b*(qS[j]-qS[i]), stock = 0;
            int tmp = qS[j]-qS[i];
            //printf("--TMP:%d--\n", tmp);
            for(int k = i+1; k < j; ++k){
                tmp-=D[k];
                stock+=(tmp*h);
            }
            G[i].push_back(NODE(j, w+stock));
            //printf("%d->%d (%d)\n", i, j, w+stock);
        }
    }
    shortestPath();
    printf("%d", DP[N]);
    return 0;
}
