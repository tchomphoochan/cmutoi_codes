#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 55;

ll p2[N];
char s[N];

int main()
{
    for (int i = 0; i < N; ++i)
        p2[i] = (1LL<<i);
    scanf("%s", s);
    int n = strlen(s);

    vector<int> pos;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1')
            pos.push_back(n-i);
    }
    ll ans = 0;
    for (int i = 0; i < pos.size(); ++i) {
        int k = pos[i];
        if (i % 2 == 0) {
            if (i == pos.size()-1)
                ans += p2[k]-1;
            else
                ans += p2[k-1];
        } else {
            ans += p2[pos[i-1]-1] - p2[k];
        }
    }
    printf("%lld\n", ans);

    return 0;
}
