#include <stdio.h>

int n, win, lose;
char answer[3000000] = {};
int count = 0;

void printResult(int w, int l)
{
    if (w == n || l == n)
    {
        answer[count - 1] = '\0';
        printf("%s\n", answer);
        answer[count - 1] = ' ';
        return;
    }

    answer[count++] = 'W';
    answer[count++] = ' ';
    printResult(w + 1, l);
    count -= 2;

    answer[count++] = 'L';
    answer[count++] = ' ';
    printResult(w, l + 1);
    count -= 2;
}

int main(void)
{
    scanf("%d%d%d", &n, &win, &lose);
    printResult(win, lose);
    return 0;
}