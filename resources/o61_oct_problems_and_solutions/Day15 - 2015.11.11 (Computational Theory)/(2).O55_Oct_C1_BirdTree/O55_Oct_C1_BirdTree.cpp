#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(){
    int totalCase;
    scanf("%d", &totalCase);
    while(totalCase--){
        int x, y, level = 1, cnt = 0;
        scanf("%d/%d", &x, &y);
        double want = (double)x/y;
        pair<int, int> L = make_pair(0, 1), cur = make_pair(1, 1), R = make_pair(1, 0);
        while(1){
            if(cur.first == x && cur.second == y)
                break;
            double frac = (double)cur.first/cur.second;
            //printf("%d/%d %d/%d %d/%d (%d)\n", L.first, L.second, cur.first, cur.second, R.first, R.second, level);
            if(level == 1){
                if(want < frac+(1e-10)){
                    R = cur;
                    cur.first+=L.first;
                    cur.second+=L.second;
                    printf("L");
                }
                else if(want > frac-(1e-10)){
                    L = cur;
                    cur.first+=R.first;
                    cur.second+=R.second;
                    printf("R");
                }
            }
            else if(level == 0){
                if(want > frac-(1e-10)){
                    R = cur;
                    cur.first+=L.first;
                    cur.second+=L.second;
                    printf("L");
                }
                else if(want < frac+(1e-10)){
                    L = cur;
                    cur.first+=R.first;
                    cur.second+=R.second;
                    printf("R");
                }
            }
            //printf("\nTO: %d/%d %d/%d %d/%d\n", L.first, L.second, cur.first, cur.second, R.first, R.second);
            //system("pause");
            swap(L, R);
            if(cnt++ > 100000)
                break;
            level = 1-level;
        }
        printf("\n");
    }
    return 0;
}
