#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main()
{
    int n;
    while (scanf("%d", &n) != EOF) {
        vector<pii> A, B;
        for (int i = 0; i < n; ++i) {
            scanf(" ");
            for (int j = 0; j < n; ++j) {
                char x;
                scanf("%c", &x);
                if (x == '1')
                    A.push_back({i, j});
                else if (x == '3')
                    B.push_back({i, j});
            }
        }
        int mx = 0;
        for (auto a : A) {
            int dist = 1e9;
            for (auto b : B) {
                dist = min(dist, abs(a.first-b.first) + abs(a.second-b.second));
            }
            mx = max(mx, dist);
        }
        printf("%d\n", mx);
    }

    return 0;
}