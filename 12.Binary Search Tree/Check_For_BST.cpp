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

int Max_In_BST(node *root)
{
    if (!root)
        return -1000000000;
    int lmax = Max_In_BST(root->left);
    int rmax = Max_In_BST(root->right);
    return max(root->key, max(lmax, rmax));
}

int Min_In_BST(node *root)
{
    if (!root)
        return 1000000000;
    int lmin = Min_In_BST(root->left);
    int rmin = Min_In_BST(root->right);
    return min(root->key, min(lmin, rmin));
}

bool Check_For_BST_Brute(node *root)
{
    if (!root)
        return 1;
    if (root->left && root->key < Max_In_BST(root->left))
        return 0;
    if (root->right && root->key > Min_In_BST(root->right))
        return 0;
    if (!Check_For_BST_Brute(root->left))
        return 0;
    if (!Check_For_BST_Brute(root->right))
        return 0;
    return 1;
}

bool Check_For_BST_Opt1(node *root, int l = INT_MIN, int r = INT_MAX)
{
    if (!root)
        return 1;
    if (root->key <= l || root->key >= r)
        return 0;
    if (!Check_For_BST_Opt1(root->left, l, root->key))
        return 0;
    if (!Check_For_BST_Opt1(root->right, root->key, r))
        return 0;
    return 1;
}
int prev = INT_MIN;
bool Check_For_BST_Opt2(node *root)
{
    if (!root)
        return 1;
    if (!Check_For_BST_Opt2(root->left))
        return 0;
    if (::prev >= root->key)
        return 0;
    ::prev = root->key;
    if (!Check_For_BST_Opt2(root->right))
        return 0;
    return 1;
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
    root->right->left->left = new node(191);
    Level_Order_Traversal_m2(root);
    cout << endl;
    cout << Check_For_BST_Brute(root);
    cout << endl
         << Check_For_BST_Opt1(root);
    cout << endl
         << Check_For_BST_Opt2(root);
    return 0;
}