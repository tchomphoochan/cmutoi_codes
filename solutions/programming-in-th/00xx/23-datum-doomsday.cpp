#include <iostream>
#include <string>

using namespace std;

int main()
{
    int d, m, y = 2009;
    cin >> d >> m;

    int weekday;
    weekday = (d += m < 3 ? y-- : y-2, 23 * m / 9 + d + 4 + y / 4 - y / 100 + y / 400) % 7;
    string wday;
    switch (weekday)
    {
        case 0: wday = "Sunday"; break;
        case 1: wday = "Monday"; break;
        case 2: wday = "Tuesday"; break;
        case 3: wday = "Wednesday"; break;
        case 4: wday = "Thursday"; break;
        case 5: wday = "Friday"; break;
        case 6: wday = "Saturday"; break;
    }
    cout << wday << endl;
}