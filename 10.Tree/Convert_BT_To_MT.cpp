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

void Level_Order_Traversal(node *root)
{
    queue<node *> que;
    que.push(root);
    while (!que.empty())
    {
        int n = que.size();
        for (int i = 0; i < n; i++)
        {
            node *curr = que.front();
            que.pop();
            cout << curr->key << " ";
            if (curr->left)
                que.push(curr->left);
            if (curr->right)
                que.push(curr->right);
        }
        cout << endl;
    }
}

void Swap(node*&curr)
{
    node*left=curr->left;
    node*right=curr->right;
    curr->left=right;
    curr->right=left;
}

void Level_Order_Traversal_c(node *root)
{
    queue<node *> que;
    que.push(root);
    while (!que.empty())
    {
        int n = que.size();
        for (int i = 0; i < n; i++)
        {
            node *curr = que.front();
            que.pop();
            Swap(curr);
            if (curr->left)
                que.push(curr->left);
            if (curr->right)
                que.push(curr->right);
        }
    }
    Level_Order_Traversal(root);
}

node *Mirror_Tree(node *root)
{
    if (!root)
        return nullptr;

    node *left = Mirror_Tree(root->left);
    node *right = Mirror_Tree(root->right);

    if (left && right) // Avoid Swapping Nullptr which is useless to do if both are null;
    {
        root->left = right;
        root->right = left;
    }

    return root;
}

int main()
{
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(40);
    root->left->right = new node(50);
    root->right->left = new node(60);
    root->right->right = new node(70);

    Level_Order_Traversal(root);
    cout << endl;
    Level_Order_Traversal_c(root);
    return 0;
}