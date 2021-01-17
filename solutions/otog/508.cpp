#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int N = 30001;
const int M = 300001;
const int SN = 175;
const int V = 1000001;

int arr[N], cnt[V];
int ql[M], qr[M], qi[M];
pii ans[M];
set<pii> tree;

inline void remove(int i) { tree.erase({cnt[arr[i]]--, arr[i]}); }
inline void add(int i) { tree.insert({++cnt[arr[i]], arr[i]}); }

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int sn = sqrt(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &ql[i], &qr[i]);
        qi[i] = i;
    }

    sort(qi, qi+m, [&] (int a, int b) {
        int ap = ql[a]/sn;
        int bp = ql[b]/sn;
        return ap < bp || (ap == bp && qr[a] < qr[b]);
    });

    int l = ql[0], r = ql[0];
    for (int i = 0; i < m; ++i) {
        if (r > qr[qi[i]]) {
            tree.clear();
            fill(cnt, cnt+V, 0);
            l = ql[qi[i]];
            r = ql[qi[i]];
        }
        while (l < ql[qi[i]])
            remove(l++);
        while (l > ql[qi[i]])
            add(--l);
        while (r < qr[qi[i]])
            add(r++);
        ans[qi[i]] = *(--tree.end());
    }

    for (int i = 0; i < m; ++i)
        printf("%d %d\n", ans[i].second, ans[i].first);

    return 0;
}