/**
 * Code Jam 2019 Qualification Round
 * D. Dat Bae
 *
 * aquablitz11 (2019-04-06)
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 1030;
const int F = 5;
char Q[F][N], A[F][N];

void build(int l, int r, int d, int z)
{
    if (d == F) return;
    for (int i = l; i <= r; i += z) {
        int j = min(i+z-1, r);
        fill(Q[d]+i, Q[d]+j+1, (i-l)/z%2==0 ? '0' : '1');
        build(i, j, d+1, z/2);
    }
}

vector<int> ans;
void read(int l, int r, int b, int e, int d, int z)
{
    //for (int i = 0; i < d; ++i) fprintf(stderr, "| ");
    //printf("read %d,%d %d,%d\n", l, r, b, e);
    if (b > e) {
        for (int i = l; i <= r; ++i)
            ans.push_back(i);
        return;
    }
    if (l == r) return;
    vector<int> li(1, 0);
    int prev = '0';
    for (int i = b; i <= e; ++i) {
        if (A[d][i] != prev)
            li.push_back(0);
        ++li.back();
        prev = A[d][i];
    }
    int sum = b;
    for (int i = l; i <= r; i += z) {
        int j = min(i+z-1, r);
        int x = (i-l)/z;
        x = x < li.size() ? li[x] : 0;
        read(i, j, sum, sum+x-1, d+1, z/2);
        sum += x;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        ans.clear();
        int n, b, _;
        scanf("%d%d%d", &n, &b, &_);
        build(0, n-1, 0, 1<<(F-1));
        for (int i = 0; i < F; ++i) {
            Q[i][n] = '\0';
            printf("%s\n", Q[i]);
            fflush(stdout);
            scanf("%s", A[i]);
        }
        read(0, n-1, 0, n-b-1, 0, 1<<(F-1));
        printf("%d", ans[0]);
        for (int i = 1; i < ans.size(); ++i)
            printf(" %d", ans[i]);
        printf("\n");
        fflush(stdout);
        scanf("%d", &_);
        if (_ != 1)
            return 0;
    }

    return 0;
}