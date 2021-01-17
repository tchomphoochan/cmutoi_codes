#include <cstdio>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    unordered_map<int, int> count;
    int m = 0;
    while (n--) {
        int x;
        scanf("%d", &x);
        m = max(m, ++count[x]);
    }

    printf("%d", m);

    return 0;
}