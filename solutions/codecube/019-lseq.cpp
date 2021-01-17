#include <cstdio>
#include <list>

using namespace std;

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    list<int> num;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        num.push_back(x);
    }

    while (k--) {
        bool rem = false;
        for (auto it = num.begin(); it != prev(num.end()); ++it) {
            if (*it > *next(it)) {
                num.erase(it);
                rem = true;
                break;
            }
        }
        if (!rem)
            num.pop_back();
    }

    for (auto x : num)
        printf(" %d", x);

    return 0;
}