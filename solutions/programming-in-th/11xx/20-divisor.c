#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int answer[1000001] = {};

typedef struct
{
    int x, y, d, answer;
} Range;

void sieve(int max)
{
    for (int multi = 2; multi <= max; multi++)
    {
        for (int n = multi; n <= max; n += multi)
            answer[n]++;
    }
}

int main(void)
{
    int q;
    scanf("%d", &q);

    Range range[100];
    int max = 1;
    for (int i = 0; i < q; i++)
    {
        scanf("%d%d%d", &range[i].x, &range[i].y, &range[i].d);
        if (range[i].y > max)
            max = range[i].y;
    }

    sieve(max);

    for (int i = 0; i < q; i++)
    {
        int count = 0;
        for (int j = range[i].x; j <= range[i].y; j++)
        {
            if (answer[j] + 1 == range[i].d)
                count++;
        }
        printf("%d\n", count);
    }
}