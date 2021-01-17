#include <stdio.h>
int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		int m, n;
		scanf("%d%d", &m, &n);
		// 0 <= n-20x <= m
		// x <= n/20
		// x >= (n-m)/20
		int mn = (n-m+19)/20;
		int mx = n/20;
		if (mn < 0) mn = 0;
		printf("Case #%d: %d\n", t, mx-mn+1);
	}
	return 0;
}