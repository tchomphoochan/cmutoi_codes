#include <cstdio>
#include <set>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    set<int> *path = new set<int>[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);

        if (x > y)
            swap(x, y);
        
        path[x].insert(y);
    }

    int longest[n + 1];
    int record = 0;
    for (int i = n; i >= 1; i--)
    {
        int lng = 0;
        for (set<int>::iterator it = path[i].begin(); it != path[i].end(); ++it)
        {
            if (longest[*it] + 1 > lng)
                lng = longest[*it] + 1;
        }
        longest[i] = lng;
        if (lng > record)
            record = lng;
    }

    printf("%d", record + 1);
    delete [] path;
}