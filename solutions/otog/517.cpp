#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9+10;
const int MR = 310;
const int MC = 5010;

int segr[4*MR], lazyr[4*MR], segc[MR][4*MC], lazyc[MR][4*MC];

void spread(int seg[], int lazy[], int pos, int begin, int end)
{
    if (lazy[pos] != 0) {
        seg[pos] = lazy[pos];
        if (begin != end) {
            lazy[2*pos+1] = lazy[pos];
            lazy[2*pos+2] = lazy[pos];
        }
        lazy[pos] = 0;
    }
}

void update(int seg[], int lazy[], int left, int right, int val, int pos, int begin, int end)
{
    spread(seg, lazy, pos, begin, end);
    if (begin > right || end < left)
        return;
    
    if (begin >= left && end <= right) {
        lazy[pos] = val;
        spread(seg, lazy, pos, begin, end);
        return;
    }

    int mid = (begin+end)/2;
    update(seg, lazy, left, right, val, 2*pos+1, begin, mid);
    update(seg, lazy, left, right, val, 2*pos+2, mid+1, end);
    seg[pos] = min(seg[2*pos+1], seg[2*pos+2]);
}

int query(int seg[], int lazy[], int left, int right, int pos, int begin, int end)
{
    spread(seg, lazy, pos, begin, end);
    if (begin > right || end < left)
        return INF;    

    if (begin >= left && end <= right)
        return seg[pos];
    
    int mid = (begin+end)/2;
    int l = query(seg, lazy, left, right, 2*pos+1, begin, mid);
    int r = query(seg, lazy, left, right, 2*pos+2, mid+1, end);
    return min(l, r);
}

int main()
{
    int R, C, M;
    scanf("%d%d%d", &R, &C, &M);

    while (M--) {
        int t;
        scanf("%d", &t);
        if (t == 1) { // set value
            int r, c, x;
            scanf("%d%d%d", &r, &c, &x);
            update(segc[r], lazyc[r], c, c, x, 0, 1, C);
            int nowmin = query(segc[r], lazyc[r], 1, C, 0, 1, C);
            update(segr, lazyr, r, r, nowmin, 0, 1, R);
        } else if (t == 2) { // set row value
            int r, x;
            scanf("%d%d", &r, &x);
            update(segc[r], lazyc[r], 1, C, x, 0, 1, C);
            update(segr, lazyr, r, r, x, 0, 1, R);
        } else if (t == 3) { // get value
            int r, c;
            scanf("%d%d", &r, &c);
            int ans = query(segc[r], lazyc[r], c, c, 0, 1, C);
            printf("%d\n", ans);
        } else if (t == 4) { // get min
            int ans = query(segr, lazyr, 1, R, 0, 1, R);
            printf("%d\n", ans);
        }
    }

    return 0;
}