#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;

Node *createNode(int data)
{
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

void addToList(int data)
{
    Node *newNode = createNode(data);
    tail->next = newNode;
    tail = newNode;
}

void removeNode(Node *rem)
{
    Node *delNode = rem->next;
    rem->next = delNode->next;
    free(delNode);
}

int main(void)
{
    int n, k;
    scanf("%d%d", &n, &k);

    head = createNode(1);
    tail = head;
    for (int i = 2; i <= n; ++i)
        addToList(i);
    
    Node *currNode = tail;
    while (n > 0)
    {
        int move = k % n;
        if (move == 0)
            move += k;
        while (--move)
            currNode = currNode->next;
        
        printf("%d\n", currNode->next->data);
        removeNode(currNode);

        --n;
    }

    return 0;
}