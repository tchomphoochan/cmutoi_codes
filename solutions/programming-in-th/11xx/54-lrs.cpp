#include <cstdio>
#include <string>
#include <map>
#include <vector>

using namespace std;

#define N 15010
#define MOD 30013

int n, k;
char s[N];
vector<int> hsh[MOD];
int count[26];

inline int mod(int x, int y)
{
    int v = x % y;
    return v < 0 ? v+y : v;
}

bool check(int l)
{
    for (int i = 0; i < MOD; ++i)
        hsh[i].clear();
    
    int mxr = 1;
    for (int i = 0; i < l-1; ++i) {
        mxr *= 26;
        mxr = mod(mxr, MOD);
    }

    int val = 0;
    for (int i = 0; i < l; ++i) {
        val *= 26;
        val += s[i]-'a';
        val = mod(val, MOD);
    }
    hsh[val].push_back(0);

    vector<int> has;
    for (int i = l; i < n; ++i) {
        val -= mxr * (s[i-l]-'a');
        val = mod(val, MOD);
        val *= 26;
        val += s[i]-'a';
        val = mod(val, MOD);
        hsh[val].push_back(i-l+1);
        if (hsh[val].size() == k)
            has.push_back(val);
    }

    for (auto h : has) {
        map<string, int> cnt;
        for (auto i : hsh[h]) {
            string t(s+i, l);
            ++cnt[t];
            if (cnt[t] >= k)
                return true;
        }
    }

    return false;
}

int main()
{
    scanf("%d%d %s", &n, &k, s);

    bool match = false;
    for (int i = 0; i < n; ++i) {
        if (count[s[i]-'a']) {
            match = true;
            break;
        }
        count[s[i]-'a'] = 1;
    }
    if (!match) {
        printf("0");
        return 0;
    }

    int left = 1;
    int right = n;
    while (left < right) {
        int mid = (left+right+1)/2;
        if (check(mid))
            left = mid;
        else
            right = mid-1;
    }

    printf("%d", right);
    return 0;
}