/**
 * toi10_prime
 * 
 * aquablitz11 (2017)
 * 100/100
 */

#include <cstdio>

#define N 200010
#define MAX 8000000

bool comp[MAX];
int prime[N];

int main()
{
    comp[1] = true;
    for (int i = 2; i*i <= MAX; ++i) {
        if (comp[i])
            continue;
        for (int j = i*2; j <= MAX; j += i) {
            comp[j] = true;
        }
    }

    int n;
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 2; i < MAX; ++i) {
        if (!comp[i]) {
            if (++cnt == n)
                printf("%d", i);
        }
    }
}
