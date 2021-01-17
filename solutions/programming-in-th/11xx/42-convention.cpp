#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int seg[4*N], lazy[4*N];

void apply(int pos, int begin, int end)
{
    if (!lazy[pos]) return;
    seg[pos] += lazy[pos];
    if (begin != end) {
        lazy[2*pos+1] += lazy[pos];
        lazy[2*pos+2] += lazy[pos];
    }
    lazy[pos] = 0;
}

int query(int left, int right, int pos, int begin, int end)
{
    if (begin > right || end < left)
        return 0;
    
    apply(pos, begin, end);
    if (begin >= left && end <= right)
        return seg[pos];
    
    int mid = (begin+end)/2;
    int l = query(left, right, 2*pos+1, begin, mid);
    int r = query(left, right, 2*pos+2, mid+1, end);
    return max(l, r);
}

void update(int left, int right, int val, int pos, int begin, int end)
{
    apply(pos, begin, end);
    if (begin > right || end < left)
        return;
    
    if (begin >= left && end <= right) {
        lazy[pos] += val;
        apply(pos, begin, end);
        return;
    }

    int mid = (begin+end)/2;
    update(left, right, val, 2*pos+1, begin, mid);
    update(left, right, val, 2*pos+2, mid+1, end);
    seg[pos] = max(seg[2*pos+1], seg[2*pos+2]);
}

int ql[N], qr[N];
vector<int> has;

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &ql[i], &qr[i]);
        has.push_back(ql[i]);
        has.push_back(qr[i]);
    }
    sort(has.begin(), has.end());
    has.resize(unique(has.begin(), has.end()) - has.begin());

    for (int i = 0; i < n; ++i) {
        int l = upper_bound(has.begin(), has.end(), ql[i])-1 - has.begin();
        int r = upper_bound(has.begin(), has.end(), qr[i])-1 - has.begin();
        if (query(l, r, 0, 0, has.size()-1) >= k) {
            printf("no\n");
        } else {
            printf("yes\n");
            update(l, r, 1, 0, 0, has.size()-1);
        }
    }

    return 0;
}