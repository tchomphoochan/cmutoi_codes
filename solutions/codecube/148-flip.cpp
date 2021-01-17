#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
const int N = 200010;

int n, m, c;
int front[N], back[N], flip[N];

int seg[N<<1], ft[N];
vector<int> coor;
vector<int> event[N];

int pos(int x);
void build();
int rmq(int l, int r);
void update(int i, int x);
int psq(int i);

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &front[i], &back[i]);
        coor.push_back(front[i]);
        coor.push_back(back[i]);
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &flip[i]);
        coor.push_back(flip[i]);
    }
    sort(coor.begin(), coor.end());
    coor.resize(unique(coor.begin(), coor.end()) - coor.begin());
    c = coor.size();
    for (int i = 1; i <= m; ++i)
        seg[c+pos(flip[i])] = max(seg[c+pos(flip[i])], i);
    build();
    
    for (int i = 1; i <= n; ++i) {
        auto card = minmax({front[i], back[i]});
        int ix = rmq(pos(card.first), pos(card.second)-1);
        if (ix != 0)
            tie(back[i], front[i]) = card;
        event[max(ix,1)].push_back(i);
    }

    for (int i = m; i >= 1; --i) {
        update(c+1-pos(flip[i]), 1);
        for (auto j : event[i]) {
            auto card = minmax({front[j], back[j]});
            int cnt = psq(c+1-pos(card.second));
            if (cnt&1) swap(front[j], back[j]);
        }
    }

    for (int i = 1; i <= n; ++i)
        printf("%d\n", front[i]);

    return 0;
}

int pos(int x)
{
    auto ptr = upper_bound(coor.begin(), coor.end(), x)-1;
    return ptr-coor.begin();
}

void build()
{
    for (int i = c-1; i > 0; --i)
        seg[i] = max(seg[i<<1], seg[i<<1|1]);
}

int rmq(int l, int r)
{
    ++r;
    int ans = 0;
    for (l += c, r += c; l < r; l >>= 1, r >>= 1) {
        if (l&1) ans = max(ans, seg[l++]);
        if (r&1) ans = max(ans, seg[--r]);
    }
    return ans;
}

void update(int i, int x)
{
    for (; i <= c+1; i += i&-i)
        ft[i] += x;
}

int psq(int i)
{
    int ans = 0;
    for (; i > 0; i -= i&-i)
        ans += ft[i];
    return ans;
}