/**
 * Code Jam 2019 Round 1A
 * B. Golf Gophers
 * 
 * aquablitz11 (2019-04-13)
 * This passes both cases. Note that CRT isn't actually required here. You can just bruteforce.
 */

// chinese remainder theorem copied from
// https://codeforces.com/blog/entry/61290

#include<bits/stdc++.h>
using namespace std;
const int N = 20;
long long GCD(long long a, long long b) { return (b == 0) ? a : GCD(b, a % b); }
inline long long LCM(long long a, long long b) { return a / GCD(a, b) * b; }
inline long long normalize(long long x, long long mod) { x %= mod; if (x < 0) x += mod; return x; }
struct GCD_type { long long x, y, d; };
GCD_type ex_GCD(long long a, long long b)
{
    if (b == 0) return {1, 0, a};
    GCD_type pom = ex_GCD(b, a % b);
    return {pom.y, pom.x - a / b * pom.y, pom.d};
}
int testCases;
int t;
long long a[N], n[] = {4, 3, 5, 7, 11, 13, 17}, ans, lcm;
int main()
{
    int tests, k, m;
    cin >> tests >> k >> m;
    while (tests--) {

        k = min(k, 7);
        for(int i = 0; i < k; i++) {
            for (int j = 0; j < 18; ++j) {
                if (j != 0) cout << " ";
                cout << n[i];
            }
            //cerr << "tried " << n[i] << endl;
            cout << endl;
            int x = 0;
                //cerr << "read";
            a[i] = 0;
            for (int j = 0; j < 18; ++j) {
                cin >> x;
                //cerr << " " << x;
                a[i] += x;
            }
            normalize(a[i], n[i]);
        }
        ans = a[0];
        lcm = n[0];
        for(int i = 1; i < k; i++)
        {
            auto pom = ex_GCD(lcm, n[i]);
            int x1 = pom.x;
            int d = pom.d;
            if((a[i] - ans) % d != 0) assert(false);
            ans = normalize(ans + x1 * (a[i] - ans) / d % (n[i] / d) * lcm, lcm * n[i] / d);
            lcm = LCM(lcm, n[i]); // you can save time by replacing above lcm * n[i] /d by lcm = lcm * n[i] / d
        }
        cout << ans << endl;
        //cerr << ans << endl;
        int x;
        cin >> x;
        if (x == -1)
            break;

    }
 
    return 0;
}