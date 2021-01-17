#include <cstdio>

#define N 81

char data[N][N];
bool hori[N][N];
bool verti[N][N];

int main()
{
    int n, m;
    scanf("%d%d", &m, &n);

    for (int i = 0; i < n; ++i) {
        scanf(" ");
        for (int j = 0; j < m; ++j) {
            scanf("%c", &data[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (data[i][j] == '^') {
                for (int k = i-1; i >= 0; --k) {
                    if (data[k][j] == '.')
                        verti[k][j] = true;
                    else
                        break;
                }
            } else if (data[i][j] == 'V') {
                for (int k = i+1; i < n; ++k) {
                    if (data[k][j] == '.')
                        verti[k][j] = true;
                    else
                        break;
                }
            } else if (data[i][j] == '<') {
                for (int k = j-1; j >= 0; --k) {
                    if (data[i][k] == '.')
                        hori[i][k] = true;
                    else
                        break;
                }
            } else if (data[i][j] == '>') {
                for (int k = j+1; j < m; ++k) {
                    if (data[i][k] == '.')
                        hori[i][k] = true;
                    else
                        break;
                }
            } else if (data[i][j] == 'B') {
                data[i][j] = '*';
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (data[i][j] == '.') {
                if (hori[i][j] && verti[i][j])
                    printf("+");
                else if (hori[i][j])
                    printf("-");
                else if (verti[i][j])
                    printf("|");
                else
                    printf(".");
            } else {
                printf("%c", data[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}