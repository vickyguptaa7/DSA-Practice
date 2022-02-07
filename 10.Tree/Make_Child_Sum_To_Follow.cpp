#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int key;
    node *left;
    node *right;
    node(int k)
    {
        key = k;
        left = nullptr;
        right = nullptr;
    }
};

void Traversal(node *root)
{
    if (!root)
        return;

    queue<node *> que;
    que.push(root);
    while (!que.empty())
    {
        int size = que.size();
        while (size--)
        {
            cout << que.front()->key << " ";
            if (que.front()->left)
                que.push(que.front()->left);
            if (que.front()->right)
                que.push(que.front()->right);
            que.pop();
        }
        cout << endl;
    }
}

void reorder(node *root)
{
    if (root == nullptr)
        return;
    int child = 0;
    if (root->left)
        child += root->left->key;

    if (root->right)
        child += root->right->key;

    if (child >= root->key)
        root->key = child;
    else
    {
        if (root->left)
            root->left->key = root->key;
        else if (root->right)
            root->right->key = root->key;
    }

    reorder(root->left);
    reorder(root->right);

    int sumlr = 0;
    if (root->left)
        sumlr += root->left->key;
    if (root->right)
        sumlr += root->right->key;
    if (root->left || root->right)
        root->key = sumlr;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right->left = new node(4);
    root->right->right = new node(13);
    Traversal(root);
    reorder(root);
    cout << endl;
    Traversal(root);
    return 0;
}