#include <cstdio>
#include <cstring>
using namespace std;

class listNode{
public:
    char str[15];
    listNode *r, *l;
    listNode(){
        r = l = NULL;
    }
    listNode(char str[]){
        strcpy(this->str, str);
        r = l = NULL;
    }
};
listNode *head = new listNode(), *tail = new listNode(), *cur;

int main(){
    int N;
    char opr[5], word[15];
    cur = head;
    head->r = tail;
    tail->l = head;
    scanf("%d", &N);
    while(N--){
        scanf("%s", opr);
        if(opr[0] == 'i'){
            scanf("%s", word);
            listNode *newNode = new listNode(word);
            newNode->r = cur->r;
            newNode->l = cur;
            cur->r->l = newNode;
            cur->r = newNode;
            cur = newNode;
        }
        else if(opr[0] == 'r'){
            if(cur->r == tail)
                continue;
            cur = cur->r;
        }
        else if(opr[0] == 'l'){
            if(cur->l != NULL)
                cur = cur->l;
        }
        else if(opr[0] == 'b'){     /// erase front of cursor
            if(cur == head)
                continue;
            listNode *delNode = cur;
            cur = cur->r;
            cur->l->l->r = cur;
            cur->l = cur->l->l;
            cur = cur->l;
            delete delNode;
        }
        else if(opr[0] == 'd'){
            if(cur->r == tail)
                continue;
            listNode *delNode = cur->r;
            cur->r->r->l = cur;
            cur->r = cur->r->r;
            delete delNode;
        }
        /*
        listNode *trav = head->r;
        while(trav != tail){
            printf("%s ", trav->str);
            trav = trav->r;
        }
        printf("\n");
        */
    }
    listNode *trav = head->r;
        while(trav != tail){
        printf("%s ", trav->str);
        trav = trav->r;
    }
    return 0;
}
/*
9
i Hello
i world
l
i this
r
b
d
l
d
*/
