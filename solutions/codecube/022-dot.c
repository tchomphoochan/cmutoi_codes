#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int count = 0;
    bool used[1002001] = {};
    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        int d = x * 1001 + y;
        if (!used[d])
        {
            used[d] = true;
            count++;
        }
    }

    printf("%d", count);
    return 0;
}