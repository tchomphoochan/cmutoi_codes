#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 1000010;

int count(int x)
{
    int cnt = 0, pnt = 2;
    while (x != 1) {
        while (x % pnt == 0) {
            x /= pnt;
            ++cnt;
        }
        ++pnt;
    }
    if (x != 1) ++cnt;
    return cnt;
}

int gcd(int a, int b)
{
    while (b != 0) {
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    // I HATE TIME LIMIT q.q

    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int ansi, ansj, ansv = 0;
    for (int i = a; i <= b; ++i) {
        for (int j = c; j <= d; ++j) {
            int g = gcd(i, j);
            int v = count(g);
            if (v > ansv ||
            (v == ansv && i+j > ansi+ansj)) {
                ansi = i;
                ansj = j;
                ansv = v;
            }
        }
    }
    printf("%d %d\n", ansi, ansj);

    return 0;
}
