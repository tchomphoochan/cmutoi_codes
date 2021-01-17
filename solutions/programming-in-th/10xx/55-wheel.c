#include <stdio.h>

int main(void)
{
    int n, k;
    int prizes[100] = {};
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &prizes[i]);

    int players[20] = {};
    int marker = -1;
    int prizeLeft = n;
    for (int i = 0; i < n && prizeLeft > 0; i++)
    {
        int dice;
        scanf("%d", &dice);
        for (int j = 0; j < dice; j++)
        {
            do
            {
                marker = (marker + 1) % n;
            }
            while (prizes[marker] == 0);
        }
        do
        {
            marker = (marker + 1) % n;
        }
        while (prizes[marker] == 0);
        players[i % k] += prizes[marker];
        prizes[marker] = 0;
        prizeLeft--;
    }

    for (int i = 0; i < k; i++)
        printf("%d\n", players[i]);
    
    return 0;
}