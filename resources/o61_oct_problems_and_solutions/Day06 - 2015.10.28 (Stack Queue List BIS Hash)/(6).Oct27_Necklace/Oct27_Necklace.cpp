#include <cstdio>
#define HEAD 0
#define TAIL 1
using namespace std;

class NODE{
public:
    int val;
    NODE *l, *r;
    NODE(int val){
        this->val = val;
        l = r = NULL;
    }
};

NODE* p[300005];

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i){
        p[i] = new NODE(i);
    }
    int to, origin;
    for(int i = 1; i < N; ++i){
        scanf("%d%d", &to, &origin);
        NODE* lastOfTo = p[to];
        if(lastOfTo->r != NULL){
            while(lastOfTo->r != NULL)
                lastOfTo = lastOfTo->r;
            if(p[origin]->r != NULL){
                p[origin]->r->l = lastOfTo;
                lastOfTo->r = p[origin]->r;
            }
            p[origin]->r = p[to];
            p[to]->l = p[origin];
        }
        else{
            p[to]->r = p[origin]->r;
            p[to]->l = p[origin];
            p[origin]->r = p[to];
        }
        /*
        printf("-> ");
        NODE* current = p[origin];
        while(current != NULL){
            printf("%d ", current->val);
            current = current->r;
        }
        printf("\n");
        //*/
    }
    int st;
    for(int i = 1; i <= N; ++i){
        if(p[i]->l == NULL){
            st = i;
            break;
        }
    }
    NODE* current = p[st];
    while(current != NULL){
        printf("%d ", current->val);
        current = current->r;
    }
    return 0;
}
