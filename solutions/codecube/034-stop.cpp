#include <cstdio>

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        bool cant[10] = {};
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            cant[x] = true;
        }
        int val[10];
        int v = 0;
        for (int i = 0; i < 10; ++i) {
            if (!cant[i])
                val[i] = v++;
        }
        int b = 10-n;

        int can = 0;
        for (int i = 0; i < 60; ++i) {
            int a = i/10;
            int b = i%10;
            if (cant[a] || cant[b])
                continue;
            ++can;
        }

        char t[10];
        scanf(" %s", t);
        int m = val[t[0]-'0']*b + val[t[1]-'0'];
        int s = val[t[3]-'0']*b + val[t[4]-'0'];
        int ms = val[t[6]-'0']*b + val[t[7]-'0'];
        ms = m*can*b*b + s*b*b + ms;
        s = ms/100;
        ms %= 100;
        m = s/60;
        s %= 60;
        printf("%02d:%02d:%02d\n", m, s, ms);
    }
    return 0;
}