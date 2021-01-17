#include <cstdio>

#define N 100010

int main()
{
    char space[] = "SPACEBAR";
    char shift[] = "SHIFT";
    char bt[] = "QWEASDV";
    auto has = [&] (char c) {
        for (int i = 0; bt[i]; ++i) {
            if (bt[i] == c)
                return true;
        }
        return false;
    };

    int n;
    char text[N];
    int count = 0;

    scanf("%d ", &n);
    gets(text);
    for (int i = 0; text[i]; ++i) {
        bool mismatch = false;
        for (int j = 0; j < 8; ++j) {
            if (!text[i+j] || space[j] != text[i+j]) {
                mismatch = true;
                break;
            }
        }
        if (!mismatch) {
            i += 7;
            ++count;
            continue;
        }
        mismatch = false;
        for (int j = 0; j < 5; ++j) {
            if (!text[i+j] || shift[j] != text[i+j]) {
                mismatch = true;
                break;
            }
        }
        if (!mismatch) {
            i += 4;
            ++count;
            continue;
        }
        if (has(text[i]))
            ++count;
    }

    printf("%d", count);
    return 0;
}