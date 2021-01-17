#include <cstdio>
#include <stack>

using namespace std;

#define N 1000010
#define INF (2e9+1)

int main()
{
    int n;
    scanf("%d", &n);

    int h[N], left[N], right[N];
    h[0] = h[n+1] = INF;
    stack<int> mx;
    mx.push(0);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &h[i]);
        while (h[i] >= h[mx.top()])
            mx.pop();
        left[i] = mx.top();
        mx.push(i);
    }

    while (!mx.empty())
        mx.pop();

    mx.push(n+1);
    for (int i = n; i >= 1; --i) {
        while (h[i] >= h[mx.top()])
            mx.pop();
        right[i] = mx.top();
        mx.push(i);
    }

    for (int i = 1; i <= n; ++i)
        printf("%d ", right[i] - left[i] - 1);

    return 0;
}