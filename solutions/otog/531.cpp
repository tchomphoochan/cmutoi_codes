#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> Q; // right,left, index

const int N = 2000010;
const int V = 50010;

int n, m;
//Q query[N];
int qr[N], ql[N];//, qi[N];
int arr[N], ft[N], last[V], answ[N], qix[N];

inline void update(int i, int x)
{
    for (; i <= n; i += i&-i)
        ft[i] += x;
}

inline int get(int i)
{
    int ans = 0;
    for (; i > 0; i -= i&-i)
        ans += ft[i];
    return ans;
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < m; ++i) {
        //int x, y;
        //scanf("%d%d", &x, &y);
        scanf("%d%d", &ql[i], &qr[i]);
        //qi[i] = i;
        //query[i] = {{y, x}, i};
        qix[i] = i;
    }

    sort(qix, qix+m, [&] (int a, int b) {
        if (qr[a] != qr[b]) return qr[a] < qr[b];
        else if (ql[a] != ql[b]) return ql[a] < ql[b];
        //return query[a] < query[b];
    });
    //sort(query, query+m);
    int c = 0;
    for (int i = 1; i <= n; ++i) {
        if (last[arr[i]]) {
            update(last[arr[i]], -1);
        }
        update(i, 1);
        last[arr[i]] = i;
        while (c < m && qr[qix[c]] == i) {//query[qix[c]].first.first == i) {
            //int x, y, q;
            /*x = ql[qix[c]];
            y = qr[qix[c]];
            q = qi[qix[c]];*/
            /*y = query[qix[c]].first.first;
            x = query[qix[c]].first.second;
            q = query[qix[c]].second;*/
            //answ[q] = get(y) - get(x-1);
            answ[qix[c]] = get(qr[qix[c]]) - get(ql[qix[c]]-1);
            ++c;
        }
    }

    for (int i = 0; i < m; ++i)
        printf("%d\n", answ[i]);

    return 0;
}