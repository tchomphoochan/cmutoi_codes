#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

struct Edge
{
    int to;
    int len;

    Edge(int t, int l)
    {
        to = t;
        len = l;
    }
};

struct Node
{
    int number;
    int lenSoFar;
    vector<Edge> edges;

    Node()
    {
        number = 0;
        lenSoFar = 0;
    }

    Node(int num)
    {
        number = num;
        lenSoFar = 0;
    }
};

struct Next
{
    int from;
    int check;
    int len;

    Next(int f, int c, int l)
    {
        from = f;
        check = c;
        len = l;
    }
};

int main()
{
    int n;
    scanf("%d", &n);
    Node *nodes = new Node[n + 1];

    for (int i = 0; i < n - 1; i++)
    {
        int x, y, len;
        scanf("%d %d %d", &x, &y, &len);
        nodes[x].edges.push_back(Edge(y, len));
        nodes[y].edges.push_back(Edge(x, len));
    }

    queue<Next> nexts;
    vector<Edge> &fe = nodes[1].edges;
    for (int i = 0; i < fe.size(); i++)
        nexts.push(Next(1, fe[i].to, fe[i].len));
    
    int best = 0;
    while (!nexts.empty())
    {
        Next next = nexts.front();
        nexts.pop();

        nodes[next.check].lenSoFar = nodes[next.from].lenSoFar + next.len;
        if (nodes[next.check].lenSoFar > best)
            best = nodes[next.check].lenSoFar;

        vector<Edge> &ce = nodes[next.check].edges;
        for (int i = 0; i < ce.size(); i++)
        {
            if (ce[i].to == next.from)
                continue;
            
            nexts.push(Next(next.check, ce[i].to, ce[i].len));
        }
    }

    printf("%d", best);
    // delete [] nodes - a waste of time
    return 0;
}