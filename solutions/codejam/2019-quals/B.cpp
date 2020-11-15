/**
 * Code Jam 2019 Qualification Round
 * B. You Can Go Your Own Way
 *
 * aquablitz11 (2019-04-06)
 * Solution simply finds the flipped solution.
 * Simple proof: Two people can only walk on the same edge when they're currently at the same node.
 * To be at the same node, they must have walked the same number of steps. However, by construction,
 * we ensure that the next step is opposite of each other. So, it's impossible to walk along the same edge.
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        string S;
        cin >> n >> S;
        for (int i = 0; i < S.size(); ++i)
            S[i] = S[i] == 'E' ? 'S' : 'E';
        cout << "Case #" << t << ": " << S << "\n";
    }
    
    return 0;
}