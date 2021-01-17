#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int N = 1010;
const int M = 4010;

int arr[N], dp[N][M];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &arr[i]);
	
	for (int i = n; i >= 1; --i) {
		for (int j = 0; j < M; ++j) {
			if (j+1 <= 3000)
				dp[i][j] = dp[i+1][j+1]+1;
			else
				dp[i][j] = INF;
			if (arr[i] > j)
				dp[i][j] = min(dp[i][j], dp[i+1][arr[i]]);
		}
	}

	printf("%d\n", dp[1][0]);
	return 0;
}