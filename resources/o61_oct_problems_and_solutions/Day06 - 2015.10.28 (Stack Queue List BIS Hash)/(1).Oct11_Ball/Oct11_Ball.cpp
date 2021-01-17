#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

stack<int> stk, tmp;
vector<int> vec;
void pushBall(int now, int stop){
    stk.pop();
    /*
    tmp = stk;
    printf("N:%d S:%d\n", now, stop);
    while(!tmp.empty()){
        printf("%d ", tmp.top());
        tmp.pop();
    }
    printf("\n\n");
    */
    if(stk.empty()){
        stk.push(stop);
        return;
    }
    if(stop < stk.top()){
        stk.push(stop);
    }
    else{
        int top = stk.top()-1;
        if(stk.top()-1 < stop-1){
            pushBall(stk.top()-1, stop-1);
            stk.push(top);
        }
        else
            stk.push(stop-1);
    }
}
void pushBall2(int en){
    stk.pop();
    if(stk.empty()){
        return;
    }
    if(stk.top() < en){
        pushBall2(en+1);
        stk.push(en);
    }
}

int main(){
    int N;
    scanf("%d", &N);
    int x;
    for(int i = 0; i < N; ++i){
        scanf("%d", &x);
        if(!stk.empty() && stk.top() == 0){
            stk.push(-1);
            pushBall2(x+1);
            stk.push(x);
        }
        else{
            stk.push(-1);
            pushBall(0, x);
        }
        /*
        tmp = stk;
        while(!tmp.empty()){
            printf("%d ", tmp.top());
            tmp.pop();
        }
        printf("\n");
        //*/
    }
    while(!stk.empty()){
        vec.push_back(stk.top());
        stk.pop();
    }
    for(int i = vec.size()-1; i >= 0; --i)
        printf("%d\n", vec[i]);
    return 0;
}
