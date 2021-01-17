#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int arr[N];

void loop(int i, int to, int inc, function<bool(int)> act)
{
    if (i == to) return;
    if (!act(i)) return;
    loop(i+inc, to, inc, act);
}

int main()
{
    int n;
    scanf("%d", &n);
    loop(0, n, 1, [&] (int i) {
        scanf("%d", &arr[i]);
        return true;
    });

    int cut;
    loop(n-2, -1, -1, [&] (int i) {
        if (arr[i] < arr[i+1]) {
            cut = i;
            return false;
        }
        return true;
    });

    int big;
    loop(n-1, cut, -1, [&] (int i) {
        if (arr[i] > arr[cut]) {
            big = i;
            return false;
        }
        return true;
    });

    loop(0, cut, 1, [&] (int i) {
        printf("%d\n", arr[i]);
        return true;
    });
    printf("%d\n", arr[big]);
    loop(n-1, big, -1, [&] (int i) {
        printf("%d\n", arr[i]);
        return true;
    });
    printf("%d\n", arr[cut]);
    loop(big-1, cut, -1, [&] (int i) {
        printf("%d\n", arr[i]);
        return true;
    });

    return 0;
}