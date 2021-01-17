#include <stdio.h>
#include <stdbool.h>

int n, m;
int numA[50000];
int numB[50000];

int main(void)
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &numA[i], &numB[i]);

    for (int i = 0; i < m; ++i)
    {
        int x;
        scanf("%d", &x);
        for (int j = 0; j < n; ++j)
        {
            if (numA[j] <= x)
            {
                int temp = numA[j];
                numA[j] = numB[j];
                numB[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; ++i)
        printf("%d\n", numA[i]);

    return 0;
}