#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> G[100005];
vector<pair<int, int> > edge, child2[100005];
int V, E, deg[100005];
long long ma;
bool visited[100005];

bool cmp(const pair<int, int> &A, const pair<int, int> &B){
    return A.second > B.second;
}

int cntChild(int u){
    int cnt = 0;
    for(int i = 0; i < G[u].size(); ++i){
        int v = G[u][i];
        if(!visited[v]){
            visited[v] = true;
            int tmp = cntChild(v);
            child2[u].push_back(make_pair(v, tmp));
            child2[v].push_back(make_pair(u, V-tmp));
            cnt+=tmp;
        }
    }
    //printf("U%d %d\n", u, cnt);
    return cnt+1;
}

int main(){
    scanf("%d", &V);
    E = V-1;
    for(int i = 0; i < E; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
        edge.push_back(make_pair(x, y));
        deg[x]++;
        deg[y]++;
    }
    for(int i = 1; i <= V; ++i){
        if(deg[i] == 1){
            visited[i] = true;
            cntChild(i);
            break;
        }
    }
    for(int i = 1; i <= V; ++i)
        sort(child2[i].begin(), child2[i].end(), cmp);
    for(int i = 0; i < E; ++i){
        int x = edge[i].first, y = edge[i].second;
        if(G[x].size()-1 == 0 || G[y].size()-1 == 0)
            continue;
        int fir, sec, a, b;
        for(int i = 0; i < child2[x].size(); ++i){
            a = child2[x][i].first;
            if(a != y){
                fir = child2[x][i].second;
                break;
            }
        }
        for(int i = 0; i < child2[y].size(); ++i){
            b = child2[y][i].first;
            if(b != x){
                sec = child2[y][i].second;
                break;
            }
        }
        //printf("%d-%d-%d-%d %d %d %lld\n", a, x, y, b, fir, sec, (long long)fir*sec);
        ma = max(ma, (long long)fir*sec);
    }
    printf("%lld", ma);
    return 0;
}
/*
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int> > child[100005];
int V, E, deg[100005], out[100005];
long long ma;
bool visited[100005], visited3[100005];

long long PROCESS(int a, int b){
    int rightA = out[1], leftB = out[2];
    long long fir = 1, sec = 1;
    for(int i = 0; i < child[a].size(); ++i){
        if(child[a][i].first != rightA)
            fir+=child[a][i].second;
    }
    for(int i = 0; i < child[b].size(); ++i){
        if(child[b][i].first != leftB)
            sec+=child[b][i].second;
    }
    //printf("%d(%d) & %d(%d)\n", a, fir, b, sec);
    return fir*sec;
}

void dfs(int st, int u, int state){
    if(state == 3){
        //printf("%d->%d (%d)\n", st, u, tmp);
        ma = max(ma, PROCESS(st, u));
        return;
    }
    for(int i = 0; i < child[u].size(); ++i){
        int v = child[u][i].first;
        if(!visited[v] && (state+1 == 3 || child[v].size()-1 != 0)){
            visited[v] = true;
            out[state] = u;
            dfs(st, v, state+1);
            visited[v] = false;
        }
    }
}

int cntChild(int u){
    int cnt = 0;
    for(int i = 0; i < child[u].size(); ++i){
        int v = child[u][i].first;
        if(!visited3[v]){
            visited3[v] = true;
            int tmp = cntChild(v);
            child[u][i].second+=tmp;
            //printf("%d->%d (%d)\n", u, v, child[u][i].second);
            for(int j = 0; j < child[v].size(); ++j){
                if(child[v][j].first == u){
                    child[v][j].second+=(V-tmp);
                    //printf("%d->%d (%d)\n", v, child[v][j].first, child[v][j].second);
                    break;
                }
            }
            cnt+=tmp;
        }
    }
    //printf("U%d %d\n", u, cnt);
    return cnt+1;
}

int main(){
    scanf("%d", &V);
    E = V-1;
    for(int i = 0; i < E; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        child[x].push_back(make_pair(y, 0));
        child[y].push_back(make_pair(x, 0));
        deg[x]++;
        deg[y]++;
    }
    for(int i = 1; i <= V; ++i){
        if(deg[i] == 1){
            visited3[i] = true;
            cntChild(i);
            visited[i] = true;
            dfs(i, i, 0);
            break;
        }
    }
    //*
    for(int i = 1; i <= V; ++i){
        visited[i] = true;
        dfs(i, i, 0);
        visited[i] = false;
    }
    //
    printf("%lld", ma);
    return 0;
}
*/
/*
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> G[100005];
int out[5];
int ma, V, E;
bool visited[100005], visited2[100005];

int dfs2(int u){
    int cnt = 0;
    for(int i = 0; i < G[u].size(); ++i){
        int v = G[u][i];
        if(!visited2[v]){
            visited2[v] = true;
            cnt+=dfs2(v);
            visited2[v] = false;
        }
    }
    return cnt+1;
}

int PROCESS(int a, int b){
    visited2[a] = true;
    int fir = dfs2(a);
    visited2[a] = false;
    visited2[b] = true;
    int sec = dfs2(b);
    visited2[b] = false;
    //printf("%d(%d) & %d(%d)\n", a, fir, b, sec);
    return fir*sec;
}

void dfs(int st, int u, int state){
    if(state == 3){
        for(int i = 1; i < 3; ++i)
            visited2[out[i]] = true;
        int tmp = PROCESS(st, u);
        //printf("%d->%d (%d)\n", st, u, tmp);
        ma = max(ma, tmp);
        for(int i = 1; i < 3; ++i)
            visited2[out[i]] = false;
        return;
    }
    for(int i = 0; i < G[u].size(); ++i){
        int v = G[u][i];
        if(!visited[v]){
            visited[v] = true;
            out[state] = u;
            dfs(st, v, state+1);
            visited[v] = false;
        }
    }
}

int main(){
    int V, E;
    scanf("%d", &V);
    E = V-1;
    for(int i = 0; i < E; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i = 1; i <= V; ++i){
        visited[i] = true;
        dfs(i, i, 0);
        visited[i] = false;
    }
    printf("%d", ma);
    return 0;
}
*/
/*
#include <cstdio>
#include <cstring>
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
vector<int> G[100005];
int GCnt[1005][1005], V, E;
bool visited[1005];
queue<NODE> q;
int cntW2(int u, int state){
    visited[u] = true;
    int cnt = 0;
    for(int i = 0; i < G[u].size(); ++i){
        int v = G[u][i];
        if(!visited[v]){
            int tmp = cntW2(v, state+G[u].size()-1);
            printf("%d->%d TMP(%d) STATE(%d)\n", u, v, tmp, state);
            cnt+=tmp;
            GCnt[u][v]+=(tmp*state);
            GCnt[v][u]+=(tmp*state);
        }
    }
    return cnt+1;
}
int cntW(int u){
    visited[u] = true;
    int cnt = 0;
    for(int i = 0; i < G[u].size(); ++i){
        int v = G[u][i];
        if(!visited[v]){
            int tmp = cntW(v);
            printf("%d->%d TMP(%d)\n", u, v, tmp);
            cnt+=tmp;
            GCnt[u][v]+=tmp;
            GCnt[v][u]+=tmp;
        }
    }
    return cnt+1;
}

int main(){
    int V, E;
    scanf("%d", &V);
    E = V-1;
    for(int i = 0; i < E; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    //*
    for(int i = 1; i <= V; ++i){
        memset(visited, 0, sizeof(visited));
        for(int j = 1; j < i; ++j)
            visited[j] = true;
        cntW(i);
    }
    //
    //*
    for(int i = 1; i <= V; ++i){
        for(int j = 1; j <= V; ++j){
            if(GCnt[i][j]){
                printf("%d->%d (%d)\n", i, j, GCnt[i][j]);
            }
        }
    }
    //
    return 0;
}
*/
/*
#include <cstdio>
#include <cstring>
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
vector<int> G[100005];
int GCnt[1005][1005], V, E;
bool visited[1005];
queue<NODE> q;

void cntW(int st){
    visited[st] = true;
    q.push(NODE(st, 0));
    while(!q.empty()){
        int u = q.front().u, w = q.front().w;
        //printf("%d->%d\n", st, u);
        q.pop();
        int cnt = 0;
        for(int i = 0; i < G[u].size(); ++i){
            int v = G[u][i];
            if(!visited[v]){
                cnt++;
                printf("%d->%d\n", u, v);
                visited[v] = true;
                GCnt[u][v]+=w+cnt;
                GCnt[v][u]+=w+cnt;
                q.push(NODE(v, w+cnt));
            }
        }
    }
}

int main(){
    int V, E;
    scanf("%d", &V);
    E = V-1;
    for(int i = 0; i < E; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i = 1; i <= V; ++i){
        cntW(i);
    }
    for(int i = 1; i <= V; ++i){
        for(int j = 1; j <= V; ++j){
            if(GCnt[i][j]){
                printf("%d->%d (%d)\n", i, j, GCnt[i][j]);
            }
        }
    }
    return 0;
}
*/
/*
6
1 3
2 3
3 4
4 5
5 6
*/
