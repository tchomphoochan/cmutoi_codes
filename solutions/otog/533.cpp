#include <bits/stdc++.h>
#include "binary_search.h"

using namespace std;

typedef unsigned long long ll;

int main()
{
    ll left = 0;
    ll right = get_n();
    int called = 0;
    while (left < right && called < 50) {
        ll mid = (left+right)/2;
        if (is_less(mid))
            left = mid+1;
        else
            right = mid;
        if (is_equal(mid)) {
            answer(mid);
            return 0;
        }
        ++called;
    }

    for (ll i = left; i <= right; ++i) {
        if (is_equal(i)) {
            answer(i);
            break;
        }
    }

    return 0;
}