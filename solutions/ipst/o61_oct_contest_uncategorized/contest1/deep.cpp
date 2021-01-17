#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 200010;
const int LN = 25;

int s, a, b;
inline int dir()
{
    int res = ((s & 8) >> 3);
    s = (s * a + b) % 40507;
    return res;
}

int n, m;
int parent[N], left[N], right[N], depth[N];
int nextdec[N]; // from node u, at depth nextdec = decision node (include that node)
int child[N][LN];

int generate_tree(int u, int d)
{
    depth[u] = d;
    if (left[u] == -1 && right[u] == -1) {
        return nextdec[u] = u;
    }
    if (left[u] != -1 && right[u] != -1) {
        generate_tree(left[u], d+1);
        generate_tree(right[u], d+1);
        return nextdec[u] = u;
    }
    return nextdec[u] = generate_tree(left[u], d+1);
}

int solve(int u, int l)
{
    if (left[u] == -1 && right[u] == -1)
        return u;
    if (l <= depth[nextdec[u]]) {
        // binary descending and answer
        for (int j = LN-1; j >= 0; --j) {
            if (child[u][j] != -1 && depth[child[u][j]] <= l)
                 u = child[u][j];
        }
        return u;
    } else if (left[u] != -1 && right[u] != -1) {
        // decision vertex
        int d = dir();
        if (d == 0) return solve(left[u], l);
        else return solve(right[u], l);
    } else {
        // still long way to go: go to decision first
        solve(nextdec[u], l);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        parent[i] = -1;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &left[i], &right[i]);
        if (left[i] == -1 && right[i] != -1)
            swap(left[i], right[i]);
        if (left[i] != -1) parent[left[i]] = i;
        if (right[i] != -1) parent[right[i]] = i;
        child[i][0] = left[i];
    }
    generate_tree(0, 0);
    for (int j = 1; j < LN; ++j) {
        for (int i = 0; i < n; ++i) {
            child[i][j] = child[i][j-1] == -1 ? -1 : child[child[i][j-1]][j-1];
        }
    }

    /*printf("\nparent\n");
    for (int i = 0; i < n; ++i)
        printf("%d ", parent[i]);
    printf("\nchild\n");
    for (int i = 0; i < n; ++i) {
        printf("[%d]: ", i);
        for (int j = 0; j < LN; ++j) {
            printf("%d ", child[i][j]);
        }
        printf("\n");
    }*/

    while (m--) {
        int l;
        scanf("%d%d%d%d", &l, &s, &a, &b);
        printf("%d\n", solve(0, l));
    }

    return 0;
}