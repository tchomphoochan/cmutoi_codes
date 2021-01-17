#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

const int N = 1010;

vector<int> arr[2*N];
int point[2*N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            scanf("%d", &x);
            arr[i+j].push_back(x);
        }
    }

    int lim = 2*(n-1);
    for (int i = 1; i <= lim; ++i) {
        sort(arr[i].begin(), arr[i].end(), greater<int>());
    }

    int ans = arr[lim][0];
    point[lim] = 1;
    for (int i = lim-1; i > 0; --i) {
        int add = i;
        int val = arr[i][0];
        for (int j = i+1; j <= lim; ++j) {
            if (point[j] != arr[j].size()
            && arr[j][point[j]] > val) {
                val = arr[j][point[j]];
                add = j;
            }
        }
        ++point[add];
        ans += val;
    }

    printf("%d", ans);
    return 0;
}

/*
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int arr[N][N];
int dp[N*N], newdp[N*N];
int X[N*N], Y[N*N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            scanf("%d", &arr[i][j]);
    }

    // precompute sequence in diagonal line
    int lim = 2*(n-1);
    int cnt = 0;
    for (int i = 0; i <= lim; ++i) {
        for (int x = 0; x <= i; ++x) {
            int y = i-x;
            if (x < 0 || x >= n || y < 0 || y >= n)
                continue;
            X[cnt] = x;
            Y[cnt] = y;
            ++cnt;
        }
    }

    // f = fire spread, i = current position
    for (int f = lim; f >= 0; --f) {
        for (int i = cnt-1; i >= 0; --i) {
            newdp[i] = newdp[i+1];
            if (X[i]+Y[i] > f)
                newdp[i] = max(newdp[i], dp[i+1] + arr[X[i]][Y[i]]);
        }
        for (int i = 0; i < cnt; ++i) {
            dp[i] = newdp[i];
        }
    }

    printf("%d", dp[0]);
    return 0;
}
*/