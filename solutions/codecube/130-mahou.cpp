#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <iterator>

#define INF (2e9)

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> A(n + 1), C(n + 1, 0), dp(n + 1, INF);
    auto cmp = [&](const int &x, const int &y) { return (dp[x - 1] + C[x]) < (dp[y - 1] + C[y]); };
    multiset<int, decltype(cmp)> s(cmp);
    list<int> q;
    auto f = [&](int x)
    {
        auto p = s.equal_range(x);
        for (auto it = p.first; it != p.second; ++it)
        {
            if (*it == x)
                return it;
        }
        return s.end();
    };

    for (int i = 1; i <= n; i++)
        cin >> A[i];

    dp[0] = 0;
    dp[1] = A[1];
    C[1] = A[1];
    q.push_front(1);
    q.push_front(2);
    s.insert(1);
    s.insert(2);

    for (int i = 2; i <= n; i++)
    {
        /* TODO - handle C */

        // remove unreachable back
        if (!q.empty() && q.back() == i - k)
        {
            s.erase(f(i - k));
            q.pop_back();
        }

        // update all C value in queue
        for (auto it = q.begin(); it != q.end() && C[*it] < A[i]; ++it)
        {
            s.erase(f(*it));
            C[*it] = A[i];
            s.insert(*it);
        }

        // set dp[i] to minimum answer
        dp[i] = C[*s.begin()] + dp[*s.begin() - 1];
        while (!q.empty() && dp[*(q.begin()) - 1] >= dp[i])
        {
            s.erase(f(*(q.begin())));
            q.pop_front();
        }
        q.push_front(i + 1);
        s.insert(i + 1);
    }

    cout << dp[n];
    return 0;
}