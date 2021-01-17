#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
const int N = 501, INF = 1e9, dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int n, m, r, c, w[N][N], dld[N][N], drd[N][N], dlu[N][N], dru[N][N], tmp[N][N];
bool mark[N][N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> r >> c;
	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) cin >> w[i][j];

	// DLD case
	for(int s = 1; s < c; s++) {
		// clear
		for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) tmp[i][j] = INF;
		memset(mark, 0, sizeof(mark));

		//init
		priority_queue<pair<int,pair<int,int> > > pq;
		tmp[r][s] = w[r][s];
		pq.emplace(-(w[r][s] + c - s), make_pair(r, s));

		// calc
		while(!pq.empty()) {
			int x, y; tie(x, y) = pq.top().second;
			pq.pop();
			if(mark[x][y]) continue;
			mark[x][y] = true;
			for(int k = 0; k < 4; k++) {
				bool valid = x+dx[k] >= 1 && x+dx[k] <= n && y+dy[k] >= 1 && y+dy[k] <= m && (x+dx[k] != r || y+dy[k] != c);
				if(!valid) continue;
				if(tmp[x][y] + w[x+dx[k]][y+dy[k]] < tmp[x+dx[k]][y+dy[k]]) {
					tmp[x+dx[k]][y+dy[k]] = tmp[x][y] + w[x+dx[k]][y+dy[k]];
					pq.emplace(-(tmp[x+dx[k]][y+dy[k]] + c - (y+dy[k])), make_pair(x+dx[k], y+dy[k]));
				}
			}
		}
		// for(int i = r; i <= n; i++) for(int j = 1; j <= c; j++) cout << s << ' ' << i << ' ' << j << ' ' << tmp[i][j] <<endl;
	
		// store
		for(int i = r+1; i <= n; i++) dld[s][i] = tmp[i][c];//, cout << s << ' ' << i << ' ' << dld[s][i] << endl;

	}
	
	// DRD case
	for(int s = c+1; s <= m; s++) {
		// clear
		for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) tmp[i][j] = INF;
		memset(mark, 0, sizeof(mark));

		//init
		priority_queue<pair<int,pair<int,int> > > pq;
		tmp[r][s] = w[r][s];
		pq.emplace(-(w[r][s] + s - c), make_pair(r, s));

		// calc
		while(!pq.empty()) {
			int x, y; tie(x, y) = pq.top().second;
			pq.pop();
			if(mark[x][y]) continue;
			mark[x][y] = true;
			for(int k = 0; k < 4; k++) {
				bool valid = x+dx[k] >= 1 && x+dx[k] <= n && y+dy[k] >= 1 && y+dy[k] <= m && (x+dx[k] != r || y+dy[k] != c);
				if(!valid) continue;
				if(tmp[x][y] + w[x+dx[k]][y+dy[k]] < tmp[x+dx[k]][y+dy[k]]) {
					tmp[x+dx[k]][y+dy[k]] = tmp[x][y] + w[x+dx[k]][y+dy[k]];
					pq.emplace(-(tmp[x+dx[k]][y+dy[k]] + (y + dy[k] - c)), make_pair(x+dx[k], y+dy[k]));
				}
			}
		}
		// for(int i = r; i <= n; i++) for(int j = 1; j <= c; j++) cout << s << ' ' << i << ' ' << j << ' ' << tmp[i][j] <<endl;
	
		// store
		for(int i = r+1; i <= n; i++) drd[s][i] = tmp[i][c];

	}

	// DLU case
	for(int s = 1; s < c; s++) {
		// clear
		for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) tmp[i][j] = INF;
		memset(mark, 0, sizeof(mark));

		//init
		priority_queue<pair<int,pair<int,int> > > pq;
		tmp[r][s] = w[r][s];
		pq.emplace(-(w[r][s] + c - s), make_pair(r, s));

		// calc
		while(!pq.empty()) {
			int x, y; tie(x, y) = pq.top().second;
			pq.pop();
			if(mark[x][y]) continue;
			mark[x][y] = true;
			for(int k = 0; k < 4; k++) {
				bool valid = x+dx[k] >= 1 && x+dx[k] <= n && y+dy[k] >= 1 && y+dy[k] <= m && (x+dx[k] != r || y+dy[k] != c);
				if(!valid) continue;
				if(tmp[x][y] + w[x+dx[k]][y+dy[k]] < tmp[x+dx[k]][y+dy[k]]) {
					tmp[x+dx[k]][y+dy[k]] = tmp[x][y] + w[x+dx[k]][y+dy[k]];
					pq.emplace(-(tmp[x+dx[k]][y+dy[k]] + c - (y+dy[k])), make_pair(x+dx[k], y+dy[k]));
				}
			}
		}
		// for(int i = r; i <= n; i++) for(int j = 1; j <= c; j++) cout << s << ' ' << i << ' ' << j << ' ' << tmp[i][j] <<endl;
	
		// store
		for(int i = 1; i < r; i++) dlu[s][i] = tmp[i][c];

	}

	// DRU case
	for(int s = c+1; s <= m; s++) {
		// clear
		for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) tmp[i][j] = INF;
		memset(mark, 0, sizeof(mark));

		//init
		priority_queue<pair<int,pair<int,int> > > pq;
		tmp[r][s] = w[r][s];
		pq.emplace(-(w[r][s] + s - c), make_pair(r, s));

		// calc
		while(!pq.empty()) {
			int x, y; tie(x, y) = pq.top().second;
			pq.pop();
			if(mark[x][y]) continue;
			mark[x][y] = true;
			for(int k = 0; k < 4; k++) {
				bool valid = x+dx[k] >= 1 && x+dx[k] <= n && y+dy[k] >= 1 && y+dy[k] <= m && (x+dx[k] != r || y+dy[k] != c);
				if(!valid) continue;
				if(tmp[x][y] + w[x+dx[k]][y+dy[k]] < tmp[x+dx[k]][y+dy[k]]) {
					tmp[x+dx[k]][y+dy[k]] = tmp[x][y] + w[x+dx[k]][y+dy[k]];
					pq.emplace(-(tmp[x+dx[k]][y+dy[k]] + y + dy[k] - c), make_pair(x+dx[k], y+dy[k]));
				}
			}
		}
		// for(int i = r; i <= n; i++) for(int j = 1; j <= c; j++) cout << s << ' ' << i << ' ' << j << ' ' << tmp[i][j] <<endl;
	
		// store
		for(int i = 1; i < r; i++) dru[s][i] = tmp[i][c];

	}

	int ans = INF;
	for(int i = 1; i < c; i++) for(int j = c+1; j <= m; j++) {
		int up = INF, down = INF;
		for(int k = 1; k < r; k++) up = min(dlu[i][k] + dru[j][k] - w[k][c], up);
		for(int k = r+1; k <= n; k++) down = min(dld[i][k] + drd[j][k] - w[k][c], down);
		ans = min(up + down - w[r][i] - w[r][j], ans);
	}

	cout << ans;
}