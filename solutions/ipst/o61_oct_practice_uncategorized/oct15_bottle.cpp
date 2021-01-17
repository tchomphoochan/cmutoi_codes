#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int N = 100010;

bool done[N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    set<pii, greater<pii> > s;
    for (int i = 0; i < n; ++i) {
        int h;
        scanf("%d", &h);
        s.insert({h, i});
    }

    while (m--) {
        int lim;
        scanf("%d", &lim);
        int cnt = 0;
        auto pnt = s.lower_bound({lim, 0});
        vector<int> tobreak;
        for (auto it = s.begin(); it != pnt; ) {
            int h, i;
            tie(h, i) = *it;
            if (done[i]) {
                auto pit = it;
                ++it;
                s.erase(pit);
                continue;
            }
            if (h > lim) {
                done[i] = true;
                ++cnt;
                tobreak.push_back(i-1);
                tobreak.push_back(i+1);
            }
            ++it;
        }
        for (auto i : tobreak) {
            if (!done[i] && i >= 0 && i < n) {
                done[i] = true;
                ++cnt;
            }
        }
        printf("%d\n", cnt);
    }

    return 0;
}