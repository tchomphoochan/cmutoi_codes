/**
 * Code Jam 2019 Qualification Round
 * A. Foregone Solution
 *
 * aquablitz11 (2019-04-06)
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        string S;
        cin >> S;
        string ans(S.size(), '0');
        int f = -1;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == '4') {
                S[i] = '3';
                ans[i] = '1';
                if (f == -1)
                    f = i;
            }
        }
        cout << "Case #" << t << ": " << S << " ";
        for (int i = f; i < ans.size(); ++i)
            cout << ans[i];
        cout << "\n";
    }

    return 0;
}