#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
const int N = 200010;
const int INF = 2e9;
int lazy[N], seg[N];

void spread(int pos, int begin, int end)
{
    seg[pos] += lazy[pos];
    if (begin != end) {
        lazy[2*pos+1] += lazy[pos];
        lazy[2*pos+2] += lazy[pos];
    }
    lazy[pos] = 0;
}

void update(int left, int right, int val, int pos, int begin, int end)
{
    spread(pos, begin, end);
    if (begin > right || end < left)
        return;
    if (begin >= left && end <= right) {
        lazy[pos] += val;
        spread(pos, begin, end);
        return;
    }

    int mid = (begin+end)/2;
    update(left, right, val, 2*pos+1, begin, mid);
    update(left, right, val, 2*pos+2, mid+1, end);
    seg[pos] = max(seg[2*pos+1], seg[2*pos+2]);
}

int query(int left, int right, int pos, int begin, int end)
{
    spread(pos, begin, end);
    if (begin > right || end < left)
        return -INF;
    if (begin >= left && end <= right)
        return seg[pos];
    
    int mid = (begin+end)/2;
    int l = query(left, right, 2*pos+1, begin, mid);
    int r = query(left, right, 2*pos+2, mid+1, end);
    return max(l, r);
} 

set<pii> inter;

void clear_interval(pii r)
{
    set<pii> nwi;
    for (auto i : inter) {
        if (i.second < r.first || i.first > r.second)
            continue;
        nwi.insert({
            max(i.first, r.first),
            min(i.second, r.second)
        });
    }
    inter = nwi;
}

void add_interval(pii r)
{
    /*printf("adding interval %d %d, currently have %d\n", r.first, r.second, inter.size());
    for (auto it : inter)
        printf("inter: %d %d\n", it.first, it.second);*/
    auto it = inter.insert(r).first;
    auto itl = prev(it);
    auto itr = next(it);
    if (it != inter.begin() && itl->second == it->first-1) {
        int lb = itl->first;
        int rb = it->second;
        inter.erase(itl);
        inter.erase(it);
        it = inter.insert({lb, rb}).first;
    }
    if (itr != inter.end() && itr->first == it->second+1) {
        int lb = it->first;
        int rb = itr->second;
        inter.erase(itr);
        inter.erase(it);
        it = inter.insert({lb, rb}).first;
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    // subtask 2
    add_interval({1, n});
    int curmx = 0;
    while (m--) {
        int a, b, x;
        scanf("%d%d%d", &a, &b, &x);
        update(a, b, x, 0, 0, n);
        if (seg[0] > curmx) {
            clear_interval({a, b});
            if (inter.size() == 0)
                add_interval({a, b});
        } else if (seg[0] == curmx) {
            add_interval({a, b});
        }
        curmx = max(curmx, seg[0]);
        printf("%d %d\n", curmx, inter.size());
    }

    return 0;
}