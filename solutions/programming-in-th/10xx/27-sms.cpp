#include <iostream>
#include <algorithm>

using namespace std;

int votes[7];

bool comp(int a, int b)
{
    if (votes[a] > votes[b])
        return true;
    else if (votes[a] == votes[b])
        return a < b;
    else
        return false;
}

int main()
{
    for (int i = 0; i < 7; i++)
        votes[i] = 0;

    int survive = 7;
    while (true)
    {
        string s;
        cin >> s;
        if (s == "!")
            break;
        
        for (int i = 0; i < s.length(); i++)
        {
            int c = s[i] - 'A';
            if (votes[c] != -1)
                votes[c]++;
        }

        if (survive > 1)
        {
            int minplayer = 0;
            int minscore = 2e9;
            int mincount = 0;
            for (int i = 0; i < 7; i++)
            {
                if (votes[i] == -1)
                    continue;
                if (votes[i] < minscore)
                {
                    minscore = votes[i];
                    minplayer = i;
                    mincount = 1;
                }
                else if (votes[i] == minscore)
                {
                    mincount++;
                }
            }
            if (mincount == 1)
            {
                votes[minplayer] = -1;
                survive--;
            }
        }
    }

    cout << survive << endl;
    int sorted[7];
    for (int i = 0; i < 7; i++)
        sorted[i] = i;
    
    sort(sorted, sorted + 7, comp);
    for (int i = 0; i < survive; i++)
    {
        char c = sorted[i] + 'A';
        cout << c << " " << votes[sorted[i]] << endl;
    }
}