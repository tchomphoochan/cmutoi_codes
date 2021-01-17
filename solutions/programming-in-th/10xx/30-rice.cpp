//#include <iostream>
//#include <iomanip>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
    //ios::sync_with_stdio(false);
    
    int k;
    //cin >> k;
    scanf("%d", &k);
    
    map<double, int> rice;
    while (k--)
    {
        int p, q;
        //cin >> p >> q;
        scanf("%d %d", &p, &q);
        double price = (double) p / q;
        
        if (rice.count(price) == 0)
            rice[price] = q;
        else
            rice[price] += q;
    }
    
    int m;
    //cin >> m;
    scanf("%d", &m);
    
    map<double, int>::iterator it = rice.begin();
    while (m--)
    {
        int b;
        //cin >> b;
        scanf("%d", &b);
        
        double money = 0;
        while (b != 0)
        {
            double p = it->first;
            int &q = it->second;
            
            if (b < q)
            {
                money += b * p;
                q -= b;
                b = 0;
                break;
            }
            
            money += q * p;
            b -= q;
            q = 0;
            
            if (q == 0)
                ++it;
        }
        
        //cout << setprecision(3) << fixed << money << endl;
        printf("%.3f\n", money);
    }
}