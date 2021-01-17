#include <cstdio>
#include <algorithm>

using namespace std;

int n, p;

bool less(pair<int*, int> a, pair<int*, int> b)
{
    for (int i = 0; i < p; i++)
    {
        if (a.first[i] < b.first[i])
            return true;
        else if (a.first[i] > b.first[i])
            return false;
    }
    return false;
}

bool less2(int *a, int *b)
{
    for (int i = 0; i < p; i++)
    {
        if (a[i] < b[i])
            return true;
        else if (a[i] > b[i])
            return false;
    }
    return false;
}

bool equal(int *a, int *b)
{
    for (int i = 0; i < p; i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

int bsearch(pair<int*, int> a[], int n, int *s)
{
    int first = 0;
    int last = n - 1;
    int middle = (first + last) / 2;

    while (first <= last)
    {
        if (less2(a[middle].first, s))
            first = middle + 1;
        else if (equal(a[middle].first, s))
            return a[middle].second;
        else
            last = middle - 1;
        middle = (first + last) / 2;
    }

    return 0;
}

int main()
{
    // int n, p;
    scanf("%d %d", &n, &p);

    pair<int*, int> *reacts = new pair<int*, int>[100000];
    for (int i = 0; i < n; i++)
    {
        int *react = new int[10];
        for (int j = 0; j < p; j++)
            scanf("%d", &react[j]);
        reacts[i] = pair<int*, int>(react, i + 1);
    }
    sort(reacts, reacts + n, &less);

    int needs[10];
    for (int i = 0; i < p; i++)
        scanf("%d", &needs[i]);

    bool found = false;
    for (int i = 0; i < n; i++)
    {
        pair<int*, int> fp = reacts[i];
        int *props = fp.first;
        int no1 = fp.second;
        if (equal(props, needs))
        {
            found = true;
            printf("%d", no1);
            break;
        }
    }

    if (!found)
    {
        for (int i = 0; i < n; i++)
        {
            pair<int*, int> fp = reacts[i];
            int *props = fp.first;
            int no1 = fp.second;
            
            int sub[10];
            for (int i = 0; i < p; i++)
                sub[i] = needs[i] - props[i];
            
            int no2 = bsearch(reacts, n, sub);
            if (no2 != 0 && no1 != no2)
            {
                if (no1 > no2)
                    swap(no1, no2);
                found = true;
                printf("%d %d", no1, no2);
                break;
            }
        }
    }

    if (!found)
        printf("NO");

    for (int i = 0; i < n; i++)
        delete [] reacts[i].first;
    delete [] reacts;
}