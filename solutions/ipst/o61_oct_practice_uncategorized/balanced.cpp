#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data, height;
    Node *left, *right;
    Node(int x) {
        data = x;
        height = 1;
        left = right = nullptr;
    }
};

int height(Node *root)
{
    if (!root) return 0;
    return root->height;
}

Node *leftRotate(Node *root)
{
    Node *newroot = root->right;
    root->right = newroot->left;
    newroot->left = root;
    root->height = max(height(root->left), height(root->right))+1;
    newroot->height = max(height(newroot->left), height(newroot->right))+1;
    return newroot;
}

Node *rightRotate(Node *root)
{
    Node *newroot = root->left;
    root->left = newroot->right;
    newroot->right = root;
    root->height = max(height(root->left), height(root->right))+1;
    newroot->height = max(height(newroot->left), height(newroot->right))+1;
    return newroot;
}

Node *insert(Node *root, int data)
{
    if (!root) return new Node(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    else return root;

    root->height = max(height(root->left), height(root->right))+1;
    int bal = height(root->left) - height(root->right);
    if (bal > 1) { // left heavy
        if (data < root->left->data) { // left left
            return rightRotate(root);
        } else {
            root->left = leftRotate(root->left); // left right
            return rightRotate(root);
        }
    } else if (bal < -1) { // right heavy
        if (data > root->right->data) { // right right
            return leftRotate(root);
        } else { // right left
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    } else {
        return root;
    }
}

bool search(Node *root, int data)
{
    if (!root) return false;
    if (data < root->data) return search(root->left, data);
    if (data > root->data) return search(root->right, data);
    return true;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    Node *root = nullptr;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }
    for (int i = 0; i < m; ++i) {
        int x;
        scanf("%d", &x);
        printf("%c\n", search(root, x) ? 'y' : 'n');
    }

    return 0;
}