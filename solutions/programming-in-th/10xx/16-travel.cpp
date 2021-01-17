#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    
    double posX = 0;
    double posY = 0;

    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        
        string way;
        cin >> way;

        double dn = n * sqrt(2) / 2;

        if (way == "N")
            posY += n;
        else if (way == "E")
            posX += n;
        else if (way == "S")
            posY -= n;
        else if (way == "W")
            posX -= n;
        else if (way == "NE")
        {
            posX += dn;
            posY += dn;
        }
        else if (way == "SE")
        {
            posX += dn;
            posY -= dn;
        }
        else if (way == "SW")
        {
            posX -= dn;
            posY -= dn;
        }
        else //if (way == "NW")
        {
            posX -= dn;
            posY += dn;
        }
    }

    cout << setprecision(3) << fixed;
    cout << posX << " " << posY << endl;
    cout << sqrt(posX * posX + posY * posY) << endl;
}