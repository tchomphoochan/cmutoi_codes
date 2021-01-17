#include <cstdio>

typedef long long ll;

struct Node
{
    int ix;
    ll ppl;
    Node *next;
    bool general;

    Node()
    {
        ix = 0;
        ppl = 0;
        next = this;
        general = true;
    }

    Node &getMaster()
    {
        Node *curr = this;
        while (!curr->general)
            curr = curr->next;
        return *curr;
    }

    void changeMaster(Node *master)
    {
        Node &curr = getMaster();
        master->general = true;
        master->next = curr.next;
        curr.general = false;
        curr.next = master;
    }
};

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    Node *gens = new Node[n + 1];
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &gens[i].ppl);
        gens[i].ix = i;
    }
    
    for (int i = 0; i < m; i++)
    {
        int ai, bi;
        scanf("%d %d", &ai, &bi);

        Node &a = gens[ai].getMaster();
        Node &b = gens[bi].getMaster();

        if (a.ix == b.ix)
        {
            printf("-1\n");
            continue;
        }

        bool awin;
        if (a.ppl > b.ppl)
            awin = true;
        else if (a.ppl == b.ppl)
            awin = (a.ix < b.ix);
        else
            awin = false;
        
        if (awin)
        {
            a.ppl += b.ppl / 2;
            b.changeMaster(&a);
            printf("%d", a.ix);
        }
        else
        {
            b.ppl += a.ppl / 2;
            a.changeMaster(&b);
            printf("%d", b.ix);
        }
        printf("\n");
    }

    return 0;
}