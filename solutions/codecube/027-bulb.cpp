#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int n;
queue<pair<int, int> > nodes;
bool closed[1048576] = {};

int main()
{
    scanf("%d", &n);
    int max1 = 1 << n;

    int start = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        start <<= 1;
        start += x;
    }
    
    nodes.push({start, 0});

    while (!nodes.empty()) {
        pair<int, int> ii = nodes.front();
        int node = ii.first;
        int length = ii.second;
        nodes.pop();

        if (closed[node])
            continue;
        closed[node] = true;
        if (node == 0) {
            printf("%d", length);
            return 0;
        }

        for (int i = 1; i < max1; i <<= 1) {
            int newNum = node ^ i;
            if (i >> 1 >= 1)
                newNum ^= (i >> 1);
            if (i << 1 < max1)
                newNum ^= (i << 1);
            nodes.push({newNum, length+1});
        }
    }

    printf("-1");
    return 0;
}