#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e7+10;
const ll PB = 98765431;

int n;
char s[N];

int main()
{
    scanf("%d %s", &n, s);

    // compute hash for first round
    ll hsh = 0, h = 0, rem = 1;
    for (int i = 0; i < n-1; ++i) {
        h *= PB;
        h += s[i];
        rem *= PB;
    }
    h *= PB;
    h += s[n-1];
    hsh = h; // save the original hash
    h -= rem*s[0];

    // keep going for second round
    for (int i = n; i < 2*n; ++i) {
        s[i] = s[i-n];
        h *= PB;
        h += s[i];
        if (hsh == h) {
            printf("%d\n", i-n+1);
            break;
        }
        h -= rem*s[i-n+1];
    }

    return 0;
}