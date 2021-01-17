#include <bits/stdc++.h>

using namespace std;

const int N = 310;

int dist[N][N];
int deg[N];

int main()
{
    int n, t;
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            scanf("%d", &dist[i][j]);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            bool has = false;
            for (int k = 0; k < n && !has; ++k) {
                if (k != i && k != j && dist[i][k]+dist[k][j] == dist[i][j])
                    has = true;
            }
            if (!has)
                ++deg[i], ++deg[j];
        }
    }

    for (int i = 0; i < n; ++i) {
        if (deg[i] > 2) {
            printf("%d\n", i+1);
            if (t == 2)
                printf("%d\n", deg[i]);
            break;
        }
    }

    return 0;
}