#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    set<int> blocks;
    for (int i = 0; i < m; i++)
    {
        int block;
        cin >> block;
        blocks.insert(block);
    }
    vector<int> foods;
    for (int i = 1; i <= n; i++)
        foods.push_back(i);

    do
    {
        if (blocks.count(foods[0]))
            continue;
        for (vector<int>::iterator it = foods.begin(); it != foods.end(); it++)
        {
            cout << *it;
            if (it != foods.end() - 1)
                cout << " ";
            else
                cout << endl;
        }
    }
    while (next_permutation(foods.begin(), foods.end()));
}