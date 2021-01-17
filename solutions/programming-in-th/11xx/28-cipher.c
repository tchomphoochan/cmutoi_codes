#include <stdio.h>

#define MOD (2553)

int main(void)
{
    int n;
    scanf("%d", &n);

    int answer = 0;
    int toadd = 0;
    int sumlast = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        sumlast = (sumlast + x) % MOD;
        toadd = (toadd + sumlast) % MOD;
        answer = (answer + toadd) % MOD;
    }

    printf("%d", answer);

    return 0;
}