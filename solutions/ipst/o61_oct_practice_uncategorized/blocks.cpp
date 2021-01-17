#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;
using ll = long long;;
using pll = pair<ll, ll>;

// ===================================================

const int INF = 1e9;
// const ll INF = 1e18;

const int N = 100010;
const int M = 200010;

int n, m;
int height[N]; // fenwick tree
int up[N], down[N]; // data
int upft[N], downft[N];

void update(int ft[], int i, int x)
{
    if (i < 1 || i > n) return;
    for (; i <= n; i += i&-i)
        ft[i] += x;
}

int query(int ft[], int i)
{
    int ans = 0;
    for (; i > 0; i -= i&-i)
        ans += ft[i];
    return ans;
}

void setto(int data[], int ft[], int i, int x)
{
    int diff = x-data[i];
    update(ft, i, diff);
    data[i] = x;
}

int main()
{
    scanf("%d%d", &n, &m);
    while (m--) {

        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);

        if (t == 1) { // add block
            update(height, x, 1);
            update(height, y+1, -1);
            int hxl = query(height, x-1);
            int hx = query(height, x);
            int hy = query(height, y);
            int hyr = query(height, y+1);
            if (hx > hxl) {
                setto(up, upft, x-1, 1);
                setto(down, downft, x, 0);
            } else if (hx == hxl) {
                setto(up, upft, x-1, 0);
                setto(down, downft, x, 0);
            } else {
                setto(up, upft, x-1, 0);
                setto(down, downft, x, 1);
            }
            if (hy > hyr) {
                setto(up, upft, y, 0);
                setto(down, downft, y+1, 1);
            } else if (hy == hyr) {
                setto(up, upft, y, 0);
                setto(down, downft, y+1, 0);
            } else {
                setto(up, upft, y, 1);
                setto(down, downft, y+1, 0);
            }
        } else if (t == 2) { // height
            int hx = query(height, x);
            int hy = query(height, y);
            printf("%d %d\n", hx, hy);
        } else { // height up down
            int hx = query(height, x);
            int hy = query(height, y);
            int cu = query(upft, y-1) - query(upft, x-1);
            int cd = query(downft, y) - query(downft, x);
            printf("%d %d %d %d\n", hx, hy, cu, cd);
        }
        /*printf("query: %d %d %d\n", t, x, y);
        printf("height\n");
        for (int i = 1; i <= n; ++i)
            printf("%d ", query(height, i));
        printf("\n");
        printf("up\n");
        for (int i = 1; i <= n; ++i)
            printf("%d ", up[i]);
        printf("\n");
        printf("upft\n");
        for (int i = 1; i <= n; ++i)
            printf("%d ", query(upft, i));
        printf("\n");
        printf("down\n");
        for (int i = 1; i <= n; ++i)
            printf("%d ", down[i]);
        printf("\n");
        printf("downft\n");
        for (int i = 1; i <= n; ++i)
            printf("%d ", query(downft, i));
        printf("\n");*/
    }
    
    return 0;
}