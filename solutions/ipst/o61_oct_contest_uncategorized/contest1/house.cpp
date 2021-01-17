#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

typedef long long ll;

int n, m;
ll arr[N], aseg[N<<2], lseg[N<<2], rseg[N<<2], qs[N];

ll sum(int l, int r)
{
    if (l > r) return 0;
    return qs[r] - (l-1 >= 0 ? qs[l-1] : 0);
}

void init(int pos, int begin, int end)
{
    if (begin == end) {
        aseg[pos] = lseg[pos] = rseg[pos] = max(0LL, arr[begin]);
        return;
    }

    int mid = (begin+end)/2;
    init(2*pos+1, begin, mid);
    init(2*pos+2, mid+1, end);
    lseg[pos] = max(lseg[2*pos+1], sum(begin, mid) + lseg[2*pos+2]);
    rseg[pos] = max(rseg[2*pos+2], sum(mid+1, end) + rseg[2*pos+1]);
    aseg[pos] = max(max(aseg[2*pos+1], aseg[2*pos+2]), rseg[2*pos+1] + lseg[2*pos+2]);
}

struct Range {
    ll lix, rix, ans, left, right, sum;
    bool operator<(const Range &other) const {
        return lix < other.lix;
    }
};

vector<Range> ranges;

void getrange(int left, int right, int pos, int begin, int end)
{
    if (begin > end || begin > right || end < left)
        return;
    if (begin >= left && end <= right) {
        ranges.push_back({begin, end, aseg[pos], lseg[pos], rseg[pos], sum(begin, end)});
        return;
    }
    int mid = (begin+end)/2;
    getrange(left, right, 2*pos+1, begin, mid);
    getrange(left, right, 2*pos+2, mid+1, end);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &arr[i]);
        if (i == 0) qs[i] = arr[i];
        else qs[i] = qs[i-1] + arr[i];
    }
    init(0, 0, n-1);

    while (m--) {
        int left, right;
        scanf("%d%d", &left, &right);
        if (left > right) {
            printf("0\n");
            return 0;
        }

        ranges.clear();
        getrange(left, right, 0, 0, n-1);

        while (ranges.size() > 1) {
            vector<Range> nranges;
            sort(ranges.begin(), ranges.end());
            while (ranges.size() >= 2) {
                Range rrange = ranges.back();
                ranges.pop_back();
                Range lrange = ranges.back();
                ranges.pop_back();

                ll nl = lrange.lix;
                ll nr = rrange.rix;
                ll nans = max(max(lrange.ans, rrange.ans), lrange.right + rrange.left);
                ll nleft = max(lrange.left, lrange.sum + rrange.left);
                ll nright = max(rrange.right, rrange.sum + lrange.right);
                ll nsum = lrange.sum + rrange.sum;
                nranges.push_back({nl, nr, nans, nleft, nright, nsum});
            }
            if (ranges.size() == 1) nranges.push_back(ranges[0]);
            ranges = nranges;
        }

        printf("%lld\n", ranges[0].ans);

    }

    return 0;
}