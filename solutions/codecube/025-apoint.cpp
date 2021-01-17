#include <cstdio>
#include <algorithm>

using namespace std;

typedef unsigned long long ll;

int n;
int arr[600] = {};
int sum[600] = {};
ll memo[600][600] = {}; // memo[end][start] cuz cache locality

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    sum[0] = arr[0];
    for (int i = 1; i < n; i++)
        sum[i] = sum[i - 1] + arr[i];
    
    for (int e = 0; e < n; e++)
    {
        for (int s = e - 1; s >= 0; s--)
        {
            ll best = 0;
            for (int i = s + 1; i <= e; i++)
            {
                ll a = sum[i - 1] - (s > 0 ? sum[s - 1] : 0); // sum from s to i - 1
                ll b = sum[e] - sum[i - 1]; // sum from i to e
                ll ab = (a <= b ? 2 * a + b : 2 * b + a);
                ll left = memo[i - 1][s];
                ll right = memo[e][i];
                best = max(best, ab + left + right);
            }
            memo[e][s] = best;
        }
    }
    
    printf("%llu", memo[n - 1][0]);
}