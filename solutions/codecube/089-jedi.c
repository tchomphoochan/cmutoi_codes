#include <stdio.h>

int n, m;
int num[1000];

void rev(int start, int end)
{
    int size = end - start + 1;
    for (int i = 0; i < (size / 2); i++)
    {
        int temp = num[(start + i) % n];
        num[(start + i) % n] = num[(end - i) % n];
        num[(end - i) % n] = temp;
    }
}

int main(void)
{
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);

    for (int i = 0; i < m; i++)
    {
        int start, size, end;
        scanf("%d%d", &start, &size);
        start -= 1;
        end = start + size - 1;

        rev(start, end);
    }

    for (int i = 0; i < n; i++)
        printf("%d ", num[i]);

    return 0;
}