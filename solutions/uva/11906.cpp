/* 11906 - Knight in a War Grid */

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

#define N 110

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {

        int r, c, n, m, w;
        bool cant[N][N] = {};
        bool vit[N][N] = {};
        scanf("%d%d%d%d%d", &r, &c, &n, &m, &w);
        while (w--) {
            int y, x;
            scanf("%d%d", &y, &x);
            cant[y][x] = true;
        }

        queue<ii> going;
        going.push({0, 0});
        while (!going.empty()) {
            ii go = going.front();
            going.pop();
            int y = go.first;
            int x = go.second;
            if (vit[y][x])
                continue;
            vit[y][x] = true;
            ii atmpts[] = {
                {y+m, x+n},
                {y-m, x-n},
                {y+m, x-n},
                {y-m, x+n},
                {y+n, x+m},
                {y-n, x-m},
                {y+n, x-m},
                {y-n, x+m}
            };
            for (auto atmpt : atmpts) {
                int ny = atmpt.first;
                int nx = atmpt.second;
                if (ny < 0 || ny >= r || nx < 0 || nx >= c
                || vit[ny][nx] || cant[ny][nx])
                    continue;
                going.push(atmpt);
            }
        }
        
        int even = 0, odd = 0;
        for (int y = 0; y < r; ++y) {
            for (int x = 0; x < c; ++x) {
                if (!vit[y][x])
                    continue;
                ii atmpts[] = {
                    {y+m, x+n},
                    {y-m, x-n},
                    {y+m, x-n},
                    {y-m, x+n},
                    {y+n, x+m},
                    {y-n, x-m},
                    {y+n, x-m},
                    {y-n, x+m}
                };
                std::sort(atmpts, atmpts+8);
                auto end = std::unique(atmpts, atmpts+8);
                int cnt = 0;
                for (auto it = atmpts; it != end; ++it) {
                    int ny = it->first;
                    int nx = it->second;
                    if (ny < 0 || ny >= r || nx < 0 || nx >= c || cant[ny][nx])
                        continue;
                    ++cnt;
                }
                if (cnt&1)
                    ++odd;
                else
                    ++even;
            }
        }

        printf("Case %d: %d %d\n", t, even, odd);

    }
    return 0;
}