#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 20;

int n;
int A[N*N][N*N];
int B[N];

int calc(int x, int y)
{
    return (x < 0 || x >= n || y < 0 || y >= n ? -1 : (x)*n+(y));
}

void swapRow(int x, int y)
{
    for (int j = 0; j <= n*n; ++j) {
        swap(A[x][j], A[y][j]);
    }
}

void addRow(int from, int to)
{
    for (int j = 0; j <= n*n; ++j) {
        A[to][j] = (A[to][j]+A[from][j])%2;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int u = calc(i,j);
            scanf("%d", &A[u][n*n]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            scanf("%d", &x);
            int u = calc(i,j);
            A[u][n*n] = (A[u][n*n]+x)%2;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int u = calc(i,j);
            int v[] = {u, calc(i-1,j), calc(i+1,j), calc(i,j-1), calc(i,j+1)};
            for (int k = 0; k < 5; ++k) {
                if (v[k] == -1)
                    v[k] = u;    
                A[v[k]][u] = 1;
            }
        }
    }

    for (int i = 0; i < n*n; ++i) {
        for (int j = i; j < n*n; ++j) {
            if (A[j][i] == 1) {
                swapRow(i, j);
                break;
            }
        }
        for (int j = 0; j < n*n; ++j) {
            if (j == i)
                continue;
            if (A[j][i] == 1)
                addRow(i, j);
        }
    }

    int cnt = 0;
    for (int i = 0; i < n*n; ++i) {
        if (A[i][n*n] == 1)
            ++cnt;
    }
    
    printf("%d\n", cnt);
    for (int i = 0; i < n*n; ++i) {
        if (A[i][n*n] == 1) {
            printf("%d %d\n", i/n+1, i%n+1);
        }
    }

    return 0;
}