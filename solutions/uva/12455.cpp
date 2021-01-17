#include <bits/stdc++.h>

using namespace std;

const int N = 25;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int k, n;
        scanf("%d%d", &k, &n);
        set<int> pos, npos;
        pos.insert(0);
        for (int i = 0; i < n; ++i) {
            int w;
            scanf("%d", &w);
            npos.clear();
            for (auto p : pos) {
                npos.insert(p);
                npos.insert(p+w);
            }
            swap(pos, npos);
        }
        if (pos.count(k))
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}