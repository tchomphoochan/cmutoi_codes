#include <cstdio>
#include <algorithm>

#define N 500010

int n, m;
int arr[N];

int arrRot = 0;
bool arrRev = false;

int arrIxT(int x)
{
    int y = (x + (n - arrRot)) % n;
    if (y < 0)
        y += n;
    return y;
}

int arrIx(int x)
{
    return arrIxT(!arrRev ? x : n-x-1);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    
    while (m--) {
        char cmd;
        int x, y;
        scanf(" %c", &cmd);
        if (cmd == 'a')  {
            scanf("%d%d", &x, &y);
            std::swap(arr[arrIx(x-1)], arr[arrIx(y-1)]);
        } else if (cmd == 'b') {
            scanf("%d%d", &x, &y);
            arr[arrIx(x-1)] = y;
        } else if (cmd == 'c') {
            scanf("%d", &x);
            arrRot += !arrRev ? (n-x) : -(n-x);
            arrRev = !arrRev;
        } else if (cmd == 'q') {
            scanf("%d", &x);
            printf("%d\n", arr[arrIx(x-1)]);
        }
    }

    return 0;
}