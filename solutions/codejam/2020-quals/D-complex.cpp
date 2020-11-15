/**
 * Code Jam 2020 Qualification Round
 * D. ESAb ATAd
 *
 * aquablitz11 (2020-04-04)
 * The key observation is that every time the bitstring is scrambled, it still retains its properties
 * but is separate from other bitstring portions we find. So, we find each independent portion first,
 * then in the end we use a few queries to link all the portions up using the same/different knowledge we had.
 * 
 * Note that Micky Tanawin had a better solution: Instead of linking up at the end, link up immediately after each shuffle.
 * So, maintenance is simple. Once we are at the end of the string, we have already completed all the linking.
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 150;

int cntq=0;
int get(int x) {
    int v = 0;
    printf("%d\n", x);
    fflush(stdout);
    scanf("%d", &v);
    ++cntq;
    /*if (cntq > 120)
        fprintf(stderr, "query(%d) = %d\n", x, v);*/
    return v;
}

int main()
{
    int T, B;
    scanf("%d%d", &T, &B);
    while (T--) {
        cntq=0;
        int val[N] = {};
        int samepair[N] = {}, diffpair[N] = {};

        for (int i = 0; i < B/10; ++i) {
            for (int j = 0; j < 5; ++j) {
                int x = i*5+j + 1;
                int y = B-x+1;
                val[x] = get(x);
                val[y] = get(y);
                if (val[x] == val[y]) {
                    samepair[i] = x;
                    if (i < B/10/2) samepair[N-1] = x;
                    else samepair[N-2] = x;
                } if (val[x] != val[y]) {
                    diffpair[i] = x;
                    if (i < B/10/2) diffpair[N-1] = x;
                    else diffpair[N-2] = x;
                }
            }
        }

        for (int i = 0; i < B/10; ++i) {
            if (samepair[i] == 0) {
                get(1);
            } else if (get(samepair[i]) != val[samepair[i]]) { // complement - same pair change
                for (int j = 0; j < 5; ++j) {
                    int x = i*5+j + 1;
                    int y = B-x+1;
                    val[x] = 1-val[x];
                    val[y] = 1-val[y];
                }
            }
            if (diffpair[i] == 0) {
                get(1);
            } else if (get(diffpair[i]) != val[diffpair[i]]) { // reverse - diff pair change
                for (int j = 0; j < 5; ++j) {
                    int x = i*5+j + 1;
                    int y = B-x+1;
                    swap(val[x], val[y]);
                }
            }
        }

        /*for (int i = 1; i <= B; ++i)
            fprintf(stderr,"%d", val[i]);
        fprintf(stderr, "\n");*/

        // last time
        if (B == 100) {
            for (int i = 1; i <= 2; ++i) {
                //fprintf(stderr, "check %d and %d\n", samepair[N-i], diffpair[N-i]);
                if (samepair[N-i] != 0 && get(samepair[N-i]) != val[samepair[N-i]]) { // complement - same pair change
                    //fprintf(stderr, "complemented\n");
                    for (int j = 0; j < B/4; ++j) {
                        int x = (i-1)*B/4 + j + 1;
                        int y = B-x+1;
                        val[x] = 1-val[x];
                        val[y] = 1-val[y];
                    }
                }
                if (diffpair[N-i] != 0 && get(diffpair[N-i]) != val[diffpair[N-i]]) { // reverse - diff pair change
                    //fprintf(stderr, "reversed\n");
                    for (int j = 0; j < B/4; ++j) {
                        int x = (i-1)*B/4 + j + 1;
                        int y = B-x+1;
                        swap(val[x], val[y]);
                    }
                }
            }
        }


        for (int i = 1; i <= B; ++i)
            printf("%d", val[i]);
        printf("\n");
        fflush(stdout);
        char res;
        scanf(" %c", &res);
        if (res == 'N')
            break;

    }
    
    return 0;
}