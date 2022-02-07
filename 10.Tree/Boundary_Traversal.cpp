#include <iostream>
#include <vector>
#include <stack>
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

void Pre_Traversal(node *root)
{
    if (!root)
        return;
    cout << root->key << " ";
    Pre_Traversal(root->left);
    Pre_Traversal(root->right);
}

bool isLeaf(node *root)
{
    if (!root->left && !root->right)
        return 1;
    else
        return 0;
}

void addLeftbndry_opt(node *root, vector<int> &res)
{
    if (!root)
        return;
    node *curr = root;
    while (curr)
    {
        if (!isLeaf(curr))
            res.push_back(curr->key);
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

void addRightbndry_opt(node *root, vector<int> &res)
{
    if (!root)
        return;
    node *curr = root;
    stack<int> st;
    while (curr)
    {
        if (!isLeaf(curr))
            st.push(curr->key);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }
}

void addBottombndry_opt(node *root, vector<int> &res)
{
    if (!root)
        return;
    if (isLeaf(root))
    {
        res.push_back(root->key);
        return;
    }
    addBottombndry_opt(root->left, res);
    addBottombndry_opt(root->right, res);
}

void Print(vector<int> res)
{
    cout << endl;
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
}

vector<int> BndryTraversal_Opt(node *root)
{
    vector<int> res;
    if (!root)
        return res;
    res.push_back(root->key);
    if (isLeaf(root))
        return res;
    addLeftbndry_opt(root->left, res);
    addBottombndry_opt(root, res);
    addRightbndry_opt(root->right, res);
    return res;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(7);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right->left = new node(5);
    root->right->right = new node(6);
    root->left->left->right = new node(8);
    root->left->left->right->left = new node(9);
    root->left->left->right->right = new node(10);
    root->right->right->left = new node(13);
    root->right->right->left->left = new node(11);
    root->right->right->left->right = new node(12);

    Pre_Traversal(root);
    Print(BndryTraversal_Opt(root));
    return 0;
}