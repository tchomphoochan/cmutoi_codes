#include <cstdio>

const int MOD = 10001;
const int N = 1010;

int B[N];

int main()
{
    int n;
    scanf("%d", &n);

    B[0] = 1;
    for (int i = 1; i <= n+1; ++i) {
        int s = 0;
        for (int j = 0; j <= i; ++j) {
            s += (j-1 >= 0 ? B[j-1] : 1) * (i-j-1 >= 0 ? B[i-j-1] : 1);
            s %= MOD;
        }
        B[i] = s;
    }

    printf("%d", B[n-1]);
    return 0;
}