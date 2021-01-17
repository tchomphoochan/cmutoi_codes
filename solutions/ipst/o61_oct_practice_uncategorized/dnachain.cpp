#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int cnt = 0;
int back[N];
int forw[N];

void constructLine(int s)
{
    for (int i = 0; i < s; ++i) {
        ++cnt;
        if (i != 0)
            back[cnt] = cnt-1;
        if (i != s-1)
            forw[cnt] = cnt+1;
    }
}

int main()
{
    int l, n;
    scanf("%d%d", &l, &n);
    for (int i = 0; i < l; ++i) {
        int s;
        scanf("%d", &s);
        constructLine(s);
    }

    int prv = -1, ptr = 1;
    while (n--) {
        char t;
        scanf(" %c", &t);
        //printf("\nquery: %c", t);
        if (t == 'F') {
            if (forw[ptr] != 0 && forw[ptr] != prv) {
                prv = ptr;
                ptr = forw[ptr];
            } else if (back[ptr] != 0 && back[ptr] != prv) {
                prv = ptr;
                ptr = back[ptr];
            }
        } else if (t == 'B') {
            if (back[ptr] == prv) {
                assert(back[ptr] != 0);
                ptr = prv;
                prv = back[ptr];
            } else if (forw[ptr] == prv) {
                assert(forw[ptr] != 0);
                ptr = prv;
                prv = forw[ptr];
            } else {
                assert(back[ptr] == 0 || forw[ptr] == 0);
            }
        } else if (t == 'C') {
            int x;
            scanf("%d", &x);
            if (forw[ptr] != prv) {
                int f = forw[ptr];
                forw[ptr] = x;
                back[f] = 0;
                if (back[forw[ptr]] == 0) back[forw[ptr]] = ptr;
                else forw[forw[ptr]] = ptr;
                prv = ptr;
                ptr = forw[ptr];
            } else if (back[ptr] != prv) {
                int b = back[ptr];
                back[ptr] = x;
                forw[b] = 0;
                if (back[back[ptr]] == 0) back[back[ptr]] = ptr;
                else forw[back[ptr]] = ptr;
                prv = ptr;
                ptr = back[ptr];
            } else {
                assert(false);
            }
        }

        printf("%d\n", ptr);
        /*printf("   ");
        for (int i = 1; i <= cnt; ++i)
            printf("%d ", i);
        printf("\nf: ");
        for (int i = 1; i <= cnt; ++i)
            printf("%d ", forw[i]);
        printf("\nb: ");
        for (int i = 1; i <= cnt; ++i)
            printf("%d ", back[i]);*/
    }

    return 0;
}