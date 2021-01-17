#include <bits/stdc++.h>

using namespace std;

bool isprime(int x)
{
    if (x == 1) return false;
    for (int i = 2; i < x; ++i) {
        if (x % i == 0)
            return false;
    }
    return true;
}

int arr[30];

int main()
{
    int sum = 0;
    bool oneprime = false, onecomp = false;
    for (int i = 0; i < 30; ++i) {
        int x;
        scanf("%d", &x);
        arr[i] = x;
        sum += x;
        if (isprime(x)) oneprime = true;
        else onecomp = true;
    }

    if (onecomp) printf("yes\n");
    else if (arr[0] <= 50) printf("no\n");
    else printf("yes\n");

    return 0;
}