#include <cstdio>

int n, m;
int count[1000001];

typedef unsigned long long ull;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        ++count[x];
    }
    
    int md2 = m>>1;
    ull ans = 0;
    for (int i = 0; i <= md2; ++i) {
        int j = m-i;
        if (i == j)
            ans += ((ull)count[i]*(count[i]-1))/2;
        else
            ans += (ull)count[i] * count[j];
    }

    printf("%llu", ans);
    return 0;
}