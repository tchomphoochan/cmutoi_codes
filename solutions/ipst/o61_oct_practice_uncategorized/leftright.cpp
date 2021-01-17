#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

Node *insert(Node *root, int data)
{
    if (!root) {
        printf("*\n");
        return new Node(data);
    }
    if (data < root->data) {
        printf("L");
        root->left = insert(root->left, data);
    } else {
        printf("R");
        root->right = insert(root->right, data);
    }
    return root;
}

int main()
{
    int n;
    scanf("%d", &n);
    Node *root = nullptr;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    return 0;
}