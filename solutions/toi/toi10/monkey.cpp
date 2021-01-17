/**
 * toi10_monkey
 * 
 * aquablitz11 (2017)
 * 100/100
 */

#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

#define N 200010
#define K 1000010

int score[N];
ii pillar[K];

bool can[N];

int main()
{
    int m, n, k;
    scanf("%d%d%d", &m, &n, &k);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &score[i]);
    }

    for (int i = 0; i < k; ++i) {
        scanf("%d%d", &pillar[i].first, &pillar[i].second);
    }

    sort(pillar, pillar+k, [&] (ii a, ii b) {
        return a.second < b.second;
    });

    int x;
    scanf("%d", &x);
    can[x] = true;
    if (x > 1)
        can[x-1] = true;
    if (x < n)
        can[x+1] = true;
    for (int i = 0; i < k; ++i) {
        swap(can[pillar[i].first], can[pillar[i].first+1]);
        if (pillar[i].first == x)
            ++x;
        else if (pillar[i].first+1 == x)
            --x;
        can[x] = true;
        if (x > 1)
            can[x-1] = true;
        if (x < n)
            can[x+1] = true;
    }
    
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
        if (can[i])
            mx = max(mx, score[i]);
    }

    printf("%d\n", mx);
    if (mx == score[x])
        printf("NO\n");
    else
        printf("USE\n");

    return 0;
}