#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    
    int posX = 0;
    int posY = 0;
    int way = 0;

    bool dead = false;
    for (int i = 0; i < n; i++)
    {
        string w;
        cin >> w;
        int k;
        cin >> k;

        if (w == "RT")
            way -= 1;
        else if (w == "LT")
            way += 1;
        else if (w == "BW")
            way += 2;
        way %= 4;
        if (way < 0)
            way += 4;   
        
        switch (way)
        {
            case 0:
                posX += k;
                break;
            
            case 1:
                posY += k;
                break;
            
            case 2:
                posX -= k;
                break;
            
            case 3:
                posY -= k;
                break;
        }

        if (posX <= -5e4 || posX >= 5e4 || posY <= -5e4 || posY >= 5e4)
        {
            dead = true;
            break;
        }
    }

    if (dead)
        cout << "DEAD" << endl;
    else
    {
        char ws;
        switch (way)
        {
            case 0:
                ws = 'E';
                break;
            
            case 1:
                ws = 'N';
                break;
            
            case 2:
                ws = 'W';
                break;
            
            case 3:
                ws = 'S';
                break;
        }
        cout << posX << " " << posY << endl << ws << endl;
    }
}