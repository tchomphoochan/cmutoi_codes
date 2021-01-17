#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define F first
#define S second
#define forx(i, x, y) for (int i = (x); i <= (y); ++i)
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define rofx(i, x, y) for (int i = x; i >= y; --i)
#define rofn(i, n) for (int i = n-1; i >= 0; --i)
#define rof1(i, n) for (int i = n; i >= 1; --i)
#define fora(x, v) for (auto x : v)
#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)

const int N = 2010;

string str[N];

mt19937 RNG(31415926);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int tc = 0;
    while (t--) {
        ++tc;

        int n, l;
        cin >> n >> l;
        vector<char> can[11] = {};
        unordered_set<string> has;
        forn(i, n) {
            ll h = 0;
            cin >> str[i];
            has.insert(str[i]);
            forn(j, l)
                can[j].pb(str[i][j]);
        }
        forn(j, l) {
            sort(all(can[j]));
            can[j].resize(unique(all(can[j])) - can[j].begin());
        }
        string ans = "-";
        int cnt = 5000;
        while (cnt--) {
            string nans = "";
            forn(j, l) {
                uniform_int_distribution<int> GEN(0, can[j].size()-1);
                nans.pb(can[j][GEN(RNG)]);
            }
            if (!has.count(nans)) {
                ans = nans;
                break;
            }
        }
        cout << "Case #" << tc << ": " << ans << endl;

    }

    return 0;
}