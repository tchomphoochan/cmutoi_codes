#include <cstdio>
#include <vector>
#include <algorithm>
#define SIZE 200000
#define notHave -1
using namespace std;

int FT[SIZE+5], N, K;
int dist[SIZE+5], parent[SIZE+5], level[SIZE+5];
vector<int> G[SIZE+5];

void update(int idx, int v){
    while(idx <= K){
        FT[idx]+=v;
        idx+=(idx&(-idx));
    }
}

int sumTo(int idx){
    int sum = 0;
    while(idx >= 1){
        sum+=FT[idx];
        idx-=(idx&(-idx));
    }
    return sum;
}

int LCA(int a, int b){
    if(level[a] < level[b])
        swap(a, b);
    while(level[a] > level[b])
        a = G[a][0];
    while(a != b){
        a = G[a][0];
        b = G[b][0];
    }
    return a;
}

int main(){
    int Q;
    scanf("%d%d%d", &N, &K, &Q);
    for(int i = 1; i <= K; ++i){
        int x;
        parent[i] = i;
        level[i] = 0;
        scanf("%d", &x);
        update(i, x);
    }
    for(int i = K+1; i <= N; ++i){
        int y, d;
        scanf("%d%d", &y, &dist[i]);
        parent[i] = parent[y];
        dist[i]+=dist[y];
        G[i].push_back(y);
        level[i] = level[y]+1;
    }
    while(Q--){
        int opr, x, y;
        scanf("%d%d%d", &opr, &x, &y);
        if(opr == 0)
            update(x, y-(sumTo(x)-sumTo(x-1)));
        else if(opr == 1){
            int ans = 0;
            if(parent[x] == parent[y])
                ans = dist[x]+dist[y]-2*dist[LCA(x, y)];
            else{
                int parX = parent[x], parY = parent[y];
                if(parX > parY)
                    swap(parX, parY);
                int all = sumTo(K);
                int xToy = sumTo(parY-1)-sumTo(parX-1);
                //printf("%d->%d (%d) ALL(%d)\n", parX, parY, xToy, all);
                ans = min(all-xToy, xToy) + dist[x] + dist[y];
            }
            printf("%d\n", ans);
        }
    }
    /*
    for(int i = 1; i <= N; ++i)
        printf("(%d)%d %d\n", i, dist[i], parent[i]);
    //*/
    return 0;
}
/*
6 3 5
1
1
1
1 2
3 3
4 2
1 2 5
1 5 6
0 3 10
1 4 5
1 2 1
*/
