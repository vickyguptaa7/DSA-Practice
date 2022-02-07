#include <iostream>
#include <vector>
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
void Level_Order_Traversal_m2(node *root)
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

void Print(vector<int> arr)
{
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

void Inorder(node *root, vector<int> &ans)
{
    if (!root)
        return;
    Inorder(root->left, ans);
    ans.push_back(root->key);
    Inorder(root->right, ans);
}

node *LCA_IN_BST_Brute(node *root, int n1, int n2)
{
    vector<node *> p1, p2;
    node *curr = root;
    while (curr)
    {
        if (curr->key == n1)
        {
            p1.push_back(curr);
            break;
        }
        else if (curr->key > n1)
        {
            p1.push_back(curr);
            curr = curr->left;
        }
        else
        {
            p1.push_back(curr);
            curr = curr->right;
        }
    }
    curr = root;
    while (curr)
    {
        if (curr->key == n2)
        {
            p2.push_back(curr);
            break;
        }
        else if (curr->key > n2)
        {
            p2.push_back(curr);
            curr = curr->left;
        }
        else
        {
            p2.push_back(curr);
            curr = curr->right;
        }
    }

    int i;
    for (i = 0; i < min(p1.size(), p2.size()); i++)
    {
        if (p1[i] != p2[i])
            break;
    }
    return p2[i - 1];
}

node *LCA_IN_BST_Opt(node *root, int n1, int n2)
{
    if(!root)return nullptr;
    if(root->key>n1&&root->key>n2)
    {
        return LCA_IN_BST_Opt(root->left,n1,n2);
    }
    else if(root->key<n1&&root->key<n2)
    {
        return LCA_IN_BST_Opt(root->right,n1,n2);
    }
    else
    {
        return root;
    }
}

int main()
{
    node *root = new node(10);
    root->left = new node(8);
    root->right = new node(20);
    root->left->left = new node(5);
    root->left->right = new node(9);
    root->right->right = new node(60);
    root->right->left = new node(15);
    Level_Order_Traversal_m2(root);
    vector<int> arr;
    Inorder(root, arr);
    Print(arr);

    cout<<LCA_IN_BST_Brute(root,1,60)->key<<endl;
    cout<<LCA_IN_BST_Opt(root,1,60)->key<<endl;
    return 0;
}