#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

char s[N], t[N];
vector<int> ix;
int val[N];
int lps[N];

int main()
{
    //time_t begin, end;
    //begin = clock();
    ix.reserve(N);
    //end = clock();
    //fprintf(stderr, "%.2fs to compute\n", ((double)end-begin)/CLOCKS_PER_SEC);

    int q;
    scanf("%d", &q);
    while (q--) {

        //begin = clock();

        scanf(" %s %s", s, t);
        int n = strlen(s);
        int m = strlen(t);
        int j = 0;
        for (int i = 1; i < m; ) {
            if (t[i] == t[j])
                lps[i++] = ++j;
            else if (j != 0)
                j = lps[j-1];
            else
                lps[i++] = 0;
        }

        //end = clock();
        //fprintf(stderr, "%.2fs to compute\n", ((double)end-begin)/CLOCKS_PER_SEC);

        //begin = clock();
        j = 0;
        for (int i = 0; i < n; ) {
            //printf("i = %d, j = %d\n", i, j);
            if (ix.empty() || ix.back() != i)
                ix.push_back(i);
            if (s[i] == t[j]) {
                val[i++] = ++j;
                if (j == m) {
                    while (j--)
                        ix.pop_back();
                    j = ix.empty() ? 0 : val[ix.back()];
                }
            } else if (j != 0) {
                j = lps[j-1];
            } else {
                val[i++] = 0;
            }
        }

        //end = clock();
        //fprintf(stderr, "%.2fs to compute\n", ((double)end-begin)/CLOCKS_PER_SEC);

        //begin = clock();
        if (ix.empty()) {
            printf("No COI Secret Code\n");
        } else {
            string x;
            for (int i : ix)
                x.push_back(s[i]);
            printf("%s\n", x.c_str());
        }

        ix.clear();

        //end = clock();
        //fprintf(stderr, "%.2fs to compute\n", ((double)end-begin)/CLOCKS_PER_SEC);

    }

    return 0;
}