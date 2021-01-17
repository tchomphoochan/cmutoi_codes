#include <iostream>

using namespace std;

bool isPalindrome(string s)
{
    int slen = s.length();
    int half = slen / 2;
    for (int i = 0; i < half; i++)
    {
        if (tolower(s[i]) != tolower(s[slen - i - 1]))
            return false;
    }
    return true;
}

int main()
{
    string s;
    cin >> s;
    int length = s.length();
    int half = length / 2;
    if (!isPalindrome(s))
        cout << "No";
    else if (!isPalindrome(s.substr(0, half))
    || !isPalindrome(s.substr(half + (length % 2), half)))
        cout << "Palindrome";
    else
        cout << "Double Palindrome";
    
    return 0;
}