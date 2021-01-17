#include <bits/stdc++.h>

using namespace std;

const int N = 10010;

string s[N];
int l[N], h[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> s[i] >> l[i] >> h[i];
        int q;
        cin >> q;
        for (int i = 0; i < q; ++i) {
            int p;
            cin >> p;
            string found;
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (l[j] <= p && p <= h[j]) {
                    ++cnt;
                    found = s[j];
                }
            }
            if (cnt == 1)
                cout << found << "\n";
            else
                cout << "UNDETERMINED" << "\n";
        }

        if (T != 0)
            cout << "\n";
    }

    return 0;
}