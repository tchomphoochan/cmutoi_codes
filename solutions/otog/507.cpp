#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, q;
    string s, p;

    cin >> t;
    while (t--) {

        cin >> s;
        cin >> q;
        while (q--) {
            string p;
            cin >> p;
            int j = 0;
            bool yes = false;
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] == p[j]) {
                    if (++j == p.size()) {
                        yes = true;
                        break;
                    }
                }
            }
            if (yes) printf("Yes\n");
            else printf("No\n");
        }

    }

    return 0;
}