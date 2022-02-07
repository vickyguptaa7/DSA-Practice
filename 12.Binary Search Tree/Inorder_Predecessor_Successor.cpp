#include <iostream>
#include <queue>
#include <vector>
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

void Find_Pre_Suc(node *root, node *&pre, node *&suc, int key)
{
    if (!root)
        return;
    if (root->key > key)
    {
        suc = root;
        Find_Pre_Suc(root->left, pre, suc, key);
    }
    else if (root->key < key)
    {
        pre = root;
        Find_Pre_Suc(root->right, pre, suc, key);
    }
    else
    {
        if (root->left)
        {
            node *curr = root->left;
            while (curr->right)
                curr = curr->right;
            pre = curr;
        }
        if (root->right)
        {
            node *curr = root->right;
            while (curr->left)
                curr = curr->left;
            suc = curr;
        }
        return;
    }
}

void Inorder_Predessor_Successor(node *root,int key)
{
    node *pre = nullptr, *suc = nullptr;
    Find_Pre_Suc(root, pre, suc, key);
    if (pre && suc)
        cout << pre->key << " " << suc->key << " ";
    else if (pre)
        cout << pre->key << " " << -1 << endl;
    else if (suc)
        cout << -1 << " " << suc->key << endl;
    else
        cout << "-1 -1" << endl;
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
    Inorder_Predessor_Successor(root,60);
    return 0;
}