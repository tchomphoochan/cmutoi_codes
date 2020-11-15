/**
 * Code Jam 2020 Qualification Round
 * E. Indicium
 *
 * aquablitz11 (2020-04-04)
 * I can't remember what the solution is anymore, and this solution was hacked together very badly.
 * Please refer to Code Jam's analysis for a more sound idea.
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 55;
using pii = pair<int, int>;

default_random_engine RNG(31415926);

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {

        int n, k;
        scanf("%d%d", &n, &k);
        int ok = k;
        bool flip = false;
        if (n*(n+1)-k < k) {
            k = n*(n+1)-k;
            flip = true;
        }

        int val[N] = {}, sum;

        if (k == n+1 || k == n*n-1 || (n == 3 && !(k == 3 || k == 6 || k == 9))) {
            printf("Case #%d: IMPOSSIBLE\n", t);
            continue;
        } else if (k%n == 0) {
            fill(val, val+n, k/n);
            sum = k;
        } else if (k%n == 1) {
            fill(val, val+n, k/n);
            ++val[0];
            ++val[1];
            --val[2];
            sum = k;
        } else if (k%n == n-1) {
            fill(val, val+n, (k+1)/n);
            ++val[0];
            --val[1];
            --val[2];
            sum = k;
        } else {
            fill(val, val+n, k/n);
            ++val[0], ++val[1];
            sum = (k/n)*n+2;
            for (int i = 0; i < n && sum < k; ++i) {
                while (sum < k && ((i < n-2 && val[i] < n)
                || (i >= n-2 && val[i] < n-1)))
                    ++val[i], ++sum;
            }
        }

        if (flip) {
            k = ok;
            for (int i = 0; i < n; ++i)
                val[i] = (n+1) - val[i];
        }

        /*for (int i = 0; i < n; ++i)
            printf("%d ", val[i]);
        printf("\n");*/
        pii cnt[N];
        for (int i = 1; i <= n; ++i)
            cnt[i] = pii(0, i);
        for (int i = 0; i < n; ++i)
            ++cnt[val[i]].first;
        sort(cnt+1, cnt+n+1, greater<pii>());

        int arr[N][N] = {}, ori[N][N] = {}; // 1-based index
        bool row[N][N] = {}, col[N][N] = {};
        bool orirow[N][N] = {}, oricol[N][N] = {};
        sum = 0; // now tracking the position
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < cnt[i].first; ++j) {
                ++sum;
                ori[sum][sum] = arr[sum][sum] = i;
                orirow[sum][i] = row[sum][i] = true;
                oricol[sum][i] = col[sum][i] = true;
            }
        }

        int last = 0;
        for (int i = 2; i <= n; ++i)
            last += cnt[i].first;
        int rev[N] = {};
        for (int i = 1; i <= n; ++i)
            rev[i] = cnt[i].second;

        /*for (int i = 1; i <= n; ++i)
            printf("%d %d\n", cnt[i].first, cnt[i].second);*/

        auto greedy = [&] (int num, int start) {
            int order[N] = {}, where=0;
            for (int i = start; i <= n; ++i)
                order[where++] = i;
            for (int i = 1; i <= start-1; ++i)
                order[where++] = i;

            for (int i = 1; i <= n; ++i) {
                if (row[i][num]) continue;
                bool ok = false;
                for (int x = 0; x < n; ++x) {
                    int j = order[x];
                    if (!arr[i][j] && !col[j][num]) {
                        arr[i][j] = num;
                        row[i][num] = col[j][num] = true;
                        ok = true;
                        break;
                    }
                }
                if (ok) continue;
                return false;
            }
            return true;
        };

        auto dogreedy = [&] (const vector<int> &ord) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    arr[i][j] = ori[i][j];
                    row[i][j] = orirow[i][j];
                    col[i][j] = oricol[i][j];
                }
            }
            for (auto x : ord) {
                if (!greedy(x, x))
                    return false;
            }
            return true;
        };

        vector<int> ord1, ord2;
        for (int i = 1; i <= n; ++i) {
            ord1.push_back(i);
            if (i == 1) ord2.push_back(n);
            if (i > 1 && i < n) ord2.push_back(i);
            ord2.push_back(1);
        }
        bool pass = true;
        if (!dogreedy(ord1)) {
            if (!dogreedy(ord2)) {
                bool ok = false;
                int cntperm = 0;
                do {
                    ++cntperm;
                    shuffle(ord1.begin(), ord1.end(), RNG);
                    if (dogreedy(ord1)) {
                        fprintf(stderr, "Case %d: %d\n", t, cntperm);
                        //for (int i = 1; i <= n; ++i)
                            //fprintf(stderr, "%d %d\n", cnt[i].first, cnt[i].second);
                        ok = true;
                        break;
                    }
                } while (cntperm < 10000);
                //} while (next_permutation(ord1.begin(), ord1.end()));
                if (!ok) pass = false;
            }
        }

        if (!pass) {
            fprintf(stderr, "FAIL ON CASE %d\n", t);
            for (int i = 1; i <= n; ++i)
                fprintf(stderr, "%d %d\n", cnt[i].first, cnt[i].second);
            exit(1);
        }

        printf("Case #%d: POSSIBLE", t);
        for (int i = 1; i <= n; ++i) {
            printf("\n");
            for (int j = 1; j <= n; ++j) {
                if (j != 1) printf(" ");
                printf("%d", rev[arr[i][j]]);
            }
        }
        printf("\n");

    }
    
    return 0;
}