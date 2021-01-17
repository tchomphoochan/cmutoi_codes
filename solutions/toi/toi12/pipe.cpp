/**
 * toi12_pipe
 * 
 * aquablitz11 (2019)
 */

#include <bits/stdc++.h>

using namespace std;
using pii=pair<int,int>;
const int N=50001;
const int INF=1e9;
pii a[N];
int ix[N]; // <-- new array for easy (first fill with 1,2,3,4,...,N)
int dist[N]; // <-- changed to array
//bool visit[N]; // <-- don't need this anymore. will use ix array instead
int edge[N];

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i) {
        scanf("%d%d",&a[i].first,&a[i].second);
        ix[i] = i; // <- fill index
    }
    fill(dist+1, dist+n+1, INF); // loop fill instead
    dist[1]=0;
    int sum=0,cnt=0;
    while(true){
        int mindist=INF,u=-1, ui=-1;
        for(int ii=1;ii<=n-cnt;++ii){ // <- loop on unvisited nodes only (n-cnt nodes left)
            int i = ix[ii]; // <- actual node (unvisited)
            if(dist[i]<mindist){
                mindist=dist[i];
                u=i;
                ui = ii; // <- keep index of "unvisited list"
            }
        }
        if(u==-1) break;
        //visited[u] = true; // <-- not needed
        swap(ix[ui], ix[n-cnt]); // set visited by swapping this node to the back instead
        edge[cnt++]=dist[u];
        sum+=dist[u];
        for(int vv=1;vv<=n-cnt;++vv){ // <- loop on unvisited nodes only
            int v = ix[vv];
            if(((abs(a[u].first-a[v].first)+abs(a[u].second-a[v].second)))<dist[v]){
                dist[v]=abs(a[u].first-a[v].first)+abs(a[u].second-a[v].second);
            }
        }
    }
    sort(edge,edge+n,greater<int>());
    for(int i=0;i<k-1;++i) sum-=edge[i];
    printf("%d",sum);
    return 0;
}
/*
5 2
2 9
9 7
14 2
12 9
16 4
*/