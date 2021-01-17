#include <stdio.h>

int n;
int up[1010], down[1010];

void flipcard(int i) {
    int temp = up[i];
    up[i] = down[i];
    down[i] = temp;
}

void playgame(int v) {
    for (int i = 0; i < n; ++i) {
        if (up[i] <= v)
            flipcard(i);
    }
}

int main()
{
    int m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &up[i], &down[i]);

    for (int i = 0; i < m; ++i) {
        int v;
        scanf("%d", &v);
        playgame(v);
    }

    for (int i = 0; i < n; ++i) {
        printf("%d\n", up[i]);
    }

}