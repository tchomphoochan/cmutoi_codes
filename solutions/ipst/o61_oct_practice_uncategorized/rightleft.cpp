#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

struct Node {
    vector<int> ix;
    Node *left;
    Node *right;
};

Node *build(int ix, Node *root, string &walk, int i)
{
    if (!root) root = new Node();
    if (walk[i] == 'L')
        root->left = build(ix, root->left, walk, i+1);
    else if (walk[i] == 'R')
        root->right = build(ix, root->right, walk, i+1);
    else
        root->ix.push_back(ix);
    return root;
}

int cnt = 0;
int ans[N];

void inorder(Node *root)
{
    if (!root) return;
    inorder(root->left);
    ++cnt;
    for (auto x : root->ix)
        ans[x] = cnt;
    inorder(root->right);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    Node *root = nullptr;
    for (int i = 0; i < n; ++i) {
        string walk;
        cin >> walk;
        root = build(i, root, walk, 0);
    }

    inorder(root);
    for (int i = 0; i < n; ++i)
        printf("%d\n", ans[i]);

    return 0;
}