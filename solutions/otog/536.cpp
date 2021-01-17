#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5e5+10;

char state[N];
int L[N], R[N];
int indeg[N];

int oc;
int order[N];

ll cnt[N];

int main()
{
    ll k;
    int n;
    scanf("%lld%d", &k, &n);

    for (int i = 1; i <= n; ++i) {
        scanf(" %c%d%d", &state[i], &L[i], &R[i]);
        ++indeg[L[i]];
        ++indeg[R[i]];
    }

    queue<int> nxt;
    for (int i = 1; i <= n; ++i) {
        if (!indeg[i])
            nxt.push(i);
    }

    while (!nxt.empty()) {
        int u = nxt.front();
        order[oc++] = u;
        nxt.pop();
        if (--indeg[L[u]] == 0)
            nxt.push(L[u]);
        if (--indeg[R[u]] == 0)
            nxt.push(R[u]);
    }
    assert(oc == n+1);

    cnt[1] = k;
    for (int i = 0; i < n; ++i) {
        int u = order[i];
        if (state[u] == 'R') {
            cnt[L[u]] += cnt[u]/2;
            cnt[R[u]] += (cnt[u]+1)/2;
        } else {
            cnt[L[u]] += (cnt[u]+1)/2;
            cnt[R[u]] += cnt[u]/2;
        }
    }

    for (int i = 1; i <= n; ++i)
        printf("%c", (cnt[i] % 2 == 0) == (state[i] == 'L') ? 'L' : 'R');

    return 0;
}