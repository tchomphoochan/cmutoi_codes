#include <stdio.h>
int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		int m, n;
		scanf("%d%d", &m, &n);
		int cnt = 0;
		for (int i = 0; i <= 10000; ++i) {
			if (0 <= n-20*i && n-20*i <= m)
				++cnt;
		}
		printf("Case #%d: %d\n", t, cnt);
	}
	return 0;
}