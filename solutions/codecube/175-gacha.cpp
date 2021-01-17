#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define F first
#define S second

const int N = 100010;

int cnt = 0;
int has[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int mx = 0;
    int n, k;
    string s;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        if (s == "UR")
            ++has[i];
        cnt += has[i];
        if (i >= k) {
            cnt -= has[i-k];
            mx = max(mx, cnt);
        }
    }
    cout << mx;

    return 0;
}