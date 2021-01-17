#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;
using ll = long long;;
using pll = pair<ll, ll>;

// ===================================================

const int INF = 1e9;
// const ll INF = 1e18;

const int N = 100010;

struct Node {
    int data;
    Node *next;
    map<int, int> rem;
    Node(int data) {
        this->data = data;
    }
};

Node *head[N];
Node *tail[N];
int size[N];

void print_list(Node *root)
{
    map<int, int> rem;
    int cnt = 0;
    while (root) {

        for (auto rm : root->rem)
            rem[rm.first] = max(rem[rm.first], rm.second+cnt);
        
        if (cnt >= rem[root->data])
            printf("%d\n", root->data);

        root = root->next;
        ++cnt;
    }
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &size[i]);
        for (int j = 0; j < size[i]; ++j) {
            int x;
            scanf("%d", &x);
            if (j != 0) {
                tail[i]->next = new Node(x);
                tail[i] = tail[i]->next;
            } else {
                tail[i] = new Node(x);
                head[i] = tail[i];
            }
        }
    }

    while (m--) {

        int t, i, j;
        scanf("%d%d%d", &t, &i, &j);
        if (t == 1) {
            head[i]->rem[j] = max(head[i]->rem[j], size[i]);
        } else {
            if (!head[j]) continue;
            if (head[i]) {
                tail[i]->next = head[j];
                tail[i] = tail[j];
                size[i] += size[j];
                head[j] = tail[j] = nullptr;
                size[j] = 0;
            } else {
                head[i] = head[j];
                tail[i] = tail[j];
                size[i] = size[j];
                head[j] = tail[j] = nullptr;
                size[j] = 0;
            }
        }

    }

    for (int i = 1; i <= n; ++i) {
        print_list(head[i]);
    }

    return 0;
}