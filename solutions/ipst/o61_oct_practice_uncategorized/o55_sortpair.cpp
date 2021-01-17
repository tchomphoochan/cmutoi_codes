#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pii> v;
    for (int i = 0; i < n; ++i) {
        pii x;
        cin >> x.first >> x.second;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i)
        cout << v[i].first << " " << v[i].second << "\n";

    return 0;
}