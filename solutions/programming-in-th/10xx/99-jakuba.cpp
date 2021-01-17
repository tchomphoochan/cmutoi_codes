#include <cstdio>
#include <cmath>
#include <set>

using namespace std;

int main()
{
    int r, g;
    scanf("%d%d", &r, &g);
    
    set<int> rc;
    for (int i = 1; i < sqrt(r); i++)
    {
        if (r % i == 0)
        {
            rc.insert(i);
            rc.insert(r / i);
        }
    }
    if (fmod(r, sqrt(r)) == 0)
        rc.insert(sqrt(r));
    
    for (set<int>::iterator it = rc.begin(); it != rc.end(); ++it)
    {
        int num = *it;
        if (g % num == 0)
            printf("%d %d %d\n", num, r / num, g / num);
    }

    return 0;
}