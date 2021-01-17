#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++)
    {
        string txt;
        cin >> txt;

        bool answer = true;
        stack<char> paren;
        for (int i = 0; i < txt.length(); i++)
        {
            if (txt[i] == '(' || txt[i] == '[' || txt[i] == '{')
            {
                paren.push(txt[i]);
            }
            else
            {
                if (paren.empty())
                {
                    answer = false;
                    break;
                }
                char top = paren.top();
                paren.pop();
                if ((top == '(' && txt[i] != ')')
                || (top == '[' && txt[i] != ']')
                || (top == '{' && txt[i] != '}'))
                {
                    answer = false;
                    break;
                }
            }
        }
        if (!paren.empty())
            answer = false;
        
        cout << (answer ? "yes" : "no") << "\n";
    }

    return 0;
}