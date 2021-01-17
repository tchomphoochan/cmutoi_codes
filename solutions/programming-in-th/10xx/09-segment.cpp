#include <iostream>
#include <cmath>

using namespace std;

class Digit
{
    private:
    char presets[10][3][3] =
    {
        { // 0
            { ' ', '_', ' ' },
            { '|', ' ', '|' },
            { '|', '_', '|' }
        },
        { // 1
            { ' ', ' ', ' ' },
            { ' ', ' ', '|' },
            { ' ', ' ', '|' }
        },
        { // 2
            { ' ', '_', ' ' },
            { ' ', '_', '|' },
            { '|', '_', ' ' }
        },
        { // 3
            { ' ', '_', ' ' },
            { ' ', '_', '|' },
            { ' ', '_', '|' }
        },
        { // 4
            { ' ', ' ', ' ' },
            { '|', '_', '|' },
            { ' ', ' ', '|' }
        },
        { // 5
            { ' ', '_', ' ' },
            { '|', '_', ' ' },
            { ' ', '_', '|' }
        },
        { // 6
            { ' ', '_', ' ' },
            { '|', '_', ' ' },
            { '|', '_', '|' }
        },
        { // 7
            { ' ', '_', ' ' },
            { ' ', ' ', '|' },
            { ' ', ' ', '|' }
        },
        { // 8
            { ' ', '_', ' ' },
            { '|', '_', '|' },
            { '|', '_', '|' }
        },
        { // 9
            { ' ', '_', ' ' },
            { '|', '_', '|' },
            { ' ', '_', '|' }
        }
    };

    bool matchArray(Digit expected, Digit actual)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (expected.digit[i][j] != actual.digit[i][j])
                    return false;
            }
        }
        return true;
    }

    void copyDigit(char dest[3][3], char src[3][3])
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                dest[i][j] = src[i][j];
        }
    }

    public:
    
    char digit[3][3];

    Digit()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                digit[i][j] = ' ';
        }
    }

    Digit(int number)
    {
        if (number >= 0 && number <= 9)
            copyDigit(digit, presets[number]);
    }

    Digit(char data[3][3])
    {
        copyDigit(digit, data);
    }

    int number()
    {
        for (int i = 0; i <= 9; i++)
        {
            if (matchArray(presets[i], digit))
                return i;
        }
        return -1;
    }

    static void readDigit(Digit digits[], int n)
    {
        for (int i = 0; i < 3; i++)
        {
            string input;
            getline(cin, input);
            // for each segment in line
            for (int j = 0; j < 4 * n - 1; j++)
            {
                char put;
                if (j >= input.length())
                    put = ' ';
                else
                    put = input[j];

                // calculate position
                int curNumber = j / 4;
                int curPoint = j % 4;
                if (curPoint != 3)
                    digits[curNumber].digit[i][curPoint] = put;
            }
        }
    }

    static unsigned readNumber(Digit digits[], int n)
    {
        unsigned value = 0;
        for (int i = 0; i < n; i++)
        {
            int num = digits[i].number();
            value += num * pow(10, n - i - 1);
        }
        return value;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    string blank;
    getline(cin, blank);
    Digit digits1[n];
    Digit::readDigit(digits1, n);
    Digit digits2[m];
    Digit::readDigit(digits2, m);

    unsigned val1 = Digit::readNumber(digits1, n); 
    unsigned val2 = Digit::readNumber(digits2, m);
    unsigned value = val1 + val2;
    cout << value << endl;
}