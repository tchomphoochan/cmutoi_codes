#include <bits/stdc++.h>

using namespace std;

const int N = 50010;

int arr[N], seg[17][N], ans[N];

void mergeSort(int level, int left, int right)
{
    if (left == right) {
        seg[level][left] = arr[left];
        return;
    }

    int mid = (left+right)/2;
    mergeSort(level+1, left, mid);
    mergeSort(level+1, mid+1, right);
    int ix = left;
    int i = left, j = mid+1;
    while (i <= mid && j <= right) {
        if (seg[level+1][i] <= seg[level+1][j]) {
            seg[level][ix] = seg[level+1][i];
            ++ix; ++i;
        } else {
            seg[level][ix] = seg[level+1][j];
            ++ix; ++j;
        }
    }
    while (i <= mid) {
        seg[level][ix] = seg[level+1][i];
        ++ix; ++i;
    }
    while (j <= right) {
        seg[level][ix] = seg[level+1][j];
        ++ix; ++j;
    }
}

vector<int> merge(int left, int right, int level, int begin, int end)
{
    if (begin > right || end < left)
        return vector<int>();
    
    if (begin >= left && end <= right) {
        if (end-begin+1 < 10)
            return vector<int>(&seg[level][begin], &seg[level][end+1]);
        else
            return vector<int>(&seg[level][begin], &seg[level][begin+10]);
    }
    
    int mid = (begin+end)/2;
    vector<int> l = merge(left, right, level+1, begin, mid);
    vector<int> r = merge(left, right, level+1, mid+1, end);
    vector<int> ans;
    int i = 0, j = 0;
    while (i < l.size() && j < r.size() && ans.size() < 10) {
        if (l[i] <= r[j])
            ans.push_back(l[i++]);
        else
            ans.push_back(r[j++]);
    }
    while (i < l.size() && ans.size() < 10)
        ans.push_back(l[i++]);
    while (j < r.size() && ans.size() < 10)
        ans.push_back(r[j++]);
    return ans;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    mergeSort(0, 0, n-1);
    
    for (int i = 0; i < m; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        vector<int> ans = merge(l, r, 0, 0, n-1);
        for (int j = 0; j < ans.size(); ++j) {
            if (j != 0)
                printf(" ");
            printf("%d", ans[j]);
        }
        printf("\n");
    }

    return 0;
}