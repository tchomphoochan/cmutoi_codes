#define DEBUG 0 // set to 0 when not debugging

#include <stdio.h>

#if DEBUG == 1
#include <time.h>
#endif

char board[1000][1000] = {};
int down[1000][1000] = {};
int up[1000][1000] = {};

int main(void)
{
    #if DEBUG == 1
    clock_t begin = clock();
    #endif

    int k;
    scanf("%d", &k);

    while (k--)
    {
        int m, n;
        scanf("%d%d", &m, &n);

        for (int r = 0; r < m; ++r)
        {
            scanf(" ");
            for (int c = 0; c < n; ++c)
                scanf("%c", &board[r][c]);
        }

        int best = 0;

        // down
        for (int c = 0; c < n; ++c)
        {
            int d = 0;
            for (int r = 0; r < m; ++r) 
            {
                if (board[r][c] == '0')
                    d = -1;
                down[r][c] = ++d;
            }
        }

        // up
        for (int c = 0; c < n; ++c)
        {
            int d = 0;
            for (int r = m - 1; r >= 0; --r)
            {
                if (board[r][c] == '0')
                    d = -1;
                up[r][c] = ++d;
            }
        }

        // right
        for (int r = 0; r < m; ++r)
        {
            int d = 0;
            for (int c = 0; c < n; ++c)
            {
                if (board[r][c] == '0')
                    d = -1;
                ++d;
                int newb = (up[r][c] > down[r][c] ? up[r][c] : down[r][c]) + d - 1;
                if (newb > best)
                    best = newb;
            }
        }

        // left
        for (int r = 0; r < m; ++r)
        {
            int d = 0;
            for (int c = n - 1; c >= 0; --c)
            {
                if (board[r][c] == '0')
                    d = -1;
                ++d;
                int newb = (up[r][c] > down[r][c] ? up[r][c] : down[r][c]) + d - 1;
                if (newb > best)
                    best = newb;
            }
        }

        printf("%d\n", best);
    }

    #if DEBUG == 1
    clock_t end = clock();
    fprintf(stderr, "%.3lf seconds", ((double) end - begin) / CLOCKS_PER_SEC);
    #endif

    return 0;
}