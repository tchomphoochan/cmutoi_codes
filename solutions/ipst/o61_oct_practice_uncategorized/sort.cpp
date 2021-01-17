#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

void loopb(int i, int to, int inc, function<bool(int)> act)
{
    if (i == to) return;
    if (!act(i)) return;
    loopb(i+inc, to, inc, act);
}
void loop(int i, int to, int inc, function<void(int)> act)
{
    if (i == to) return;
    act(i);
    loop(i+inc, to, inc, act);
}

int arr[N];

int main()
{
    int n;
    scanf("%d", &n);
    loop(0, n, 1, [&] (int i) {
        scanf("%d", &arr[i]);
    });

    loop(0, n, 1, [&] (int i) {
        int mn = i;
        loop(i, n, 1, [&] (int j) {
            if (arr[j] < arr[mn])
                mn = j;
        });
        swap(arr[i], arr[mn]);
        printf("%d\n", arr[i]);
    });

    return 0;
}