/**
 * toi10_raider
 * 
 * aquablitz11 (unsure) (2019)
 * 100/100
 */

#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pi;
typedef pair<int,pi> pii;
int ar[100][105],n,m;
int di1[] = {-1,0,1,1,0,-1};
int dj1[] = {0,1,0,-1,-1,-1};
int di2[] = {-1,0,1,1,0,-1};
int dj2[] = {1,1,1,0,-1,0};
bool vs[2520][110][110];
int dist[2520][110][110];
bool p(int i,int j){
	return (i>=0 and i<n and j>=0 and j<m);
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			scanf("%d",&ar[i][j]);
	queue<pii> q;
    dist[1][(n-1)/2-1][0] = 1;
    dist[1][(n-1)/2][0] = 1;
    dist[1][(n-1)/2+1][0] = 1;
	q.push({1,{(n-1)/2-1,0}});
	q.push({1,{(n-1)/2,0}});
	q.push({1,{(n-1)/2+1,0}});
	while(!q.empty()){
		int d = q.front().first;
		int i = q.front().second.first;
		int j = q.front().second.second;
		q.pop();
		if(!ar[i][j] or d%ar[i][j] != 0) continue;
		if(i==(n-1)/2 and j==m-1){
			printf("%d",dist[d][i][j]);
			return 0;
		}
		if(i%2==1){
			for(int k=0;k<6;++k)
				if(p(i+di1[k],j+dj1[k]) and !vs[(d+1)%2520][i+di1[k]][j+dj1[k]]){
					q.push({(d+1)%2520,{i+di1[k],j+dj1[k]}});
					dist[(d+1)%2520][i+di1[k]][j+dj1[k]] = dist[d][i][j]+1;
					vs[(d+1)%2520][i+di1[k]][j+dj1[k]] = true;
				}
		}else{
			for(int k=0;k<6;++k)
				if(p(i+di2[k],j+dj2[k]) and !vs[(d+1)%2520][i+di2[k]][j+dj2[k]]){
					q.push({(d+1)%2520,{i+di2[k],j+dj2[k]}});
					dist[(d+1)%2520][i+di2[k]][j+dj2[k]] = dist[d][i][j]+1;
					vs[(d+1)%2520][i+di2[k]][j+dj2[k]] = true;
				}
		}
	}
	printf("-1");
	return 0;
}