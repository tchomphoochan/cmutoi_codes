#include <bits/stdc++.h>

using namespace std;

char *otog[7] = {".........................",
"..###..#####..###...####.",
".#...#...#...#...#.#.....",
".#...#...#...#...#.#.###.",
".#...#...#...#...#.#...#.",
"..###....#....###...###..",
"........................."};

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < 7; ++i) {
        for (int r = 0; r < n; ++r) {
            for (int j = 0; otog[i][j]; ++j){
                for (int s = 0; s < n; ++s) {
                    printf("%c", otog[i][j]);
                }
            }
            printf("\n");
        }
    }

    return 0;
}