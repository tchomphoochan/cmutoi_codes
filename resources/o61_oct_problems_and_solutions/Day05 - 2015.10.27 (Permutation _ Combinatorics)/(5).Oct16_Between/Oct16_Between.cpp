#include <cstdio>
#include <vector>
using namespace std;

vector<pair<int, int> > mid[25], border[25];
int N, ans[25], pos[25], cntCMP;
bool visited[25];

bool valid(int now){
    cntCMP++;
    int a, b, m;
    for(int i = 0; i < mid[now].size(); ++i){
        a = mid[now][i].first, b = mid[now][i].second;
        if((visited[a]||visited[b]) == 0 || (visited[a]&&visited[b]) == 1)
            return 0;
    }
    for(int i = 0; i < border[now].size(); ++i){
        a = border[now][i].first, m = border[now][i].second;
        if(((visited[a]&&visited[m]) && pos[a] < pos[m]) || (!visited[a] && !visited[m]))
            continue;
        else
            return 0;
    }
    return 1;
}

bool rec(int len){
    /*
    for(int i = 1; i < len; ++i)
        printf("%d ", ans[i]);
    printf("\n");
    */
    if(cntCMP >= 10000000)
        return 0;
    if(len == N+1)
        return 1;
    else{
        for(int i = N; i >= 0; --i){
            if(!visited[i] && valid(i)){
                //printf("REC %d\n", i);
                visited[i] = true;
                ans[len] = i;
                pos[i] = len;
                if(rec(len+1))
                    return 1;
                visited[i] = false;
                ans[len] = 0;
                pos[i] = 0;
            }
            if(cntCMP >= 10000000)
                return 0;
        }
    }
}

int main(){
    int c;
    scanf("%d%d", &N, &c);
    for(int i = 0; i < c; ++i){
        int l, m, r;
        scanf("%d%d%d", &m, &l, &r);
        mid[m].push_back(make_pair(l, r));
        border[l].push_back(make_pair(r, m));
        border[r].push_back(make_pair(l, m));
    }
    if(rec(1)){
        printf("YES\n");
        printf("%d", ans[1]);
        for(int i = 2; i <= N; ++i)
            printf(" %d", ans[i]);
    }
    else
        printf("NO");
    return 0;
}
