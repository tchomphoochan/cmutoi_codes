#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<char, int> vars;
    for (char c = 'A'; c <= 'Z'; c++)
        vars[c] = 0;
    
    while (true)
    {
        char command;
        cin >> command;
        if (command == '!')
            break;
        
        char c1, c2;
        int v;
        switch (command)
        {
            case '=':
                cin >> c1 >> v;
                vars[c1] = v;
                break;
            
            case '+':
                cin >> c1 >> c2;
                vars[c1] += vars[c2];
                break;
            
            case '-':
                cin >> c1 >> c2;
                vars[c1] -= vars[c2];
                break;
            
            case '*':
                cin >> c1 >> c2;
                vars[c1] *= vars[c2];
                break;
            
            case '/':
                cin >> c1 >> c2;
                vars[c1] /= vars[c2];
                break;
            
            case '#':
                cin >> c1;
                cout << vars[c1] << endl;
        }
    }

    cout << "!" << endl;
}