#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int N = 1000010;

int ft[N];
int n;

void update(int x)
{
    for (; x <= n; x+=x&-x)
        ++ft[x];
}

int query(int x)
{
    int ans = 0;
    for (; x > 0; x-=x&-x)
        ans += ft[x];
    return ans;
}

int arr[N];

int main()
{
    double x0, x1;
    scanf("%d%lf%lf", &n, &x0, &x1);
    vector<double> l(n), r(n), sl, sr;
    for (int i = 0; i < n; ++i) {
        double m, c;
        scanf("%lf%lf", &m, &c);
        l[i] = m*x0+c;
        r[i] = m*x1+c;
    }
    sl = l; sr = r;
    sort(sl.begin(), sl.end());
    sort(sr.begin(), sr.end());
    for (int i = 0; i < n; ++i) {
        int rl = upper_bound(sl.begin(), sl.end(), l[i])-1 - sl.begin();
        int rr = upper_bound(sr.begin(), sr.end(), r[i])-1 - sr.begin();
        arr[rl] = rr+1;
    }

    ll ans = 0;
    for (int i = n-1; i >= 0; --i) {
        ans += query(arr[i]-1);
        update(arr[i]);
    }
    printf("%lld", ans);

    return 0;
}