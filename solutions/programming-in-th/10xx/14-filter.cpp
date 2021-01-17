#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int w, h, n;
    cin >> w >> h >> n;

    int filter[w];
    for (int i = 0; i < w; i++)
        filter[i] = 0;
        
    for (int i = 0; i < n; i++)
    {
        int start, width;
        cin >> start >> width;
        for (int j = start; j < start + width && j < w; j++)
            filter[j] += 1;
    }

    int count50 = 0;
    int count100 = 0;
    for (int i = 0; i < w; i++)
    {
        if (filter[i] == 0)
            count100++;
        if (filter[i] == 1)
            count50++;
    }

    cout << count100 * h << " " << count50 * h << endl;
}