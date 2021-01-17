#include <bits/stdc++.h>
using namespace std;

#define INF (1 << 30)
#define min(a, b) a <= b ? a : b;
#define max(a, b) a >= b ? a : b;

typedef long long ll;

int main()
{
    int l, n;
    cin >> l >> n;
    string word[n];

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> word[i];
        if (i == 0)
            continue;
        
        int alive = 3;
        for (int j = 0; j < l; j++)
        {
            if (word[i][j] != word[i - 1][j])
            {
                if (--alive == 0)
                    break;
            }
        }
        if (alive == 0)
            break;
        count++;
    }
    
    cout << word[count] << endl;

    return 0;
}