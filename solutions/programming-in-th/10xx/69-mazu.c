#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *prev;
    struct node *next;
    char data;
} node;

node *createNode(char data)
{
    node *newNode = (node*) malloc(sizeof(node));
    newNode->prev = NULL;
    newNode->next = NULL;
    newNode->data = data;
    return newNode;
}

void addToEnd(node **head, node **tail, char data)
{
    node *newNode = createNode(data);

    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);

    node *head = NULL;
    node *tail = NULL;
    for (int i = 0; i < n; i++)
    {
        char c;
        scanf(" %c", &c);
        addToEnd(&head, &tail, c);
    }

    bool removed;
    do
    {
        removed = false;

        node **pp = &head;
        while (*pp)
        {
            if ((*pp)->next && (*pp)->data == (*pp)->next->data)
            {
                node *prev = (*pp)->prev;
                *pp = (*pp)->next->next;
                if (*pp)
                    (*pp)->prev = prev;
                else
                    tail = prev;
                removed = true;
                n -= 2;
            }
            else
            {
                pp = &((*pp)->next);
            }
        }
    }
    while (removed);

    if (n == 0)
    {
        printf("0\nempty");
    }
    else
    {
        printf("%d\n", n);
        for (node *currNode = tail; currNode != NULL; currNode = currNode->prev)
            printf("%c", currNode->data);
    }

    return 0;
}