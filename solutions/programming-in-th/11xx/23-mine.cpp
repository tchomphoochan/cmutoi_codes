#include <cstdio>
#include <deque>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, k, dn, ddn;
int a[N][N], qs[N][N], rqs[N][N], rsmx[N][N];
int cmx[N][N], smx[N][N], gmx[N][N];

void input(int (*rmx)[N])
{
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &a[i][j]);
            qs[i][j] = qs[i-1][j] + qs[i][j-1] - qs[i-1][j-1] + a[i][j];
        }
    }
    for (int i = 1; i <= dn; ++i) {
        for (int j = 1; j <= dn; ++j) {
            rqs[i][j] = qs[i+k-1][j+k-1] - qs[i+k-1][j-1] - qs[i-1][j+k-1] + qs[i-1][j-1];
        }
    }

    for (int i = 1; i <= dn; ++i) {
        deque<int> q;
        for (int j = 1; j <= dn; ++j) {
            while (!q.empty() && q.front() <= j-k)
                q.pop_front();
            while (!q.empty() && rqs[i][q.back()] <= rqs[i][j])
                q.pop_back();
            q.push_back(j);
            if (j >= k) {
                rsmx[i][j-k+1] = rqs[i][q.front()];
            }
        }
    }

    for (int j = 1; j <= ddn; ++j) {
        deque<int> q;
        for (int i = 1; i <= dn; ++i) {
            while (!q.empty() && q.front() <= i-k)
                q.pop_front();
            while (!q.empty() && rsmx[q.back()][j] <= rsmx[i][j])
                q.pop_back();
            q.push_back(i);
            if (i >= k) {
                rmx[i-k+1][j] = rsmx[q.front()][j];
            }
        }
    }

}

int main()
{
    scanf("%d%d", &n, &k);
    dn = n-k+1;
    ddn = dn-k+1;
    input(cmx);
    input(smx);
    input(gmx);

    int ans = 0;
    for (int i = 1; i <= dn-k+1; ++i) {
        for (int j = 1; j <= dn-k+1; ++j) {
            ans = max(ans, cmx[i][j]+smx[i][j]+gmx[i][j]);
        }
    }

    printf("%d", ans);
    return 0;
}