#include <cstdio>
#include <algorithm>

int cases, ct, cnt;
int w[5] = {};

int get_case() {
    scanf("%d", &cases);
    ct = 0;
    return cases;
}

void sort_init() {
    for (int i = 0; i < 5; ++i) scanf("%d", &w[i]);
    ++ct;
    printf("Case #%d: ", ct);
    cnt = 0;
}

int sort_weight(int a, int b) {
    ++cnt;
    return w[a] < w[b] ? -1 : 1;
}

void sort_answer(int a, int b, int c, int d, int e) {
    if (w[a] < w[b] && w[b] < w[c] && w[c] < w[d] && w[d] < w[e]) {
        if (cnt <= 7)
            printf("Correct (%d)\n", cnt);
        else
            printf("Incorrect (%d)\n", cnt);
    } else {
        printf("Incorrect (Not sorted)\n");
    }
}