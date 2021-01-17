#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 500010;
const int INF = 1e9;

vector<pii> v;
int n;
int arr[N];
int *ft, *old;

void update(int ft[], int x)
{
    ++x;
    for (; x <= n; x += x&-x)
        ++ft[x];
}

int query(int ft[], int x)
{
    int ans = 0;
    ++x;
    for (; x > 0; x -= x&-x)
        ans += ft[x];
    return ans;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        v.push_back({arr[i], i});
    }
    ft = new int[N]();
    old = new int[N]();
    sort(v.begin(), v.end(), greater<pii>());
    ll ans = 0;
    for (int p = 0; p < n; ++p) {

        int x, i;
        tie(x, i) = v[p];
        if (p > 0 && x != v[p-1].first) {
            for (int i = 1; i <= n; ++i)
                old[i] += ft[i];
        }

        int left = 0;
        int right = i;
        while (left < right) {
            int mid = (left+right+1)/2;
            if (query(old, i) - query(old, i-mid-1) > 0)
                right = mid-1;
            else
                left = mid;
        }
        ans += query(ft, i) - query(ft, i-right-1) + (i-right == 0 ? 0 : 1);

        left = 0;
        right = n-i-1;
        while (left < right) {
            int mid = (left+right+1)/2;
            if (query(old, i+mid) - query(old, i-1) > 0)
                right = mid-1;
            else
                left = mid;
        }
        ans += query(ft, i+right) - query(ft, i) + (i+right == n-1 ? 0 : 1);

        update(ft, i);
    }
    printf("%lld", ans);

    return 0;
}