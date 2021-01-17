#include <cstdio>
#include <stack>
#include <map>
using namespace std;

int preOrder[1005], postOrder[1005];
map<int, bool> use;
stack<int> st;

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &preOrder[i]);
    for(int i = 0; i < N; ++i)
        scanf("%d", &postOrder[i]);
    int idxPost = 0;
    for(int i = 0; i < N; ++i){
        st.push(preOrder[i]);
        /*
        stack<int> tmp = st;
        printf("STACK-> ");
        while(!tmp.empty()){
            printf("%d ", tmp.top());
            tmp.pop();
        }
        printf("\n");
        */
        while(use.find(postOrder[idxPost]) != use.end())
            idxPost++;
        if(preOrder[i] == postOrder[idxPost]){
            printf("%d\n", st.top());
            use[st.top()] = true;
            st.pop();
            if(!st.empty()){
                printf("%d\n", st.top());
                use[st.top()] = true;
                st.pop();
            }
        }
    }
    return 0;
}
/*
4
1
2
7
8
2
8
7
1

15
1
2
4
8
9
5
10
11
3
6
12
13
7
14
15
8
9
4
10
11
5
2
12
13
6
14
15
7
3
1
*/
