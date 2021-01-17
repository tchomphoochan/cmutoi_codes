#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
int v[N], ft[N];

void add(int x)
{
    v[x] = 1;
    for (; x <= n; x += x&(-x))
        ++ft[x];
}

int query(int x)
{
    int ans = 0;
    for (; x > 0; x -= x&(-x))
        ans += ft[x];
    return ans;
}

int count_from(int l, int s)
{
    int r = (l+s-1)%n;
    if (r == 0)
        r = n;
    return r;
}

int get_size(int l, int s)
{
    int r = count_from(l, s);
    if (l <= r)
        return s - (query(r) - query(l-1));
    else
        return s - (query(n) - query(l-1) + query(r));
}

int main()
{
    int k;
    scanf("%d%d", &n, &k);

    int alive = n;
    int pnt = 1;
    while (alive > 1) {
        k = k%alive == 0 ? alive : k%alive;
        int left = k;
        int right = n;
        while (left < right) {
            int mid = (left+right)/2;
            if (get_size(pnt, mid) < k)
                left = mid+1;
            else
                right = mid;
        }
        k = count_from(pnt, right);
        add(k);
        pnt = count_from(k, 2);
        --alive;
    }

    for (int i = 1; i <= n; ++i) {
        if (!v[i])
            printf("%d", i);
    }

    return 0;
}