#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+1, INF = 1e9;

int n, a[N], h[N], b[N], k[N], mxl[N], mxr[N];
priority_queue<int> pq;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> h[i] >> a[i];
	for(int i = 0; i < n; i++) cin >> k[i] >> b[i];
	for(int i = 0; i < n; i++) mxl[i] = mxr[i] = -INF;
	for(int i = 0, j = 0; i < n; i++) {
		while(j < n && k[j] <= h[i]) {
			pq.push(b[j] + k[j]);
			++j;
		}
		if(!pq.empty()) mxl[i] = a[i] - h[i] + pq.top();
	}
	while(!pq.empty()) pq.pop();
	for(int i = n-1, j = n-1; i >= 0; i--) {
		while(j >= 0 && k[j] >= h[i]) {
			pq.push(b[j] - k[j]);
			--j;
		}
		if(!pq.empty()) mxr[i] = a[i] + h[i] + pq.top();
	}
	for(int i = 0; i < n; i++) cout << max(mxl[i], mxr[i]) << '\n';
}