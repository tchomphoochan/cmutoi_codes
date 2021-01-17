#include <cstdio>

#define N 4000

char rect[N][N];

void fillRect(int x1, int y1, int x2, int y2, char c)
{
    for (int x = x1; x <= x2; ++x) {
        for (int y = y1; y <= y2; ++y) {
            rect[x][y] = c;
        }
    }
}

void printRect(int x1, int y1, int x2, int y2)
{
    for (int y = y1; y <= y2; ++y) {
        for (int x = x1; x <= x2; ++x) {
            printf("%c", rect[x][y]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int x1, x2, y1, y2;
    x1 = x2 = y1 = y2 = N/2;
    rect[N/2][N/2] = 'A';

    for (int i = 0; i < n-1; ++i) {

        char c = 'B' + i;
        if (i % 4 == 0) {
            fillRect(x2+1, y1, x2+y2-y1+1, y2, c);
            x2 = x2+y2-y1+1;
        } else if (i % 4 == 1) {
            fillRect(x1, y2+1, x2, y2+x2-x1+1, c);
            y2 = y2+x2-x1+1;
        } else if (i % 4 == 2) {
            fillRect(x1-(y2-y1+1), y1, x1-1, y2, c);
            x1 = x1-(y2-y1+1);
        } else if (i % 4 == 3) {
            fillRect(x1, y1-(x2-x1+1), x2, y1-1, c);
            y1 = y1-(x2-x1+1);
        }

    }

    printRect(x1, y1, x2, y2);

    return 0;
}