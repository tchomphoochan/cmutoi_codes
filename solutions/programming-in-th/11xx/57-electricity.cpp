#include <cstdio>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int n, k;
int data[500000] = {};
int best[500000] = {};

struct cmp
{
    bool operator()(int a, int b)
    {
        return best[a] > best[b];
    }
};

priority_queue<int, vector<int>, cmp> heap;

int main()
{
    scanf("%d%d", &n, &k);
    scanf("%d", &data[0]);
    best[0] = data[0];
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &data[i]);
        heap.push(i - 1);
        while (!heap.empty() && heap.top() < i - k)
            heap.pop();
        best[i] = data[i] + best[heap.top()];
    }

    printf("%d", best[n - 1]);
    return 0;
}