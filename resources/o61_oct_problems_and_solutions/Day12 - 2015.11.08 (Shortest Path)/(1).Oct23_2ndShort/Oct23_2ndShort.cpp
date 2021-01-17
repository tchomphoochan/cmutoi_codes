#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

class NODE{
public:
    int u, w;
    NODE(int u, int w){
        this->u = u;
        this->w = w;
    }
};
struct cmp{
    bool operator()(const NODE& A, const NODE& B){
        return !(A.w < B.w);
    }
};
int dest;
vector<pair<int, int> > G[10005];
priority_queue<NODE, vector<NODE>, cmp> q;
int secondShortestPath(int st){
    q.push(NODE(st, 0));
    int cnt = 0;
    while(!q.empty()){
        int u = q.top().u, S = q.top().w;
        q.pop();
        if(u == dest){
            cnt++;
            if(cnt == 2)
                return S;
        }
        for(int i = 0; i < G[u].size(); ++i){
            int v = G[u][i].first, w = G[u][i].second;
            q.push(NODE(v, S+w));
        }
    }
}

int main(){
    int V, E, st;
    scanf("%d%d", &V, &E);
    scanf("%d%d", &st, &dest);
    for(int i = 0; i < E; ++i){
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        G[x].push_back(make_pair(y, w));
    }
    printf("%d", secondShortestPath(st));
    return 0;
}
