#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int pmem[N];
list<int>::iterator it[N];

int main()
{
    int p, s, m;
    int nowmem = 0;
    list<int> prog;
    scanf("%d%d%d", &p, &s, &m);
    for (int i = 1; i <= p; ++i) {
        scanf("%d", &pmem[i]);
        it[i] = prog.end();
    }

    for (int i = 0; i < s; ++i) {
        int x;
        scanf("%d", &x);
        if (it[x] != prog.end()) {
            nowmem -= pmem[x];
            prog.erase(it[x]);
            it[x] = prog.end();
        }
        while (nowmem + pmem[x] > m) {
            int r = prog.front();
            nowmem -= pmem[r];
            prog.pop_front();
            it[r] = prog.end();
        }
        nowmem += pmem[x];
        prog.push_back(x);
        it[x] = prev(prog.end());
    }
    printf("%d\n", m-nowmem);

    return 0;
}