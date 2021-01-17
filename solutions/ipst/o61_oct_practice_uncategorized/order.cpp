#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int pre[N], post[N];
map<int, int> lh, rh;

void solve(int i1, int i2, int j1, int j2)
{
    if (i1 >= i2 || j1 >= j2)
        return;
    int u = pre[i1];
    for (int j = j1; j <= j2; ++j) {
        if (pre[i1+1] == post[j]) {
            int im = i1+(j-j1+1);
            lh[u] = pre[i1+1];
            if (im+1 <= i2)
                rh[u] = pre[im+1];
            solve(i1+1, im, j1, j);
            solve(im+1, i2, j+1, j2-1);
            return;
        }
    }
    assert(false); // this wasn't the problem
}

int cnt = 0;
void inorder(int u)
{
    if (u == 0) return;
    inorder(lh[u]);
    printf("%d\n", u);
    ++cnt;
    inorder(rh[u]);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &pre[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &post[i]);
    solve(1, n, 1, n);

    inorder(pre[1]);
    //assert(cnt == n); // THIS IS THE PROBLEM

    /*for (int i = 1; i <= n; ++i)
        printf("%d: %d-%d\n", i, lh[i], rh[i]);*/

    return 0;
}