#include <bits/stdc++.h>
using namespace std;

#define min(a, b) a <= b ? a : b;

int main()
{
    priority_queue<int, vector<int>, greater<int> > top;
    for (int i = 0; i < 4; i++)
    {
        int num;
        cin >> num;
        top.push(num);
    }

    int a = top.top();
    top.pop();
    a = min(a, top.top());
    top.pop();

    int b = top.top();
    top.pop();
    b = min(b, top.top());
    top.pop();

    cout << a * b << endl;

    return 0;
}