/**
 * toi15_archery
 * 
 * aquablitz11 (2020)
 * 100/100
 */

#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using ll = long long;

#define h second
#define p first

const int N = 500010;
pii arr[N];
ll qsh[N], qsp[N];

int main()
{
    int n;
    scanf("%d", &n);
    int mnh = 2e9, mnp;
    vector<ll> intp;
    for (int i = 1; i <= n; ++i) {
        int h;
        scanf("%d", &h);
        arr[i].second = h;
        mnh = min(mnh, h);
    }
    for (int i = 1; i <= n; ++i) {
        int p;
        scanf("%d", &p);
        arr[i].first = p;
        mnp = min(mnp, p);
        intp.push_back(p);
    }
    sort(arr+1, arr+n+1);
    intp.push_back(mnh);
    sort(intp.begin(), intp.end());
    for (int i = 1; i <= n; ++i) {
        qsh[i] = qsh[i-1]+arr[i].h;
        qsp[i] = qsp[i-1]+arr[i].p;
    }
    pair<long long, int> minans(1e18, 1);
    int i = 1;
    for (auto x : intp) {
        //printf("%d %d\n", arr[i].p, arr[i].h);
        while (i <= n && arr[i].p < x)
            ++i;
        if (i > n || x > mnh)
            continue;
        ll ld = qsp[i-1];
        ll ld2 = qsh[i-1] - (ll)(i-1)*x;
        ll rd = (qsp[n]-qsp[i-1])-(ll)x*(n-i+1);
        //printf("%lld %lld %lld\n", ld, ld2, rd);
        minans = min(minans, make_pair(ld+ld2+rd, (int)x));
    }
    printf("%d %lld\n", minans.second, minans.first);
    
    return 0;
}