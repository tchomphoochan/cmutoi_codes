#include <stdio.h>

#define INF 1e9

int n, q;
int tree[524287] = {}; // 2(2^18) - 1

int max(int a, int b)
{
    return a > b ? a : b;
}

void updateElement(int begin, int end, int pos, int to, int number)
{
    if (to > end || to < begin)
        return;
    if (begin == end)
    {
        if (begin == to)
            tree[pos] = number;
        return;
    }

    int mid = (begin + end) / 2;
    updateElement(begin, mid, 2 * pos + 1, to, number);
    updateElement(mid + 1, end, 2 * pos + 2, to, number);
    tree[pos] = max(tree[2 * pos + 1], tree[2 * pos + 2]);
}

int queryMax(int begin, int end, int pos, int from, int to)
{
    if (from > end || to < begin)
        return -INF;
    
    if (begin >= from && end <= to)
        return tree[pos];

    int mid = (begin + end) / 2;
    return max(queryMax(begin, mid, 2 * pos + 1, from, to),
    queryMax(mid + 1, end, 2 * pos + 2, from, to));
}

int main(void)
{
    scanf("%d%d", &n, &q);
    while (q--)
    {
        char t;
        int a, b;
        scanf(" %c%d%d", &t, &a, &b);
        if (t == 'U')
        {
            updateElement(0, n - 1, 0, a - 1, b);
        }
        else // if (t == 'P')
        {
            int x = queryMax(0, n - 1, 0, a - 1, b - 1);
            printf("%d\n", x);
        }
    }

    return 0;
}