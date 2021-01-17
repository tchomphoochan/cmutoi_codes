#include <cstdio>
#include <vector>
#include <queue>
#define SIZE 300
using namespace std;

class EDGE{
public:
    int u, v, w;
    EDGE(int u, int v, int w){
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
struct cmp{
    bool operator()(const EDGE &A, const EDGE &B){
        return !(A.w < B.w);
    }
};

int matG[SIZE+5][SIZE+5], H[SIZE+5];
vector<int> G[SIZE+5];
priority_queue<EDGE, vector<EDGE>, cmp> q;

int findH(int a){
    if(H[a] == a)
        return H[a];
    return H[a] = findH(H[a]);
}

int main(){
    int N, T;
    scanf("%d%d", &N, &T);
    for(int i = 1; i <= N; ++i){
        H[i] = i;
        for(int j = 1; j <= N; ++j)
            scanf("%d", &matG[i][j]);
    }
    for(int i = 1; i <= N; ++i){
        for(int j = i+1; j <= N; ++j)
            q.push(EDGE(i, j, matG[i][j]));
    }
    while(!q.empty()){
        int u = q.top().u, v = q.top().v, w = q.top().w;
        q.pop();
        int hU = findH(u), hV = findH(v);
        if(hU != hV){
            G[u].push_back(v);
            G[v].push_back(u);
            H[hU] = H[hV];
        }
    }
    for(int i = 1; i <= N; ++i){
        if(G[i].size() >= 3){
            printf("%d", i);
            if(T == 2)
                printf("\n%d", G[i].size());
            break;
        }
    }
    return 0;
}
