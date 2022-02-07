#include <iostream>
#include <queue>
#include <stack>
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

bool Check_leaf_Recursion(node *root, int lvl, int &leaflvl)
{
    if (!root)
        return 1;
    if (!root->left && !root->right)
    {
        if (leaflvl == 0)
        {
            leaflvl = lvl;
        }
        if (leaflvl == lvl)
            return 1;
        else
            return 0;
    }
    return Check_leaf_Recursion(root->left,lvl+1,leaflvl)
    &&Check_leaf_Recursion(root->right,lvl+1,leaflvl);
}

bool Check_Leaf(node *root) // Iterative
{
    queue<node *> que;
    que.push(root);
    int count = 0;
    while (!que.empty())
    {
        int n = que.size();
        bool chk = 0;
        for (int i = 0; i < n; i++)
        {
            node *curr = que.front();
            que.pop();
            if (curr->left)
                que.push(curr->left);
            if (curr->right)
                que.push(curr->right);

            if (!curr->right && !curr->left)
                chk = 1;
        }
        if (chk)
            count++;
        if (count > 1)
            break;
    }
    return (count == 1) ? 1 : 0;
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

    Level_Order_Traversal(root); //method 1
    cout << endl;
    int leaflvl=0;
    cout << Check_leaf_Recursion(root,0,leaflvl) << " ";
    return 0;
}