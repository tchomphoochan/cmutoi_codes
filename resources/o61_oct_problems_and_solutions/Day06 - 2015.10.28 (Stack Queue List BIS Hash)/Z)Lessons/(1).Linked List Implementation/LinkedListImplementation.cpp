#include <cstdio>
using namespace std;

template <typename T>
class ListNode
{
public:
    T val;
    ListNode* next;

    ListNode()
    {
        next = NULL;
    }

    ListNode(T v)
    {
        val = v;
        next = NULL;
    }
};

template <typename T>
class LinkedList
{
public:
    ListNode<T> *header, *tail;
    LinkedList()
    {
        header = new ListNode<T>;
        tail = header;
    }
    void push_back(T x);
};

template <typename T>
void LinkedList<T>::push_back(T x)
{
    ListNode<T> *n = new ListNode<T>(x);
    tail->next = n;
    tail = n;
}

int main()
{

    return 0;
}
