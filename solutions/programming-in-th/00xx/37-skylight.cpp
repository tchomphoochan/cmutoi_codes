#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, l, k, c;
    cin >> n >> m >> l >> k >> c;
    int lightsum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int num;
            cin >> num;
            lightsum += num;
        }
    }
    
    int cost = ceil((lightsum / (double)c) + (l * k));
    cout << cost << endl;
}