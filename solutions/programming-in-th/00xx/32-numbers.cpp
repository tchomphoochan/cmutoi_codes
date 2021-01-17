#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int zeros = 0;
    vector<int> numbers;

    for (int i = 0; i < n; i++)
    {
        int got;
        cin >> got;
        if (got == 0)
            zeros++;
        else
            numbers.push_back(got);
    }

    sort(numbers.begin(), numbers.end());

    cout << numbers[0];
    for (int i = 0; i < zeros; i++)
        cout << "0";
    for (int i = 1; i < numbers.size(); i++)
        cout << numbers[i];
    
    cout << endl;
    return 0;
}