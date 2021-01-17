#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int a = 0, b = 0, c = 0, d = 0, e = 0;
    for (int i = 0; i < n; i++)
    {
        int p, q, r, s, t;
        cin >> p >> q >> r >> s >> t;
        a += p;
        b += q;
        c += r;
        d += s;
        e += t;
    }

    int cake = a + b;

    int nd = b;
    cake += ceil(c / 2.0);
    if (c % 2 != 0)
        nd += 2;
    
    if (nd >= d)
    {
        // d = 0;
        nd -= d;
    }
    else
    {
        d -= nd;
        // nd = 0;

        cake += ceil(d / 4.0);
        nd = (4 - (d % 4)) % 4;
    }

    int ne = nd * 2;
    if (ne < e)
    {
        e -= ne;
        cake += ceil(e / 8.0);
    }

    cout << cake << endl;
}