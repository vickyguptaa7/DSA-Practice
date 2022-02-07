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

void Level_Order_Traversal_m1(node *root)
{
    queue<node *> que;
    que.push(root);
    que.push(nullptr);
    while (que.size() > 1)
    {
        node *curr = que.front();
        que.pop();
        if (!curr)
        {
            cout << endl;
            que.push(nullptr);
            continue;
        }
        cout << curr->key << " ";
        if (curr->left)
            que.push(curr->left);
        if (curr->right)
            que.push(curr->right);
    }
}

void Level_Order_Traversal_m2(node *root)
{
    queue<node *> que;
    que.push(root);
    while (!que.empty())
    {
        int count = que.size();
        for (int i = 0; i < count; i++)
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

int Children_Sum_Property(node *root)
{
    if ((!root)||(!root->left&&!root->right))
        return 1;

    int sum = root->key;
    if (root->left)
        sum -= root->left->key;
    if (root->right)
        sum -= root->right->key;
    if (sum == 0)
    {
        bool c1=Children_Sum_Property(root->left);
        bool c2=Children_Sum_Property(root->right);
        return (c1&&c2);
    }
    else 
    return 0;
}

int main()
{
    node *root = new node(10);
    root->left = new node(3);
    root->right = new node(7);
    root->left->left = new node(2);
    root->left->right = new node(1);
    root->right->left = new node(7);
    root->right->right = new node(0);

    Level_Order_Traversal_m2(root);
    cout << endl<< endl;
    
    cout<<Children_Sum_Property(root);
    return 0;
}