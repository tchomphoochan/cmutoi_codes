#include <cstdio>
#include <cctype>
#include <queue>

using namespace std;

int index(char c)
{
    if (islower(c))
        return c - 'a';
    if (isupper(c))
        return 26 + c - 'A';
    return -1;
}

int main()
{
    unsigned n1, n2;
    scanf("%u %u ", &n1, &n2);

    unsigned wfreq[52] = {};
    unsigned sfreq[52] = {};
    queue<char> old;

    for (unsigned i = 0; i < n1; i++)
    {
        char c;
        scanf("%c", &c);
        wfreq[index(c)]++;
    }

    // first few characters
    scanf(" ");
    for (unsigned i = 0; i < n1; i++)
    {
        char c;
        scanf("%c", &c);
        sfreq[index(c)]++;
        old.push(c);
    }

    unsigned count = 0;
    bool m = true;
    for (int j = 0; j < 52; j++)
    {
        if (wfreq[j] != sfreq[j])
        {
            m = false;
            break;
        }
    }
    if (m)
        count++;
            
    for (unsigned i = n1; i < n2; i++)
    {
        char o = old.front();
        old.pop();

        char c;
        scanf("%c", &c);
        old.push(c);

        sfreq[index(o)]--;
        sfreq[index(c)]++;

        bool match = true;
        for (int j = 0; j < 52; j++)
        {
            if (wfreq[j] != sfreq[j])
            {
                match = false;
                break;
            }
        }

        if (match)
            count++;
    }

    printf("%u", count);
}