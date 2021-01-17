#include <bits/stdc++.h>

using namespace std;

const int N = 20010;

int n, now;
vector<int> ft[N];
vector<int> ver[N];

void init()
{
    for (int i = 1; i < N; ++i) {
        ft[i].clear(); ver[i].clear();
        ft[i].push_back(0);
        ver[i].push_back(0);
    }
}

void update(int x, int v)
{
    ++now;
    while (x < N) {
        ft[x].push_back(ft[x].back() + v);
        ver[x].push_back(now);
        x += x&(-x);
    }
}

int query(int d, int x)
{
    int ans = 0;
    while (x > 0) {
        auto p = (upper_bound(ver[x].begin(), ver[x].end(), d)-1) - ver[x].begin();
        ans += ft[x][p];
        x -= x&(-x);
    }
    return ans;
}

int arr[N];
vector<int> exi;

void genMapping()
{
    exi.clear();
    exi.push_back(0);
    for (int i = 1; i <= n; ++i)
        exi.push_back(arr[i]);
    sort(exi.begin(), exi.end());
    exi.resize(unique(exi.begin(), exi.end()) - exi.begin());
}

int getIndex(int x)
{
    int idx = lower_bound(exi.begin(), exi.end(), x) - exi.begin();
    return idx+1;
}

int getNum(int i)
{
    return exi[i-1];
}

int main()
{
    int q;
    scanf("%d%d", &n, &q);
    init();

    for (int i = 1; i <= n; ++i)
        scanf("%d", &arr[i]);
    genMapping();

    for (int i = 1; i <= n; ++i) {
        int idx = getIndex(arr[i]);
        update(idx, 1);
    }

    while (q--) {
        int a, b, s, e;
        scanf("%d%d%d%d", &a, &b, &s, &e);

        int ns = getIndex(s)-1;
        int ne = getIndex(e);
        if (getNum(ne) != e)
            --ne;

        int cntb = query(b, ne) - query(b, ns);
        int cnta = query(a-1, ne) - query(a-1, ns);
        printf("%d ", cntb - cnta);
    }

    return 0;
}