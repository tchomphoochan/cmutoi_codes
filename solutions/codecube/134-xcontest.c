#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int count[28] = {};
    int ncount[28] = {};

    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        for (int j = 0; j < 28; j++)
        {
            if (x & (1 << j))
                ++count[j];
        }
    }

    for (int i = 0; i < 28; i++)
        ncount[i] = n - count[i];
    
    int m;
    scanf("%d", &m);
    long long answer = 0;
    for (int i = 0; i < m; i++)
    {
        int x;
        scanf("%d", &x);

        for (int j = 0; j < 28; j++)
        {
            if (x & (1 << j))
                answer += (1 << j) * (long long) ncount[j];
            else
                answer += (1 << j) * (long long) count[j];
        }
    }

    printf("%lld", answer);
    return 0;
}