#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

class BOX{
public:
    int w, c;
    BOX(){}
    BOX(int w, int c){
        this->w = w;
        this->c = c;
    }
};
int N, hah[100005];
vector<BOX> vec;
int PROCESS(int limit){
    memset(hah, 0, sizeof(hah));
    int boxes = 1, w = 0;
    for(int i = 1; i <= N; ++i){
        if(hah[vec[i].c] == boxes){    // have been use c
            boxes++;
            w = vec[i].w;
            hah[vec[i].c] = boxes;
            continue;
        }
        if(w+vec[i].w > limit){
            w = vec[i].w;
            boxes++;
        }
        else
            w+=vec[i].w;
        hah[vec[i].c] = boxes;
    }
    return boxes;
}

int main(){
    int totalCase;
    bool blank = false;
    scanf("%d", &totalCase);
    vec.resize(100005);
    while(totalCase--){
        int want, ma = 0;
        scanf("%d%d", &N, &want);
        for(int i = 1; i <= N; ++i){
            int w, c;
            scanf("%d%d", &w, &c);
            vec[i] = BOX(w, c);
            ma = max(ma, w);
        }
        int L = ma, R = 100000000, mid, idx = -1;
        while(L <= R){
            mid = (L+R)/2;
            int boxUse = PROCESS(mid);
            //printf("%d->%d\n", mid, boxUse);
            if(boxUse <= want){
                idx = mid;
                R = mid-1;
            }
            else
                L = mid+1;
        }
        printf("%d", idx);
    }
    return 0;
}
/*
2
5 3
10 1
10 2
40 1
30 3
30 4
5 3
10 1
10 2
10 1
10 1
10 1
*/
