#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int key, height;
    Node *left, *right;
    Node(int data) {
        key = data;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
};

int height(Node *root)
{
    if (!root) return 0;
    else return root->height;
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

Node *leftRotate(Node *root)
{
    Node *newroot = root->right;
    root->right = newroot->left;
    newroot->left = root;
    root->height = max(height(root->left), height(root->right))+1;
    newroot->height = max(height(newroot->left), height(newroot->right))+1;
    return newroot;
}

Node *insert(Node *root, int data)
{
    if (!root) return new Node(data);
    if (data < root->key) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);

    root->height = max(height(root->left), height(root->right))+1;
    int balance = height(root->left) - height(root->right);

    if (balance > 1) {
        if (data < root->left->key) { // left left
            return rightRotate(root);
        } else { // left right
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    } else if (balance < -1) {
        if (data < root->right->key) { // right left
            root->right = rightRotate(root->right);
            return leftRotate(root);
        } else { // right right
            return leftRotate(root);
        }
    } else {
        return root;
    }
}

void *preorder(Node *root, int level)
{
    for (int i = 0; i < level; ++i)
        printf("| ");

    if (!root) {
        printf("null\n");
    } else {
        printf("%d\n", root->key);
        preorder(root->left, level+1);
        preorder(root->right, level+1);
    }
}

int main()
{
    Node *root = nullptr;
    while (true) {
        int v;
        scanf("%d", &v);
        root = insert(root, v);
        preorder(root, 0);
    }

    return 0;
}